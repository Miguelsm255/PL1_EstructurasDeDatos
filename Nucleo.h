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
    int ID;
public:
    Nucleo();
    Nucleo(int id);
    ~Nucleo();
    bool esVacio();
    void procesar(Proceso proceso);
    void encolarProceso(Proceso proceso);
    void quitarProceso();
    void mostrarNucleo();
    void mostrarColaNucleo();
    int NdeProcesosEnCola();
    int actualizar();
    Cola* obtenerColaNucleo();
    int getID();
};
#endif // NUCLEO_H
