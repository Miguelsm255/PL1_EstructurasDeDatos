#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Elemento.h"
#include <iostream>
class NodoCola
{
    friend class Cola;

private:
    NodoCola *siguiente;
    Elemento elemento;

public:
    NodoCola();
    NodoCola(Elemento e, NodoCola *sig = NULL);
    ~NodoCola();
};
#endif // NODOCOLA_H