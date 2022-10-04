#include<bits/stdc++.h>
using namespace std;

int main()
{
    string post; cin >> post;
    stack<int> ms;
    for(int i = 0; i < post.size(); i++){
        char x = post[i];
        if(!(x == '+' || x == '-' || x == '*' || x == '/')){
            int xi = int(x) - 48;
            ms.push(xi);
        }else{
            int b = ms.top(); ms.pop();
            int a = ms.top(); ms.pop();

            if(x == '+'){
                ms.push(a + b);
            }else if(x == '-'){
                ms.push(a - b);
            }else if(x == '*'){
                ms.push(a * b);
            }else if(x == '/'){
                ms.push(a / b);
            }
        }
    }
    cout << ms.top() << endl;
    return 0;
}