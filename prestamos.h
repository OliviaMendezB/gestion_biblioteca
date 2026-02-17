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
    private:
        tPrestamo* prestamos;
        int cont;
        int tam;

        void redimensionar();
        bool existePrestamo(const tPrestamo& prestamo, int& pos) const;

    public:
        tPrestamos();
        ~tPrestamos();

        bool insertarOrdenadoPrestamo(const tPrestamo& prestamo);
        bool eliminarPrestamo(const tPrestamo& prestamo);
        void mostrarPrestamos() const;
};
#endif
