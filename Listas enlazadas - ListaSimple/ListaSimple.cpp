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
    ultimo = nullptr;
}

// ==================================

ListaSimple::~ListaSimple()
{
    Vaciar();
}

// ==================================

ListaSimple::ListaSimple(const ListaSimple& lista)
{
    *this = lista;
}

// ==================================

ListaSimple& ListaSimple::operator=(const ListaSimple& lista)
{
    if (this == &lista) return *this; // handle self assignment
    //assignment operator

    Vaciar();

    if(lista.EstaVacia()){
        return *this;
    }

    Elemento *visitado = lista.inicio;

    do{
        AgregarFinal(visitado->valor);
        visitado = visitado->siguiente;
    }while(visitado != nullptr);

    return *this;
}

// ==================================
// MÉTODOS PÚBLICOS
// ==================================

void ListaSimple::AgregarInicio(int valor)
{
    try{
        Elemento *nuevo = new Elemento(valor);

        nuevo->siguiente = inicio;

        inicio = nuevo;

        if(EstaVacia()){
            ultimo = nuevo;
        }

        ++numElem;
    }catch(const std::bad_alloc&){
        // throw ListaNoMemoria();
    }
}

// ==================================

void ListaSimple::AgregarFinal(int valor)
{
    try{
        Elemento *nuevo = new Elemento(valor);

        if(EstaVacia()){

            inicio = nuevo;
            ultimo = nuevo;

        }else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

        ++numElem;
    }catch(const std::bad_alloc&){
        // throw ListaNoMemoria();
    }
}

// ==================================

void ListaSimple::AgregarEnPosicion(int valor, int pos)
{
    if (pos < 0 || pos > numElem){
        //throw // Excepcion
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

        }catch(const std::bad_alloc&){
            //throw ListaNoMemoria();
        }


    }
}

// ==================================

void ListaSimple::EliminarInicio()
{
    if(EstaVacia()){
        //throw ListaVacia();
    }

    Elemento *porBorrar = inicio;


    if(numElem == 1){

        inicio = nullptr;
        ultimo = nullptr;

    }else{
        inicio = inicio->siguiente;
    }

    delete porBorrar;
    --numElem;
}

// ==================================

void ListaSimple::EliminarFinal()
{
    if(EstaVacia()){
        //throw ListaVacia();
    }

    Elemento *porBorrar = ultimo;

    if(numElem == 1){
        inicio = nullptr;
        ultimo = nullptr;
    }else{

        Elemento *anterior = inicio;

        for(int i = 2 ; i < numElem ; ++i){
            anterior = anterior->siguiente;
        }

        anterior->siguiente = nullptr;
        ultimo = anterior;

    }

    delete porBorrar;
    --numElem;

}

// ==================================

void ListaSimple::EliminarEnPosicion(int pos)
{
    if(pos < 0 || pos >= numElem){
        //throw // EXCEPCION
    }

    if(pos == 0){
        EliminarInicio();
    }else if(pos == numElem-1){
        EliminarFinal();
    }else{
        Elemento *anterior = inicio;

        for(int i = 1 ; i < pos ; ++i){
            anterior = anterior->siguiente;
        }

        Elemento *porBorrar = anterior->siguiente;
        anterior->siguiente = porBorrar->siguiente;
        delete porBorrar;
        --numElem;
    }
}

// ==================================

bool ListaSimple::BuscarValor(int valor) const
{
    Elemento *visitado = inicio;
    while(visitado != nullptr && visitado->valor != valor){
        visitado = visitado->siguiente;
    }

    return visitado != nullptr;
}

// ==================================

// Nos devuelve en que posicion esta cierto valor
// Ejemplo:
// x = [2,4,6,8,10]
// BuscarPosicion(6);
// Regresa 2

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

// ==================================

int ListaSimple::ObtenerPrimero() const
{
    if(EstaVacia()){
        //throw ListaVacia();
    }

    return inicio->valor;
}

// ==================================

int ListaSimple::ObtenerUltimo() const
{
    if(EstaVacia()){
        //throw ListaVacia();
    }

    return ultimo->valor;
}

// ==================================

int ListaSimple::ObtenerEnPosicion(int pos) const
{
    if(pos < 0 || pos >= numElem){
        //throw // Excepcion
    }

    Elemento *visitado = inicio;

    for(int i = 0 ; i < pos ; ++i){
        visitado = visitado->siguiente;
    }

    return visitado->valor;
}

// ==================================

bool ListaSimple::EstaVacia() const
{
    return numElem == 0;
}

// ==================================

int ListaSimple::ObtenerTam() const
{
    return numElem;
}

// ==================================

void ListaSimple::Vaciar()
{
    while(!EstaVacia()) EliminarInicio();
}

// ==================================

void ListaSimple::Imprimir() const
{
    if(EstaVacia()){
        std::cout << "[ ]" << std::endl;
        return;
    }

    Elemento *visitado = inicio;
    std::cout << "[ ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b ]";
}




ListaSimple::Elemento::Elemento(int v, Elemento *sig /*=nullptr*/) : valor(v), siguiente(sig){}
