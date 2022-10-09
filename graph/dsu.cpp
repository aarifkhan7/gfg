#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> arr;
    int n;
    DSU(){
        
    }
    DSU(int n_){
        n = n_;
        for(int i = 0; i < n; i++){
            arr.push_back(i);
        }
    }
    int parent(int k){
        int tmp = k;
        while(arr[tmp] != tmp){
            tmp = arr[tmp];
        }
        return tmp;
    }
    bool same(int a, int b){
        return parent(a) == parent(b);
    }
    void unionof(int a, int b){
        for(int i = 0; i < n; i++){
            if(same(i, a)){
                arr[i] = parent(b);
            }
        }
    }
};