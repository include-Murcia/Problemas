#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<queue>
using namespace std;

inline bool valid_pos(unsigned int i, unsigned int j , const vector<string> &grid){
    return (i >= 0 && i < (grid.size()) && j >= 0  && j < (grid[0].length()));
}

int split_num( vector<string> &grid,unsigned int i, unsigned int j){
    if(valid_pos(i,j,grid)){
        if(grid[i][j] == '^'){
            return 1 + split_num(grid,i,j+1) + split_num(grid,i,j-1);
        }
        else if (grid[i][j] != '|'){grid[i][j] = '|'; return split_num(grid,i+1,j);}
        else return 0;
    }
    else {
        return 0;
    }
}
int main(){
    
    ifstream input("input.txt");
    string str;
    queue<string> cola;
    while(getline(input,str)) { // guardamos inicialmente el mapa en  una estructura dinámica ya que no nos dan su tamaño
        cola.push(str);
    }
    unsigned int tam_cola = cola.size();
    vector<string> grid(tam_cola);

    for(unsigned int i = 0; i<tam_cola;i++){ // ahora que ya sabemos su tamaño lo copiamos en un vector para facilitar su uso.
        grid[i] = cola.front();
        cola.pop();
    }
    unsigned int k=0;
    for (k=0; k<grid[0].size();k++){
        if(grid[0][k] == 'S') break;
    }
    char aux = grid[0][k];
    cout<< split_num(grid,0,k)<<endl;
    for(int i = 0; i< tam_cola; i++){
        cout<<grid[i]<<endl;
    }
    
}