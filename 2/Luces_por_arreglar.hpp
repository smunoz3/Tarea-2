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
~tABB();
void BorrarArbol(tNodoArbolBin* nodo);
void insert(tNodoArbolBin x);       //bien
tNodoArbolBin* insertHelp(tNodoArbolBin* nodo, int valor);
bool find(tNodoArbolBin x);     //bien
tNodoArbolBin* findHelp(tNodoArbolBin *nodo, tNodoArbolBin item);
int lower_bound(tNodoArbolBin x);
int lower_boundHelp(tNodoArbolBin* nodo, int valor);
/* void ENCENDER (int i);
void CUANTOS_ENCENDER (int i);
void PARAR_PROGRAMA(); */
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
    if (nodo != nullptr) {
        BorrarArbol(nodo->izq);
        BorrarArbol(nodo->der);
        delete nodo;
    }
}

void tABB::insert(tNodoArbolBin x){
    if (find(x)){
        std::cout<<"Elemento ya ingresado"<<std::endl;
        return;
    }
    raiz = insertHelp(raiz, x.posicion);
}
tNodoArbolBin* tABB::insertHelp(tNodoArbolBin* nodo, int valor){
    if (nodo == NULL) {
        tNodoArbolBin* nuevoNodo = new tNodoArbolBin();         //new recordar borrar
        nuevoNodo->posicion = valor;
        nuevoNodo->encendido = false;
        nuevoNodo->der = NULL;
        nuevoNodo->izq = NULL;
        return nuevoNodo;  
    }
    if (valor < nodo->posicion) {
        nodo->izq = insertHelp(nodo->izq, valor);
    } else if (valor > nodo->posicion) {
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
//
tNodoArbolBin* tABB::findHelp(tNodoArbolBin *nodo, tNodoArbolBin item) {
    if (nodo == NULL) { // item no está en el ABB
        return NULL;
    } 
    if (nodo->posicion == item.posicion){
        return nodo; // item encontrado
    }
    if (item.posicion < nodo->posicion){
        return findHelp(nodo->izq, item);
    }
    else{
        return findHelp(nodo->der, item);
    }
}

/* int tABB::lower_bound(tNodoArbolBin x){
    int contador = 0;
    return lower_boundHelp(raiz, x.posicion,contador); // revisar que retorna
} */

int tABB::lower_bound(tNodoArbolBin x){
    return lower_boundHelp(raiz, x.posicion);
}
int tABB::lower_boundHelp(tNodoArbolBin* nodo, int valor){
    if (nodo == NULL){ // no encontro
    std::cout<<"no encontro"<<std::endl;
        return -1;
    }
    if (nodo->posicion == valor){
        std::cout<<"encontro"<<std::endl;
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



/* int tABB::lower_boundHelp(tNodoArbolBin* nodo, int valor, int& contador){
    contador ++;
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
} */

/* void tABB::ENCENDER(int i){
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
    if (resultado != -1){
        
    }
    else {
        std::cout <<resultado<<std::endl;
    }
}

void tABB::PARAR_PROGRAMA(){
    std::remove("system");
} */