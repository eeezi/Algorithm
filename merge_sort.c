#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 8
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  if(i>mid)
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];

  else
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];

  for(l=left; l<=right; l++)
    list[l] = sorted[l];
    
    for(int m=0; m<=right; m++)
        printf("%d ", list[m]);
    printf("\n");
}

int merge_sort(int list[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
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

    printf("-----정렬시작-----\n");
    merge_sort(list, 0, MAX_SIZE-1);

    printf("\n-----정렬완료-----\n");
    for(int i=0; i<MAX_SIZE; i++)
        printf("%d ",sorted[i]);
}