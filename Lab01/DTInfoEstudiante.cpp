#include "DTInfoEstudiante.h"

DTInfoEstudiante::DTInfoEstudiante(int ci, string nombre, int idInfo)
    : ci(ci), nombre(nombre), idInfo(idInfo) {}

int DTInfoEstudiante::getCI() const { return ci; }
string DTInfoEstudiante::getNombre() const { return nombre; }
int DTInfoEstudiante::getIdInfo() const { return idInfo; }

string DTInfoEstudiante::toString() const {
    return to_string(ci) + ", " + nombre + ", " + to_string(idInfo);
}

bool DTInfoEstudiante::operator<(const DTInfoEstudiante& otro) const {

    return ci < otro.ci || (ci == otro.ci && idInfo < otro.idInfo);
}
