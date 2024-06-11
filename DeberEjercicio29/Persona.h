#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>

using namespace std;

class Persona{
private:
    std::string nombre;
    std::string ocupacion;
public:
    /*Persona(std::string, std::string);
    friend ::ostream& operator<<(std::ostream& os, const Persona& persona);
    bool operator==(const Persona& otra) const;*/
Persona(string nombre,string ocupacion):
nombre(nombre), ocupacion(ocupacion)
{}

friend std ::ostream& operator<<(ostream& os, const Persona& persona){
    os << persona.nombre<<" "<<persona.ocupacion;
    return os;
}

bool operator==( const Persona& persona) const{
    return nombre == persona.nombre && ocupacion == persona.ocupacion;
}
};