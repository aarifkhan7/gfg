#include "graph.cpp"

int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,0);
    g1.addEdge(1,2);
    g1.addEdge(2,1);
    g1.addEdge(3,4);
    g1.addEdge(4,3);
    cout << g1.countComponents() << '\n';
}