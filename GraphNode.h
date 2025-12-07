#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "../ListLinked/ListLinked.h"
#include <stdexcept>

using namespace std;
class GraphNode {
    public:
        int id;
        ListLinked<GraphNode*> *vecinos;

        GraphNode(int _id){
            id = _id;
            vecinos = new ListLinked<GraphNode*>;
        }
        GraphNode(int _id, ListLinked<GraphNode*> *_vecinos ){
            id = _id;
            vecinos = _vecinos;
        }
        ~GraphNode(){
            delete vecinos;
        }
    
        bool tieneVecino(int id) const {
            for (int i = 0; i < vecinos->size(); ++i)
                if (vecinos->get(i)->id == id) return true;
            return false;
        }

        void annyairVecino(GraphNode* vecino){
            if (!tieneVecino(vecino->id)) //comprueba si el vecino ya existe
                vecinos->prepend(vecino);
            else throw std::runtime_error("Veicno ya es vecino del nodo");
        }
        GraphNode* eliminarVecino(int id){
        for (int i = 0; i < vecinos->size(); ++i) {
            if (vecinos->get(i)->id == id) {
                return vecinos->remove(i);
            }
        }
        throw std::out_of_range("Vecino no existe");

        }

        int cantidad_vecinos(){
            return vecinos->size();
        }


        
};

#endif