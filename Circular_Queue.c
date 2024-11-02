#include <stdio.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

int is_empty(Queue* q) {
    return (q->front == q->rear);
}

int is_full(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue* q, element item) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

element front(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    }
}

element rear(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->data[q->rear];
    }
}

int size(Queue* q) {
    return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void display(Queue* q) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i > q->front && i <= q->rear) {
            printf("%d\t|", q->data[i]);
        } else if (q->front > q->rear) {
            if (i > q->front || i <= q->rear) {
                printf("%d\t|", q->data[i]);
            } else {
                printf("\t|");
            }
        } else {
            printf("\t|");
        }
    }
    printf("\n");
}