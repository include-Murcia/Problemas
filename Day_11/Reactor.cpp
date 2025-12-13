#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include "../HashTable/HashTable.h"
#include "../Grafo/Graph.h"

//#define DEBUG
using namespace std;
HashTable<int> tabla = HashTable<int>(700);
Graph grafo;
void load(vector<vector<string>> &out){
    ifstream input("input.txt");
    string str,line;
    int cont=0;
    while(getline(input,line)){                             //Cogemos la linea
        vector<string> v_aux;                               //Creamos un vector auxiliar
        stringstream ss(line);                              //Creamos un string stream para leer la linea
        while(ss>>str){ 
           if(str.size() > 3){
            str = str.substr(0,3);
            grafo.insertNode(cont);
            tabla.insert(str,cont);
            cont++;
           }
            v_aux.push_back(str);
        }               
        
        out.push_back(v_aux);
    }
    grafo.insertNode(cont);
    tabla.insert("out",cont);
}

void add_neig(const vector<vector<string>> &adj){ //Funcion que une los nodos dada la lista de adyacencia
    for(int i = 0; i<adj.size();i++){
        int idA = tabla.search(adj[i][0]); //Buscas en la tabla la id del nodo del que se parte
        for (int j = 1;j<adj[i].size();j++){ // Le añades los vecinos
            int idB = tabla.search(adj[i][j]); 
            grafo.addEdge(idA,idB,true); // Unes Nodo A con Nodo B de forma dirigida
        }
    }
}

long long path_count(int id,vector<long long> &mem){
    if( mem[id] != -1) return mem[id];
    if (id == tabla.search("out")) return 1;
    int cantidad_vecinos = grafo.graph[id].cantidad_vecinos();
    int sum = 0;
    for(int i=0; i < cantidad_vecinos;i++){
        int new_id = grafo.graph[id].vecinos[i];
        sum += path_count(new_id,mem);
    }
    mem[id] = sum;
    return mem[id];

}
int main(){
    vector<vector<string>> input;
    load(input);
    add_neig(input);

#ifdef DEBUG
    cout<<tabla<<endl<<endl;
    grafo.print(); cout<<endl;
#endif
    //Búsqueda de los nodos inicio y final
    int id_you = tabla.search("you"); 

    //aplicación de algoritmo para saber cuantos caminos hay de un nodo a otro
    vector<long long> mem(grafo.graph.size(),-1);
    cout<<path_count(id_you,mem)<<endl;
    
}