#include <stdio.h>
#define MAX_STACK_SIZE 10000

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element top(Stack* s);
int size(Stack* s);

void init_stack(Stack* s)
{
    s->top = -1;
}

int is_empty(Stack* s)
{
    return (s->top == -1);
}

int is_full(Stack* s)
{
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(Stack* s, element item)
{
    if (is_full(s)) {
        printf("Stack is full\n");
    } else {
        s->data[++(s->top)] = item;
    }
}

element pop(Stack* s)
{
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->data[(s->top)--];
    }
}

element top(Stack* s)
{
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

int size(Stack* s)
{
    if (is_empty(s)) {
        return 0;
    } else {
        return s->top + 1;
    }
}