#pragma once
#include <set>
#include "DTFecha.h"
using namespace std;

class Estudiante;

class Informacion {
protected:
    int id;
    DTFecha fecha;
    set<Estudiante*> estudiantes;

public:
    Informacion(int id, DTFecha fecha);
    virtual ~Informacion();

    int getId();
    DTFecha getFecha();

    void agregarEstudiante(Estudiante* e);
    void quitarEstudiante(Estudiante* e);
    set<Estudiante*> getEstudiantes();

    virtual string toString() = 0;
};
