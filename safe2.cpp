//#include<Murcia>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
    ifstream input;
    input.open("input.txt");

    if(input.is_open()){
        int password=0,num=50;
        char dir;
        string pos,cad;
        int cont = 0;
        while(getline(input,cad)) { 
            if(cad.empty()){
                continue;
            }
            dir = cad[0];
            pos = cad.substr(1);
            int aux = stoi(pos)%100, vueltas_completas = stoi(pos)/100;
            switch (dir)
            {
            case 'R':
                password+=vueltas_completas;
                if ((num + aux) > 99){
                    num = ((num + aux)- 100);
                    if(num!=0){
                        password++;
                    }
                    cont++;
                }else{
                    num = num + aux;
                    cont++;
                }
                break;
            case 'L':
                password+=vueltas_completas;
                if ((num - aux) < 0) {
                    if(num!=0){
                        password++;
                    }
                    num = num - aux + 100;
                    cont++;
                }else {
                    num = num-aux;
                    cont++;
                }
                break;
                
            }

            if (num == 0 ){
                password++;
                cout<<"En la linea "<<cont<<" el dial de la caja fuerte apunta a 0."<<endl;
                cout<<"El giro era de "<<pos<<" unidades."<<endl;
            }
        }
        cout<<password<<endl;
        input.close();
        return 0;
    }else{
        cout<<"No se pudo abrir el archivo."<<endl;
        return -1;
    }

}