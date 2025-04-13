#include "Informacion.h"
#include "Estudiante.h"

Informacion::Informacion(int id, DTFecha fecha) : fecha(fecha) {
    this->id = id;
}

Informacion::~Informacion() {}

int Informacion::getId() { return id; }

DTFecha Informacion::getFecha() { return fecha; }

void Informacion::agregarEstudiante(Estudiante* e) {
    estudiantes.insert(e);
}

void Informacion::quitarEstudiante(Estudiante* e) {
    estudiantes.erase(e);
}

set<Estudiante*> Informacion::getEstudiantes() {
    return estudiantes;
}
