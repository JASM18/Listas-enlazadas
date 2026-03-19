#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

//***********************************
// CONSTRUCTORES
//***********************************

template <typename T>
ListaSimple<T>::ListaSimple()
{

    numElem = 0;
    inicio = nullptr;
    ultimo = nullptr;
}

//***********************************

template <typename T>
ListaSimple<T>::~ListaSimple()
{
    Vaciar();
}

//***********************************

template <typename T>
ListaSimple<T>::ListaSimple(const ListaSimple& lista)
{
    *this = lista;
}

//***********************************

template <typename T>
ListaSimple<T> &ListaSimple<T>::operator=(const ListaSimple& lista)
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

//***********************************
// MÉTODOS PÚBLICOS
//***********************************

template <typename T>
void ListaSimple<T>::AgregarInicio(T valor)
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
        throw ListaNoMemoria();
    }
}

//***********************************

template <typename T>
void ListaSimple<T>::AgregarFinal(T valor)
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
        throw ListaNoMemoria();
    }
}

//***********************************

template <typename T>
void ListaSimple<T>::AgregarEnPosicion(T valor, int pos)
{
    if (pos < 0 || pos > numElem){
        throw ListaIndice();
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
            throw ListaNoMemoria();
        }


    }
}

//***********************************

template <typename T>
void ListaSimple<T>::EliminarInicio()
{
    if(EstaVacia()){
        throw ListaVacia();
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

//***********************************

template <typename T>
void ListaSimple<T>::EliminarFinal()
{
    if(EstaVacia()){
        throw ListaVacia();
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

//***********************************

template <typename T>
void ListaSimple<T>::EliminarEnPosicion(int pos)
{
    if(pos < 0 || pos >= numElem){
        throw ListaIndice();
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

//***********************************

template <typename T>
bool ListaSimple<T>::BuscarValor(T valor) const
{
    Elemento *visitado = inicio;
    while(visitado != nullptr && visitado->valor != valor){
        visitado = visitado->siguiente;
    }

    return visitado != nullptr;
}

//***********************************

// Nos devuelve en que posicion esta cierto valor
// Ejemplo:
// x = [2,4,6,8,10]
// BuscarPosicion(6);
// Regresa 2

template <typename T>
int ListaSimple<T>::BuscarPosicion(T valor) const
{
    Elemento *visitado = inicio;
    int pos = 0;

    while (visitado != nullptr && visitado->valor != valor){
        visitado = visitado->siguiente;
        ++pos;
    }

    return visitado != nullptr ? pos : -1;
}

//***********************************

template <typename T>
T ListaSimple<T>::ObtenerPrimero() const
{
    if(EstaVacia()){
        throw ListaVacia();
    }

    return inicio->valor;
}

//***********************************

template <typename T>
T ListaSimple<T>::ObtenerUltimo() const
{
    if(EstaVacia()){
        throw ListaVacia();
    }

    return ultimo->valor;
}

//***********************************

template <typename T>
T ListaSimple<T>::ObtenerEnPosicion(int pos) const
{
    if(pos < 0 || pos >= numElem){
        throw ListaIndice();
    }

    Elemento *visitado = inicio;

    for(int i = 0 ; i < pos ; ++i){
        visitado = visitado->siguiente;
    }

    return visitado->valor;
}

//***********************************

template <typename T>
bool ListaSimple<T>::EstaVacia() const
{
    return numElem == 0;
}

// ==================================

template <typename T>
int ListaSimple<T>::ObtenerTam() const
{
    return numElem;
}

//***********************************

template <typename T>
void ListaSimple<T>::Vaciar()
{
    while(!EstaVacia()) EliminarInicio();
}

//***********************************

template <typename T>
void ListaSimple<T>::Imprimir() const
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

//***********************************

template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaSimple<T>& lista)
{
    lista.Imprimir();
    return salida;
}


//***********************************
// Constructor de Elemento
//***********************************

template <typename T>
ListaSimple<T>::Elemento::Elemento(T v, Elemento *sig /*=nullptr*/) : valor(v), siguiente(sig){}

//***********************************
// Implementación de la clase ListaVacia
//***********************************

template <typename T>
ListaSimple<T>::ListaVacia::ListaVacia() throw() {}

//***********************************

template <typename T>
ListaSimple<T>::ListaNoMemoria::ListaNoMemoria() throw(){}

//***********************************

template <typename T>
ListaSimple<T>::ListaIndice::ListaIndice() throw(){}

//***********************************

template <typename T>
const char *ListaSimple<T>::ListaVacia::what() const throw()
{
    return "La Lista se encuentra vac\241a.";
}

//***********************************

template <typename T>
const char *ListaSimple<T>::ListaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}

//***********************************

template <typename T>
const char *ListaSimple<T>::ListaIndice::what() const throw()
{
    return "Indice fuera de rango.";
}
