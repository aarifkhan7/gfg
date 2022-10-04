#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter prefix string: ";
    string pre; cin >> pre;
    stack<char> as;
    stack<string> ms;
    for(char x : pre){
        as.push(x);
    }
    while(!as.empty()){
        char x = as.top();
        if(!(x == '+' || x == '-' || x == '*' || x == '/')){
            ms.push(string(1,x));
            as.pop();
            cout << "pushing " << string(1,x) << '\n';
        }else{
            string a = ms.top(); ms.pop();
            string b = ms.top(); ms.pop();
            string tmp = a + b + x;
            cout << "pushing " << tmp << '\n';
            ms.push(tmp);
            as.pop();
        }
    }
    cout << ms.top() << endl;
    return 0;
}