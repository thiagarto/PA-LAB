
#ifndef DTINFOESTUDIANTE_H
#define DTINFOESTUDIANTE_H

#include <string>
using namespace std;

class DTInfoEstudiante {

public:
    DTInfoEstudiante(int ci, string nombre, int idInfo);

    int getCI() const;
    string getNombre() const;
    int getIdInfo() const;
    string toString() const;

    bool operator<(const DTInfoEstudiante& otro) const;

private:
    int ci;
    string nombre;
    int idInfo;

};

#endif
