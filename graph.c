#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct graph *Graph;

Graph graph_create(int n);
void graph_destroy(Graph);
void graph_add_edge(Graph, int source, int sink);
int graph_vertex_count(Graph);
int graph_edge_count(Graph);

int graph_out_degree(Graph, int source);
int graph_has_edge(Graph, int source, int sink);
void graph_foreach(Graph g, int source, void (*f)(Graph g, int source, int sink, void *data), void *data);
int intcmp(const void *a, const void *b);

struct graph {
    int n;
    int m;

    struct successors {
        int d;
        int len;
        char is_sorted;
        int list[1];
    } *alist[1];
};

Graph graph_create(int n) {
    Graph g;
    int i;

    g = malloc(sizeof(struct graph) + sizeof(struct successors));
    assert(g);

    g->n = n;
    g->m = 0;

    for(i = 0; i < n; i++) {
        g->alist[i] = malloc(sizeof(struct successors));
        assert(g->alist[i]);

        g->alist[i]->d = 0;
        g->alist[i]->len = 1;
        g->alist[i]->is_sorted = 1;
    }

    return g;
}

void graph_add_edge(Graph g, int u, int v) {
    assert(u >= 0);
    assert(u < g->n);
    assert(v >= 0);
    assert(v < g->n);

    while(g->alist[u]->d >= g->alist[u]->len) {
        g->alist[u]->len *= 2;
        g->alist[u] = realloc(g->alist[u], sizeof(struct successors) + sizeof(int) * (g->alist[u]->len - 1));
    }

    g->alist[u]->list[g->alist[u]->d++] = v;
    g->alist[u]->is_sorted = 0;

    g->m++;
}

int graph_vertex_count(Graph g) {
    return g->n;
}

int graph_edge_count(Graph g) {
    return g->m;
}

int graph_out_degree(Graph g, int source) {
    assert(source >= 0);
    assert(source < g->n);

    return g->alist[source]->d;
}

#define BSEARCH_THRESHOLD 10

int graph_has_edge(Graph g, int source, int sink) {
    int i;

    assert(source >= 0);
    assert(source < g->n);
    assert(sink >= 0);
    assert(sink < g->n);

    if(graph_out_degree(g, source) >= BSEARCH_THRESHOLD) {
        if(!g->alist[source]->is_sorted) {
            qsort(g->alist[source]->list, g->alist[source]->d, sizeof(int), intcmp);
        }

        return bsearch(&sink,
                       g->alist[source]->list,
                       g->alist[source]->d,
                       sizeof(int),
                       intcmp) != 0;
    } else {
        for(i = 0; i < g->alist[source]->d; i++) {
            if(g->alist[source]->list[i] == sink) {
                return 1;
            }
        }
        return 0;
    }
}

void graph_foreach(Graph g, int source, void (*f)(Graph g, int source, int sink, void *data), void *data) {
    int i;

    assert(source >= 0);
    assert(source < g->n);

    for(i = 0; i < g->alist[source]->d; i++) {
        f(g, source, g->alist[source]->list[i], data);
    }
}

int intcmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    return 0;
}

int main() {
    int N;
    int M;

    Graph g;
    int i;
    int j;
    int ui;
    int vi;

    scanf("%d %d", &N, &M);

    g = graph_create(N+1);
    for(i = 0; i < M; i++) {
        scanf("%d %d", &ui, &vi);
        printf("%d %d", ui, vi);
        graph_add_edge(g, ui, vi);
    }

    return 0;
}
