/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "ListasSimples.h"
#include "Persona.h"
#include "Nodo.h"

using namespace std;

inline ListaSimples::ListaSimples() {
    cabeza = NULL;
}


inline void ListaSimples::Insertar(Persona per) {
    /*Nodo<Persona>* nuevo = new Nodo(per);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo<Persona>* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }*/
   Nodo<Persona>* nuevo = new Nodo<Persona>(per);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo<Persona>* aux = cabeza;
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}
/*
inline void ListaSimples::Buscar(Persona per) {
    Nodo<Persona>* aux = cabeza;
    while (aux != NULL) {
        if (aux->getDato() == per) {
            cout << "El dato " << per << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << per << " no se encuentra en la lista" << endl;
}

inline void ListaSimples::Eliminar(Persona per) {
    Nodo<Persona>* aux = cabeza;
    Nodo<Persona>* anterior = NULL;
    while (aux != NULL) {
        if (aux->getDato() == per) {
            if (anterior == NULL) {
                cabeza = aux->getSiguiente();
            }
            else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            cout << "El dato " << per << " se ha eliminado de la lista" << endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    cout << "El dato " << per << " no se encuentra en la lista" << endl;
}*/

inline void ListaSimples::Mostrar() {
    Nodo<Persona>* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}
