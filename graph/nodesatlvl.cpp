#include "graph.cpp"

int main(){
    Graph g1(7);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,3);
    g1.addEdge(1,4);
    g1.addEdge(1,5);
    g1.addEdge(2,6);
    cout << g1.nodesAtLevel(1);
}