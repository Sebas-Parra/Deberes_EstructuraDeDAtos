#include "Pila.h"
#include <iostream>
#include <stdexcept>
#include <limits.h>

Pila::Pila() : cima(nullptr) {}

Pila::~Pila() {
    while (!estaVacia()) {
        desapilar();
    }
}

void Pila::apilar(int d) {
    Nodo* nuevoNodo = new Nodo(d);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    std::cout << "Dato " << d << " ingresado correctamente\n";
}

int Pila::desapilar() {
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }
    int dato = cima->dato;
    Nodo* nodoAEliminar = cima;
    cima = cima->siguiente;
    delete nodoAEliminar;
    std::cout << "Dato eliminado correctamente\n";
    return dato;
}

bool Pila::estaVacia() const {
    return cima == nullptr;
}

int Pila::obtenerCima() const {
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }
    return cima->dato;
}

int Pila::encontrarMayor() const {
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }

    int mayor = INT_MIN;
    Nodo* actual = cima;

    while (actual != nullptr) {
        if (actual->dato > mayor) {
            mayor = actual->dato;
        }
        actual = actual->siguiente;
    }

    return mayor;
}

void Pila::mostrarElementos() const {
    if (estaVacia()) {
        std::cout << "La pila está vacía\n";
        return;
    }

    Nodo* actual = cima;
    while (actual != nullptr) {
        std::cout << "|       " << actual->dato << "      |\n";
        std::cout << "------------------\n";
        actual = actual->siguiente;
    }
}
