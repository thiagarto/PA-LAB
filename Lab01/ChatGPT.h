
#ifndef CHATGPT_H
#define CHATGPT_H

#include "Informacion.h"
using namespace std;


class ChatGPT : public Informacion{
public:
    ChatGPT(int id, DTFecha fecha, string pregunta, string respuesta);
    virtual ~ChatGPT();
    string toString();

private:
    string pregunta;
    string respuesta;
};



#endif
