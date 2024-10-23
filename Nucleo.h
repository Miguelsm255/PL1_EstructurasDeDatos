#ifndef NUCLEO_H
#define NUCLEO_H
#include "Proceso.h"
#include "Cola.h"

class Nucleo
{
private:
    Cola colaNucleo;
public:
    Nucleo();
    ~Nucleo();
    bool esVacio();
    void procesar(Proceso proceso);
    void quitarProceso();
    void mostrarColaNucleo();
};
#endif
