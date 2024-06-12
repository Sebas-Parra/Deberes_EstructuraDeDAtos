#include "Pila.cpp"

using namespace std;
int main(){
    Pila pila1;
    pila1.crearPila();

    cout<<"\n\tEliminar elemtno cuando la pila esta vacia.";
    pila1.pop();

    cout<<"\n\tMostrar elementos cuando la pila esta vacia"<<endl;
    pila1.imprimir();

    cout<<"\n\tInsertamos elementos."<<endl;
    pila1.push(6);
    pila1.push(20);
    pila1.push(16);
    pila1.push(15);
    pila1.push(25);
    pila1.push(3);

    cout<<"\n";
    cout<<"\n\tEliminar elemento cuando la pila tiene datos.";
    pila1.pop();

    cout<<"\tMostrar elementos cuando la pila tiene datos. \n"<<endl;
    pila1.imprimir();

    return 0;
}