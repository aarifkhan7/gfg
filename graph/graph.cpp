#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    // vector<int> vert;
    vector<list<int>> adj;
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    int countBFS(int s);
    int countDFS(int s);
    vector<int> listDFS(int s);
    int motherVertex();
    int nodesAtLevel(int l);
    bool isCyclic(int s);
    void checkPath(int n, int m);
};

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
    // for(int i = 0; i < V; i++)
        // vert.push_back(i);
    adj.resize(V);
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