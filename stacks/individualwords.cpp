#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> ms;
    for(string s : {"hello","world"}){
        ms.push(s);
    }
    string ans = "";
    while(!ms.empty())
    {
        reverse(ms.top().begin(), ms.top().end());
        ans = ms.top() + ' ' + ans;
        ms.pop();
    }
    cout << ans << '\n';
    return 0;
}