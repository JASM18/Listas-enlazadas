#include <iostream>

#include "ListaSimple.hpp"

using namespace std;

int main()
{
    ListaSimple lista;

    lista.Imprimir();

    for(int i = 0 ; i < 15 ; ++i){
        lista.AgregarFinal(i);
        lista.Imprimir();
    }

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Eliminando el ultimo elemento " << lista.ObtenerUltimo() << endl;
    lista.EliminarFinal();
    lista.Imprimir();

    cout << endl;

    cout << "Eliminando el primer elemento " << lista.ObtenerPrimero() << endl;
    lista.EliminarInicio();
    lista.Imprimir();

    ListaSimple lista2;

    cout << "Copiando parametros..." << endl;
    lista2 = lista;

    cout << "Imprimiendo lista 2..." << endl;
    lista2.Imprimir();

    system("Pause");
    return 0;
}
