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
        while(getline(input,cad)) { //Revisamos linea por linea el archivo de movimientos
            if(cad.empty()){
                continue; // si la línea está vacía avanzamos a la siguiente
            }
            dir = cad[0]; //obtenemos el sentido de giro 
            pos = cad.substr(1); //obtenemos el número de movimientos 
            int aux = stoi(pos)%100; // obtenemos el número de movimientos obviando giros completos
            switch (dir) //clasificamos según la direcci´pn de giro
            {
            case 'R':

                if ((num + aux) > 99){
                    num = ((num + aux)- 100);
                    cont++;
                }else{
                    num = num + aux;
                    cont++;
                }
                break;
            case 'L':
                if ((num - aux) < 0) {
                    num = num - aux +100;
                    cont++;
                }else {
                    num = num-aux;
                    cont++;
                }
                break;
            }

            if (num == 0 ){
                password++; //si el dial apunta a cero, incrementamos password
                cout<<"En la linea "<<cont+1<<" el dial de la caja fuerte apunta a 0."<<endl;
                cout<<"El giro era de "<<aux<<" unidades."<<endl;
            }
        }
        cout<<password<<endl;
        input.close(); //cerramos archivo input
        return 0;
    }else{
        cout<<"No se pudo abrir el archivo."<<endl; //si se produce algun error en la apertura de input se muestra este mensaje
        return -1;
    }

}
