#include <iostream>
#include <fstream>
#include "biblioteca.h"
#include "prestamos.h"

using namespace std;

void procesarOpcion1(tBiblioteca& biblioteca, tPrestamos& prestamos);
void procesarOpcion2(tBiblioteca& biblioteca, tPrestamos& prestamos);

int main() {

    tBiblioteca biblioteca;
    tPrestamos prestamos;

    ifstream archivo("biblioteca.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo\n";
        return 1;
    }

    biblioteca.cargarBiblioteca(archivo);
    archivo.close();

    int opcion = 0;

    while (opcion != 6) {

        cout << "\n1. Prestar\n2. Devolver\n3. Mostrar biblioteca\n4. Mostrar prestamos\n5. Ranking\n6. Salir\nOpcion: ";
        cin >> opcion;

        if (opcion == 1)
            procesarOpcion1(biblioteca, prestamos);
        else if (opcion == 2)
            procesarOpcion2(biblioteca, prestamos);
        else if (opcion == 3)
            biblioteca.mostrarBiblioteca();
        else if (opcion == 4)
            prestamos.mostrarPrestamos();
        else if (opcion == 5)
            biblioteca.mostrarRanking();
        else if (opcion != 6)
            cout << "Opcion invalida.\n";

        biblioteca.guardarBiblioteca("biblioteca.txt");
    }
    if (opcion == 6) return 1;

    return 0;
}

void procesarOpcion1(tBiblioteca& biblioteca, tPrestamos& prestamos) {

    int isbn;
    cout << "Ingrese ISBN del libro a prestar: ";
    cin >> isbn;

    tPtrLibro libro = biblioteca.getLibro(isbn);

    if (!libro) {
        cout << "Libro no existe en la biblioteca.\n";
        return;
    }

    if (libro->getNumPrestados() >= libro->getNumEjemplares()) {
        cout << "No hay ejemplares disponibles.\n";
        return;
    }

    int dni;
    cout << "Ingrese DNI del usuario: ";
    cin >> dni;

    tPrestamo prestamo(dni, isbn);

    if (prestamos.insertarOrdenadoPrestamo(prestamo)) {
        libro->setNumPrestados(libro->getNumPrestados() + 1);
        cout << "Prestamo realizado con exito.\n";
    }
    else {
        cout << "El usuario ya tiene prestado este libro.\n";
    }
}

void procesarOpcion2(tBiblioteca& biblioteca, tPrestamos& prestamos) {

    int isbn, dni;
    cout << "Ingrese ISBN del libro a devolver: ";
    cin >> isbn;

    cout << "Ingrese DNI del usuario: ";
    cin >> dni;

    tPrestamo prestamo(dni, isbn);

    if (prestamos.eliminarPrestamo(prestamo)) {
        tPtrLibro libro = biblioteca.getLibro(isbn);
        if (libro)
            libro->setNumPrestados(libro->getNumPrestados() - 1);

        cout << "Devolucion realizada con exito.\n";
    }
    else {
        cout << "No existe prestamo registrado para este usuario y libro.\n";
    }
}
