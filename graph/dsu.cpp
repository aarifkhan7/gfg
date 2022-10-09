// Implementation of weighted-Disjoint Set Union-Data Structure using the concept of trees
#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> arr;
    vector<int> parentofall;
    vector<int> treesize;
    int n;
    DSU(){
        
    }
    DSU(int n_){
        n = n_;
        for(int i = 0; i < n; i++){
            arr.push_back(i);
            parentofall.push_back(i);
            treesize.push_back(1);
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
        int pa = parent(a);
        int pb = parent(b);
        if(treesize[pa] < treesize[pb]){
            arr[pa] = arr[pb];
            treesize[pb] += treesize[pa];
        }else{
            arr[pb] = arr[pa];
            treesize[pa] += treesize[pb];
        }
    }
    int countdistinct(){
        int count = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] == i)
                count++;
        return count;
    }
};