
#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(int id, DTFecha fecha, string titulo, string link, string texto): Informacion(id, fecha) {
    this->titulo = titulo;
    this->link = link;
    this->texto = texto;
}

PaginaWeb::~PaginaWeb() {
}

string PaginaWeb::toString() {
    return to_string(id) + ", " + fecha.toString() + ", " + titulo + ", " + link + ", " + texto;
}
