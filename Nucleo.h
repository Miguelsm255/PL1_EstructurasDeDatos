#ifndef NUCLEO_H
#define NUCLEO_H
#include "Proceso.h"
#include "Cola.h"

class Nucleo
{
private:
    Proceso proceso;
    bool libre;
    int tiempoProcesado;
    Cola colaProcesos;
public:
    Nucleo();
    ~Nucleo();
    bool esVacio();
    void procesar(Proceso proceso);
    void encolarProceso(Proceso proceso);
    void quitarProceso();
    void mostrarNucleo();
    void mostrarColaNucleo();
    int procesosEnCola();
    int actualizar();
};
#endif // NUCLEO_H
