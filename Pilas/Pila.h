#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class Pila{
private:
    int* pila;
    int ultimo;
public:
    void crearPila();
    bool pilaVacia();
    void push(int);
    void pop();
    void imprimir();
    int getUltimo();
};