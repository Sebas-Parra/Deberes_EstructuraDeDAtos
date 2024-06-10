/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
template<typename T>
class Nodo {
private:
    T persona;
    Nodo<T>* siguiente;
public:
    Nodo(T);
    void setDato(T);
    T getDato();
    void setSiguiente(Nodo<T>*);
    Nodo<T>* getSiguiente();
    friend class ListaSimples;
};

