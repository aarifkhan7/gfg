#include "graph.cpp"

int extra_edges = 0;

void DFS(vector<bool>& visited, vector<bool>& currentstack, Graph g, int s){
    if(!visited[s]){
        currentstack[s] = true;
        visited[s] = true;
        // DFS starts from here
        for(int x : g.adj[s]){
            DFS(visited, currentstack, g, x);
        }
        currentstack[s] = false;
    }else{
        extra_edges++;
    }
}

void extraEdges(Graph& g){
    int comp = 0;
    int n = g.V;
    // DFS
    vector<bool> visited(n, false);
    vector<bool> currentstack(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            comp++;
            DFS(visited, currentstack, g, i);
        }
    }
    cout << comp << '\t' << extra_edges << '\n';
}

int main(){
    Graph g(6);
    vector<vector<int>> v = {
        {0,1},
        {0,2},
        {0,3},
        {1,2}
    };
    for(auto x : v){
        g.addEdge(x[0],x[1]);
    }
    // Program to find extra edges
    extraEdges(g);
}