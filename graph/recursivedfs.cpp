// Recursive DFS with stack record and print;
#include "graph.cpp"
#define size 8

bool visited[size] = {false};
bool currentstack[size] = {false};

void DFS(Graph& g, int v){
    currentstack[v] = true;
    cout << v << ' ';
    // Print Current DFS Stack
    cout << " current dfs stack: ";
    for(int i = 1; i < size; i++){
        if(currentstack[i]){
            cout << i << ' ';
        }
    }
    cout << endl;
    // Continuation of DFS
    visited[v] = true;
    for(auto x : g.adj[v]){
        if(!visited[x]){
            DFS(g, x);
        }
    }
    currentstack[v] = false;
}

int main(){
    // Preparation of Graph
    Graph g1(size);
    vector<vector<int>> e = {{1,2},{1,3},{1,5},{2,4},{2,6},{3,7},{6,5}};
    for(auto x : e){
        g1.addEdge(x[0],x[1]);
    }
    // Recursive DFS
    DFS(g1, 1);
}