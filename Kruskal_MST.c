#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_VERTICES 50
#define INF 999

int parent[MAX_VERTICES];

void set_init(int n){
    for(int i=0; i<n; i++)
        parent[i] = -1;
}

int set_find(int curr){
    if(parent[curr] == -1)
        return curr;
    while (parent[curr] == -1)
        curr = parent[curr];
    return curr;
    
}

void set_union(int a, int b){
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
        parent[root1] = root2;
}

struct Edge{
    int start, end, weight;
};

typedef struct GraphType{
    int n;
    struct Edge edges[2*MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g){
    g->n = 0;
    for(int i=0; i<2*MAX_VERTICES; i++){
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType* g, int start, int end, int w){
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

void kruskal(GraphType* g){
    int edge_accpted = 0;
    int uset, vset;
    struct Edge e;

    set_init(g->n);

    printf("Kruskal MST Algorithm\n");
    int i = 0;
    while (edge_accpted < (g->n -1)){
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);
        if(uset != vset){
            printf("choose: edge(%d, %d) %d", e.start, e.end, e.weight);
            edge_accpted++;
            set_union(uset, vset);
            for(int j=0; j<=6; j++)
                printf(" [%d] %2d ", j, parent[j]);
            printf("\n");
        }
        i++;
    }
    
}

int main(void){
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 1, 2, 7);
    insert_edge(g, 2, 3, 9);
    insert_edge(g, 0, 1, 14);
    insert_edge(g, 6, 0, 20);
    insert_edge(g, 2, 6, 25);
    insert_edge(g, 3, 6, 28);
    insert_edge(g, 5, 6, 32);
    insert_edge(g, 3, 4, 36);
    insert_edge(g, 4, 5, 40);
    insert_edge(g, 5, 0, 41);
    

    kruskal(g);
    free(g);
    return 0;
}