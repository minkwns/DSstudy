#include <stdio.h>
#include "dbdlinkedlist.h"
#include "dbdlinkedlist.c"

int main()
   {

    List list;
    int data;
    ListInit(&list);

    //10개의 데이터 저장하기 
    LInsert(&list,1);
    LInsert(&list,2);
    LInsert(&list,3);
    LInsert(&list,4);
    LInsert(&list,5);
    LInsert(&list,6);
    LInsert(&list,7);
    LInsert(&list,8);
    LInsert(&list,9);
    LInsert(&list,10); 

    //저장된 데이터 조회 
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
        printf("%d ", data);

        puts("");
    }

    //3의 배수인 경우 모두 삭제  
    if(LFirst(&list, &data))
    {
        if(data %3 == 0)
        LRemove(&list);

        while(LNext(&list, &data))
        {
            if(data %3 ==0)
            LRemove(&list);
        }
    }

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
        printf("%d ", data);
        puts("");
    }
}

