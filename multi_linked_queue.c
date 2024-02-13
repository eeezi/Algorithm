#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
    element data;
    struct QueueNode *link;
}QueueNode;

typedef struct{
    QueueNode *front, *rear;
}LinkedQueueType;

void init(LinkedQueueType *q, int i){
    q[i].rear = NULL;
    q[i].front = NULL;
    //printf("\n\n구조체변수 q의 주소= %d\n", &q, q[i], &(q[i].front), &(q[i].rear));
    printf("\n%d번째 큐\n", i);
    printf("front의 주소= %d, rear의 주소= %d\n", &(q[i].front), &(q[i].rear));
    printf("init q의 주소= %d\n", &q);
}

int is_emptyQueue(LinkedQueueType *q, int i){
    return(q[i].front == NULL);
}

int enqueue(LinkedQueueType *q, element data, int i){
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_emptyQueue(q, i)){
        q[i].front = temp;
        q[i].rear = temp;
    }
    else{
        q[i].rear->link = temp;
        q[i].rear = temp;
    }
}

element dequeue(LinkedQueueType *q, int i){
    QueueNode *temp = q[i].front;
    element data;
    if(is_emptyQueue(q, i)){
        printf("큐가 비었음");
        exit(1);
    }
    else{
        data = temp->data;
        q[i].front = temp->link;
        if(q[i].front == NULL)
            q[i].rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueueType *q, int i){
    QueueNode *p;
    for(p = q[i].front; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

int main(void){
    LinkedQueueType queue[3];

    for(int i=0; i<3; i++){
        init(&queue, i);
        enqueue(&queue, 1, i);print_queue(&queue, i);
        enqueue(&queue, 2, i);print_queue(&queue, i);
        enqueue(&queue, 3, i);print_queue(&queue, i);
        dequeue(&queue, i);print_queue(&queue, i);
        dequeue(&queue, i);print_queue(&queue, i);
        dequeue(&queue, i);print_queue(&queue, i);
    }

    return 0;
}