/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Nodo.h"

using namespace std;
template<typename T>
Nodo<T>::Nodo(T per) {
    persona = per;
    siguiente = NULL;
}
template<typename T>
inline void Nodo<T>::setDato(T per) {
    persona = per;
}
template<typename T>
T Nodo<T>::getDato() {
    return persona;
}
template<typename T>
 void Nodo<T>::setSiguiente(Nodo<T>* _siguiente) {
    siguiente = _siguiente;
}
template<typename T>
 Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

