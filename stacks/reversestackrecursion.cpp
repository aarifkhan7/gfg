#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int> * f, stack<int> * s){
    if(f->size() == 0){
        return;
    }else{
        s->push(f->top());
        f->pop();
        return reverse(f, s);
    }
}

int main()
{
    // Input
    stack<int> ms;
    stack<int> as;
    int n; cin >> n;
    while(n--){
        int tmp; cin >> tmp;
        ms.push(tmp);
    }
    // Main Algorithm
    reverse(&ms, &as);
    while(!as.empty()){
        cout << as.top() << ' ';
        as.pop();
    } cout << endl;
    return 0;
}