#include <stdio.h>
#define Vertex 5
#define Far 999

int W[Vertex][Vertex] = {
    {0, 3, Far, 2, 1},
    {9, 0, 7, 1, Far},
    {Far, Far, 0, 5, Far},
    {Far, Far, 3, 0, 8},
    {2, Far, Far, 3, 0}
};

int D[Vertex][Vertex];
int P[Vertex][Vertex];

void Floyd(){
    int i, j, k;
    for(i = 0; i < Vertex; i++){
        for(j = 0; j < Vertex; j++){
            P[i][j] = -1;
            D[i][j] = W[i][j];
        }
    }
    for(k=0; k < Vertex; k++){
        for(i = 0; i < Vertex; i++){
            for(j = 0; j <Vertex; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                    printf("D[%d][%d]�� ������ �ִܰŸ�: %d\n", i, j, D[i][j]);
                }
            }
        }
    }
    printf("--------------------------------\n");
    printf("�ʱ��� �迭 W\n");
    for(i = 0; i < Vertex; i++){
        for(j = 0; j < Vertex; j++)
            printf("%d ", W[i][j]);
        printf("\n");
    }
    printf("--------------------------------\n");
    printf("������ �迭 D\n");
    for(i = 0; i < Vertex; i++){
        for(j = 0; j < Vertex; j++)
            printf("%d ", D[i][j]);
        printf("\n");
    }
    printf("--------------------------------\n");
    printf("��� P\n");
    for(i = 0; i < Vertex; i++){
        for(j = 0; j < Vertex; j++)
            printf("%d ", P[i][j]);
        printf("\n");
    }
        
}

void Path(int a, int b){
    if(P[a][b] != -1){
        Path(a, P[a][b]);
        printf("%d ", P[a][b]);
        Path(P[a][b], b);
    }
}

int main(){
    Floyd();
    int a, b;
    printf("\n--------------------------------");
    printf("\n������� ������ �Է�(0 ~ %d): ", Vertex -1);
    scanf("%d %d", &a, &b);
    printf("�ִܰŸ�: %d\n", D[a][b]);
    printf("�ִܰ��: ");
    printf("%d ", a);
    Path(a,b);
    if(D[a][b] != 0)
        printf("%d", b);
    return 0;
}