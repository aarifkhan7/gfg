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
#define inarr(x, n) int x[n]; range(0, n){cin >> x[i];}
#define inll(x) ll x; cin >> x;
#define instr(x) string x; cin >> x; 
#define printc(cont) for(auto x : cont) cout << x << ' '; cout << '\n';
#define printp(cont) for(auto x : cont) cout << x.first << ' ' << x.ss << '\n';
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair

using namespace std;

void solve(){
    inint(n);
    inarr(arr, n);
    inint(target);
    int pivot = 0;
    range(0,n-1){
        if(arr[i+1] < arr[i]){
            pivot = i+1;
        }
    }
    int p1 = pivot;
    int p2 = pivot-1;
    if(p2 < 0)
        p2 += n;
    bool found = false;
    while(p1 != p2){
        int t = arr[p1] + arr[p2];
        if(t < target){
            p1++;
            if(p1 == n){
                p1 = 0;
            }
        }else if(t > target){
            p2--;
            if(p2 < 0)
                p2 += n;
        }else{
            cout << "true" << '\n';
            found = true;
            break;
        }
    }
    if(!found){
        cout << "false\n";
    }

}

int main()
{
    fast;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}