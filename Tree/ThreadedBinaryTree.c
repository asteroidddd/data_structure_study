#include <stdio.h>

typedef struct ThreadedTreeNode {
    int data;
    struct ThreadedTreeNode *left;
    struct ThreadedTreeNode *right;
    int leftThread;
    int rightThread;
} ThreadedTreeNode;

void inorder(ThreadedTreeNode* root) {
    ThreadedTreeNode* current = root;
    while (current->leftThread == 0) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->rightThread == 1) {
            current = current->right;
        } else {
            current = current->right;
            while (current != NULL && current->leftThread == 0) {
                current = current->left;
            }
        }
    }
}