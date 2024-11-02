#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node* llink;
    struct Node* rlink;
} Node;

typedef struct {
    Node* head;
    int length;
} LinkedList;

void init(LinkedList* L) {
    L->head = (Node*)calloc(1, sizeof(Node));
    L->head->llink = L->head;
    L->head->rlink = L->head;
    L->length = 0;
}

int is_empty(LinkedList* L) {
    return L->length == 0;
}

int get_length(LinkedList* L) {
    return L->length;
}

void insert(LinkedList* L, int pos, element item) {
    if (pos < 0 || pos > L->length) {
        printf("Invalid location\n");
        return;
    }
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->data = item;
    Node* pre;
    if (pos == 0) {
        node->rlink = L->head->rlink;
        node->llink = L->head;
        L->head->rlink->llink = node;
        L->head->rlink = node;
    } else if (pos <= L->length / 2) {
        pre = L->head->rlink;
        for (int i = 0; i < pos - 1; i++) {
            pre = pre->rlink;
        }
        node->rlink = pre->rlink;
        node->llink = pre;
        pre->rlink->llink = node;
        pre->rlink = node;
    } else {
        pre = L->head->llink;
        for (int i = L->length; i > pos; i--) {
            pre = pre->llink;
        }
        node->rlink = pre->rlink;
        node->llink = pre;
        pre->rlink->llink = node;
        pre->rlink = node;
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
        removed = L->head->llink;
        L->head->llink = L->head;
        L->head->rlink = L->head;
    } else if (pos > L->length / 2) {
        removed = L->head->llink;
        for (int i = 0; i < L->length - pos - 1; i++) {
            removed = removed->llink;
        }
        removed->llink->rlink = removed->rlink;
        removed->rlink->llink = removed->llink;
    } else {
        removed = L->head->rlink;
        for (int i = 0; i < pos; i++) {
            removed = removed->rlink;
        }
        removed->llink->rlink = removed->rlink;
        removed->rlink->llink = removed->llink;
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
    }
    Node* current;
    if (pos <= L->length / 2) {
        current = L->head->rlink;
        for (int i = 0; i < pos; i++) {
            current = current->rlink;
        }
    } else {
        current = L->head->llink;
        for (int i = L->length - 1; i > pos; i--) {
            current = current->llink;
        }
    }
    return current->data;
}

void print_list(LinkedList* L) {
    if (is_empty(L)) {
        printf("NULL\n");
    } else {
        Node* current = L->head->rlink;
        for (int i = 0; i < L->length; i++) {
            printf("%d -> ", current->data);
            current = current->rlink;
        }
        printf("First Node\n");
    }
}