#pragma once
#include <iostream>

using namespace std;

class Persona{
private:
    string nombre;
    string nombre2;
    string apellido;
    string cedula;
    string correo;
public:
    Persona(string,string,string,string,string);
    void setPersona(string);
    string getPersona();
    void setNombre2(string);
    string getNombre2();
    void setApellido(string);
    string getApellido();
    void setCedula(string);
    string getCedula();
    void setCorreo(string);
    string getCorreo();
    bool operator==(const Persona& otra) const;
    bool operator!=(const Persona& otra) const;
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);
};

