#include <bits/stdc++.h>

// Aarif Khan
// Codechef: https://www.codechef.com/users/aarifkhan_7
// Github: https://github.com/aarifkhan7

#define pi (3.141592653589)
#define MOD 1e9+7
#define ll long long int
#define all(x) x.begin(), x.end()
#define range(a, b) for(int i = a; i < b; i++)
#define range1(a, b) for(int j = a; j < b; j++)
#define inint(x) int x; cin >> x;
#define inarr(x, n) int arr[n]; range(0, n){cin >> x[i];}
#define inll(x) ll x; cin >> x;
#define instr(x) string x; cin >> x; 
#define printc(cont) for(auto x : cont) cout << x << ' '; cout << '\n';
#define printp(cont) for(auto x : cont) cout << x.first << ' ' << x.second << '\n';
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    fast;
    inint(n); inarr(arr, n);
    int p = 0, i = 0;
    for(i = 0; i < n; i++){
        if(i + p >= n){
            break;
        }
        if(arr[i+p] == 0){
            int j = i;
            while(arr[j] == 0){
                j++;
                p++;
            }
        }
        arr[i] = arr[i + p];
    }
    range1(i, n){
        arr[j] = 0;
    }
    printc(arr);
    return 0;
}