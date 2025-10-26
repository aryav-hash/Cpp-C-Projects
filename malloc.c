// Simple allocator that can allocate size of different chunks. 
// Also a garbage collector that can deallocate chunks.
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define HEAP_CAPACITY 640000

char heap[HEAP_CAPACITY] = {0};
size_t heap_size = 0;

void *heap_alloc(size_t size) {
    assert(heap_size + size <= HEAP_CAPACITY);
    void *result = heap + heap_size;
    heap_size += size;
    return result;
}

void heap_free(void *ptr) {
    assert(false && "Not implemented yet");
}

void heap_collect() {
    assert(false && "Not implemented yet");
}

int main() {
    char *root = heap_alloc(69);
    return 0;
}