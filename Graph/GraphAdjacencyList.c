#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define QUEUE_SIZE 100

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph {
	int n;
	Node* adj_list[MAX_VERTICES];
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
	g->n = 0;
	for (int v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
    }
}

void insert_vertex(Graph* g, int v) {
    if (g->n + 1 > MAX_VERTICES) {
        fprintf(stderr, "Number of graph vertices exceeded\n");
        return;
    }
    g->n++;
}

void insert_edge(Graph* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Graph vertex number error\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = g->adj_list[start];
    g->adj_list[start] = newNode;
    // 무방향 그래프라면 반대 방향도 추가
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = start;
    newNode->next = g->adj_list[end];
    g->adj_list[end] = newNode;
}

void DFS_recursive(Graph* g, int v, int* visited) {
    Node* w;
    visited[v] = 1;
    printf("vertex %d -> ", v);
    for (w = g->adj_list[v]; w; w = w->next) {
        if (!visited[w->vertex]) {
            DFS_recursive(g, w->vertex, visited);
        }
    }
}

void DFS_list(Graph* g, int v) {
    int* visited = (int*)malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    DFS_recursive(g, v, visited);
    free(visited);
}

void BFS_list(Graph* g, int v) {
    Node* w;
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
        for (w = g->adj_list[v]; w; w = w->next) {
            if (!visited[w->vertex]) {
                visited[w->vertex] = 1;
                printf("%d visited -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
    free(visited);
}