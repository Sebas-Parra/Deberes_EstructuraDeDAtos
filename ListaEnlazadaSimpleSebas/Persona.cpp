#include <iostream>
#include "Persona.h"
#include <string.h>

Persona::Persona(std::string nombre,std::string nombre2,std::string apellido,std::string cedula,std::string correo): 
nombre(nombre), nombre2(nombre2),apellido(apellido),cedula(cedula), correo(correo)
{
}

void Persona::setPersona(std::string nombre){
    this->nombre = nombre;
}

void Persona::setNombre2(std::string nombre2){
    this->nombre2 = nombre2;
}

void Persona::setApellido(std::string apellido){
    this->nombre2 = nombre2;
}

void Persona::setCedula(std::string cedula){
    this->cedula = cedula;
}

void Persona::setCorreo(std::string correo){
    this->correo = correo;
}

std::string Persona::getCorreo(){
    return correo;
}

std::string Persona::getCedula(){
    return cedula;
}

std::string Persona::getApellido(){
    return apellido;
}

std::string Persona::getNombre2(){
    return nombre2;
}

std::string Persona::getPersona(){
    return nombre;
}

bool Persona::operator==(const Persona& otra) const{
    return nombre == otra.nombre, nombre2 == otra.nombre2, apellido == otra.apellido, cedula == otra.cedula, correo == otra.correo;
}
std::ostream& operator<<(std::ostream& os, const Persona& persona){
    os << persona.nombre << persona.nombre2 << persona.apellido << persona.cedula << persona.correo;
    return os;
}

bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}