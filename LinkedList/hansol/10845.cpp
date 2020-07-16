#include "Queue_LinkedList.cpp"

class myque:public Queue{
    
public:
    int front(){
        return mFront->data;
    }
    int back(){
        return mRear->data;
    }
};
