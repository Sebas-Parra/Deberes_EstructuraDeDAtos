#include <iostream>
#include <string>
#include <cctype>
#include "Persona.h"

using namespace std;
Persona::Persona(string nombre,string ocupacion):
nombre(nombre), ocupacion(ocupacion)
{}

std ::ostream& operator<<(ostream& os, const Persona& persona){
    os << persona.nombre<<" "<<persona.ocupacion;
    return os;
}

bool Persona::operator==( const Persona& persona) const{
    return nombre == persona.nombre && ocupacion == persona.ocupacion;
}
