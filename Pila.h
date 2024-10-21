#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Proceso.h"

class Pila
{
private:
    pnodo cima;

public:
    Pila();
    ~Pila();
    bool esVacia();
    void apilar(Proceso proceso);
    void desapilar();
    int mostrar();
    Proceso cimaPila();
};
#endif // PILA_H