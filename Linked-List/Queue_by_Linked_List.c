#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node *link;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void init(Queue* q) {
    q->front = q->rear = 0;
}

int is_empty(Queue* q) {
    return (q->front == NULL);
}

int is_full(Queue *q) {
    return 0;
}

void enqueue(Queue* q, element data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    if (is_empty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->link = node;
        q->rear = node;
    }
}

element dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* removed = q->front;
    element data = removed->data;
    q->front = q->front->link;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(removed);
    return data;
}

element front(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->front->data;
    }
}

element rear(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->rear->data;
    }
}

int size(Queue* q) {
    int sum = 0;
    for (Node* p = q->front; p != NULL; p = p->link) {
        sum += 1;
    }
    return sum;
}

void print_queue(Queue* q) {
    for (Node* p = q->front; p != NULL; p = p->link) {
        printf("%c -> ", p->data);
    }
    printf("NULL\n");
}