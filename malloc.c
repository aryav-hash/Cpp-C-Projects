// Simple allocator that can allocate size of different chunks. 
// Also a garbage collector that can deallocate chunks.
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024
#define HEAP_FREED_CAP 1024
typedef struct {
    void *start;
    size_t size;
} Heap_chunk;

char heap[HEAP_CAP] = {0};
Heap_chunk heap_alloced[HEAP_ALLOCED_CAP] = {0}; // This is sort of a metadata table.
size_t heap_size = 0;
size_t heap_alloced_size = 0;
Heap_chunk heap_freed[HEAP_FREED_CAP] = {0};

void *heap_alloc(size_t size) {
    if (size > 0) {
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
    else {
        return NULL;
    }
}

// Function 
void heap_dump_alloced_chunks(void) {
    printf("Allocated chunks (%zu):\n", heap_alloced_size);
    for (size_t i = 0; i < heap_alloced_size; i++) {
        printf(" start: %p, size: %zu\n", 
               heap_alloced[i].start, 
               heap_alloced[i].size);
    }
}

// TC O(alloced_size)
void heap_free(void *ptr) {

    for (size_t i = 0; i < heap_alloced_size; i++) {
        if (heap_alloced[i].start == ptr) {
            
        }
    }

}

void heap_collect() {
    assert(false && "Not implemented yet");
}

int main() {
    for (int i = 0; i < 100; i++) {
        void *p = heap_alloc(i);
        if (i%2 == 0) {
            heap_free(p); // try to do fragmentation.
        }
    }

    heap_dump_alloced_chunks();

    //heap_free(root);

    return 0;
}