#include <iostream>

using namespace std;
bool validarCedula(string cedula);

int main(){
    string cedula;
    //Se pide al usuario que digite la cedula
    cout<<"Digite la cedula: "<<endl;
    cin>>cedula;
    //Se verifica que la cedula es rechazada o aceptada
    validarCedula(cedula);

    return 0;
 };

 //Validador de cedula
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