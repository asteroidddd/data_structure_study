#include <stdio.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Deque;

void init_deque(Deque* d) {
    d->front = d->rear = 0;
}

int is_empty(Deque* d) {
    return (d->front == d->rear);
}

int is_full(Deque* d) {
    return ((d->rear + 1) % MAX_QUEUE_SIZE == d->front);
}

void add_front(Deque* d, element item) {
    if (is_full(d)) {
        printf("Deque is full\n");
        return;
    } else {
        d->data[d->front] = item;
        d->front = (d->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
}

void add_rear(Deque* d, element item) {
    if (is_full(d)) {
        printf("Deque is full\n");
        return;
    } else {
        d->rear = (d->rear + 1) % MAX_QUEUE_SIZE;
        d->data[d->rear] = item;
    }
}

element delete_front(Deque* d) {
    if (is_empty(d)) {
        printf("Deque is empty\n");
        return -1;
    } else {
        d->front = (d->front + 1) % MAX_QUEUE_SIZE;
        return d->data[d->front];
    }
}

element delete_rear(Deque* d) {
    if (is_empty(d)) {
        printf("Deque is empty\n");
        return -1;
    } else {
        d->rear = (d->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        return d->data[d->rear];
    }
}

element front(Deque* d) {
    if (is_empty(d)) {
        printf("Deque is empty\n");
        return -1;
    } else {
        return d->data[(d->front + 1) % MAX_QUEUE_SIZE];
    }
}

element rear(Deque* d) {
    if (is_empty(d)) {
        printf("Deque is empty\n");
        return -1;
    } else {
        return d->data[(d->rear - 1) % MAX_QUEUE_SIZE];
    }
}

int size(Deque* d) {
    return (d->rear - d->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void display(Deque* d) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i > d->front && i <= d->rear) {
            printf("%d\t|", d->data[i]);
        } else if (d->front > d->rear) {
            if (i > d->front || i <= d->rear) {
                printf("%d\t|", d->data[i]);
            } else {
                printf("\t|");
            }
        } else {
            printf("\t|");
        }
    }
    printf("\n");
}