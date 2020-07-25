#include <stdio.h> // singlylinkedlist로 stack 구현 . pop() push() display() , LIFO
#include <stdlib.h>

typedef struct Node{
    int data;
    Node *next;
} node;

node *head = (node*)malloc(sizeof(node)); // dummy pillar "head"
node *tail = (node*)malloc(sizeof(node)); // dummy pillar "tail"

void initNode(){
    head->data = NULL;
    tail->data = NULL;

    head->next = tail;
    tail->next = NULL;
}

void push(int value){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = head->next;
    head->next = newNode;

}

void pop(){
    node *cur;
    cur = head->next;
    head->next = cur->next;
    free(cur);
}

void display(){
    node *cur;
    int bin = 1;
    cur = head->next;
    printf("<");
    while(cur->data){ // NULL이 아닐 때까지 이동
        if(cur->next == tail) bin = 0; // 마지막엔 쉼표를 안찍어야 하므로 onoff

        printf("%d", cur->data);
        if(bin == 1){
            printf(", ");
        }
        cur = cur->next;
    }
    printf(">\n");
}
int main(void){
    initNode();
    push(3);
    display();
    push(4);
    display();
    push(5);
    push(6);
    push(7);
    push(8);
    pop();
    pop();

    display();
    return 0;
}
