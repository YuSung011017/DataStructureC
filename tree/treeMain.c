#include<stdio.h>
#include<stdlib.h>

typedef struct tnode {
	int data;
	struct tnode* left, * right;
}tnode_t;
void preorder(tnode_t* root) { //������ȸ
	if (root != NULL) {
		printf("[%d] -> ", root->data); //��Ʈ �湮
		preorder(root->left); //��ȯ - ����Լ�, ���� ��带 ��Ʈ�� �����ؼ� �ٽ� ���� ��ȸ 
		preorder(root->right); //���� ����Ʈ�� ��� �湮 �� ������ ����Ʈ�� �湮
	}
}
void inorder(tnode_t* root) { //������ȸ
	if (root != NULL) {
		inorder(root->left); //���� ����Ʈ������ �湮
		printf("[%d] -> ", root->data); //��Ʈ �湮
		inorder(root->right); //������ ����Ʈ�� �湮
	}
} 
void postorder(tnode_t* root) { //������ȸ
	if (root != NULL) {
		postorder(root->left); //���� ����Ʈ������ �湮
		postorder(root->right); //������ ����Ʈ�� �湮
		printf("[%d] -> ", root->data); //�������� ��Ʈ �湮
	}
}

void main() {
	tnode_t n7 = { 7,NULL,NULL };
	tnode_t n6 = { 6, NULL, NULL };
	tnode_t n5 = { 4, NULL, NULL };
	tnode_t n4 = { 3, NULL, NULL };
	tnode_t n3 = { 5, &n6, &n7 };
	tnode_t n2 = { 2, &n4, &n5 };
	tnode_t n1 = { 1, &n2, &n3 };
	tnode_t* root = &n1;
	printf("���� ��ȸ");
	preorder(root);
	printf("\n ���� ��ȸ");
	inorder(root);
	printf("\n���� ��ȸ");
	postorder(root);
}
