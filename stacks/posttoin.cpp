#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter postfix string: ";
    string post; cin >> post;
    stack<string> ms;
    for(int i = 0; i < post.size(); i++){
        char x = post[i];
        if(!(x == '+' || x == '-' || x == '*' || x == '/')){
            ms.push(string(1,x));
        }else{
            string b = ms.top(); ms.pop();
            string a = ms.top(); ms.pop();
            ms.push("(" + a + x + b + ")");
        }
    }
    cout << "Infix string: " << ms.top() << endl; 
    return 0;
}