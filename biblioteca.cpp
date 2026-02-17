#include "biblioteca.h"
#include <iostream>
#include <vector>
#include <algorithm>

tLibro::tLibro() : isbn(0), titulo(""), numEjemplares(0), numPrestados(0) {}

tLibro::tLibro(int isbn_, string titulo_, int nE, int nP)
    : isbn(isbn_), titulo(titulo_), numEjemplares(nE), numPrestados(nP) {
}

int tLibro::getISBN() const { return isbn; }
string tLibro::getTitulo() const { return titulo; }
int tLibro::getNumEjemplares() const { return numEjemplares; }
int tLibro::getNumPrestados() const { return numPrestados; }
void tLibro::setNumPrestados(int n) { numPrestados = n; }

tBiblioteca::tBiblioteca() {
    cont = 0;
    for (int i = 0; i < MAX_LIBROS; i++)
        libros[i] = nullptr;
}

void cargarBiblioteca(tBiblioteca& biblioteca, ifstream& archivo) {

    int n;
    archivo >> n;
    archivo.ignore();

    biblioteca.cont = n;

    for (int i = 0; i < n; i++) {

        int isbn, ejemplares, prestados;
        string titulo;

        archivo >> isbn;
        archivo.ignore();
        getline(archivo, titulo);
        archivo >> ejemplares;
        archivo >> prestados;
        archivo.ignore();

        biblioteca.libros[i] = new tLibro(isbn, titulo, ejemplares, prestados);
        biblioteca.indiceISBN[isbn] = i;
    }
}

void mostrarBiblioteca(const tBiblioteca& biblioteca) {

    for (int i = 0; i < biblioteca.cont; i++) {
        cout << biblioteca.libros[i]->getISBN() << "\n";
        cout << biblioteca.libros[i]->getTitulo() << "\n";
        cout << biblioteca.libros[i]->getNumEjemplares() << "\n";
        cout << biblioteca.libros[i]->getNumPrestados() << "\n";
    }
}

tPtrLibro getLibro(const tBiblioteca& biblioteca, int isbn) {

    auto it = biblioteca.indiceISBN.find(isbn);

    if (it != biblioteca.indiceISBN.end())
        return biblioteca.libros[it->second];

    return nullptr;
}

int getNumExistentes(tPtrLibro ptr_libro) {
    return (ptr_libro != nullptr) ? ptr_libro->getNumEjemplares() : 0;
}

int getNumPrestados(tPtrLibro ptr_libro) {
    return (ptr_libro != nullptr) ? ptr_libro->getNumPrestados() : 0;
}

void setNumPrestados(tPtrLibro ptr_libro, int num_prestados) {
    if (ptr_libro != nullptr)
        ptr_libro->setNumPrestados(num_prestados);
}

void liberarBiblioteca(tBiblioteca& biblioteca) {

    for (int i = 0; i < biblioteca.cont; i++) {
        delete biblioteca.libros[i];
        biblioteca.libros[i] = nullptr;
    }

    biblioteca.cont = 0;
    biblioteca.indiceISBN.clear();
}

void guardarBiblioteca(const tBiblioteca& biblioteca, const std::string& nombreArchivo) {

    std::ofstream archivo(nombreArchivo);

    archivo << biblioteca.cont << "\n";

    for (int i = 0; i < biblioteca.cont; i++) {

        archivo << biblioteca.libros[i]->getISBN() << "\n";
        archivo << biblioteca.libros[i]->getTitulo() << "\n";
        archivo << biblioteca.libros[i]->getNumEjemplares() << "\n";
        archivo << biblioteca.libros[i]->getNumPrestados() << "\n";
    }

    archivo.close();
}

void mostrarRanking(const tBiblioteca& biblioteca) {

    vector<tPtrLibro> copia;

    for (int i = 0; i < biblioteca.cont; i++)
        copia.push_back(biblioteca.libros[i]);

    sort(copia.begin(), copia.end(),
        [](tPtrLibro a, tPtrLibro b) {
            return a->getNumPrestados() > b->getNumPrestados();
        });

    cout << "\n=== Ranking libros mas prestados ===\n";

    for (auto libro : copia) {
        cout << libro->getTitulo()
            << " (" << libro->getNumPrestados() << " prestamos)\n";
    }
}
