#include <stdio.h>
#include <malloc.h>

typedef char Data;

typedef struct q_node {
    Data data;
    struct q_node *next;
} QNode;

typedef struct {
    QNode *front, *rear;
} LinkedQueue;

LinkedQueue *createQueue() {
    LinkedQueue *Q;
    Q = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

void enQueue(LinkedQueue *Q, Data d) {
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    newnode->data = d;
    newnode->next = NULL;

    if(Q->front == NULL) {   
        Q->front = newnode;
        Q->rear = newnode;
    }

    else {
        Q->rear->next = newnode;
        Q->rear = newnode;
    }
}

Data deQueue(LinkedQueue *Q) {
    QNode *del = Q->front;   // FIFO
    Data d;

    if (Q->front == NULL)
        return 0;

    else {
        d = del->data;
        Q->front = Q->front->next;
        if(Q->front == NULL)   // 노드가 하나뿐이어서 삭제 후 공백이 되면
            Q->rear = NULL;
        free(del);
        return d;
    }
}

void printQ(LinkedQueue *Q) {
    QNode *temp = Q->front;
    printf("\nQueue[ ");
    while(temp) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("]");
}

void main()
{
    LinkedQueue* Q = createQueue();   // 연결 큐 생성

    Data data;

    enQueue(Q, 'A');    printQ(Q);
    enQueue(Q, 'B');    printQ(Q);
    enQueue(Q, 'C');    printQ(Q);

    data = deQueue(Q);  printQ(Q);
    data = deQueue(Q);  printQ(Q);
    data = deQueue(Q);  printQ(Q);
}