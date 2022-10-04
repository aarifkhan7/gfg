#include "graph.cpp"

int main(){
    Graph g1(7);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(0,3);
    g1.addEdge(1,4);
    g1.addEdge(2,5);
    g1.addEdge(3,6);
    g1.checkPath(0,4);
    g1.checkPath(0,5);
    g1.checkPath(1,5);
    
}