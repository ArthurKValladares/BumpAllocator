#include "bump.h"

#include <stdlib.h>
#include <cassert>

BumpAllocator BumpAllocator::CreateWithCapacity(size_t capacity) {
    void* start_ptr = malloc(capacity);
    return BumpAllocator {
        capacity,
        0,
        start_ptr
    };
}

void* BumpAllocator::Allocate(size_t size) {
    assert(size < capacity - offset);
    void* ptr_to_curr_head = (void*)(static_cast<char*>(start_ptr) + offset);
    offset += size;
    return ptr_to_curr_head;
}

void BumpAllocator::Reset() {
    offset = 0;
}
