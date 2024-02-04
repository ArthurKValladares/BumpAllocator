#pragma once

struct BumpAllocator {
    static BumpAllocator CreateWithSize(size_t size);
    void* Allocate(size_t size);
    void Reset();

    BumpArray AllocateArray(size_t capacity);

    size_t size;
    size_t offset;
    void* start_ptr;
};

struct BumpArray {
    void* start_ptr;
    size_t capacity;
};