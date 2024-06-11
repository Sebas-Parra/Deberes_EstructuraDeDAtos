#include <iostream>
#include "Persona.h"
#include <string.h>

Persona::Persona(std::string nombre): nombre(nombre){}

void Persona::setPersona(std::string nombre){
    this->nombre = nombre;
}

std::string Persona::getPersona(){
    return nombre;
}

bool Persona::operator==(const Persona& otra) const{
    return nombre == otra.nombre;
}
std::ostream& operator<<(std::ostream& os, const Persona& persona){
    os << persona.nombre;
    return os;
}

bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}