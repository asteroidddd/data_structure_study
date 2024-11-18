#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define QUEUE_SIZE 100

typedef struct {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef int element;
typedef struct {
    element data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

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

void init_graph(Graph* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r<MAX_VERTICES; r++) {
        for (c = 0; c<MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(Graph* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "Number of graph vertices exceeded");
        return;
    }
    g->n++;
}

void insert_edge(Graph* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Graph vertex number error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void DFS_recursive(Graph* g, int v, int* visited) {
    int w;
    visited[v] = 1;
    printf("vertex %d -> ", v);
    for (w = 0; w < g->n; w++) {
        if (g->adj_mat[v][w] && !visited[w]) {
            DFS_recursive(g, w, visited);
        }
    }
}

void DFS_mat(Graph* g, int v) {
    int* visited = (int*)malloc(sizeof(int)*g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    DFS_recursive(g, v, visited);
    free(visited);
}

void BFS_mat(Graph* g, int v) {
    int w;
    Queue q;
    init_queue(&q);
    int* visited = (int*)malloc(sizeof(int)*g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    visited[v] = 1;
    printf("%d visited -> ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = 0; w<g->n; w++) {
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = 1;
                printf("%d visited -> ", w);
                enqueue(&q, w);
            }
        }
    }
    free(visited);
}