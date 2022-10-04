#include <bits/stdc++.h>
#include "graph.cpp"

using namespace std;

int main(){
    Graph g1(7);
    g1.addEdge(0,1); g1.addEdge(0,2);
    g1.addEdge(1,3);
    g1.addEdge(4,1);
    g1.addEdge(5,2);
    g1.addEdge(5,6);
    g1.addEdge(6,0);
    g1.addEdge(6,4);
    cout << g1.motherVertex() << endl;

    Graph g2(5);
    g2.addEdge(0,2);
    g2.addEdge(0,3);
    g2.addEdge(1,0);
    g2.addEdge(2,1);
    g2.addEdge(3,4);
    cout << g2.motherVertex() << endl;
}