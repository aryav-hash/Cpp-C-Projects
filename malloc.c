// Simple allocator that can allocate size of different chunks. 
// Also a garbage collector that can deallocate chunks.
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024
typedef struct {
    void *start;
    size_t size;
} Heap_chunk;

char heap[HEAP_CAP] = {0};
Heap_chunk heap_alloced[HEAP_ALLOCED_CAP] = {0}; // This is sort of a metadata table.
size_t heap_size = 0;
size_t heap_alloced_size = 0;

void *heap_alloc(size_t size) {
    assert(heap_size + size <= HEAP_CAP);
    void *result = heap + heap_size;
    heap_size += size;

    const Heap_chunk chunk = {
        .start = result,
        .size = size,
    };
    
    assert(heap_alloced_size < HEAP_ALLOCED_CAP);
    heap_alloced[heap_alloced_size++] = chunk;

    return result;
}

void heap_free(void *ptr) {
    (void) ptr;
    assert(false && "Not implemented yet");
}

void heap_collect() {
    assert(false && "Not implemented yet");
}

int main() {
    char *root = heap_alloc(26);
    for (int i = 0; i < 26; i++) {
        root[i] = i + 'A';
    }

    heap_free(root);

    return 0;
}