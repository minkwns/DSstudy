#include <iostream>

using namespace std;

class Node
{
public:
   Node* llink;
   Node* rlink;
   int data;
};
class Queue
{
private:
   Node* front;
   Node* rear;
public:
   Queue();
   void push(int);
   int pop();
   bool is_empty();
   void pt();
};
Queue::Queue()
{
   front = NULL;
   rear = NULL;
}
void Queue::push(int dt)
{
   Node* new_node = new Node;
   new_node->data = dt;
   if (is_empty())
   {
      new_node->rlink = NULL;
      new_node->llink = NULL;
      front = new_node;
      rear = new_node;
   }
   else
   {
      rear->rlink = new_node;
      new_node->llink = rear;
      new_node->rlink = NULL;
      rear = new_node;
   }
}
int Queue::pop()
{
   if (is_empty())
   {
      printf("Queue is empty\n");
      exit(-1);
   }
   else
   {
      int dt;
      Node* Old = front;
      dt = Old->data;
      if (front->rlink==NULL)
      {
         front = NULL;
         rear = NULL;
      }
      else
      {
         front = front->rlink;
         front->llink = NULL;
      }
      delete(Old);
      return dt;
   }
}
bool Queue::is_empty()
{
   if (rear == NULL)
      return -1;
   else
      return 0;
}
void Queue::pt()
{
   Node* a = front;
   while (a)
   {
      printf("%d\n", a->data);
      a = a->rlink;
   }
}
int main(void)
{
   Queue my;
   my.push(1);
   my.push(2);
   my.pop();
   my.pop();
   my.pt();
}
