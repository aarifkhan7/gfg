#include "graph.cpp"

int main(){
    // Preparation of Graph
    Graph g1(3+1);
    vector<vector<int>> e = {{1,2},{1,3},{2,3}};
    for(auto x : e){
        g1.addEdge(x[0], x[1]);
    }
    e = {{2,1},{3,1},{3,2}};
    for(auto x : e){
        g1.addEdge(x[0], x[1]);
    }
    // Cycle detection using bfs;
    int flag = -1;
    vector<bool> visited(3+1,false);
    queue<int> wait;
    wait.push(1);
    while(!wait.empty()){
        int tmp = wait.front(); wait.pop();
        if(!visited[tmp]){
            for(auto x : g1.adj[tmp]){
                wait.push(x);
            }
        }else{
            cout << "cycle starting at " << tmp << '\n';
            flag = tmp;
            break;
        }
        visited[tmp] = true;
    }
    auto it = --e.end();
    for(it = it; it != e.begin(); it--){
        if((*it)[0] == flag || (*it)[1] == flag){
            cout << "delete edge " << (*it)[0] << " to " << (*it)[1] << endl;
            break;
        }
    }
}