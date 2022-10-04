#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> ms;
    stack<int> as;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        ms.push(tmp);
    }
    for(int i = 0; i < n/2; i++){
        as.push(ms.top());
        ms.pop();
    }
    ms.pop();
    while(!as.empty()){
        ms.push(as.top());
        as.pop();
    }
    while(!ms.empty()){
        cout << ms.top() << ' ';
        ms.pop();
    } cout << endl;
    return 0;
}