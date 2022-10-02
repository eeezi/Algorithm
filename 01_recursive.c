#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double cnt = 0;

double fib_recursive(int n) {
    cnt++;

    if (n <= 1)
        return n;
    else
        return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    clock_t start, stop;
    double duration;

    printf("재귀호출을 이용한 피보나치 수\n\n");

    for (int i = 10; i <= 50; i += 10) {
        start = clock();
        double num = fib_recursive(i);
        printf("%d번째 피보나치 수: %.0lf\n", i, num);

        stop = clock();
        duration = (long double)(stop - start) / CLOCKS_PER_SEC;
        printf("수행시간: %f초\n", duration);
        printf("함수 실행 횟수: %.0lf\n\n", cnt);
    }
}
