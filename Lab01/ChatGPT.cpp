
#include "ChatGPT.h"

ChatGPT::ChatGPT(int id, DTFecha fecha, string pregunta, string respuesta): Informacion(id, fecha) {
    this->pregunta = pregunta;
    this->respuesta = respuesta;
}

ChatGPT::~ChatGPT() {
}

string ChatGPT::toString() {
    return to_string(id) + ", " + fecha.toString() + ", " + pregunta + ", " + respuesta;
}
