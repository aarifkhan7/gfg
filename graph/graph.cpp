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
    int motherVertex();
    int nodesAtLevel(int l);
    bool isCyclic(int s);
};

bool Graph::isCyclic(int s){
    bool visited[V] = {false};
    queue<int> wait;
    wait.push(s);
    while(!wait.empty()){
        int tmp = wait.front();
        if(visited[tmp] == false){
            wait.pop();
            for(int x : adj[tmp]){
                wait.push(x);
            }
            visited[tmp] = true;
        }else{
            wait.pop();
            return true;
        }
    }
    return false;
}

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