#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include "../ListLinked/ListLinked.h"
#include <stdexcept>

using namespace std;
class GraphNode {
    public:
        int id;
        ListLinked<GraphNode*> *vecinos;
        int cantidad_vecinos;

        GraphNode(int _id){
            id = _id;
            cantidad_vecinos = 0;
        }
        GraphNode(int _id, ListLinked<GraphNode*> *_vecinos ){
            id = _id;
            vecinos = _vecinos;
            cantidad_vecinos = vecinos->size();
        }
        void annyairVecino(int id){
            GraphNode* vecino = new GraphNode(id);
            vecinos->prepend(vecino);
            cantidad_vecinos++;
        }
        GraphNode* eliminarVecino(int id){
            GraphNode* vecino = new GraphNode(id);
            int iter = vecinos->search(vecino);
            if (iter!=-1){
                GraphNode* eliminado = vecinos->remove(iter);
                cantidad_vecinos--;
                return eliminado;
            }
            else throw std::out_of_range("Vecino no existe");
            
        }


        
};

#endif