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

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType* g){
    int r, c;
    g->n = 0;
    for(r=0; r<MAX_VERTICES; r++){
        for(c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
    }
}

//인접행렬 vertex 삽입
void insert_vertex(GraphType* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

//인접행렬 edge 삽입
void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr,"그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

//인접행렬 출력함수
int print_adj_mat(GraphType* g){
    printf("\n-------인접행렬 출력-------\n");
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            printf("%d ",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

//DFS
void DFS(GraphType* g, int v, StackType* s){
    int tmp;

    printf("* vertex %d 방문\n", v);
    visited_DFS[v] = TRUE;
    
    for(int i=0; i<g->n; i++){
        if(g->adj_mat[v][i] && !visited_DFS[i]){
            visited_DFS[i] = TRUE;
            push(s, i);
        }
    }
    tmp = pop(s);
    printf("-> pop %d\n\n", tmp);
    if(!is_emptyStack(s))
        DFS(g, tmp, s);
    else printf("* vertex %d 방문\n", tmp);
}

//BFS
void BFS(GraphType* g, int v, QueueType* q){
    int tmp;

    printf("* vertex %d 방문\n", v);
    visited_BFS[v] = TRUE;

    for(int i=0; i<g->n; i++){
        if(g->adj_mat[v][i] && !visited_BFS[i]){
            visited_BFS[i] = TRUE;
            enqueue(q, i);
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
    insert_edge(g,0,2);
    insert_edge(g,0,4);
    insert_edge(g,1,2);
    insert_edge(g,1,3);
    insert_edge(g,2,4);
    insert_edge(g,3,4);
    insert_edge(g,3,5);
    insert_edge(g,4,5);

    print_adj_mat(g);
    printf("\n<-------깊이우선탐색(DFS)------->\n");
    DFS(g, 0, s);
    printf("\n<-------너비우선탐색(BFS)------->\n");
    BFS(g, 0, q);
    printf("\n");
    free(g);
    return 0;
}