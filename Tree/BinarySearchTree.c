#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* search_recursion(TreeNode* node, int key)
{
    if (node == NULL) {
        return NULL;
    }
    if (key == node->data) {
        return node;
    } else if (key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

TreeNode* search_iterative(TreeNode* node, int key) {
    while (node != NULL) {
        if (key == node->data) {
            return node;
        } else if (key < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return NULL;
}

TreeNode* new_node(int item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
    if (node == NULL) {
        return new_node(key);
    }
    if (key < node->data) {
        node->left = insert_node(node->left, key);
    } else if (key > node->data) {
        node->right = insert_node(node->right, key);
    }
    return node;
}

TreeNode* delete_node(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}