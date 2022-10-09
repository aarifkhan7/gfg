#include "graph.cpp"

vector<int> q = {
    3,
    2,
    5,
    4,
    6,
    1,
    7,
    0
};

int dfs(Graph& g, int s){
    int tmpans = q[s];
    for(auto x : g.adj[s]){
        tmpans = min(tmpans, dfs(g, x));
    }
    for(int i = 0; i < q.size(); i++){
        if(q[i] == tmpans)
            return i;
    }
    return -1;
}

int main(){
    // Preparation of Graph
    Graph g(8);
    vector<vector<int>> e = {
        {0,1},
        {1,2},
        {1,3},
        {7,3},
        {3,4},
        {3,5},
        {3,6}
    };
    for(auto x : e){
        g.addEdge(x[0],x[1]);
    }
    // Main Algo
    for(int i = 0; i < 8; i++){
        cout << dfs(g, i) << ' ';
    }
    cout << '\n';
}