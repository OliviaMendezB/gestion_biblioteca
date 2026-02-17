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

tBiblioteca::~tBiblioteca() {
    for (int i = 0; i < cont; i++) {
        delete libros[i];
        libros[i] = nullptr;
    }
    cont = 0;
    indiceISBN.clear();
}

void tBiblioteca::cargarBiblioteca(ifstream& archivo) {

    int n;
    archivo >> n;
    archivo.ignore();

    cont = n;

    for (int i = 0; i < n; i++) {

        int isbn, ejemplares, prestados;
        string titulo;

        archivo >> isbn;
        archivo.ignore();
        getline(archivo, titulo);
        archivo >> ejemplares;
        archivo >> prestados;
        archivo.ignore();

        libros[i] = new tLibro(isbn, titulo, ejemplares, prestados);
        indiceISBN[isbn] = i;
    }
}

void tBiblioteca::mostrarBiblioteca() const {

    for (int i = 0; i < cont; i++) {
        cout << libros[i]->getISBN() << "\n";
        cout << libros[i]->getTitulo() << "\n";
        cout << libros[i]->getNumEjemplares() << "\n";
        cout << libros[i]->getNumPrestados() << "\n";
    }
}

tPtrLibro tBiblioteca::getLibro(int isbn) const {

    auto it = indiceISBN.find(isbn);

    if (it != indiceISBN.end())
        return libros[it->second];

    return nullptr;
}

void tBiblioteca::guardarBiblioteca(const string& nombreArchivo) const {

    ofstream archivo(nombreArchivo);

    archivo << cont << "\n";

    for (int i = 0; i < cont; i++) {

        archivo << libros[i]->getISBN() << "\n";
        archivo << libros[i]->getTitulo() << "\n";
        archivo << libros[i]->getNumEjemplares() << "\n";
        archivo << libros[i]->getNumPrestados() << "\n";
    }

    archivo.close();
}

void tBiblioteca::mostrarRanking() const {

    vector<tPtrLibro> copia;

    for (int i = 0; i < cont; i++)
        copia.push_back(libros[i]);

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
