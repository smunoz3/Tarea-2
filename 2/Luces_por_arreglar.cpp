#include <iostream>
#include <string>
#include "Luces_por_arreglar.hpp"

using namespace std;

void insertar(tNodoArbolBin*& raiz, int posicion) {
    if (raiz == nullptr) {
        raiz = new tNodoArbolBin;
        raiz->posicion = posicion;
        raiz->encendido = false;
        raiz->izq = nullptr;
        raiz->der = nullptr;
        return;
    }
    if (posicion < raiz->posicion) {
        insertar(raiz->izq, posicion);
    } else if (posicion > raiz->posicion) {
        insertar(raiz->der, posicion);
    } else {
        // El valor ya existe en el árbol, puedes decidir cómo manejarlo
        std::cout << "Elemento ya ingresado" << std::endl;
    }
}

int main() {
    tABB treeBB;
    int pos_encendido = 0;

    tNodoArbolBin* raiz = NULL;
    insertar(raiz, 5);
    insertar(raiz, 3);
    insertar(raiz, 7);
    insertar(raiz, 2);
    insertar(raiz, 4);
    insertar(raiz, 6);
    insertar(raiz, 8);

    while (true)
    {
        string comando;
        cin >> comando;

        if (comando == "ENCENDER"){
            tNodoArbolBin nodo;
            int i;
            cin >> i;
            nodo.posicion = i;
            if (!treeBB.find(nodo)){
                treeBB.insert(nodo);
                pos_encendido++;
            }
        }
        else if (comando == "CUANTOS_ENCENDER"){
            tNodoArbolBin nodo;
            int i;
            cin >> i;
            nodo.posicion = i;
            int cercano = treeBB.lower_bound(nodo);
            if (cercano == -1){
                cout<<"uno"<<endl;
                cout<<pos_encendido<<endl;
            }
            else {
                int count = cercano -i;
                cout<<"dos"<<endl;
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