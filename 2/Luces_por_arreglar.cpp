#include <iostream>
#include <string>
#include "Luces_por_arreglar.hpp"

using namespace std;


int main(){
    int n;
    cin>>n;
    tNodoArbolBin nodo2;
    nodo2.posicion = 2;

    tNodoArbolBin nodo;
    for (int i = 0;i<n;i++){
        nodo.posicion = i;
        nodo.encendido = false;
    }
    tABB arbol;
    arbol.insert(nodo);
    cout<<arbol.find(nodo)<<endl;
    cout<<arbol.find(nodo2)<<endl;
    return 0;
}

// cd 2
// g++ Luces_por_arreglar.cpp Luces_por_arreglar.hpp -o Luces -Wall
// ./Luces