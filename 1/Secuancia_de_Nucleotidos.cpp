#include <iostream>
#include <fstream>
#include "Secuancia_de_Nucleotidos.hpp"
using namespace std;

#include <iostream>

int main() {
    int i;
    char n;
    tListaNucleotidos lista;
    ifstream fp;
    fp.open("secuencias_nucleotidos.txt");
    if (!fp.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    int longSec, cantSec;
    string Sec, operacion;
    if (operacion == "INSERTAR"){
        lista.Inserciones(i, n);
    }
    else if (operacion == "BORRAR"){
        lista.Borrados(i);
    }
    else if (operacion == "INTERCAMBIAR"){
        lista.Intercambios(i, n);
    }


    return 0;
}