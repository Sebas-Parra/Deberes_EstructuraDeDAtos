#pragma once
#include "Nodo.h"
#include <iostream>
#include "Persona.h"

using namespace std;

class ListaEnlazadaSimple{
private:
    Nodo<Persona>* cabeza;
public:
ListaEnlazadaSimple() {
    cabeza = nullptr;
}

~ListaEnlazadaSimple() {
    Nodo<Persona>* actual = cabeza;
    Nodo<Persona>* siguiente;
    while (actual != nullptr) {
        siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

void insertar(Persona valor) {
    Nodo<Persona>* nuevoNodo = new Nodo<Persona>(valor);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo<Persona>* temp = cabeza;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
    }
}

/*void eliminar(Persona valor) {
    if (cabeza == nullptr) return;

    if (cabeza->getPer() == valor) {
        Nodo<Persona>* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
        return;
    }

    Nodo<Persona>* temp = cabeza;
    while (temp->getSiguiente() != nullptr && temp->getSiguiente()->getPer() != valor) {
        temp = temp->getSiguiente();
    }

    if (temp->getSiguiente() == nullptr) return;

    Nodo<Persona>* nodoAEliminar = temp->getSiguiente();
    temp->setSiguiente(temp->getSiguiente()->getSiguiente());
    delete nodoAEliminar;
}*/

void mostrar() const{
    Nodo<Persona>* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->getPer() << " -> ";
        temp = temp->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}
};