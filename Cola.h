#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"

class Cola
{
private:
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;

public:
    Cola();
    ~Cola();
    void encolar(Elemento e);
    Elemento inicio();
    Elemento fin();
    int colaLongitud();
    Elemento desencolar();
    bool esVacia();
    void mostrarCola(); /* Muestra los elementos de la cola, aunque no es correcto del todo, ya que si quieres acceder
    a un elemento en específico de la cola, no puedes usar esta función.*/
    void encolarPrioridad(Elemento e);
};
#endif // COLA_H