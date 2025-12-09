#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>

using namespace std;

vector<int> di = {0,0,-1,1,1,1,-1,-1}; //vectores para hacer más simple la visita del mapa;
vector<int> dj = {-1,1,0,0,1,-1,1,-1};
inline bool valid_pos(int i,int j , const vector<vector<int>> &grid){
    return (i >= 0 && i < ((int)grid.size()) && j >= 0  && j < ((int)grid[0].size()));
}
int cont_adj(int i, int j, const vector<vector<int>> &mapa){
    int sum = 0;
    for(int dir = 0;dir<8;dir++){
        int newI = i + di[dir]; //manera fácil de comprobar los vecinos
        int newJ= j + dj[dir];
        if ( valid_pos(newI,newJ,mapa) && sum < 4){
            if (mapa[newI][newJ] == 1) sum++;
        }
    }
    if (sum < 4) { cout <<"Posicion recogida"<<i<<" "<<j<<endl; return 1;}
    else return 0;
}
int main(){

    ifstream input("input.txt");

    if (!input) {
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }
    vector<vector<int>> mapa;
    string line;
    int row=0;
    while(getline(input,line)) {
        vector<int> aux;
        for(unsigned int i=0; i<line.size();i++){
            if (line[i] == '.')
                aux.push_back(0);
            else 
                aux.push_back(1);
        }
        mapa.push_back(aux);
    }
    int sum=0;
    for (unsigned int i = 0; i< mapa.size(); i++){
        for(unsigned int j = 0; j< mapa[0].size();j++){
            cout<<mapa[i][j];
        }cout<<endl;

    }
    for (unsigned int i = 0; i< mapa.size(); i++){
        for(unsigned int j = 0; j< mapa[0].size();j++){
            if (mapa[i][j] != 0)
                sum+=cont_adj(i,j,mapa);
        }

    }

    cout<<sum<<endl;
    return 0;
}