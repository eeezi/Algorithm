#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int *col;

void printQueens(){
    int i;
    for(i = 1; i <= n; i++)
        printf("%d행 %d열에 퀸이 있음\n", i, col[i]);
    exit(1);
}

int promising(int i){
    int k = 1;
    while (k < i){
        if(col[i] == col[k] || abs(col[i]) - col[k] == abs(i - k))
            return 0;
        k++;
    }
    return 1; 
}

void queens(int i){
    int j;
    if(promising(i)){
        if(i == n){
            printQueens();
            return;
        }
        else{
            for(j = 1; j <= n; j++){
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}

int main(){
    printf("보드판의 크기 입력: ");
    scanf("%d", &n);
    col = (int*)malloc(sizeof(int)*(n+1));
    queens(0);
    printf("해결방법 없음");

    return 0;
}