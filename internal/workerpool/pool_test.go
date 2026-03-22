// SPDX-FileCopyrightText: Copyright (c) 2025 Cisco Systems
// SPDX-License-Identifier: BSD-2-Clause

package workerpool

import (
	"sync"
	"sync/atomic"
	"testing"
	"time"
)

func TestPool_Submit(t *testing.T) {
	pool := New(4, 100)
	defer pool.Close()

	var counter atomic.Int32
	var wg sync.WaitGroup

	const numTasks = 100
	wg.Add(numTasks)

	for i := 0; i < numTasks; i++ {
		pool.Submit(func() {
			counter.Add(1)
			wg.Done()
		})
	}

	wg.Wait()

	if got := counter.Load(); got != numTasks {
		t.Errorf("expected %d tasks completed, got %d", numTasks, got)
	}
}

func TestPool_Submit_Overflow(t *testing.T) {
	// Small queue to test overflow behavior
	pool := New(2, 4)
	defer pool.Close()

	var counter atomic.Int32
	var wg sync.WaitGroup

	// Submit more tasks than the queue can hold
	const numTasks = 50
	wg.Add(numTasks)

	for i := 0; i < numTasks; i++ {
		pool.Submit(func() {
			time.Sleep(time.Millisecond)
			counter.Add(1)
			wg.Done()
		})
	}

	wg.Wait()

	if got := counter.Load(); got != numTasks {
		t.Errorf("expected %d tasks completed, got %d", numTasks, got)
	}
}

func TestPool_TrySubmit(t *testing.T) {
	pool := New(1, 1)
	defer pool.Close()

	// Block the worker with synchronization
	started := make(chan struct{})
	blocking := make(chan struct{})
	pool.Submit(func() {
		close(started)
		<-blocking
	})

	// Wait for worker to start processing
	<-started

	// Fill the queue
	queued := pool.TrySubmit(func() {})

	// Queue should be full now
	notQueued := pool.TrySubmit(func() {})

	if !queued {
		t.Error("first TrySubmit should have succeeded")
	}
	if notQueued {
		t.Error("second TrySubmit should have failed (queue full)")
	}

	close(blocking)
}

func TestPool_Close(t *testing.T) {
	pool := New(4, 100)

	var counter atomic.Int32
	var wg sync.WaitGroup

	const numTasks = 50
	wg.Add(numTasks)

	for i := 0; i < numTasks; i++ {
		pool.Submit(func() {
			counter.Add(1)
			wg.Done()
		})
	}

	// Close waits for all tasks to complete
	pool.Close()
	wg.Wait()

	if got := counter.Load(); got != numTasks {
		t.Errorf("expected %d tasks completed after close, got %d", numTasks, got)
	}
}

func TestDefaultWorkers(t *testing.T) {
	workers := DefaultWorkers()
	if workers < 4 {
		t.Errorf("expected at least 4 workers, got %d", workers)
	}
	if workers > 16 {
		t.Errorf("expected at most 16 workers, got %d", workers)
	}
}

func BenchmarkPool_Submit(b *testing.B) {
	pool := New(0, 0)
	defer pool.Close()

	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		done := make(chan struct{})
		pool.Submit(func() {
			close(done)
		})
		<-done
	}
}

func BenchmarkGoroutine_Spawn(b *testing.B) {
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		done := make(chan struct{})
		go func() {
			close(done)
		}()
		<-done
	}
}
