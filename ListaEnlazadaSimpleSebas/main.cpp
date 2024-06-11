#include "ListaEnlazadaSimple.h"
#include "Persona.cpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

bool esEntero(string);

int main() {
    ListaEnlazadaSimple* lista = new ListaEnlazadaSimple();
    int opcion;
    string linea, i, b, e, m, s;
    bool rep = true;
    bool repite = true;
    bool repetir = true;
    string nombre;

    do {
        system("cls");
        cout << "***********Listas Simples***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        do {
          
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 5 || opcion < 1) {
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
            cout<<"Ingrese el nombre: "<<endl;
            cin>>nombre;
            lista->insertar(Persona(nombre));
            break;
        case 2:
        lista->mostrar();
            break; 
        }
        system("pause");
    } while (opcion != 2);
    return 0;
}

//Fucion para validar
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