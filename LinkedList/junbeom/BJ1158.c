#include <stdio.h>  // 1158
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
} node;

node *head = NULL;


void initNode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    node *ptr = head;
    newNode->data = value;

    if(head == NULL){ // 아무것도 없을
        head = newNode;
        newNode->next = newNode;

    }
    else{
        while(ptr->next != NULL && ptr->next != head){ ptr = ptr->next; }
        ptr->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(node *ptr){
    printf("%d", ptr->data);
    node *cur = head;

    if(head->data == ptr->data && head->next == head) {
        head = NULL;
        return;
    }
    while(cur->next->data != ptr->data) cur = cur->next;
    if(head->data == ptr->data) head = ptr->next;
    cur->next = ptr->next;
    free(ptr);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        initNode(i);
    }
    int check = 0;
    int once = 1;
    node* run = head;
    printf("<");
    while (head != NULL) {
        check++;
        if (check%k == 0 && check != 0) {
            if (once != 1) {
                printf(", ");
            }
            else once = 0;

            node* ptr = run;
            run = run->next;
            deleteNode(ptr);
        }
        else {
            run = run->next;
        }
    }
    printf(">");

    return 0;
}
