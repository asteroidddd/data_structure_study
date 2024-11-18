#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init(Graph* g) {
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