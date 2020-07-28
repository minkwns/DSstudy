#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

typedef struct s_node {
    Data data;
    struct s_node *next;
} StackNode;

StackNode* top;

void push(Data d) {
    StackNode* ins = (StackNode *)malloc(sizeof(StackNode));   // 삽입할 노드 메모리 할당
    ins->data = d;
    ins->next = top;
    top = ins;
}

Data pop() {
    Data d;
    StackNode* del = top;   // LIFO이므로 top에 있는 원소가 삭제

    if(top == NULL) {
        return 0;
    }

    else {
        d = del->data;
        top = del->next;
        free(del);
        return d;
    }
}

void printStack() {
    StackNode* p = top;

    printf("\n STACK[ ");
    while(p) {
        printf("%d ", p->data);
        p = p -> next;
    }
    printf("]");
}

void main() 
{
    Data data;
    top = NULL;

    printStack();

    push(1);    printStack();
    push(2);    printStack();
    push(3);    printStack();

    data = pop();   
    printStack();
    data = pop();
    printStack();
    data = pop();
    printStack();
}