#include "Graph.h"
#include <iostream>
#include "../ListLinked/ListLinked.h"
using namespace std;

int main(){
    Graph caja;
    
    for(int i = 0; i < 4; i++){
        caja.insertNode(i);
    }
    caja.search(0)->annyairVecino(1);
    caja.search(1)->annyairVecino(2);
    caja.search(2)->annyairVecino(3);
    caja.search(3)->annyairVecino(0);
    caja.search(0)->annyairVecino(2);
    caja.search(3)->annyairVecino(1);

    caja.print();

    caja.removeNode(0);

    cout<<endl;
    caja.print();
    
}
