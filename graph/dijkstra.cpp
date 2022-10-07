#include "graph.cpp"

int main(){
    Graph g(6);
    vector<vector<int>> v = {
        {0,1,4},
        {0,2,4},
        {1,2,2},
        {2,3,3},
        {2,4,6},
        {2,5,1},
        {3,4,2},
        {5,4,3}
    };
    for(auto x : v){
        g.addEdgew(x[0],x[1],x[2]);
    }
    g.dijkstra(0);
    for(int i = 0; i < 6; i++){
        cout << i << " = " << g.dijkDistance[i] << '\n';
    }
}