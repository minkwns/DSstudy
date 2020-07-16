#include "10845.cpp"

int main(){
    myque q;
    int N; cin>>N;
    string cm; int x;
    
    while(N--){
        cin>>cm;
        if(cm == "push"){
            cin>>x;
            q.Enque(x);
        }
        else if(cm == "front"){
            if(q.IsEmpty()){
                cout<<-1<<endl;
                continue;
            }
            cout<<q.front()<<endl;
        }
        else if(cm == "back"){
            if(q.IsEmpty()){
                cout<<-1<<endl;
                continue;
            }
            cout<<q.back()<<endl;
        }
        else if(cm == "size")
            cout<<q.length()<<endl;
        
        else if(cm == "empty")
            cout<<q.IsEmpty()<<endl;
        
        else if(cm == "pop"){
            if(q.IsEmpty()){
                cout<<-1<<endl;
                continue;
            }
            int tmp;
            q.Deque(tmp);
            cout<<tmp<<endl;
        }
        
    }
}
