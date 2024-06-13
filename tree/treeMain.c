#include<stdio.h>
#include<stdlib.h>

typedef struct tnode {
	int data;
	struct tnode* left, * right;
}tnode_t;
void preorder(tnode_t* root) { //전위순회
	if (root != NULL) {
		printf("[%d] -> ", root->data); //루트 방문
		preorder(root->left); //순환 - 재귀함수, 왼쪽 노드를 루트로 전달해서 다시 전위 순회 
		preorder(root->right); //왼쪽 서브트리 모두 방문 후 오른쪽 서브트리 방문
	}
}
void inorder(tnode_t* root) { //중위순회
	if (root != NULL) {
		inorder(root->left); //왼쪽 서브트리부터 방문
		printf("[%d] -> ", root->data); //루트 방문
		inorder(root->right); //오른쪽 서브트리 방문
	}
} 
void postorder(tnode_t* root) { //후위순회
	if (root != NULL) {
		postorder(root->left); //왼쪽 서브트리부터 방문
		postorder(root->right); //오른쪽 서브트리 방문
		printf("[%d] -> ", root->data); //마지막에 루트 방문
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
	printf("전위 순회");
	preorder(root);
	printf("\n 중위 순회");
	inorder(root);
	printf("\n전위 순회");
	postorder(root);
}
