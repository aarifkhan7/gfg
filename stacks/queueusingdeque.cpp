#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    deque<int> data;
    void push(int x){
        data.push_back(x);
    }
    void pop(){
        data.pop_front();
    }
    int top(){
        return data.front();
    }
    int size(){
        return data.size();
    }
    bool empty(){
        return data.empty();
    }
    Queue(){

    }
    Queue(vector<int> data){
        for(int i : data){
            this->push(i);
        }
    }
};

int main()
{
    Queue q1({10,20,30,40,50});
    cout << q1.top() << endl;
    q1.pop();
    cout << q1.top() << endl;
    q1.pop();
    cout << q1.size() << endl;
    return 0;
}