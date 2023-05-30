#include <iostream>
#include <fstream>
#include <string>
#include "Secuancia_de_Nucleotidos.hpp"
using namespace std;

#include <iostream>

int main() {
    
    ifstream arch_entrada;
    arch_entrada.open("secuencias-nucleotidos.txt");
    if (!arch_entrada.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    int tam_secuencia;
    string secuencia_base;
    int num_secuencias;

    arch_entrada >> tam_secuencia;
    arch_entrada >> secuencia_base;
    arch_entrada >> num_secuencias;


    tListaNucleotidos lista = tListaNucleotidos(); //Inicializar la lista

    //Crear archivo de salida
    ofstream arch_salida;
    arch_salida.open("secuencias-reconstruidas.txt");
    if (!arch_salida.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    


    int modificaciones;
    string operacion;
    int posicion;
    char nucleotido;
    char letra;
    string lista_modificada;

    for(int i=0; i<num_secuencias; i++){
        arch_entrada >> modificaciones;
        //Recorrer el string secuencia_base y hacer inserciones en la lista

 
        for(int k=0;k<tam_secuencia;k++){
        letra = secuencia_base[k];
        lista.Inserciones(k,letra);
        }

        for(int j=0; j<modificaciones; j++){

            //Ver que operacion se desea realizar
            arch_entrada >> operacion;
            if(operacion == "INSERTAR"){
                arch_entrada >> posicion;
                arch_entrada >> nucleotido;
                lista.Inserciones(posicion,nucleotido);
            }else if(operacion == "INTERCAMBIAR"){
                arch_entrada >> posicion;
                arch_entrada >> nucleotido;
                lista.Intercambios(posicion,nucleotido);
            }else if(operacion == "BORRAR"){
                arch_entrada >> posicion;
                lista.Borrados(posicion);
            }

            
        }
        //Recorrer la lista y guardarla en un string
        for(int a=0; a<lista.tamaño(); a++){
            lista_modificada = lista_modificada + lista.DatoPosActual(a);
        }

        //Guardar la lista en el archivo
        arch_salida << lista_modificada << endl;

        lista_modificada = "";
        //Borrar los elementos de la lista para que quede vacia
        lista.BorrarDatos();
    }
    

    arch_salida.close();
    arch_entrada.close();
    return 0;
    
   /*
   tListaNucleotidos lista;

    // Prueba de los métodos de la lista
    
    lista.Inserciones(0, 'A');
    lista.Inserciones(1, 'C');
    lista.Inserciones(2, 'G');
    lista.Inserciones(3, 'T');

    std::cout << "Tamaño de la lista: " << lista.tamaño() << std::endl;

    std::cout << "Elementos de la lista: ";
    for (int i = 0; i < lista.tamaño(); i++) {
        cout << i << " ";
        std::cout << lista.DatoPosActual(i) << " ";
        cout << i << "  ";
    }
    std::cout << std::endl;

    lista.Borrados(2);

    std::cout << "Tamaño de la lista después del borrado: " << lista.tamaño() << std::endl;

    std::cout << "Elementos de la lista después del borrado: ";
    for (int i = 0; i < lista.tamaño(); i++) {
        std::cout << lista.DatoPosActual(i) << " ";
    }
    std::cout << std::endl;

    lista.Intercambios(0, 'G');

    std::cout << "Tamaño de la lista después del intercambio: " << lista.tamaño() << std::endl;

    std::cout << "Elementos de la lista después del intercambio: ";
    for (int i = 0; i < lista.tamaño(); i++) {
        std::cout << lista.DatoPosActual(i) << " ";
    }
    std::cout << std::endl;

    lista.BorrarDatos();

    std::cout << "Tamaño de la lista después de borrar todos los datos: " << lista.tamaño() << std::endl;

    return 0;
    */

}