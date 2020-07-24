#include <stdio.h> //1406  
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
} node;

node *head, *tail, *cur;

void initNode() {
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));

    head->prev = head;
    head->next = tail;
    head->data = 'H';

    tail->prev = head;
    tail->next = tail;
    tail->data = 'T';

    cur = tail; // cur를 tail로 보냄
}

void left()
{
    if(cur->prev == head) return;

    cur = cur->prev;
}

void right()
{
    if(cur == tail) return;

    cur = cur->next;
}

void insertNode(char c)
{
    node *n = (node *)malloc(sizeof(node));
    n->prev = cur->prev;
    n->next = cur;
    n->data = c;

    cur->prev->next = n;
    cur->prev = n;
}

void deleteNode()
{
    if(cur->prev == head) return;

    node *n = cur->prev;
    n->prev->next = cur;
    cur->prev = n->prev;
    free(n);
}

void printList()
{
    node *n = head;
    while(1)
    {
        n = n->next;
        if(n == tail) break;
        printf("%c", n->data);
    }
    printf("\n");
}

char str[100001];

int count;
int main(void)
{

    scanf("%s", str);
    initNode();
    for(int i = 0; i < strlen(str); i++)
    {
        insertNode(str[i]);
    }

    scanf("%d", &count);
    char ch;
    while(count--)
    {
        scanf("%c", &ch);
        if(ch == 'L')
        {
            left();
        }
        else if(ch == 'D')
        {
            right();
        }
        else if(ch == 'B')
        {
            deleteNode();
        }
        else if(ch == 'P')
        {
            scanf("%c", &ch);
            insertNode(ch);
        }
    }
    printList();

    return 0;
}
