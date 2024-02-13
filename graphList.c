#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define TRUE 1
#define FALSE 0

int visited_DFS[MAX_VERTICES] = {0,};
int visited_BFS[MAX_VERTICES] = {0,};

typedef struct StackType {
	int stack[MAX_VERTICES];
	int top;
}StackType;

int init_stack(StackType* s) {
	s->top = -1;
}

int push(StackType* s, int item) {
	s->stack[++(s->top)] = item;
    printf("push %d\n", item);
}

int is_emptyStack(StackType* s) {
	return s->top == -1;
}

int pop(StackType* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

typedef int element;
typedef struct QueueType{
    int front;
    int rear;
    element data[MAX_VERTICES];
}QueueType;

void init_queue(QueueType *q){
    q->rear = -1;
    q->front = -1;
}

int is_emptyQueue(QueueType *q){
    return(q->front == q->rear);
}

int enqueue(QueueType *q, int item){
    q->data[++(q->rear)] = item;
    printf("enqueue %d\n", item);
}

element dequeue(QueueType *q){
    int item = q->data[++(q->front)];
    return item;
}

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n;
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g){
    int v;
    g->n = 0;
    for(v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

//인접리스트 vertex 삽입
void insert_vertex(GraphType* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

//인접리스트 edge 삽입
void insert_edge(GraphType* g, int u, int v){
    GraphNode *node, *q;
    if(u >= g->n || v >= g->n){
        fprintf(stderr,"그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    if(g->adj_list[u] == NULL){
        node->vertex =v;
        node->link = g->adj_list[u];
        g->adj_list[u] = node;
    }
    else{
        node->vertex = v;
        q = g->adj_list[u];
        while(q->link != NULL)
            q = q->link;
        q->link = node;
    }
}

//인접리스트 출력함수
int print_adj_list(GraphType* g){
    GraphNode *p;
    printf("\n-------인접리스트 출력-------\n");
    for(int i=0; i<g->n; i++){
        GraphNode* p = g->adj_list[i];
        printf("vertex %d: ", i);
        while(p != NULL){
            printf("%d -> ", p->vertex);
            p = p->link;
        }
        printf("NULL\n");
    }
}

int DFS(GraphType* g, int v, StackType* s){
    GraphNode *w;
    int tmp;

    visited_DFS[v] = TRUE;
    printf("* vertex %d 방문\n", v);

    for(w=g->adj_list[v]; w; w=w->link){
        if(!visited_DFS[w->vertex]){
            visited_DFS[w->vertex] = TRUE;
            push(s, w->vertex);
        }
    }
    tmp = pop(s);
    printf("-> pop%d\n\n", tmp);
    if(!is_emptyStack(s))
        DFS(g, tmp, s);
    else printf("* vertex %d 방문\n", tmp);
}

int BFS(GraphType* g, int v, QueueType* q){
    GraphNode *w;
    int tmp;

    printf("* vertex %d 방문\n", v);
    visited_BFS[v] = TRUE;

    for(w=g->adj_list[v]; w; w=w->link){
        if(!visited_BFS[w->vertex]){
            visited_BFS[w->vertex] = TRUE;
            enqueue(q, w->vertex);
        }
    }
    tmp = dequeue(q);
    printf("-> dequeue %d\n\n", tmp);
    if(!is_emptyQueue(q))
        BFS(g, tmp, q);
    else printf("* vertex %d 방문\n", tmp);
}

int main(){
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    StackType* s = (StackType*)malloc(sizeof(StackType));
    init_stack(s);
    QueueType* q = (QueueType*)malloc(sizeof(QueueType));
    init_queue(q);

    for(int i=0; i<6; i++)
        insert_vertex(g, i);

    insert_edge(g,0,1);
    insert_edge(g,1,0);
    insert_edge(g,0,2);
    insert_edge(g,2,0);
    insert_edge(g,0,4);
    insert_edge(g,4,0);
    insert_edge(g,1,2);
    insert_edge(g,2,1);
    insert_edge(g,1,3);
    insert_edge(g,3,1);
    insert_edge(g,2,4);
    insert_edge(g,4,2);
    insert_edge(g,3,4);
    insert_edge(g,4,3);
    insert_edge(g,3,5);
    insert_edge(g,5,3);
    insert_edge(g,4,5);
    insert_edge(g,5,4);

    print_adj_list(g);
    printf("\n<-------깊이우선탐색(DFS)------->\n");
    DFS(g, 0, s);
    printf("\n<-------너비우선탐색(BFS)------->\n");
    BFS(g, 0, q);

    free(g);
}