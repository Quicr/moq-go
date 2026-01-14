package registry

import (
	"sync"
	"testing"
)

func TestRegistry_Register(t *testing.T) {
	r := New[string]()

	id1 := r.Register("hello")
	id2 := r.Register("world")

	if id1 == id2 {
		t.Error("Register should return unique IDs")
	}
	if id1 == 0 || id2 == 0 {
		t.Error("Register should return non-zero IDs")
	}
}

func TestRegistry_Get(t *testing.T) {
	r := New[string]()

	id := r.Register("hello")

	got, ok := r.Get(id)
	if !ok {
		t.Error("Get should return true for registered object")
	}
	if got != "hello" {
		t.Errorf("Get returned wrong value: got %q, want %q", got, "hello")
	}

	_, ok = r.Get(999)
	if ok {
		t.Error("Get should return false for non-existent ID")
	}
}

func TestRegistry_Unregister(t *testing.T) {
	r := New[string]()

	id := r.Register("hello")
	r.Unregister(id)

	_, ok := r.Get(id)
	if ok {
		t.Error("Get should return false after Unregister")
	}
}

func TestRegistry_Count(t *testing.T) {
	r := New[int]()

	if r.Count() != 0 {
		t.Error("Count should be 0 for empty registry")
	}

	id1 := r.Register(1)
	r.Register(2)

	if r.Count() != 2 {
		t.Errorf("Count should be 2, got %d", r.Count())
	}

	r.Unregister(id1)
	if r.Count() != 1 {
		t.Errorf("Count should be 1 after unregister, got %d", r.Count())
	}
}

func TestRegistry_Clear(t *testing.T) {
	r := New[int]()

	r.Register(1)
	r.Register(2)
	r.Register(3)

	r.Clear()

	if r.Count() != 0 {
		t.Errorf("Count should be 0 after Clear, got %d", r.Count())
	}
}

func TestRegistry_ForEach(t *testing.T) {
	r := New[int]()

	r.Register(10)
	r.Register(20)
	r.Register(30)

	sum := 0
	count := 0
	r.ForEach(func(id uint64, obj int) bool {
		sum += obj
		count++
		return true
	})

	if count != 3 {
		t.Errorf("ForEach should iterate 3 times, got %d", count)
	}
	if sum != 60 {
		t.Errorf("Sum should be 60, got %d", sum)
	}
}

func TestRegistry_ForEach_EarlyStop(t *testing.T) {
	r := New[int]()

	r.Register(1)
	r.Register(2)
	r.Register(3)

	count := 0
	r.ForEach(func(id uint64, obj int) bool {
		count++
		return count < 2 // Stop after 2 iterations
	})

	if count != 2 {
		t.Errorf("ForEach should stop early, got %d iterations", count)
	}
}

func TestRegistry_Concurrent(t *testing.T) {
	r := New[int]()
	var wg sync.WaitGroup

	// Concurrent writes
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func(val int) {
			defer wg.Done()
			id := r.Register(val)
			_, _ = r.Get(id)
		}(i)
	}

	wg.Wait()

	if r.Count() != 100 {
		t.Errorf("Count should be 100, got %d", r.Count())
	}
}

func TestRegistry_ConcurrentReadWrite(t *testing.T) {
	r := New[int]()
	var wg sync.WaitGroup

	// Pre-populate
	ids := make([]uint64, 10)
	for i := 0; i < 10; i++ {
		ids[i] = r.Register(i)
	}

	// Concurrent reads
	for i := 0; i < 50; i++ {
		wg.Add(1)
		go func(idx int) {
			defer wg.Done()
			_, _ = r.Get(ids[idx%10])
		}(i)
	}

	// Concurrent writes
	for i := 0; i < 50; i++ {
		wg.Add(1)
		go func(val int) {
			defer wg.Done()
			r.Register(val + 100)
		}(i)
	}

	wg.Wait()

	if r.Count() != 60 {
		t.Errorf("Count should be 60, got %d", r.Count())
	}
}

func BenchmarkRegistry_Register(b *testing.B) {
	r := New[int]()
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		r.Register(i)
	}
}

func BenchmarkRegistry_Get(b *testing.B) {
	r := New[int]()
	id := r.Register(42)
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		r.Get(id)
	}
}

func BenchmarkRegistry_ConcurrentGet(b *testing.B) {
	r := New[int]()
	id := r.Register(42)
	b.ResetTimer()
	b.RunParallel(func(pb *testing.PB) {
		for pb.Next() {
			r.Get(id)
		}
	})
}
