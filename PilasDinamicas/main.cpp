#include <iostream>
#include "Pila.h"

int main() {
    Pila pila;

    std::cout << "Eliminar elemento cuando la pila está vacía.\n";
    try {
        pila.desapilar();
    } catch (const std::out_of_range& e) {
        std::cout << "La pila está vacía\n\n";
    }

    std::cout << "Mostrar elementos cuando la pila está vacía.\n\n";
    pila.mostrarElementos();

    std::cout << "\nInsertamos elementos.\n";
    pila.apilar(6);
    pila.apilar(20);
    pila.apilar(16);
    pila.apilar(15);
    pila.apilar(25);
    pila.apilar(3);

    std::cout << "\nEliminar elemento cuando la pila tiene datos.\n";
    pila.desapilar();

    std::cout << "Mostrar elementos cuando la pila tiene datos.\n\n";
    pila.mostrarElementos();

    std::cout << "\nEncontrar el mayor elemento en la pila.\n";
    try {
        int mayor = pila.encontrarMayor();
        std::cout << "El mayor elemento en la pila es: " << mayor << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "La pila está vacía\n";
    }

    return 0;
}
