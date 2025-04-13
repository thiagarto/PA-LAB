
#include "DTFecha.h"

DTFecha::DTFecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

int DTFecha::getDia() { return dia; }
int DTFecha::getMes() { return mes; }
int DTFecha::getAnio() { return anio; }

DTFecha::~DTFecha() {
}

string DTFecha::toString() {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}