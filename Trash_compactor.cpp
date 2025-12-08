#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<sstream>
using namespace std;
long long suma(const vector<vector<string>> nums, int col){
    long long sum = 0;
    for(int i = 0;i< nums.size() -1 ;i++){ // suma todos los numeros de la columna excepto el último (el operador)
        sum += stoll(nums[i][col]);
    }
    return sum;
}
long long mult(const vector<vector<string>> nums, int col){
    long long mul = 1;
    for(int i = 0;i< nums.size() -1 ;i++){ // suma todos los numeros de la columna excepto el último (el operador)
         mul *= stoll(nums[i][col]);
    }
    return mul;
}
int main(){
    
    ifstream input("input.txt");
    string str;
    vector<vector<string>> in;
    while(getline(input,str)) { // guardamos inicialmente el mapa en  una estructura dinámica ya que no nos dan su tamaño
        stringstream ss(str);
        vector<string> fila;
        string valor;
        while(ss >> valor) fila.push_back(valor);
        in.push_back(fila);
    }
    long long res=0;
    for (int i = 0; i< (in[0].size());i++){
        if (in[in.size() -1][i] == "+") res += suma(in,i);
        else                            res += mult(in,i);
    }
    cout<<res<<endl;


    return 0;
}