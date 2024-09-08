#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, element item);
element dequeue(Queue *q);
void display(Queue *q);

void init_queue(Queue *q) {
    q->front = q->rear = -1;
}

int is_empty(Queue *q) {
    return (q->front == q->rear);
}

int is_full(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue *q, element item) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[++(q->rear)] = item;
}

element dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[++(q->front)];
}

void display(Queue *q) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i <= q->front || i > q->rear)
            printf("\t|");
        else
            printf("%d\t|", q->data[i]);
    }
    printf("\n");
}