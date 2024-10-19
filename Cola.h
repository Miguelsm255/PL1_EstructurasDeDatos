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
    void encolar(char e);
    char inicio();
    char fin();
    int colaLongitud();
    char desencolar();
    bool esVacia();
    void mostrarCola(); /* Muestra los elementos de la cola, aunque no es correcto del todo, ya que si quieres acceder
    a un elemento en específico de la cola, no puedes usar esta función.*/
};
#endif // COLA_H