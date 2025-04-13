#pragma once
#include "Informacion.h"
#include <set>
using namespace std;

class Libro : public Informacion {
private:
    string titulo;
    set<string> autores;
    string resumen;

public:
    Libro(int id, DTFecha fecha, string titulo, set<string> autores, string resumen);
    ~Libro();
    string toString() override;
};
