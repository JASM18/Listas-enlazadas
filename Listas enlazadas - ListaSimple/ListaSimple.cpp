#include <iostream>

#include "ListaSimple.hpp"

using std::cout;
using std::endl;
using std::cerr;

// ==================================
// CONSTRUCTORES
// ==================================

ListaSimple::ListaSimple()
{

    numElem = 0;
    inicio = nullptr;
}

ListaSimple::~ListaSimple()
{
    Vaciar();
}

ListaSimple::ListaSimple(const ListaSimple& lista)
{
    *this = lista;
}

ListaSimple& ListaSimple::operator=(const ListaSimple& lista)
{
    //this->numElem = lista,numElem;
}

// ==================================
// MÉTODOS PÚBLICOS
// ==================================

void ListaSimple::ListaSimple::AgregarInicio(int valor){

}

void ListaSimple::AgregarFinal(int valor)
{

}

void ListaSimple::AgregarEnPosicion(int valor, int pos)
{
    if (pos < 0 || pos > numElem){
        throw "NOOOOOOO";
    }

    if(pos == 0){
        AgregarInicio(valor);
    }else if(pos == numElem){
        AgregarFinal(valor);
    }else{

        Elemento *anterior = inicio;
        for(int i = 1 ; i < pos ; ++i){
            anterior = anterior->siguiente;
        }

        try{
            Elemento *nuevo = new Elemento(valor, anterior->siguiente);
            anterior->siguiente = nuevo;
            ++numElem;

        }catch(...){
            cerr << "EL DIABLO NO HAY MEMORIA" << endl;
        }


    }
}

void ListaSimple::EliminarInicio()
{

}

void ListaSimple::EliminarFinal()
{
    if (EstaVacia()){
        cout << "esta vacia";
    }

    Elemento *porBorrar = ultimo;

    if (numElem);
}

void ListaSimple::EliminarEnPosicion()
{

}

int ListaSimple::BuscarValor(int pos) const
{

}

int ListaSimple::BuscarPosicion(int valor) const
{
    Elemento *visitado = inicio;
    int pos = 0;

    while (visitado != nullptr && visitado->valor != valor){
        visitado = visitado->siguiente;
        ++pos;
    }

    return visitado != nullptr ? pos : -1;

}

int ListaSimple::ObtenerPrimero() const{

}

int ListaSimple::ObtenerUltimo() const
{

}

int ListaSimple::ObtenerEnPosicion() const
{

}

bool ListaSimple::EstaVacia() const
{

}

int ListaSimple::ObtenerTam() const
{

}

void ListaSimple::Vaciar()
{

}

void ListaSimple::Imprimir() const
{

}




ListaSimple::Elemento::Elemento(int v, Elemento *sig /*=nullptr*/) : valor(v), siguiente(sig){}
