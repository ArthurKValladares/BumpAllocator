#pragma once

template<class T>
struct BumpArray {
    T* start_ptr;
    size_t capacity;

    T& operator[](size_t n) { 
        return start_ptr[n]; 
    }
};

struct BumpAllocator {
    static BumpAllocator CreateWithCapacity(size_t capacity);
    void* Allocate(size_t capacity);
    void Reset();

    template<class T>
    BumpArray<T> AllocateArray(size_t count) {
        const size_t size = count * sizeof(T);
        T* arr_start_ptr = (T*) Allocate(size);
        return BumpArray<T> {
            arr_start_ptr,
            count
        };
    }

    size_t capacity;
    size_t offset;
    void* start_ptr;
};