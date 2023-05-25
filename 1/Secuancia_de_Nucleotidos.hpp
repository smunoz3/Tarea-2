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
    void Inserciones(int i, char n);
    void Borrados(int i);
    void Intercambios(int i, char n);
};

tListaNucleotidos::tListaNucleotidos() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
}

tListaNucleotidos::~tListaNucleotidos() {
    // Aquí puedes realizar las tareas de limpieza necesarias para liberar recursos
}

void tListaNucleotidos::Inserciones(int i, char n) {
    // Implementación del método Inserciones
    if (i < 0 || i > listSize){
        return ;
    }
    curr = head;
    for(int j=0; j < i; j++){
        curr = curr->sig;
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
    // Implementación del método Borrados
    return;
}

void tListaNucleotidos::Intercambios(int i, char n) {
    // Implementación del método Intercambios
    return;
}