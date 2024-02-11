#pragma once

template<class T>
struct BumpArray {
    T* start_ptr;
    size_t capacity;

    T& operator[](size_t n) {
        assert(n < capacity);
        return start_ptr[n]; 
    }
};

template<class T>
struct BumpVec {
    T* start_ptr;
    size_t capacity;
    size_t size;

    void push_back(T val) {
        assert(size < capacity);
        start_ptr[size] = std::move(val);
        ++size;
    }

    void clear() {
        size = 0;
    }

    T& operator[](size_t n) {
        assert(n < size && n < capacity);
        return start_ptr[n]; 
    }
};

struct BumpAllocator {
    static BumpAllocator CreateWithCapacity(size_t capacity);
    void* Allocate(size_t capacity);
    void Reset();
    void Free();
    
    template<class T>
    BumpArray<T> AllocateArray(size_t count) {
        const size_t size = count * sizeof(T);
        T* arr_start_ptr = (T*) Allocate(size);
        return BumpArray<T> {
            arr_start_ptr,
            count
        };
    }

    template<class T>
    BumpVec<T> AllocateVec(size_t count) {
        const size_t size = count * sizeof(T);
        T* arr_start_ptr = (T*) Allocate(size);
        return BumpVec<T> {
            arr_start_ptr,
            count,
            0
        };
    }

    size_t capacity;
    size_t offset;
    void* start_ptr;
};