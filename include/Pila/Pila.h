#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "../Proceso/Proceso.h"

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
    void mostrar();
    Proceso cimaPila();
    void insertarTiempo(Proceso proceso);
};
#endif // PILA_H
