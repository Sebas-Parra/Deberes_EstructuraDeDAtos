#pragma once
#include "Nodo.h"
#include "Persona.h"
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class ListaEnlazadaDoble {
private:
    NodoDoble<Persona>* cabeza;
    std::vector<std::string>leerCorreos() {
        std::vector<std::string> correos;
        std::ifstream archivo("correos.txt");
        std::string linea;
        while (std::getline(archivo, linea)) {
            correos.push_back(linea);
        }
        archivo.close();
        return correos;
    }

public:
    ListaEnlazadaDoble() : cabeza(nullptr) {}

    ~ListaEnlazadaDoble() {
        while (cabeza) {
            NodoDoble<Persona>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
     void insertar(Persona dato) {
        /*NodoDoble<Persona>* nuevo = new NodoDoble<Persona>(dato);
        nuevo->siguiente = cabeza;
        if (cabeza) cabeza->anterior = nuevo;
        cabeza = nuevo;
        generarCorreo(dato.nombre1, dato.nombre2, dato.apellido);*/
        
        /*std::string correo = generarCorreo(dato.nombre1, dato.nombre2, dato.apellido);
        dato.correo = correo;
        NodoDoble<Persona>* nuevo = new NodoDoble<Persona>(dato);
        nuevo->siguiente = cabeza;
        if (cabeza) cabeza->anterior = nuevo;
        cabeza = nuevo;

    // Guardar los datos en el archivo "datos.txt"
    std::ofstream archivo("correos.txt", std::ios::app); // Abre el archivo en modo de adjuntar (append)
    if (archivo.is_open()) { // Verifica si el archivo se pudo abrir correctamente
        archivo << dato.nombre1 << " " << dato.nombre2 << " " << dato.apellido << " " << dato.cedula << " " << dato.correo << std::endl;
        archivo.close(); // Cierra el archivo
        std::cout << "Los datos se han guardado en datos.txt." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo datos.txt." << std::endl;
    }*/
   int cont = 1;
   std::string correo = generarCorreo(dato.nombre1, dato.nombre2, dato.apellido, cont);
    dato.correo = correo;
    // Verificar si el correo ya existe en la lista
    NodoDoble<Persona>* temp = cabeza;
    
    while (temp) {
        if (temp->dato.correo == correo) {
            correo = generarCorreo(dato.nombre1, dato.nombre2, dato.apellido, cont++);
            dato.correo = correo;
            temp = cabeza; // Reiniciar la búsqueda desde el principio
            continue;
        }
        temp = temp->siguiente;
    }

    // Continuar con la inserción
    NodoDoble<Persona>* nuevo = new NodoDoble<Persona>(dato);
    nuevo->siguiente = cabeza;
    if (cabeza) cabeza->anterior = nuevo;
    cabeza = nuevo;

    // Guardar los datos en el archivo "datos.txt"
    std::ofstream archivo("correos.txt", std::ios::app); // Abre el archivo en modo de adjuntar (append)
    if (archivo.is_open()) { // Verifica si el archivo se pudo abrir correctamente
        archivo << dato.nombre1 << " " << dato.nombre2 << " " << dato.apellido << " " << dato.cedula << " " << dato.correo << std::endl;
        archivo.close(); // Cierra el archivo
        std::cout << "Los datos se han guardado en datos.txt." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo datos.txt." << std::endl;
    }
    }

    void recorrer(std::function<void(Persona)> callback) {
        NodoDoble<Persona>* temp = cabeza;
        while (temp) {
            callback(temp->dato);
            temp = temp->siguiente;
        }
    }
    void mostrar(){
        recorrer([](Persona dato) {
            std::cout << dato << " ";
        });
        std::cout << std::endl; 
    }

    
    std::string generarCorreo(const std::string& nombre1, const std::string& nombre2, const std::string& apellido,const int cont) {
        std::string correoBase;
        correoBase += tolower(nombre1[0]);
        correoBase += tolower(nombre2[0]);
        correoBase += apellido;

        std::string correoCompleto = correoBase + "@espe.edu.ec";
        std::vector<std::string> correosExistentes = leerCorreos();

        int contador = 1;
        while (std::find(correosExistentes.begin(), correosExistentes.end(), correoCompleto) != correosExistentes.end()) {
            correoCompleto = correoBase + std::to_string(contador) + "@espe.edu.ec";
            contador++;
        }

        guardarCorreo(correoCompleto);
        return correoCompleto;
    }

    void guardarCorreo(const std::string& correo) {
        std::ofstream archivo("correos.txt", std::ios::app);
        archivo << correo << std::endl;
        archivo.close();
    }
};