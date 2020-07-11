/* Doubly Linked List */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
     int data;
     struct Node *prev;
     struct Node *next;
} node;

node *head, *tail;


void initNode(){
  head = (node*)malloc(sizeof(node));
  tail = (node*)malloc(sizeof(node));

  head->next = tail;
  head->prev = NULL;
  tail->prev = head;
  tail->next = tail;
  
}

void insertNode(int data){
  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  newNode->data = data;

  newNode->next = head->next;
  newNode->prev = head;
  head->next->prev = newNode;
  head->next = newNode;
  
}


void deleteNode(int value){
  node *cur;
  cur = head;

  while(cur != tail){
    if(cur->next->data == value){
      
      cur->next = cur->next->next;
      cur->next->prev = cur;

      break;
    }
    cur = cur->next;
  }
  if(cur == tail){
    printf("There is no inputs here.\n\n");
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
    printf("===All of nodes are printed===\n");
  }
}

int main(void) {
  
  initNode();
  insertNode(3);
  insertNode(5);
  insertNode(6);
  insertNode(7);
  deleteNode(3);
  deleteNode(5);
  
  printNodes();
  return 0;
}
