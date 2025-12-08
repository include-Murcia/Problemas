#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<queue>
using namespace std;
int sum = 0;
inline bool valid_pos(int i,int j , const vector<string> &grid){
    return (i >= 0 && i < ((int)grid.size()) && j >= 0  && j < ((int)grid[0].length()));
}

long long split_num( const vector<string> grid,int i,int j,vector<vector<long long>> &mem){
    if(valid_pos(i,j,grid)){
        if(mem[i][j] != -1) return mem[i][j];
        
        if(grid[i][j] == '^'){
            mem [i][j] = split_num(grid,i+1,j+1,mem) + split_num(grid,i+1,j-1,mem);     
        }
        else {
            if(i == grid.size() -1) mem[i][j] = 1;
            else mem[i][j] = split_num(grid,i+1,j,mem);
        }
        return mem[i][j];
    }
    return 0;
}
int main(){
    
    ifstream input("input.txt");
    string str;
    vector<string> grid;
    while(getline(input,str)) { // guardamos inicialmente el mapa en  una estructura dinámica ya que no nos dan su tamaño
        grid.push_back(str);
    }

    int k=0;
    for (k=0; k< (int)grid[0].size();k++){
        if(grid[0][k] == 'S') break;
    }
    vector<vector<long long>> mem (grid.size(),vector<long long>(grid[0].length(),-1));
    char aux = grid[0][k];
     cout<< split_num(grid,0,k,mem)<<endl;

    
}