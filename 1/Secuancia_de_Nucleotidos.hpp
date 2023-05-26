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
    ~tListaNucleotidos(){};
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    void moveToPos(int i);
    void Inserciones(int i, char n);
    void Borrados(int i);
    void Intercambios(int i, char n);
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
    while (curr != nullptr) {
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

void tListaNucleotidos::Inserciones(int i, char n) {
    if (i < 0 || i > listSize) {
        return;
    }
    moveToPos(i);
    tNodo* aux = new tNodo;
    aux->nucleotido = n;
    aux->sig = curr->sig;
    curr->sig = aux;
    if (curr->sig == nullptr) {
        tail = aux;
    }
    listSize++;
    return;
}

void tListaNucleotidos::Inserciones(int i, char n) {
    // Implementación del método Inserciones
    if (i < 0 || i > listSize){
        return ;
    }
    
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->nucleotido = n;
    curr->sig->sig = aux;
    if (curr == tail){
        tail = curr->sig;
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
    if (nodoAnterior->sig == nullptr) {
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
    if (curr == nullptr) {
        return;
    }
    curr->nucleotido = n;
    return;
}