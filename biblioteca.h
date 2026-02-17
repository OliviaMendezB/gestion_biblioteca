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
public:
    tPtrLibro libros[MAX_LIBROS];
    int cont;

    unordered_map<int, int> indiceISBN;

    tBiblioteca();
};

void cargarBiblioteca(tBiblioteca& biblioteca, ifstream& archivo);
void mostrarBiblioteca(const tBiblioteca& biblioteca);
tPtrLibro getLibro(const tBiblioteca& biblioteca, int isbn);
int getNumExistentes(tPtrLibro ptr_libro);
int getNumPrestados(tPtrLibro ptr_libro);
void setNumPrestados(tPtrLibro ptr_libro, int num_prestados);
void liberarBiblioteca(tBiblioteca& biblioteca);
void guardarBiblioteca(const tBiblioteca& biblioteca, const string& nombreArchivo);
void mostrarRanking(const tBiblioteca& biblioteca);

#endif
