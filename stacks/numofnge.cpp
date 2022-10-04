#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Input
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> ms;
    // Main Algorithm
    int ans[n];
    ans[n-1] = 0;
    ms.push(n-1);
    for(int i = n-2; i >= 0; i--){
        int tmp = arr[i];
        // cout << "running for " << tmp << endl;
        if(!ms.empty() && tmp < arr[ms.top()]){
            ans[i] = ans[ms.top()] + 1;
            ms.push(i);
        }else{
            while(!ms.empty() && tmp >= arr[ms.top()]){
                ms.pop();
            }
            if(!ms.empty()){
                ans[i] = ans[ms.top()] + 1;
            }else{
                ans[i] = 0;
            }
            ms.push(i);
        }
        // cout << "ans of " << tmp << " is " << ans[i] << endl;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
    return 0;
}