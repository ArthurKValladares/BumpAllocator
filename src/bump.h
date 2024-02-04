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
    static BumpAllocator CreateWithSize(size_t size);
    void* Allocate(size_t size);
    void Reset();

    template<class T>
    BumpArray<T> AllocateArray(size_t count) {
        T* arr_start_ptr = (T*) Allocate(count * sizeof(T));
        return BumpArray<T> {
            arr_start_ptr,
            count
        };
    }

    size_t size;
    size_t offset;
    void* start_ptr;
};