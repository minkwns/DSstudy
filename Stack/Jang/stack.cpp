#include <iostream>

using namespace std;

class Node
{
public:
   Node* up;
   Node* down;
   int data;
};
class Stack
{
private:
   Node* top;
   Node* bottom;
public:
   Stack();
   void push(int);
   void pop();
   bool is_empty();
   void pt();
};
Stack::Stack()
{
   top = NULL;
   bottom = NULL;
}
void Stack::push(int dt)
{
   Node* new_node = new Node;
   new_node->data = dt;
   if (is_empty())
   {
      new_node->up = NULL;
      new_node->down = NULL;
      top = new_node;
      bottom = new_node;
   }
   else
   {
      bottom->down = new_node;
      new_node->up = bottom;
      new_node->down = NULL;
      bottom = new_node;
   }
}
void Stack::pop()
{
   if (is_empty())
   {
      printf("Stack is empty\n");
      exit(-1);
   }
   else
   {
      Node* Old = top;
      if (top->down == NULL)
      {
         top = NULL;
         bottom = NULL;
      }
      else
      {
         top = top->down;
         top->up = NULL;
      }
      delete(Old);
   }
}
bool Stack::is_empty()
{
   if (top == NULL)
      return -1;
   else
      return 0;
}
void Stack::pt()
{
   Node* a=top;
   while (a)
   {
      printf("%d\n", a->data);
      a = a->down;
   }
}
int main(void)
{
   Stack my;
   my.push(2);
   my.push(1);
   my.pop();
   my.pt();
}