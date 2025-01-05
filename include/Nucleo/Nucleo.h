#ifndef NUCLEO_H
#define NUCLEO_H
#include "../Proceso/Proceso.h"
#include "../Cola/Cola.h"
#include "../ABBProcesos/ABBProcesos.h"

class Nucleo
{
private:
    Proceso proceso;
    bool libre;
    int tiempoProcesado;
    Cola* colaProcesos;
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
    void actualizar(ABBProcesos* arbolProcesos);
    Cola* obtenerColaNucleo();
    int getID();
};
#endif // NUCLEO_H
