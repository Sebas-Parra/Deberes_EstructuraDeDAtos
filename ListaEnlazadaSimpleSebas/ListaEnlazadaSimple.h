#pragma once
#include "Nodo.h"
#include "Persona.h"
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class ListaEnlazadaSimple{
private:
    Nodo<Persona>* cabeza;
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
ListaEnlazadaSimple() {
    cabeza = nullptr;
}

~ListaEnlazadaSimple() {
    Nodo<Persona>* actual = cabeza;
    Nodo<Persona>* siguiente;
    while (actual != nullptr) {
        siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

void insertar(Persona dato) {
    Nodo<Persona>* nuevoNodo = new Nodo<Persona>(dato);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo<Persona>* temp = cabeza;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
    }
}

    std::string generarCorreo(const std::string& nombre, const std::string& nombre2, const std::string& apellido,const int cont) {
        std::string correoBase;
        correoBase += tolower(nombre[0]);
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

std::string encryptCesar(Persona per) {
    std::string password = "";

    char ultimaLetraApellido = per.getApellido().back();

    char primeraLetraNombre1 = per.getPersona().front();

    char ultimaLetraNombre2 = per.getNombre2().back();

    int shift = 1;

    for (char c : std::string(1, ultimaLetraApellido) + primeraLetraNombre1 + ultimaLetraNombre2) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            char encryptedChar = (c - base + shift) % 26 + base;
            password += encryptedChar;
        } else {
            password += c;
        }
    }

    // Agregar las letras restantes del apellido al password en orden inverso y cifrarlas
    for (int i = per.getApellido().size() - 2; i >= 0; --i) {
        char c = per.getApellido()[i];
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            char encryptedChar = (c - base + shift) % 26 + base;
            password += encryptedChar;
        } else {
            password += c;
        }
    }

    return password;
}


std::string generatePassword(Persona per) {
    std::string password = "";

    char ultimaLetraApellido = per.getApellido().back();

    char primeraLetraNombre1 = per.getPersona().front();

    char ultimaLetraNombre2 = per.getNombre2().back();

    password += ultimaLetraApellido;
    password += primeraLetraNombre1;
    password += ultimaLetraNombre2;

    for (int i = per.getApellido().size() - 2; i >= 0; --i) {
        password += per.getApellido()[i];
    }

    return password;
}

void mostrar() const{
    Nodo<Persona>* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->getPer() << " -> ";
        temp = temp->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}
};