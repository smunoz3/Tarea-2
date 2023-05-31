#include <iostream>
#include <string>
#include "Luces_por_arreglar.hpp"

using namespace std;

int main() {
    tABB treeBB;
    int postes_encendidos = 0;
    //tNodoArbolBin* raiz = nullptr;
    string comando;
    int i;
    while (true){
        cin >> comando;
        if (comando == "ENCENDER"){
            cin >> i;
            ENCENDER(treeBB,i,postes_encendidos);
        }
        else if (comando == "CUANTOS_ENCENDER"){
            cin >> i;
            CUANTOS_ENCENDER(treeBB,i,postes_encendidos);
        }
        else if (comando == "PARAR_PROGRAMA"){
            PARAR_PROGRAMA(postes_encendidos);
            break;
        }
    }
    return 0;
} 

// cd 2
// g++ Luces_por_arreglar.cpp Luces_por_arreglar.hpp -o Luces -Wall
// ./Luces