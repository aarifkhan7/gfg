#include "graph.cpp"

int main(){
    Graph g1(4);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(2,3);
    if(g1.isCyclic(0)){
        cout << "Cyclic...\n";
    }else{
        cout << "ACYCLIC...\n";
    }
}