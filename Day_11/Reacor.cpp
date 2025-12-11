#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include "../HashTable/HashTable.h"
#include "../Grafo/Graph.h"
using namespace std;
HashTable<int> tabla;
Graph grafo;
void load(vector<vector<string>> &out){
    ifstream input("input.txt");
    string str,line;
    int cont=0;
    while(getline(input,line)){                             //Cogemos la linea
        vector<string> v_aux;                               //Creamos un vector auxiliar
        stringstream ss(line);                              //Creamos un string stream para leer la linea
        while(ss>>str){ 
           str = (str.size() > 3) ? str.substr(0,2) : str; //Si la cadena tiene : se lo quitamos
            v_aux.push_back(str);                          // Lo añadimos al vector para luego hacer la unión de nodos
            try { //Miras si existe la clave, si existe no haces nada, saltas al bloque catch.
                tabla.search(str);
                tabla.insert(str,cont); //Si no existía el string, insertas en la hash y en el grafo con valor = id = cont
                grafo.insertNode(cont);
                cont++;                 //Cont + 1
            }
            catch (runtime_error &ex){}
        
        }               
            
        out.push_back(v_aux);
    }
    
}

int main(){
    vector<vector<string>> input;
    load(input);

    
}