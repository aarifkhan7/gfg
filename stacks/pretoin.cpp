#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter prefix string: ";
    string pre; cin >> pre;
    stack<string> ms;
    for(int i = pre.size() - 1; i >= 0; i--){
        if(!(pre[i] == '+' || pre[i] == '-' || pre[i] == '*' || pre[i] == '/')){
            string tmp(1, pre[i]);
            cout << "pushing " << tmp << endl;
            ms.push(tmp);
        }else{
            string a = ms.top(); ms.pop();
            string b = ms.top(); ms.pop();
            string tmp = "(" + a + pre[i] + b + ")";
            cout << "pushing " << tmp << endl;
            ms.push(tmp);
        }
    }
    cout << ms.top();
    cout << endl;
    return 0;
}