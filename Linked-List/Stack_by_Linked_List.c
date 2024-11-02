#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node* link;
} Node;

typedef struct {
    Node* top;
} Stack;

void init(Stack* s) {
    s->top = NULL;
}

int is_empty(Stack* s) {
    return (s->top == NULL);
}

int is_full(Stack* s) {
    return 0;
}

void push(Stack* s, element item) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = item;
    node->link = s->top;
    s->top = node;
}

element pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        Node* removed = s->top;
        int data = removed->data;
        s->top = s->top->link;
        free(removed);
        return data;
    }
}

element top(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->top->data;
    }
}

int size(Stack* s) {
    if (is_empty(s)) {
        return 0;
    } else {
        int sum = 0;
        for (Node* p = s->top; p != NULL; p = p->link) {
            sum += 1;
        }
        return sum;
    }
}

void print_stack(Stack *s) {
    for (Node* p = s->top; p != NULL; p = p->link) {
        printf("%c -> ", p->data);
    }
    printf("NULL \n");
}