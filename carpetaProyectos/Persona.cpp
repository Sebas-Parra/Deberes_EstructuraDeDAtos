#include <string.h>
#include "Persona.h"
#include <vector>

using namespace std;
Persona::Persona(string nombre1,string nombre2,string apellido, string cedula, string correo):
nombre1(nombre1), nombre2(nombre2), apellido(apellido), cedula(cedula), correo(correo)
{
}

string Persona ::generarSecuenciaNombre(){
    string str = "";
    str += nombre1.at(0);
    str += nombre2.at(0);
    str.append(apellido);
    return str;
}

std ::ostream& operator<<(std::ostream& os, const Persona& persona){
    os << persona.nombre1<<" "<<persona.nombre2<<" "<<persona.apellido<< " "<<persona.cedula<< " "<<persona.correo;
    return os;
}