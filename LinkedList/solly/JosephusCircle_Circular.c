/* Josephus Circle */
/* n명이 둥글게 앉아있을 때, 임의의 한명부터 순서를 세어 m번째 사람을 제외 */
/* 반복하여 마지막까지 살아남는 사람을 구하는 문제 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct s_node {
	int data;
	struct s_node* link;
} Node;

//원형 연결 리스트 생성
Node *newNode(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->link = temp;
	temp->data = data;
	return temp;
}

void getJosephusPosition(int n, int m)
{
	Node* head = newNode(1);   // 리스트 시작 노드 생성
	Node* prev = head;

	//n명의 사람으로 구성된 연결리스트를 만들기 위한 for문
	for (int i = 2; i <= n; i++) {
		prev->link = newNode(i);
		prev = prev->link;
	}
	prev->link = head;   // 마지막과 첫번재를 연결 (원형)

	Node *ptr1 = head, *ptr2 = head;   // 삭제를 하기 위해 ptr1,2 두개 만듦

	while (ptr1->link != ptr1) {   // 마지막 하나만 남기 전까지 while문 돌리기
		int count = 1;
		while (count != m)   // m번째 노드 찾기 위한
		{
			ptr2 = ptr1;
			ptr1 = ptr1->link;
			count++;
		}
		ptr2->link = ptr1->link;
		free(ptr1);   // m번째 노드 삭제
		ptr1 = ptr2->link;
	}

	printf("Last person left is %d\n", ptr1->data);
}

void main()
{
	int n, m;
	printf("n과 m을 차례로 입력하시오: ");
	scanf("%d %d", &n, &m);
	getJosephusPosition(n, m);
}