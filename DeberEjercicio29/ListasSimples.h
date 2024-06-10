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
#include "Nodo.h"
#include "Persona.h"

using namespace std;

class ListaSimples {

private:
    Nodo<Persona>* cabeza;
public:
    ListaSimples();
    void Insertar(Persona);
    void Buscar(Persona);
    void Eliminar(Persona);
    void Mostrar();
};

