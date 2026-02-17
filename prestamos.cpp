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
}

bool insertarOrdenadoPrestamo(tPrestamos& p, const tPrestamo& prestamo) {

    for (int i = 0; i < p.cont; i++)
        if (p.prestamos[i].getDni() == prestamo.getDni() &&
            p.prestamos[i].getIsbn() == prestamo.getIsbn())
            return false;

    if (p.cont == p.tam) {
        int newTam = p.tam + INCR_TAM;
        tPrestamo* nuevo = new tPrestamo[newTam];

        for (int i = 0; i < p.cont; i++)
            nuevo[i] = p.prestamos[i];

        delete[] p.prestamos;
        p.prestamos = nuevo;
        p.tam = newTam;
    }

    p.prestamos[p.cont++] = prestamo;
    return true;
}

bool eliminarPrestamo(tPrestamos& p, const tPrestamo& prestamo) {

    for (int i = 0; i < p.cont; i++) {

        if (p.prestamos[i].getDni() == prestamo.getDni() &&
            p.prestamos[i].getIsbn() == prestamo.getIsbn()) {

            for (int j = i; j < p.cont - 1; j++)
                p.prestamos[j] = p.prestamos[j + 1];

            p.cont--;
            return true;
        }
    }

    return false;
}

void mostrarPrestamos(const tPrestamos& p) {

    for (int i = 0; i < p.cont; i++)
        cout << "DNI: " << p.prestamos[i].getDni()
        << " ISBN: " << p.prestamos[i].getIsbn() << "\n";
}

void liberarPrestamos(tPrestamos& p) {
    delete[] p.prestamos;
    p.cont = 0;
    p.tam = 0;
}
