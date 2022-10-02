#include <stdio.h>
#define INF 99999

typedef struct knapsack
{
    int w, v;
}knapsack;

knapsack ks[101];

int ddp(int now, int weight);
int maximum(int x, int y);

int dp[101][100001] = {0};
int n,k;

int main(){
    int i;
    printf("전체 상품의 갯수, 담을 수 있는 최대 상품 무게 입력");
    scanf("%d %d", &n,&k);
    for(i=0; i<n; i++)
        scanf("%d %d", &ks[i].w, &ks[i].v);
    printf("%d", ddp(0,0));
}

int maximum(int x, int y){
    return x > y ? x : y;
}

int ddp(int now, int weight){
    int tmp1, tmp2, ans;
    if(weight > k)
        return (-1) * INF;
    if(now == n)
        return 0;
    if(dp[now][weight] != 0)
        return dp[now+1][weight];
    
    tmp1 = ks[now].v + ddp(now+1, weight+ks[now].w);
    tmp2 = ddp(now+1, weight);

    ans = maximum(tmp1, tmp2);
    dp[now][weight] = ans;

    return ans;
}