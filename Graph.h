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
            graph = new ListLinked<GraphNode*>;
        }
        ~Graph(){
        for (int i = 0; i < graph->size(); ++i) {
            delete graph->get(i);
        }
        delete graph;

        }
        void insertNode(int id,ListLinked<GraphNode*> *vecinos = nullptr){
            GraphNode* nodo;
            if (search(id) != nullptr) {
                throw std::runtime_error("El nodo ya existe en el grafo");
            }
            if(vecinos != nullptr)
                nodo = new GraphNode (id,vecinos);
            else
                nodo = new GraphNode(id);
            graph->prepend(nodo);
            n++;
                
        }
        void addEdge(int idA, int idB,bool dirigido = false){
            GraphNode* A = search(idA);
            GraphNode* B = search(idB);

            if(A == nullptr || B == nullptr) throw std::runtime_error("Alguno de los nodos no existe");
            if (!(A->tieneVecino(idB))) A->annyairVecino(B);
            if (!(B->tieneVecino(idA)) && !dirigido) B->annyairVecino(A); //solo añade A a B si no es dirigido

        }
        void removeNode(int id){
        if (search(id) == nullptr)  throw std::out_of_range("Nodo no existe");
        for (int i = 0; i < graph->size(); ++i) { //Primero eliminas el nodo en las listas de vecinos
            GraphNode* aux = graph->get(i);
            for (int j = 0; j < aux->vecinos->size();j++) { //Buscas hasta que encuentras el nodo
                if (aux->vecinos->get(j)->id == id) {
                    aux->vecinos->remove(j);
                    break;
                }
            }
        }

        // Eliminas el nodo del grafo ahora que ya no es vecino de nadie
        for (int i = 0; i < graph->size(); ++i) {
            if (graph->get(i)->id == id) {
                GraphNode* toDelete = graph->remove(i);
                --n;
                delete toDelete;
                break;
            }
        }

        }
        GraphNode* search(int id){
            for (int i = 0; i < graph->size(); ++i) {
                if (graph->get(i)->id == id) return graph->get(i);
            }
            return nullptr;
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