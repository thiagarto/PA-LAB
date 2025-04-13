#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <set>
#include "Informacion.h"
using namespace std;

class Estudiante {
public:
    Estudiante(string nombre, int ci, string email);
    virtual ~Estudiante();

    string getNombre();
    int getCI();
    string getEmail();

    void agregarInformacion(Informacion* info);
    set<string> listarInfo(DTFecha desde);

    void quitarInformacion(Informacion* info);

private:
    string nombre;
    int ci;
    string email;
    set<Informacion*> informaciones;
};

#endif
