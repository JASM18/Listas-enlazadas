#ifndef LISTASIMPLE_HPP_INCLUDED
#define LISTASIMPLE_HPP_INCLUDED

#include <exception>

template <typename T>
class ListaSimple {

public:

    // ===== CONSTRUCTORES =====

    ListaSimple(); // Listo

    ~ListaSimple(); // Listo

    ListaSimple(const ListaSimple& lista); // Listo

    ListaSimple& operator=(const ListaSimple& pila); // Listo

    // ===== MÉTODOS =====

    void AgregarInicio(T valor); // Listo

    void AgregarFinal(T valor); // Listo

    void AgregarEnPosicion(T valor, int pos); // Listo

    void EliminarInicio(); // Listo

    void EliminarFinal(); // Listo

    void EliminarEnPosicion(int pos); // Listo

    bool BuscarValor(T valor) const; // Listo

    int BuscarPosicion(T valor) const; // Listo

    T ObtenerPrimero() const; // Listo

    T ObtenerUltimo() const; // Listo

    T ObtenerEnPosicion(int pos) const; // Listo

    bool EstaVacia() const; // Listo

    int ObtenerTam() const; // Listo

    void Vaciar(); // Lista

    void Imprimir() const; // Lista

    /**
     * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando se intenta acceder o extraer de una cola vac&iacute;a.
     */
    class ListaVacia : public std::exception {
    public:
        /** \brief Constructor por default de la excepci&oacute;n ColaVacia.
         */
        ListaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una lista vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando ocurren fallos de reserva de memoria.
    */
    class ListaNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando no haya memoria disponible.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando el cliente intenta acceder a indices no disponibles
    */
    class ListaIndice : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaIndice() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando el cliente intente acceder a indices no disponibles.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:
    int numElem;

    struct Elemento{

        T valor;
        Elemento *siguiente;
        Elemento(T val, Elemento *sig = nullptr); // Constructor de Elemento

    };

    Elemento *inicio;
    Elemento *ultimo;

};

#include "ListaSimple.tpp"

#endif // LISTASIMPLE_HPP_INCLUDED
