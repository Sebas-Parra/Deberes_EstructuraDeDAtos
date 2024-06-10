#include <iostream>
#include "ListaEnlazadaDoble.h"
#include "Persona.cpp"

using namespace std;
bool esEntero(string linea);
bool validarCedula(string cedula);

int main() {
    ListaEnlazadaDoble* lista = new ListaEnlazadaDoble();
    int opcion, dato;
    string linea, i, b, e, m, s;
    bool rep = true;
    bool repite = true;
    bool repetir = true;
    string nombre1;
    string nombre2;
    string apellido;
    string cedula;
    bool validado = false;

    do {
        system("cls");
        cout << "***********Listas Dobles***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Salir" << endl;
        do {
            cout << "Opcion: ";
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion >  3 || opcion < 1) {
                    repetir = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
                
            }
        } while (repite);
        opcion = atoi(linea.c_str());
        
        switch (opcion) {

        case 1:
            
            cout<<"\nIngrese el primer nombre: "<<endl;
            cin>>nombre1;
            cout<<"\nIngrese el segundo nombre: "<<endl;
            cin>>nombre2;
            cout<<"\nIngrese el apellido: "<<endl;
            cin>>apellido;
            
            do{
                cout<<"\nIngrese la cedula: "<<endl;
                cin>>cedula;
            
                if(validarCedula(cedula)){
                    validado = true;
                }else {  
                    validado = false;
                }
            }while(!validado);
            
            lista->insertar(Persona(nombre1,nombre2,apellido,cedula,""));

            break;
        case 2:
            lista->mostrar();
            break;
        }
        system("pause");
    } while (opcion != 3);
    return 0;
}

bool esEntero(string linea) {
    bool esEntero = true;
    int longitud = linea.size();

    if (longitud == 0) {
        esEntero = false;
    }
    else if (longitud == 1 && !isdigit(linea[0])) {
        esEntero = false;
    }
    else {
        int indice = 0;
        if (linea[0] == '+' || linea[0] == '-') {
            indice = 1;
        }
        else {
            indice = 0;
        }

        while (indice < longitud) {
            if (!isdigit(linea[indice])) {
                esEntero = false;
                break;
            }
            indice++;
        }
    }


    return esEntero;
}

bool validarCedula(string cedula) {
    if (cedula.length() != 10) {
        cout<<"Cedula rechazada";
        return false;
    }

    for (char c : cedula) {
        if (!isdigit(c)) {
            cout<<"Cedula rechazada";
            return false;
        }
    }

    int provincia = stoi(cedula.substr(0, 2));
    if (provincia < 1 || provincia > 24) {
        cout<<"Cedula rechazada";
        return false;
    }

    int verificador = cedula[9] - '0';
    int suma = 0;
    for (int i = 0; i < 9; ++i) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        suma += digito;
    }

    int TOTAL = ((suma / 10) + 1) * 10;
    if ((TOTAL - suma == verificador) || (verificador == 0 && TOTAL - suma == 10)) {
        cout<<"Cedula aceptada";
        return true;
    }

    return false;
    cout<<"Cedula rechazada";
}
