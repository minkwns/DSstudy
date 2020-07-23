#include <stdio.h>  // 1158
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
} node;

node *head = NULL;


void initNode(int value){ // initialize and add
    node *newNode = (node*)malloc(sizeof(node));
    node *ptr = head;
    newNode->data = value;

    if(head == NULL){ // 아무것도 없을 때
        head = newNode;
        newNode->next = newNode;
    }
    else{
        while(ptr->next != NULL && ptr->next != head){ ptr = ptr->next; } // 계속 앞으로 진행
        ptr->next = newNode;
        newNode->next = head;
    }
}

void delAndDisplay(node *ptr){
    printf("%d", ptr->data);
    node *cur = head;

    if(head->data == ptr->data && head->next == head) {
        head = NULL;
        return;
    }
    while(cur->next->data != ptr->data) cur = cur->next;
    if(head->data == ptr->data) head = head->next;
    cur->next = ptr->next;
    free(ptr);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        initNode(i);
    }
    int idx = 0; // index
    int bin = 1; // 0, 1
    node* cur = head;
    printf("<");
    while (head != NULL) {
        idx++;
        if (idx%k == 0 && idx != 0) {
            if (bin != 1) {
                printf(", ");
            }
            else bin = 0;

            node* ptr = cur;
            cur = cur->next;
            delAndDisplay(ptr); // delete and display node ptr
        }
        else {
            cur = cur->next;
        }
    }
    printf(">");

    return 0;
}

