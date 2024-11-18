#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph {
	int n;
	Node* adj_list[MAX_VERTICES];
} Graph;

void init(Graph* g) {
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