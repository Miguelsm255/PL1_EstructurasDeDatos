#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Proceso.h"
#include <iostream>
class NodoCola
{
    friend class Cola;

private:
    Proceso proceso;
    NodoCola *siguiente;

public:
    NodoCola();
    NodoCola(Proceso p, NodoCola *sig = NULL);
    ~NodoCola();
};
#endif // NODOCOLA_H