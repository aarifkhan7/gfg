#include<bits/stdc++.h>
using namespace std;

void sortedinsert(stack<int> * s, int tmp){
    stack<int> as;
    while(!s->empty() && tmp > s->top()){
        as.push(s->top()); s->pop();
    }
    s->push(tmp);
    while(!as.empty()){
        s->push(as.top()); as.pop();
    }
}

void sortstack(stack<int> * s){
    stack<int> ss;
    if(ss.empty()){
        ss.push(s->top());
        s->pop();
    }
    while(!s->empty()){
        sortedinsert(&ss, s->top());
        s->pop();
    }
    while(!ss.empty()){
        s->push(ss.top());
        ss.pop();
    }
}

int main()
{
    int n; cin >> n;
    stack<int> ms;
    stack<int> as;
    while(n--){
        int tmp; cin >> tmp;
        ms.push(tmp);
    }
    // Main Program
    sortstack(&ms);
    while(!ms.empty()){
        cout << ms.top() << ' '; ms.pop();
    } cout << endl;
}