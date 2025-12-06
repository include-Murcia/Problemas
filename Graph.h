#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include "../ListLinked/ListLinked.h"
#include<iostream>
using namespace std;

class Graph {
    public:
        int n;
        ListLinked<GraphNode*> *graph;

        Graph(){
            n=0;
        }
        void insertNode(int id,ListLinked<GraphNode*> *vecinos = nullptr){
            GraphNode* nodo;
            if (search(id)->id != -1)
                {
                
                if(vecinos != nullptr)
                    nodo = new GraphNode (id,vecinos);
                else
                    nodo = new GraphNode(id);
                    
                graph->prepend(nodo);
                n++;
                }
            else throw std::runtime_error("Nodo con esa id ya existente en el grafo");    
        }
        void removeNode(int id){
            GraphNode* aux;
                for(int i=0; i<n; i++){
                    if ((graph->get(i)->id) == id)
                    for (int j=0; j<( graph->get(i)->vecinos->size() );j++){
                         aux = graph->get(i)->vecinos->get(j)->eliminarVecino(id);
                    }
                }
                n--;
                delete aux;

        }
        GraphNode* search(int id){
            if (n > 0)
                for(int i = 0; i<n; i++){
                    if((graph->get(i)->id) == id) {
                        return new GraphNode(id,graph->get(i)->vecinos);
                    }
                }
            new GraphNode(-1);
            return new GraphNode(-1);
        }

        void print(){
            for(int i = 0; i<n;i++){
                cout<<"Nodo: "<<graph->get(i)->id<<"- Vecinos: ";
                for (int j =0;j< graph->get(i)->vecinos->size(); j++) {
                    cout<< graph->get(i)->vecinos->get(j)->id <<" ";
                }
                cout<<endl;
            }
        }

};
#endif