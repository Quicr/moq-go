// Package registry provides thread-safe registries for managing
// handle-to-object mappings used in CGO callback bridging.
package registry

import (
	"sync"
	"sync/atomic"
)

// Registry provides a thread-safe mapping between uint64 handle IDs and Go objects.
// It uses sync.Map for lock-free reads in the hot path (callback routing).
// This is optimized for the pattern where entries are written once, read many times,
// and eventually deleted.
type Registry[T any] struct {
	handles sync.Map // map[uint64]T
	nextID  atomic.Uint64
}

// New creates a new Registry.
func New[T any]() *Registry[T] {
	return &Registry[T]{}
}

// Register adds an object to the registry and returns its unique handle ID.
// The handle ID can be passed to C code as user_data for callbacks.
func (r *Registry[T]) Register(obj T) uint64 {
	id := r.nextID.Add(1)
	r.handles.Store(id, obj)
	return id
}

// Get retrieves an object by its handle ID.
// Returns the object and true if found, zero value and false otherwise.
// This is lock-free in the common case for optimal callback performance.
func (r *Registry[T]) Get(id uint64) (T, bool) {
	val, ok := r.handles.Load(id)
	if !ok {
		var zero T
		return zero, false
	}
	return val.(T), true
}

// Unregister removes an object from the registry by its handle ID.
// This should be called when the C handle is destroyed to prevent memory leaks.
func (r *Registry[T]) Unregister(id uint64) {
	r.handles.Delete(id)
}

// Count returns the number of registered objects.
func (r *Registry[T]) Count() int {
	count := 0
	r.handles.Range(func(_, _ any) bool {
		count++
		return true
	})
	return count
}

// Clear removes all objects from the registry.
func (r *Registry[T]) Clear() {
	r.handles.Range(func(key, _ any) bool {
		r.handles.Delete(key)
		return true
	})
}

// ForEach calls fn for each registered object.
// The iteration stops if fn returns false.
func (r *Registry[T]) ForEach(fn func(id uint64, obj T) bool) {
	r.handles.Range(func(key, val any) bool {
		return fn(key.(uint64), val.(T))
	})
}
