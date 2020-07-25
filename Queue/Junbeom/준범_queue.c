#include <stdio.h> // singlylinkedlist로 queue 구현 . Enqueue(), Dequeue(), display() , FIFO
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

void Enqueue(int value){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = head->next;
    head->next = newNode;
}

void Dequeue(){
    node *cur, *deletePtr;
    cur = head;
    while(cur->next->next != tail) cur = cur->next;

    deletePtr = cur->next;
    cur->next = deletePtr->next;
    free(deletePtr);

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

int main(){
    initNode();

    Enqueue(3);
    Enqueue(4);
    Dequeue();
    display();
    Enqueue(5);
    Enqueue(6);
    Dequeue();
    Enqueue(7);


    display();
    return 0;
}
