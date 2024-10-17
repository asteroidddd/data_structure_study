#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element data;
    Node* link;
} Node;

typedef struct {
    Node* head;
    int length;
} LinkedList;

void init(LinkedList* L) {
    L->head = NULL;
    L->length = 0;
}

int is_empty(LinkedList* L) {
    return L->length == 0;
}

void insert(LinkedList* L, int pos, element item) {
    if (pos < 0 || pos > L->length) {
        printf("Invalid location\n");
        return L;
    } 
    Node* p = (Node*)calloc(1, sizeof(Node));
    p->data = item;
    if (pos == 0) {
        p->link = L->head;
        L->head = p;
        
    } else {
        Node* pre = L->head;
        for (int i = 0; i < pos - 1; i++) {
            pre = pre->link;
        }
        p->link = pre->link;
        pre->link = p;
    }
    L->length++;
}

void insert_first(LinkedList* L, element item) {
    insert(L, 0, item);
}

void insert_last(LinkedList* L, element item) {
    insert(L, L->length, item);
}

void delete(LinkedList* L, int pos) {
    if (pos < 0 || pos > L->length) {
        printf("Invalid location\n");
        return L;
    }
    Node* removed;
    if (pos == 0) {
        removed = L->head;
        L->head = L->head->link;
    } else {
        Node* pre = L->head;
        for (int i = 0; i < pos - 1; i++) {
            pre = pre->link;
        }
        removed = pre->link;
        pre->link = removed->link;
    }
    free(removed);
    L->length--;
}

void delete_first(LinkedList* L) {
    delete(L, 0);
}

void delete_last(LinkedList* L) {
    delete(L, L->length - 1);
}

element get_entry(LinkedList* L, int pos) {
    if (pos < 0 || pos > L->length) {
        printf("Invalid location\n");
        return -1;
    }
    Node* current = L->head;
    for (int i = 0; i < pos; i++) {
        current = current->link;
    }
    return current->data;
}

int get_length(LinkedList* L) {
    return L->length;
}

void print_list(LinkedList* L) {
    Node* current = L->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}