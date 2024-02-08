﻿# Bump Allocator

 Simple Bump Allocator. Bump allocation is a strategy that aims to increase performance by reducing the amount of transient allocations in a program. This is accomplished by creating an allocator that keeps track of a large chunck of memory and a pointer to the start of  the free memory in that chunk ahead of time. During program execution, whenever we need to allocate transient memory, we can simplify increment that internal pointer and return the user a "span" of the originally allocated chunk of memory.
