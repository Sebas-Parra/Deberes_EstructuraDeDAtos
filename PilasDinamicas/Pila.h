#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

class Pila {
private:
    Nodo* cima;

public:
    Pila();
    ~Pila();

    void apilar(int d);
    int desapilar();
    bool estaVacia() const;
    int obtenerCima() const;
    int encontrarMayor() const;  // Declaración del método encontrarMayor
    void mostrarElementos() const;  // Declaración del método mostrarElementos
};

#endif // PILA_H
