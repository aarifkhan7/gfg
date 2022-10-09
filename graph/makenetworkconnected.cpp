#include "graph.cpp"
#include "dsu.cpp"

int main(){
    int n = 12;
    vector<vector<int>> edges = {
        {1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}
    };
    DSU dsu1(n);
    int extra_edges = 0;
    for(auto e : edges){
        if(dsu1.same(e[0], e[1])){
            extra_edges++;
        }else{
            dsu1.unionof(e[0], e[1]);
        }
    }
    int comp = dsu1.countdistinct();
    for(int i = 0; i < n; i++){
        cout << i << ":" << dsu1.arr[i] << '\n';
    }
    // if(comp == 1){
    //     return 0;
    // }
    // if(comp-1 <= extra_edges){
    //     return comp-1;
    // }else{
    //     return -1;
    // }
}