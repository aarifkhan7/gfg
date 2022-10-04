#include<bits/stdc++.h>
#include "graph.cpp"
using namespace std;

int main()
{
    Graph g1(4);
    g1.addEdge(0,1);
    g1.addEdge(1,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(2,0);
    g1.BFS(1);
    return 0;
}