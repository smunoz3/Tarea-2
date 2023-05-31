#include <iostream>

struct tNodoArbolBin{
int posicion;
//bool encendido;
tNodoArbolBin* izq;
tNodoArbolBin* der;
};

class tABB {
private:
tNodoArbolBin *raiz; // puntero al nodo raíz del ABB
int nElems; // cantidad de elementos en el ABB

public:
tABB();
~tABB();
void BorrarArbol(tNodoArbolBin* nodo);
void insert(tNodoArbolBin x);       //bien
tNodoArbolBin* insertHelp(tNodoArbolBin* nodo, int valor);
bool find(tNodoArbolBin x);     //bien
tNodoArbolBin* findHelp(tNodoArbolBin *nodo, tNodoArbolBin item);
int lower_bound(tNodoArbolBin x);
int lower_boundHelp(tNodoArbolBin* nodo, int valor);
};

tABB::tABB(){ //Constructor
raiz = NULL;
nElems = 0;
}

// Destructor
tABB::~tABB() {
    // Llamamos a una función auxiliar para liberar la memoria recursivamente
    BorrarArbol(raiz);
}

//Con esto se borra el arbol recursivamente
void tABB::BorrarArbol(tNodoArbolBin* nodo) {
    if (nodo != NULL) {
        BorrarArbol(nodo->izq);
        BorrarArbol(nodo->der);
        delete nodo;
    }
}

void tABB::insert(tNodoArbolBin x) {
    raiz = insertHelp(raiz, x.posicion);
    nElems = x.posicion + 1;
}

tNodoArbolBin* tABB::insertHelp(tNodoArbolBin* nodo, int valor) {
    if (nodo == NULL) {
        // Creamos un nuevo nodo y lo retornamos como el nodo actual
        tNodoArbolBin* nuevoNodo = new tNodoArbolBin;
        nuevoNodo->posicion = valor;
        //nuevoNodo->encendido = false;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        return nuevoNodo;
    }

    if (valor < nodo->posicion) {
        // El valor es menor, por lo tanto, debe ir en el subárbol izquierdo
        nodo->izq = insertHelp(nodo->izq, valor);
    } else if (valor > nodo->posicion) {
        // El valor es mayor, por lo tanto, debe ir en el subárbol derecho
        nodo->der = insertHelp(nodo->der, valor);
    }
    return nodo;
}


bool tABB::find(tNodoArbolBin item) {
    if (findHelp(raiz, item)!=NULL){
        return true;
    }
    return false;
}

tNodoArbolBin* tABB::findHelp(tNodoArbolBin *raiz, tNodoArbolBin item) {
    if (raiz == NULL) { // item no está en el ABB
        return NULL;
    } 
    if (raiz->posicion == item.posicion){
        return raiz; // item encontrado
    }
    if (item.posicion < raiz->posicion){
        return findHelp(raiz->izq, item);
    }
    else{
        return findHelp(raiz->der, item);
    }
}

int tABB::lower_bound(tNodoArbolBin x){
    return lower_boundHelp(raiz, x.posicion);
}
int tABB::lower_boundHelp(tNodoArbolBin* nodo, int valor){
    if (nodo == NULL){ // no encontro
        return -1;
    }
    if (nodo->posicion <= valor){
        return nodo->posicion;
    }
    if (valor < nodo->posicion) {
        return lower_boundHelp(nodo->izq, valor);
    } 
    if (valor > nodo->posicion) {
        return lower_boundHelp(nodo->der, valor);
    }
    return nodo->posicion;
}

void ENCENDER(tABB& treeBB,int i, int& postes_encendidos){
    tNodoArbolBin nodo;
    nodo.posicion = i;
    if (!treeBB.find(nodo)){
                treeBB.insert(nodo);
                postes_encendidos++;
            }
}

void CUANTOS_ENCENDER(tABB& treeBB, int i, int& postes_encendidos) {
    tNodoArbolBin nodo;
    nodo.posicion = i;
    int resultado = 0;
    if (treeBB.find(nodo)) {
        std::cout << resultado << std::endl;
        return;
    }
    int menor_o_igual = treeBB.lower_bound(nodo);
    if (menor_o_igual != -1) {
        resultado = i - menor_o_igual;
    } else {
        resultado = i + 1 - postes_encendidos;
    }
    std::cout << resultado << std::endl;
}

void PARAR_PROGRAMA(int postes_encendidos) {
    std::cout << postes_encendidos << std::endl;
}