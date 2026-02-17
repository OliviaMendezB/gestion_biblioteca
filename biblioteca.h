#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

const int MAX_LIBROS = 50;

class tLibro {
private:
    int isbn;
    string titulo;
    int numEjemplares;
    int numPrestados;

public:
    tLibro();
    tLibro(int isbn_, string titulo_, int nE, int nP);

    int getISBN() const;
    string getTitulo() const;
    int getNumEjemplares() const;
    int getNumPrestados() const;

    void setNumPrestados(int n);
};

typedef tLibro* tPtrLibro;

class tBiblioteca {
    private:
        tPtrLibro libros[MAX_LIBROS];
        int cont;
        unordered_map<int, int> indiceISBN;

    public:
        tBiblioteca();
        ~tBiblioteca();
        void cargarBiblioteca(ifstream& archivo);
        void guardarBiblioteca(const string& nombreArchivo) const;
    
        void mostrarBiblioteca() const;
        void mostrarRanking() const;

        tPtrLibro getLibro(int isbn) const;
};

#endif
