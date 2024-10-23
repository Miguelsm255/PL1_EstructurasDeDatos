#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include "Proceso.h"

class NodoPila
{
private:
    Proceso proceso;
    NodoPila *siguiente;
    friend class Pila;

public:
    NodoPila();
    NodoPila(Proceso proceso, NodoPila *sig = NULL);
    ~NodoPila();
};
typedef NodoPila *pnodo;
#endif // NODOPILA_H
