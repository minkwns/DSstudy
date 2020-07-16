#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
protected:
    Node* mFront;
    Node* mRear;
    int mSize;
public:
    Queue(){
        mFront = nullptr;
        mRear = nullptr;
        mSize = 0;
    }
    ~Queue(){
        Node* temp;
        while(mFront != nullptr){
            temp = mFront;
            mFront = mFront->next;
            delete temp;
        }
        mRear = nullptr;
    }
    
    bool IsEmpty(){
        return mFront == nullptr;
    }
    
    bool IsFull(){
        Node* loc;
        try{
            loc = new Node;
            delete loc;
            return false;
        }
        catch(bad_alloc exception){
            return true;
        }
    }
    
    void Enque(int item){
        if(!IsFull()){
            mSize++;
            Node* newData = new Node;
            newData->data = item;
            newData->next = nullptr;
            
            if(mRear == nullptr){
                mFront = newData;
            }
            else
                mRear->next = newData;
            mRear = newData;
        }
    }
    void Deque(int& data){
        if(!IsEmpty()){
            mSize--;
            Node* temp;
            temp = mFront;
            data = mFront->data;
            mFront = mFront->next;
            
            if(mFront == nullptr)
                mRear = nullptr;
            delete temp;
            
        }
    }
    int length()const{
        return mSize;
    }
    
    void print()const{
        Node* travel = mFront;
        while(1){
            if(travel == mRear->next){
                cout<<'\n';
                return;
            }
            cout<<travel->data<<' ';
            travel = travel->next;
        }
    }
    
};
