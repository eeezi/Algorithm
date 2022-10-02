#include <stdio.h>

void quick_sort(int data[], int low, int high){
    int L = low, H = high;
    int tmp;
    int pivot = data[(low + high) / 2];
    printf("------------------------\n");
    printf("L: %d, pivot: %d, H: %d\n", L, (low+high)/2, H);

    while (L <= H) {
        while (data[L] < pivot) L++;
        while (data[H] > pivot) H--;
        if(L <= H){
            tmp = data[L];
            data[L] = data[H];
            data[H] = tmp;
            L++;
            H--;

            for(int i=0; i<8; i++) printf("%d ",data[i]);
            printf("\n");
        }
    }
    
    if (L < high) quick_sort(data, L, high);
    if (low < H) quick_sort(data, low, H);
}

int main(){
    int i;
    int data[8] = {15, 22, 13, 27, 12, 10, 20, 25};
    printf("정렬 전:\n");
    for(i=0; i<8; i++) printf("%d ", data[i]);
    printf("\n");

    quick_sort(data, 0, 7);

    printf("------------------------\n");
    printf("정렬 후:\n");
    for(i=0; i<8; i++) printf("%d ", data[i]);
    printf("\n");

    return 0;
}