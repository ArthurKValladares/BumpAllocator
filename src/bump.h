#pragma once

#include <stdio>

struct BumpAllocator {
    static BumpAllocator CreateWithSize(std::size_t size);
    void* Allocate(std::size_t size);
    void Reset();

    std::size_t size;
    std::size_t offset;
    void* start_ptr;
};