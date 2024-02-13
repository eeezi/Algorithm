#include<stdio.h>

#define max_size 100

typedef struct Stack {
	int stack[max_size];
	int top;
}Stack;

int Stack_init(Stack* s) {
	s->top = -1;
    printf("top의 메모리 주소:   %d\n", &s->top);
    printf("stack의 메모리 주소: %d\n\n", &s->stack);
}

int Stack_push(Stack* s, int item) {
	s->stack[++(s->top)] = item;
    //printf("push: top의 값: %d\n", s->top);
}

int is_empty(Stack* s) {
	return s->top == -1;
}

int Stack_pop(Stack* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	int n, temp;
	Stack s;
	Stack_init(&s);

	printf("정수 배열의 크기 : ");
	scanf("%d", &n);
	printf("정수를 입력하시오 : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		Stack_push(&s, temp);
	}
	printf("반전된 정수 배열 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Stack_pop(&s));
	}
	return 0;
}