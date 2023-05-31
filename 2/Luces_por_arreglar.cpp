#include <iostream>
#include <string>
#include "Luces_por_arreglar.hpp"

using namespace std;
/* 
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
 */
int main() {
    tABB treeBB;
    int pos_encendido = 0;
    tNodoArbolBin* raiz = nullptr;
    while (true)
    {

        string comando;
        cin >> comando;

        if (comando == "ENCENDER"){
            tNodoArbolBin nodo;
            int i;
            cin >> i;
            nodo.posicion = i;
            if (!treeBB.find(nodo)){ // si no esta el nodo se incerta como true
                nodo.encendido = true;
                treeBB.insert(nodo);
                pos_encendido++;
            }
            else{
                tNodoArbolBin* nodo_puntero;
                nodo_puntero = treeBB.findHelp(raiz,nodo); 
                if (nodo_puntero->encendido != true){   //si es true no pasa nada
                    nodo_puntero->encendido = true;
                }
            }
        }
        else if (comando == "CUANTOS_ENCENDER"){
            tNodoArbolBin nodo;
            int i;
            cin >> i;
            nodo.posicion = i;
            int cercano = treeBB.lower_bound(nodo);
            if (cercano == -1){
                cout<<i+1<<endl;
            }
            else {
                int count = i - cercano;
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