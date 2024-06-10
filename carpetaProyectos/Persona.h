#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Persona{
public:
    Persona(string nombre1,string nombre2,string apellido, string cedula);
    string generarSecuenciaNombre();
    friend ::ostream& operator<<(std::ostream& os, const Persona& persona);
    string nombre1;
    string nombre2;
    string apellido;
    string cedula;
};