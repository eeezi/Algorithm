#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

int insert(ListNode** head, ListNode* new_node) {
	if (*head == NULL) {
		new_node->link = NULL;
		*head = new_node;
	}
	else {
		new_node->link = NULL;
		ListNode* p = *head;
		while (p->link != NULL)
			p = p->link;
		p->link = new_node;
	}
}

ListNode* create_node(element data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
    printf("   데이터 주소 : %d\n", &new_node->data);
    printf("     노드 주소 : %d\n\n", &new_node->link);
    return new_node;
}

int get_sum(ListNode* head) {
	int sum = 0;
	ListNode* p = head;
	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}

int main(void) {
  ListNode* list = NULL;
	int n, t;
	printf("노드의 개수 : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf("%d", &t);
		insert(&list, create_node(t));
	}
	printf("연결리스트의 합 : %d\n", get_sum(list));
}