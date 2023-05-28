#include <iostream>

struct tNodoArbolBin{
int posicion;
bool encendido;
tNodoArbolBin* izq;
tNodoArbolBin* der;
};


class tABB {
private:
tNodoArbolBin *raiz; // puntero al nodo raíz del ABB
int nElems; // cantidad de elementos en el ABB
public:
tABB();
~tABB(){};
void insert(tNodoArbolBin x);
bool find(tNodoArbolBin x);
int lower_bound(tNodoArbolBin x);
};

tABB::tABB(){ //Constructor
raiz = NULL;
nElems = 0;
}


bool tABB::find(tNodoArbolBin item) {
return findHelp(raiz, item);
}
//
bool findHelp(tNodoArbolBin *nodo, tNodoArbolBin item) {
if (nodo == NULL) { // item no está en el ABB- puede que sea return
    return false;
} 
if (nodo->posicion == item.posicion){
    return true; // item encontrado
}
if (item.posicion < nodo->posicion){
    return findHelp(nodo->izq, item);
}
else
return findHelp(nodo->der, item);
}


/* void ENCENDER(int i){
    if (tABB::find(i)!=true){
        return;
    }
} */