#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<vector>

#define max(a,b) (((a)>(b)) ? (a): (b))
using namespace std;

int maximize(const string cad, int i, int j, vector<vector<int>> &mem ){
    
    if (i >= cad.length() || j >= cad.length() || i >= j) return 0; // Si i o j están out_of_range o si i > j = return 0
    else if (mem[i][j] != 0) return mem[i][j];                      // Si ya existe el valor en la posición se devuelve directamente
    else {
        string aux = {cad[i],cad[j]};
        // Se busca el máximo entre: (opción actual) - (avanzar i) - (avanzar j) - (avanzar ambas)
        mem[i][j] = max(max( stoi(aux) , maximize(cad,i+1,j,mem) ) , max(maximize(cad,i,j+1,mem),maximize(cad,i+1,j+1,mem)));
    }
    return mem[i][j];
}

int main(){
    ifstream input("input.txt");
    string cad;
    int sum=0;
    while(getline(input,cad)){
        // Creamos una matriz de tamaño cadxcad inicializada a 0
        vector<vector<int>> mem(cad.size(),vector<int>(cad.size(),0));
        sum += maximize(cad,0, 1,mem); //Sumamos los resultados
    }
    cout<<sum<<endl;
    return 0;
}
