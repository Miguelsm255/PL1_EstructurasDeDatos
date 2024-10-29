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
public:
    Nucleo();
    ~Nucleo();
    bool esVacio();
    void procesar(Proceso proceso);
    void quitarProceso();
    void mostrarNucleo();
    int actualizar();
};
#endif // NUCLEO_H
