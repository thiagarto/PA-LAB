#include "Libro.h"

Libro::Libro(int id, DTFecha fecha, string titulo, set<string> autores, string resumen)
    : Informacion(id, fecha) {
    this->titulo = titulo;
    this->autores = autores;
    this->resumen = resumen;
}

Libro::~Libro() {}

string Libro::toString() {
    string texto = to_string(id) + ", " + fecha.toString() + ", " + titulo + ", ";

    for (auto it = autores.begin(); it != autores.end(); ++it) {
        texto += *it;
        if (next(it) != autores.end())
            texto += " & ";
    }

    texto += ", " + resumen;
    return texto;
}
