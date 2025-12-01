#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(){
    ifstream input;
    input.open("input.txt");

    int password=0,num=50;
    char dir;
    string pos,cad;
    while(getline(input,cad)) {
        dir = cad[0];
        for (unsigned int i=1; i<cad.size();i++){
            pos[i] = cad[i];
        }
         int aux = stoi(pos);
        switch (dir)
        {
        case 'R':

            if ((num + aux) > 99){
                num = ((num + aux)- 100);
            }else{
                num = num + aux;
            }
            break;
        case 'L':
            if ((num - aux) < 0) {
                num = (100 - (num-aux));
            }else {
                num = num-aux;
            }
            break;
        }

        if (num == 0){
            password++;
        }
    }
    cout<<password<<endl;

}
