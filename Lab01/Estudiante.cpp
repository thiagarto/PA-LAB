#include "Estudiante.h"

Estudiante::Estudiante(string nombre, int ci, string email) {
    this->nombre = nombre;
    this->ci = ci;
    this->email = email;
}

Estudiante::~Estudiante() {}

string Estudiante::getNombre() { return nombre; }
int Estudiante::getCI() { return ci; }
string Estudiante::getEmail() { return email; }

void Estudiante::agregarInformacion(Informacion* info) {
    informaciones.insert(info);
    info->agregarEstudiante(this);
}
5


set<string> Estudiante::listarInfo(DTFecha desde) {
    set<string> resultado;

    for (auto* info : informaciones) {
        DTFecha f = info->getFecha();
        if (f.getAnio() > desde.getAnio() ||
            (f.getAnio() == desde.getAnio() && f.getMes() > desde.getMes()) ||
            (f.getAnio() == desde.getAnio() && f.getMes() == desde.getMes() && f.getDia() >= desde.getDia())) {
            resultado.insert(info->toString());
            }
    }

    return resultado;
}

void Estudiante::quitarInformacion(Informacion* info) {
    informaciones.erase(info);
    info->quitarEstudiante(this);
}

