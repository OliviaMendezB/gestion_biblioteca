#ifndef PRESTAMOS_H
#define PRESTAMOS_H
using namespace std;

const int TAM_INI = 2;
const int INCR_TAM = 2;

class tPrestamo {
private:
    int dni;
    int isbn;

public:
    tPrestamo();
    tPrestamo(int dni_, int isbn_);

    int getDni() const;
    int getIsbn() const;
};

class tPrestamos {
public:
    tPrestamo* prestamos;
    int cont;
    int tam;

    tPrestamos();
    ~tPrestamos();
};

bool insertarOrdenadoPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo);
bool eliminarPrestamo(tPrestamos& prestamos, const tPrestamo& prestamo);
void mostrarPrestamos(const tPrestamos& prestamos);
void liberarPrestamos(tPrestamos& prestamos);

#endif
