#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node //노드생성 초기화 
{
    Data data; 
    struct _node *next;
    struct _node *prev;
} node;

typedef struct _dbdlinkedlist //양방향리스트 초기화 
{
    node*head;
    node*tail;
    node*cur;
    int numOfdata;
} dbdlinkedlist;

void ListInit(List*plist); 
void LInsert(List*plist, Data data); //꼬리에 노드 추가 

int LFirst(List*plist, Data*pdata);
int LNext(List*plist, Data*pdata);

Data LRemove(List*plist);
int LCount(List*plist);

#endif
