#include<stdio.h>

#define max_size 100

typedef struct Stack {
	char stack[max_size];
	int top;
}Stack;

void Stack_init(Stack* s) {
	s->top = -1;
    printf("top의 메모리 주소:   %d\n", &s->top);
    printf("stack의 메모리 주소: %d\n\n", &s->stack);
}

void Stack_push(Stack* s, char item) {
	s->stack[++(s->top)] = item;
	return;
}

int is_empty(Stack* s) {
	return s->top == -1;
}

char Stack_pop(Stack* s) {
	char t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	printf("문자열을 입력하시오 : ");
	char input[max_size];
	scanf("%s", input, sizeof(input));

	Stack s;
	Stack_init(&s);
	int i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z')
			Stack_push(&s, input[i]);
		else if ('A' <= input[i] && input[i] <= 'Z')
			Stack_push(&s, input[i] - ('A' - 'a')); 
		i++;
	}
	int flag = 1;
	i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z') {
			if (Stack_pop(&s) != input[i]) {
				flag = 0;
				break;
			}
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			if (Stack_pop(&s) != (input[i] - ('A' - 'a'))) {
				flag = 0;
				break;
			}
		}
		i++;
	}
	if (flag)
		printf("회문입니다.\n");
	else
		printf("회문이아닙니다.\n");
}