#ifndef LISTASIMPLE_HPP_INCLUDED
#define LISTASIMPLE_HPP_INCLUDED


class ListaSimple{
public:

    // ===== CONSTRUCTORES =====

    ListaSimple();

    ~ListaSimple();

    ListaSimple(const ListaSimple& lista);

    ListaSimple& operator=(const ListaSimple& pila);

    // ===== MÉTODOS =====

    void AgregarInicio(int valor);

    void AgregarFinal(int valor);

    void AgregarEnPosicion(int valor, int pos);

    void EliminarInicio();

    void EliminarFinal();

    void EliminarEnPosicion();

    int BuscarValor(int valor) const;

    int BuscarPosicion(int valor) const;

    int ObtenerPrimero() const;

    int ObtenerUltimo() const;

    int ObtenerEnPosicion() const;

    bool EstaVacia() const;

    int ObtenerTam() const;

    void Vaciar();

    void Imprimir() const;

private:
    int numElem;

    struct Elemento{

        int valor;
        Elemento *siguiente;
        Elemento(int val, Elemento *sig); // Constructor de Elemento

    };

    Elemento *inicio;
    Elemento *ultimo;

};

#endif // LISTASIMPLE_HPP_INCLUDED
