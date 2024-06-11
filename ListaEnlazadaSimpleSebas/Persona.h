#pragma once
#include <iostream>

using namespace std;

class Persona{
private:
    string nombre;
public:
    Persona(string);
    void setPersona(string);
    string getPersona();
    bool operator==(const Persona& otra) const;
    bool operator!=(const Persona& otra) const;
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);
};

