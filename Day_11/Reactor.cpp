#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include "../HashTable/HashTable.h"
#include "../Grafo/Graph.h"
using namespace std;
HashTable<int> tabla = HashTable<int>(30);
Graph grafo;
void load(vector<vector<string>> &out){
    ifstream input("input.txt");
    string str,line;
    int cont=0;
    while(getline(input,line)){                             //Cogemos la linea
        vector<string> v_aux;                               //Creamos un vector auxiliar
        stringstream ss(line);                              //Creamos un string stream para leer la linea
        while(ss>>str){ 
           str = (str.size() > 3) ? str.substr(0,3) : str; //Si la cadena tiene : se lo quitamos
            v_aux.push_back(str);                          // Lo añadimos al vector para luego hacer la unión de nodos
            try { //Miras si existe la clave, si existe saltas al bloque catch.
                tabla.search(str);
            }
            catch (runtime_error &ex){
                tabla.insert(str,cont); //Si no existía el string, insertas en la hash y en el grafo con valor = id = cont
                grafo.insertNode(cont);
                cont++;                 //Cont + 1
            }
        
        }               
            
        out.push_back(v_aux);
    }
    
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
int main(){
    vector<vector<string>> input;
    load(input);
    add_neig(input);

    cout<<tabla<<endl<<endl;
    grafo.print(); cout<<endl;
    //Búsqueda de los nodos inicio y final
    int id_you = tabla.search("you"); 
    int id_out = tabla.search("out");

    //aplicación de algoritmo para saber cuantos caminos hay de un nodo a otro

    
}