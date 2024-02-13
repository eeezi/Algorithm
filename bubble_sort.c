#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 8
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))


int bubble_sort(int list[]){
    int i, j, tmp;
    printf("------정렬시작------\n");
    for(i=0; i<MAX_SIZE; i++){
        for(j=0; j<MAX_SIZE-i-1; j++){
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], tmp);
        }
        printf("i = %d: ", i);
        for(int k=0; k<MAX_SIZE; k++)
            printf("%d ",list[k]);
        printf("\n");
    }
    printf("\n------정렬완료------\n");
    for(i=0; i<MAX_SIZE; i++)
        printf("%d ",list[i]);
}

int main(){
    int list[MAX_SIZE];

    srand(time(NULL));
    for(int i=0; i<MAX_SIZE; i++)
        list[i] = rand() % 100;
    
    printf("-----초기값------\n");
    for(int j=0; j<MAX_SIZE; j++)
        printf("%d ",list[j]);
    printf("\n\n");

    bubble_sort(list);
}