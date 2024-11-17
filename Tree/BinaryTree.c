#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define QUEUE_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef TreeNode* element;

typedef struct {
    int top;
    element data[STACK_SIZE];
} Stack;

typedef struct {
    element data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_stack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, element p)
{
    if (s->top < STACK_SIZE - 1) {
        s->data[++s->top] = p;
    }
}

element pop(Stack* s)
{
    if (s->top < 0) {
        return NULL;
    }
    return s->data[s->top--];
}

void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, element item) {
    if ((q->rear + 1) % QUEUE_SIZE == q->front) {
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(Queue* q) {
    if (q->front == q->rear) {
        return NULL;
    }
    q->front = (q->front + 1) % QUEUE_SIZE;
    return q->data[q->front];
}

preorder_traversal(TreeNode* root) {
    if (root) {
        printf("%d", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

inorder_traversal(TreeNode *root) {
    if (root) {
        inorder_traversal(root->left);
        printf("%d", root->data);
        inorder_traversal(root->right);
    }
}

postorder_traversal(TreeNode *root) {
    if (root) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d", root->data);
    }
}

void inorder_traversal_iterative(TreeNode *root) {
    Stack s;
    init(&s);
    while (1) {
        for (; root; root = root->left) {
            push(&s, root);
        }
        push(&s, root);
        root = pop(&s);
        if (!root) {
            break;
        }
        printf("%d", root->data);
        root = root->right;
    }
}

void level_order_traversal(TreeNode* ptr) {
    Queue q;
    init_queue(&q);
    if (ptr == NULL) {
        return;
    }
    enqueue(&q, ptr);
    while (!is_empty(&q)) {
        ptr = dequeue(&q);
        printf("%d", ptr->data);
        if (ptr->left) {
            enqueue(&q, ptr->left);
        }
        if (ptr->right) {
            enqueue(&q, ptr->right);
        }
    }
}

int get_size(TreeNode* node) {
    int count = 0;
    if (node != NULL) {
        count = 1 + get_size(node->left) + get_size(node->right);
    }
    return count;
}

int get_height(TreeNode* node) {
    int height = 0;
    if (node != NULL) {
        height = 1 + max(get_height(node->left), get_height(node->right));
    }
    return height;
}

int get_leaf_count(TreeNode* node) {
    int count = 0;
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            return 1;
        } else {
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
        }
    }
    return count;
}