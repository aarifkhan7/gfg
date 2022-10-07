#include<bits/stdc++.h>
using namespace std;

class wAdjItem{
    public:
    int t, w = -1;
    wAdjItem(int _t){
        t = _t;
    }
    wAdjItem(int _t, int _w){
        t = _t;
        w = _w;
    }
};

void print(vector<int> v){
    for(int x : v) cout << x << ' '; cout << endl;
}

class Graph{
    public:
    int V;
    // vector<int> vert;
    vector<list<int>> adj;
    vector<list<wAdjItem>> wadj;
    vector<int> dijkDistance;
    Graph(int V);
    void addEdge(int v, int w);
    void addEdgew(int v, int w, int d);
    void BFS(int s);
    void DFS(int s);
    int countBFS(int s);
    int countDFS(int s);
    vector<int> listDFS(int s);
    int motherVertex();
    int nodesAtLevel(int l);
    bool isCyclic(int s);
    void checkPath(int n, int m);
    int countComponents();
    void paths(int s, int t, vector<int> nodes);
    void dijkstra(int s);
};

void Graph::dijkstra(int s){
    dijkDistance[s] = 0;
    vector<bool> visited(V, false);
    queue<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.front(); wait.pop();
        if(!visited[tmp]){
            for(auto x : wadj[tmp]){
                if(dijkDistance[tmp] + x.w < dijkDistance[x.t]){
                    dijkDistance[x.t] = dijkDistance[tmp] + x.w;
                    visited[x.t] = false;
                }
                if(!visited[x.t]){
                    wait.push(x.t);
                }
            }
        }
        visited[tmp] = true;
    }
}

void Graph::addEdgew(int v, int w, int d){
    wadj[v].push_back(wAdjItem(w, d));
}

void Graph::paths(int s, int t, vector<int> nodes){
    if(find(nodes.begin(), nodes.end(), s) == nodes.end()){
        nodes.push_back(s);
        if(s == t){
            print(nodes);
        }else{
            for(int x : adj[s]){
                paths(x, t, nodes);
            }
        }
    }else{
        return;
    }
}

int Graph::countComponents(){
    bool visited[V] = {false};
    int compCount = 0;
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            // DFS
            stack<int> wait;
            wait.push(i);
            while(!wait.empty()){
                int tmp = wait.top();
                wait.pop();
                if(visited[tmp] == false){
                    reverse(adj[tmp].begin(), adj[tmp].end());
                    for(int x : adj[tmp]){
                        wait.push(x);
                    }
                    visited[tmp] = true;
                }
            }
            // Increase component Count
            compCount++;
        }
    }
    return compCount;
}

void Graph::checkPath(int n, int m){
    vector<int> d1 = listDFS(n);
    vector<int> d2 = listDFS(m);
    if(find(d1.begin(), d1.end(), m) != d1.end() || find(d2.begin(), d2.end(), n) != d2.end()){
        cout << "Same path...\n";
    }else{
        cout << "DIFFERENT!!\n";
    }
}

// bool Graph::isCyclic(int s){
//     bool visited[V] = {false};
//     queue<int> wait;
//     wait.push(s);
//     while(!wait.empty()){
//         int tmp = wait.front();
//         if(visited[tmp] == false){
//             wait.pop();
//             for(int x : adj[tmp]){
//                 wait.push(x);
//             }
//             visited[tmp] = true;
//         }else{
//             wait.pop();
//             return true;
//         }
//     }
//     return false;
// }

int Graph::nodesAtLevel(int l){
    bool visited[V] = {false};
    int level[V] = {0};
    queue<int> wait;
    wait.push(0);
    while(!wait.empty()){
        int tmp = wait.front();
        if(visited[tmp] == false){
            // cout << tmp << ' ';
            wait.pop();
            for(int x : adj[tmp]){
                wait.push(x);
                level[x] = level[tmp] + 1;
            }
            visited[tmp] = true;
        }else{
            wait.pop();
        }
    }
    int i = 0;
    for(int x : level)
        if(x == l)
            i++;
    return i;
}

int Graph::motherVertex(){
    for(int i = 0; i < V; i++){
        if(countBFS(i) == V){
            return i;
        }
    }
    return -1;
}

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
    wadj.resize(V);
    dijkDistance.resize(V,INT_MAX);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    bool visited[V] = {false};
    queue<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.front();
        if(visited[tmp] == false){
            cout << tmp << ' ';
            wait.pop();
            for(int x : adj[tmp]){
                wait.push(x);
            }
            visited[tmp] = true;
        }else{
            wait.pop();
        }
    }
    cout << endl;
}

void Graph::DFS(int s){
    bool visited[V] = {false};
    stack<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.top();
        wait.pop();
        if(visited[tmp] == false){
            cout << tmp << ' ';
            reverse(adj[tmp].begin(), adj[tmp].end());
            for(int x : adj[tmp]){
                wait.push(x);
            }
            visited[tmp] = true;
        }
    }
    cout << endl;
}

int Graph::countBFS(int s){
    int count = 0;
    bool visited[V] = {false};
    queue<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.front();
        if(visited[tmp] == false){
            count++;
            wait.pop();
            for(int x : adj[tmp]){
                wait.push(x);
            }
            visited[tmp] = true;
        }else{
            wait.pop();
        }
    }
    return count;
}

int Graph::countDFS(int s){
    int count = 0;
    bool visited[V] = {false};
    stack<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.top();
        wait.pop();
        if(visited[tmp] == false){
            count++;
            reverse(adj[tmp].begin(), adj[tmp].end());
            for(int x : adj[tmp]){
                wait.push(x);
            }
            visited[tmp] = true;
        }
    }
    return count;
}

vector<int> Graph::listDFS(int s){
    vector<int> res;
    bool visited[V] = {false};
    stack<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.top();
        wait.pop();
        if(visited[tmp] == false){
            res.push_back(tmp);
            reverse(adj[tmp].begin(), adj[tmp].end());
            for(int x : adj[tmp]){
                wait.push(x);
            }
            visited[tmp] = true;
        }
    }
    return res;
}