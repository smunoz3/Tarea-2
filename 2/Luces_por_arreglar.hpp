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
tNodoArbolBin* insertHelp(tNodoArbolBin* nodo, int valor,bool encendido);
bool find(tNodoArbolBin x);
tNodoArbolBin* findHelp(tNodoArbolBin *nodo, tNodoArbolBin item);
int lower_bound(tNodoArbolBin x);
int lower_boundHelp(tNodoArbolBin* nodo, int valor, int& contador);
void ENCENDER (int i);
void CUANTOS_ENCENDER (int i);
void PARAR_PROGRAMA();
};

tABB::tABB(){ //Constructor
raiz = NULL;
nElems = 0;
}

void tABB::insert(tNodoArbolBin x){
    if (find(x)){
        std::cout<<"Elemento ya ingresado"<<std::endl;
        return;
    }
    raiz = insertHelp(raiz, x.posicion,x.encendido);
}
tNodoArbolBin* tABB::insertHelp(tNodoArbolBin* nodo, int valor,bool encendido){
    if (nodo == NULL) {
        return nodo;
    }
    if (valor < nodo->posicion) {
        nodo->izq = insertHelp(nodo->izq, valor,encendido);
    } else if (valor > nodo->posicion) {
        nodo->der = insertHelp(nodo->der, valor,encendido);
    }
    return nodo;
}

bool tABB::find(tNodoArbolBin item) {
    if (findHelp(raiz, item)!=NULL){
        return true;
    }
    return false;
}
//
tNodoArbolBin* tABB::findHelp(tNodoArbolBin *nodo, tNodoArbolBin item) {
if (nodo == NULL) { // item no está en el ABB- puede que sea return
    return NULL;
} 
if (nodo->posicion == item.posicion){
    return nodo; // item encontrado
}
if (item.posicion < nodo->posicion){
    return findHelp(nodo->izq, item);
}
else
return findHelp(nodo->der, item);
}

// Pude estar mal enfocado
int tABB::lower_bound(tNodoArbolBin x){
    int contador = 0;
    return lower_boundHelp(raiz, x.posicion,contador);
}
int tABB::lower_boundHelp(tNodoArbolBin* nodo, int valor, int& contador){
    if (nodo == NULL){
        return -1;
    }
    if (nodo->posicion == valor){
        return nodo->posicion;
    }
    if (valor < nodo->posicion){
        return lower_boundHelp(nodo->izq, valor,contador);
    }
    if (valor > nodo->posicion){
        return lower_boundHelp(nodo->der, valor,contador);
    }
    return nodo->posicion;
}
/*
int tABB::lower_bound(tNodoArbolBin x) {
    int contador = 0;  // Inicializar el contador
    return lower_boundHelp(raiz, x.posicion, contador);
}

int tABB::lower_boundHelp(tNodoArbolBin* nodo, int valor, int& contador) {
    contador++;  // Incrementar el contador en cada llamada recursiva
   
    if (nodo == nullptr) {
        return -1;  // Valor no encontrado
    }
    if (valor == nodo->posicion) {
        return nodo->posicion;  // Nodo encontrado
    }
    if (valor < nodo->posicion) {
        return lower_boundHelp(nodo->izq, valor, contador);
    } else {
        int resultado = lower_boundHelp(nodo->der, valor, contador);
        if (resultado == -1) {
            return nodo->posicion;  // Valor no encontrado, devuelve el valor más cercano inferior
        } else {
            return resultado;  // Valor encontrado en subárbol derecho
        }
    }
} 
*/
void tABB::ENCENDER(int i){
    tNodoArbolBin nodo;
    nodo.posicion = i;
    if (find(nodo)!=true){
        return;
    }
    tNodoArbolBin* nodo2;
    nodo2 =findHelp(raiz, nodo);
    if (nodo2->encendido !=true){
        nodo2->encendido = true;
    }
    return;
}

void tABB::CUANTOS_ENCENDER (int i){
    tNodoArbolBin* nodo;
    nodo->posicion = i;
    int nApagado = 0;
    int resultado = lower_boundHelp(nodo,i,nApagado);
    std::cout <<resultado<<std::endl;
}