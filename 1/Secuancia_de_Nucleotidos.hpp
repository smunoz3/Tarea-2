#include <iostream>
#include <string>

struct tNodo {
    char nucleotido;
    tNodo* sig;
};

class tListaNucleotidos {
private:
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    int listSize;
    int pos;

public:
    tListaNucleotidos();
    ~tListaNucleotidos();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    void moveToPos(int i);
    void Inserciones(int i, char n);
    void Borrados(int i);
    void Intercambios(int i, char n);
    void BorrarDatos();
    char DatoPosActual(int i);
    int tamaño();
};

tListaNucleotidos::tListaNucleotidos() {
    //Constructor de la lista de nucleotidos
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
}

tListaNucleotidos::~tListaNucleotidos() {
    //Este es el destructor de la lista de nucleotidos
    curr = head;
    while (curr != NULL) {
        tNodo* next = curr->sig;
        delete curr;
        curr = next;
    }
}

void tListaNucleotidos::moveToStart(){
    //Moverse al inicio de la lista
    curr = head;
    pos = 0;
    return ;
}

void tListaNucleotidos::moveToEnd(){
    //Moverse al final de la lista
    curr = tail;
    pos = listSize;
    return;
}

void tListaNucleotidos::prev(){
    //Moverse a la posición previa
    tNodo* temp;
    if (curr == head){
        return;
    }
    temp = head;
    while (temp->sig != curr){
        temp = temp->sig;
    }
    curr = temp;
    pos--;
    return;
}

void tListaNucleotidos::next(){
    //Moverse a la siguiente posición
    if (curr != tail){
        curr = curr->sig;
        pos++;
    }
    return;
}

void tListaNucleotidos::moveToPos(int i) {
    // Mover a una posición
    int j;
    if (i < 0 || i > listSize){
        return ;
    }
    curr = head;
    pos = 0;
    if (i==0){
        return;
    } ;
    for (j = 0; j < i; j++ ){
        curr = curr->sig;
        pos++;
    }
    return;
}

void tListaNucleotidos::Inserciones(int i, char n) {
    // Implementación del método Inserciones
    if (i < 0 || i > listSize) {
        return;
    }
    if (i == 0) {
        tNodo* aux = new tNodo;
        aux->nucleotido = n;
        aux->sig = head;
        head = aux;
        if (listSize == 0) {
            tail = aux;
        }
        listSize++;
        return;
    }
    moveToPos(i-1);
    tNodo* aux = new tNodo;
    aux->nucleotido = n;
    aux->sig = curr->sig;
    curr->sig = aux;
    if (curr->sig == NULL) {
        tail = aux;
    }
    listSize++;
    return;
}

void tListaNucleotidos::Borrados(int i) {
    //Borrar el nucleotido en la posición i
    if (i < 0 || i >= listSize) {
        return;
    }
    moveToPos(i - 1);
    tNodo* nodoAnterior = curr;
    if (nodoAnterior->sig == NULL) {
        return;
    }
    tNodo* nodoBorrado = nodoAnterior->sig;
    nodoAnterior->sig = nodoBorrado->sig;
    if (nodoBorrado == tail) {
        tail = nodoAnterior;
    }
    delete nodoBorrado;
    listSize--;
    return;
}

void tListaNucleotidos::Intercambios(int i, char n) {
    //Intercambiar el nucleotido de la posición i por el nucleotido n
    if (i < 0 || i >= listSize) {
        return;
    }
    moveToPos(i);
    if (curr == NULL) {
        return;
    }
    curr->nucleotido = n;
    return;
}

void tListaNucleotidos::BorrarDatos(){
    curr = head;
    while (curr != nullptr) {
        tNodo* next = curr->sig;
        delete curr;
        curr = next;
    }
    head = tail = curr = new tNodo; // Reinicializar los punteros
    listSize = 0;
    pos = 0;
}

char tListaNucleotidos::DatoPosActual(int i){
    moveToPos(i);
    return curr->nucleotido;
}

int tListaNucleotidos::tamaño(){
    return listSize;
}