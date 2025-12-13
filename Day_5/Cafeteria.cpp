#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main(){
ifstream input("input.txt");
vector<pair<long long,long long>> rangos;
int cont=0;
long long minrange=1000000,maxrange=0;
string line;
while(getline(input,line)){
    if (line.empty()) continue;
    int token = line.find('-');
    if(token != string::npos && token > 0){
        long long min = stoll(line.substr(0,token));
        long long max = stoll(line.substr(token+1));
        if (minrange > min) minrange=min;
        if(maxrange < max) maxrange = max;
        rangos.push_back({min,max});
    }
    else{
        long long num = stoll(line);
        bool fresh=false;
        if(num > maxrange || num < minrange) break;
        for(unsigned int i=0; i<rangos.size();i++){
            if(num >= rangos[i].first && num <= rangos[i].second) { fresh = true;break;}
        }
        if(fresh) cont++;
    }
    
}
cout<<cont<<endl;
return 0;
}