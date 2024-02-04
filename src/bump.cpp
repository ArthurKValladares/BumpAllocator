#include "bump.h"

#include <stdlib.h>

BumpAllocator BumpAllocator::CreateWithSize(size_t size) {
    void* start_ptr = malloc(size);
    return BumpAllocator {
        size,
        0,
        start_ptr
    };
}

void* BumpAllocator::Allocate(size_t size) {
    void* ptr_to_curr_head = (void*)(static_cast<char*>(start_ptr) + offset);
    offset += size;
    return ptr_to_curr_head;
}

void BumpAllocator::Reset() {
    offset = 0;
}
