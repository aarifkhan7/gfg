#include "graph.cpp"

int main(){
    // Graph g1(4);
    // g1.addEdge(0,1);
    // g1.addEdge(0,2);
    // g1.addEdge(1,3);
    // g1.addEdge(2,3);
    // g1.paths(0,3,{});

    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(0,3);
    g1.addEdge(0,4);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(1,4);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.paths(0,4,{});
}