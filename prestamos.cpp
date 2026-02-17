#include "prestamos.h"
#include <iostream>

tPrestamo::tPrestamo() : dni(0), isbn(0) {}
tPrestamo::tPrestamo(int dni_, int isbn_) : dni(dni_), isbn(isbn_) {}

int tPrestamo::getDni() const { return dni; }
int tPrestamo::getIsbn() const { return isbn; }

tPrestamos::tPrestamos() {
    prestamos = new tPrestamo[TAM_INI];
    cont = 0;
    tam = TAM_INI;
}

tPrestamos::~tPrestamos() {
    delete[] prestamos;
    prestamos = nullptr;
    cont = 0;
    tam = 0;
}

void tPrestamos::redimensionar() {
    int newSize = 2 * tam;
    tPrestamo* vaux = new tPrestamo[newSize];

    for (int i = 0; i < cont; i++) {
        vaux[i] = prestamos[i];
    }

    tam = newSize;
    delete[] prestamos;
    prestamos = vaux;
}

bool tPrestamos::insertarOrdenadoPrestamo(const tPrestamo& prestamo) {
    int pos;
    if (existePrestamo(prestamo, pos)) return false; 

    if (cont == tam) redimensionar();

    for (int i = cont; i > pos; i--) {
        prestamos[i] = prestamos[i - 1];
    }
    prestamos[pos] = prestamo;
    cont++;
    return true;
}


bool tPrestamos::eliminarPrestamo(const tPrestamo& prestamo) {

    for (int i = 0; i < cont; i++) {

        if (prestamos[i].getDni() == prestamo.getDni() &&
            prestamos[i].getIsbn() == prestamo.getIsbn()) {

            for (int j = i; j < cont - 1; j++)
                prestamos[j] = prestamos[j + 1];

            cont--;
            return true;
        }
    }

    return false;
}

void tPrestamos::mostrarPrestamos() const{
    for (int i = 0; i < cont; i++)
        cout << "DNI: " << prestamos[i].getDni()
        << " ISBN: " << prestamos[i].getIsbn() << "\n";
}

bool tPrestamos::existePrestamo(const tPrestamo& prestamo, int& pos) const {
    pos = 0;
    while (pos < cont) {
        if (prestamos[pos].getDni() == prestamo.getDni()) {
            if (prestamos[pos].getIsbn() == prestamo.getIsbn())
                return true; 
            else if (prestamo.getIsbn() < prestamos[pos].getIsbn())
                return false; 
        }
        else if (prestamo.getDni() < prestamos[pos].getDni()) {
            return false; 
        }
        pos++;
    }
    return false;
}
