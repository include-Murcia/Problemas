#include "Graph.h"
#include <iostream>
#include "../ListLinked/ListLinked.h"
using namespace std;

int main(){
    Graph caja;
    
    for(int i = 0; i < 4; i++){
        caja.insertNode(i);
    }
    caja.addEdge(0,1);
    caja.addEdge(1,2);
    caja.addEdge(2,3);
    caja.addEdge(0,3);
    caja.addEdge(0,2);
    caja.addEdge(1,3);
    
    caja.print();

    caja.removeNode(0);

    cout<<endl;
    caja.print();
    
}
