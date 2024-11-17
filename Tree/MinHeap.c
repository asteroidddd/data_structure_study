#include <stdio.h>
#include <stdlib.h>
#define HEAP_SIZE 100

typedef struct {
    int key;
} element;

typedef struct {
    element heap[HEAP_SIZE];
    int heap_size;
} Heap;

Heap* create() {
    return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h) {
    h->heap_size = 0;
}

void insert_min_heap(Heap* h, element item) {
    int i = ++(h->heap_size);
    while ((i != 1) && (item.key < h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(Heap* h) {
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key) {
            child++;
        }
        if (temp.key < h->heap[child].key) {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}