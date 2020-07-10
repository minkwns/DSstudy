#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *head, *tail;

void initNode(){
  head = (node*)malloc(sizeof(node));
  tail = (node*)malloc(sizeof(node));

  head->next = tail;
  tail->next = tail;
}

void insertNode(int data){
  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = head->next;
  head->next = newNode;
}

void deleteNode(int value){
  node *cur;
  cur = head;

  while(cur != tail){
    if(cur->next->data == value){
        cur->next = cur->next->next;
        free(cur->next);
        break;
    }
    cur = cur->next;
  }
  if(cur == tail){
    printf("input is not here.\n\n");
  }
}

void printNodes(){
  node *cur;
  cur = head->next;
  
  while(cur != tail){
    printf("Data is %d\n\n", cur->data);
    cur = cur->next;
  }
  if(cur == tail){
    printf("======All of nodes are printed======");
  }
}

int main(void) {
  
  initNode();
  insertNode(3);
  insertNode(5);
  insertNode(7);
  deleteNode(3);
  printNodes();

  return 0;
}

