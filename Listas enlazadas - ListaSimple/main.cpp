#include <iostream>
#include <string>
#include "ListaSimple.hpp"

using namespace std;

int main()
{
    cout << "=== INICIANDO PRUEBAS DE LISTA SIMPLE ===" << endl;

    try {
        ListaSimple<string> listaNombres;

        cout << "\n--- Agregando Elementos ---" << endl;
        listaNombres.AgregarFinal("Carlos");
        listaNombres.AgregarInicio("Ana");
        listaNombres.AgregarFinal("Diana");
        listaNombres.AgregarEnPosicion("Beto", 1);

        cout << "Lista actual: " << listaNombres << endl;
        cout << "Tamano: " << listaNombres.ObtenerTam() << endl;

        // 2. Probando búsquedas
        cout << "\n--- Busquedas ---" << endl;
        cout << "El primero es: " << listaNombres.ObtenerPrimero() << endl;
        cout << "El ultimo es: " << listaNombres.ObtenerUltimo() << endl;
        cout << "Beto esta en la posicion: " << listaNombres.BuscarPosicion("Beto") << endl;

        // 3. Probando eliminaciones
        cout << "\n--- Eliminaciones ---" << endl;
        listaNombres.EliminarInicio(); // Adios Ana
        listaNombres.EliminarFinal();  // Adios Diana
        listaNombres.EliminarEnPosicion(0); // Adios Beto (ahora es el índice 0)

        cout << "Lista despues de eliminar: " << listaNombres << endl;

        // 4. Probando vaciado y excepciones
        cout << "\n\n--- Vaciado y Excepciones ---" << endl;
        listaNombres.Vaciar();
        cout << "Lista vaciada. Tamano actual: " << listaNombres.ObtenerTam() << endl;
        cout << listaNombres << endl;

        cout << "Intentando eliminar en una lista vacia..." << endl;
        listaNombres.EliminarFinal(); // ¡Esto debería lanzar la excepción!

    }catch(const char* mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        cerr << "Error: " << error.what();
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }

    cout << "\n=== PRUEBAS FINALIZADAS ===" << endl;

    return 0;
}
