#pragma once

struct BumpAllocator {
    static BumpAllocator CreateWithSize(size_t size);
    void* Allocate(size_t size);
    void Reset();

    size_t size;
    size_t offset;
    void* start_ptr;
};