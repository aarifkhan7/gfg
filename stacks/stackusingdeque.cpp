#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    deque<int> data;
    void push(int x){
        data.push_front(x);
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
    Stack(){

    }
    Stack(vector<int> data){
        for(int i : data){
            this->push(i);
        }
    }
};

int main()
{
    Stack s1({10,20,30,40,50});
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    return 0;
}