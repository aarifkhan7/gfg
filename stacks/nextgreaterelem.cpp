#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n], ans[n];
    arr[n-1] = -1;
    stack<int> ms;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        arr[i] = tmp;
    }
    ms.push(arr[n-1]);
    ans[n-1] = -1;
    for(int i = n-2; i >= 0; i--){
        bool found = false;
        while(!ms.empty()){
            if(arr[i] < ms.top()){
                found = true;
                ans[i] = ms.top();
                ms.push(arr[i]);
                break;
            }else{
                ms.pop();
            }
        }
        if(!found){
            ans[i] = -1;
        }
    }
    for(int x : ans){
        cout << x << ' ';
    } cout << endl;
    return 0;
}