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
    Persona(std::string, std::string);
    friend ::ostream& operator<<(std::ostream& os, const Persona& persona);
    bool operator==(const Persona& otra) const;
};