
#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include "Informacion.h"
using namespace std;

class PaginaWeb : public Informacion {
public:
    PaginaWeb(int id, DTFecha fecha, string titulo, string link, string texto);
    virtual ~PaginaWeb();
    string toString();

private:
    string titulo;
    string link;
    string texto;


};


#endif
