#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node* link;
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
        return;
    }
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->data = item;
    if (L->head == NULL) {
        L->head = node;
        L->head->link = node;
    } else if (pos == 0) {
        node->link = L->head->link;
        L->head->link = node;
    } else if (pos == L->length) {
        node->link = L->head->link;
        L->head->link = node;
        L->head = node;
    } else {
        Node* pre = L->head->link;
        for (int i = 0; i < pos - 1; i++) {
            pre = pre->link;
        }
        node->link = pre->link;
        pre->link = node;
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
    if (pos < 0 || pos >= L->length) {
        printf("Invalid location\n");
        return;
    }
    Node* removed;
    if (L->length == 1) {
        removed = L->head;
        L->head = NULL;
    } else if (pos == 0) {
        removed = L->head->link;
        L->head->link = L->head->link->link;
    } else {
        Node* pre = L->head->link;
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
    if (pos < 0 || pos >= L->length) {
        printf("Invalid location\n");
        return -1;
    } else if (pos == L->length - 1) {
        return L->head->data;
    } else {
        Node* current = L->head->link;
        for (int i = 0; i < pos; i++) {
            current = current->link;
        }
        return current->data;
    }
}

int get_length(LinkedList* L) {
    return L->length;
}

void print_list(LinkedList* L) {
    if (L->head == NULL) {
        printf("NULL\n");
    } else {
        Node* current = L->head->link;
        do {
            printf("%d -> ", current->data);
            current = current->link;
        } while (current != L->head->link);
        printf("Head\n");
    }
}