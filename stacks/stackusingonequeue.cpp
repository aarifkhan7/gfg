#include<bits/stdc++.h>
using namespace std;

class s{
    queue<int> data;
    public:
    void push(int d){
        int n = data.size();
        data.push(d);
        for(int i = 0; i < n; i++){
            data.push(data.front());
            data.pop();
        }
    }
    void pop(){
        data.pop();
    }
    int top(){
        return data.front();
    }
};

int main()
{
    s s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    return 0;
}