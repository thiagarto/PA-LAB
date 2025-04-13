
#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>
using namespace std;

class DTFecha {
public:
    DTFecha(int d, int m, int a);
    virtual ~DTFecha();
    int getDia();
    int getMes();
    int getAnio();
    string toString();

private:
    int dia;
    int mes;
    int anio;
};



#endif
