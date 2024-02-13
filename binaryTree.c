#include <stdio.h>

typedef struct TreeNode{
    char data;
    struct TreeNode *left, *right;
}TreeNode;

add_count = 0;

void inorder(TreeNode* node) {
        if(node){
            inorder(node->left);
            printf("%c", node->data);
            inorder(node->right);
        }
}

void inorder_add(TreeNode* node){ 
    printf("inoder 호출 횟수 %d회\n", ++add_count); 
    if (node != NULL) {
        printf("node->left(%d)\n", node->left);
        inorder_add(node->left);
        printf("node의 주소 = %d, 값 = %c\n", node, node->data);
        printf("node->right(%d)\n", node->right);
        inorder_add(node->right);
        printf("\n");

    }
}

int main(void){
    TreeNode n1={'A', NULL, NULL};
    TreeNode n2={'B', NULL, NULL};
    TreeNode n3={'+', &n1, &n2};
    TreeNode n4={'C', NULL, NULL};
    TreeNode n5={'D', NULL, NULL};
    TreeNode n6={'*', &n4, &n5};
    TreeNode n7={'-', &n3, &n6};
    TreeNode n8={'E', NULL, NULL};
    TreeNode n9={'F', NULL, NULL};
    TreeNode n10={'*', &n8, &n9};
    TreeNode n11={'+', &n7, &n10};
    TreeNode *root = &n11;

    printf("트리 주소 출력\n");
    inorder_add(root);
    printf("\n수식 출력: ");
    inorder(root);
    printf("\n");
    return 0;
}