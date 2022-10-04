#include<bits/stdc++.h>
#include "graph.cpp"
using namespace std;

int main()
{
    Graph g1(4);
    g1.addEdge(0,1); g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(2,0); g1.addEdge(2,3);
    g1.addEdge(3,3);
    g1.DFS(2);
    return 0;
}