#include <iostream>
#include <string>
#include "exp.hpp"

using namespace std;

int main() {
    tABB treeBB;
    int postes_encendidos = 0;

    while (true) {
        string comando;
        cin >> comando;

        if (comando == "ENCENDER") {
            int i;
            cin >> i;
            ENCENDER(treeBB, i, postes_encendidos);
        } else if (comando == "CUANTOS_ENCENDER") {
            int i;
            cin >> i;
            CUANTOS_ENCENDER(treeBB, i, postes_encendidos);
        } else if (comando == "PARAR_PROGRAMA") {
            PARAR_PROGRAMA(postes_encendidos);
        }
    }

    return 0;
}

// g++ exp.cpp exp.hpp -o exp -Wall
// ./exp

// cd 2
// g++ Luces_por_arreglar.cpp Luces_por_arreglar.hpp -o Luces -Wall
// ./Luces

//g++ Secuancia_de_Nucleotidos.cpp Secuancia_de_Nucleotidos.hpp -o nucleogods -Wall
//./nucleogods < secuencias-nucleotidos.txt