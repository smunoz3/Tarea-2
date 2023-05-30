#include <iostream>
#include <string>
#include "Luces_por_arreglar.hpp"

using namespace std;


int main() {
    tABB bst;
    int pos_encendido =0;
    while (true)
    {
        string comando;
        cin >> comando;

        if (comando == "ENCENDER"){
            tNodoArbolBin nodo;
            int i;
            cin >> i;
            nodo.posicion = i;
            if (!bst.find(nodo)){
                bst.insert(nodo);
                pos_encendido++;
            }
        }
        else if (comando == "CUANTOS_ENCENDER"){
            tNodoArbolBin nodo;
            int i;
            cin >> i;
            nodo.posicion = i;
            int closest = bst.lower_bound(nodo);
            if (closest == -1){
                cout<<pos_encendido<<endl;
            }
            else {
                int count = closest -i;
                cout<<count <<endl;
            }
        }
        else if (comando == "PARAR_PROGRAMA"){
            cout << pos_encendido<<endl;
            break;
        }
    }
    return 0;
} 

// cd 2
// g++ Luces_por_arreglar.cpp Luces_por_arreglar.hpp -o Luces -Wall
// ./Luces