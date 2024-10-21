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
    void encolar(Proceso p);
    Proceso inicio();
    Proceso fin();
    int colaLongitud();
    Proceso desencolar();
    bool esVacia();
    void mostrarCola(); /* Muestra los procesos de la cola, aunque no es correcto del todo, ya que si quieres acceder
    a un proceso en específico de la cola, no puedes usar esta función.*/
    void encolarPrioridad(Proceso p);
};
#endif // COLA_H