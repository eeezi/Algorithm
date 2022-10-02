#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double cnt = 0;

double fib_repeat(int n) {
    double* f = malloc(sizeof(double) * n);
    f[0] = 0;

    if (n > 0) {
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
            cnt++;
        }
        return f[n];
    }
}

int main() {
    clock_t start, stop;
    double duration;

    printf("반복적 방법을 이용한 피보나치 수\n\n");

    for (int i = 10; i <= 50; i += 10) {
        start = clock();
        double num = fib_repeat(i);
        printf("%d번째 피보나치 수: %.0lf\n", i, num);

        stop = clock();
        duration = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("수행시간: %lf초\n", duration);
        printf("함수 실행 횟수: %.0lf\n\n", cnt);
        cnt = 0;
    }
}
