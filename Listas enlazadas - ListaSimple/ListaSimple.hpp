#ifndef LISTASIMPLE_HPP_INCLUDED
#define LISTASIMPLE_HPP_INCLUDED


class ListaSimple{
public:

    // ===== CONSTRUCTORES =====

    ListaSimple(); // Listo

    ~ListaSimple(); // Listo

    ListaSimple(const ListaSimple& lista); // Listo

    ListaSimple& operator=(const ListaSimple& pila); // FALTA ✖️

    // ===== MÉTODOS =====

    void AgregarInicio(int valor); // Listo

    void AgregarFinal(int valor); // Listo

    void AgregarEnPosicion(int valor, int pos); // Listo

    void EliminarInicio(); // Listo

    void EliminarFinal(); // Listo

    void EliminarEnPosicion(int pos); // Listo

    bool BuscarValor(int valor) const; // Listo

    int BuscarPosicion(int valor) const; // Listo

    int ObtenerPrimero() const; // Listo

    int ObtenerUltimo() const; // Listo

    int ObtenerEnPosicion(int pos) const; // Listo

    bool EstaVacia() const; // Listo

    int ObtenerTam() const; // Listo

    void Vaciar(); // Lista

    void Imprimir() const; // Lista

private:
    int numElem;

    struct Elemento{

        int valor;
        Elemento *siguiente;
        Elemento(int val, Elemento *sig = nullptr); // Constructor de Elemento

    };

    Elemento *inicio;
    Elemento *ultimo;

};

#endif // LISTASIMPLE_HPP_INCLUDED
