#include "NodoPila.h"
#include "../Proceso/Proceso.h"

NodoPila::NodoPila()
{
    Proceso proceso;
    siguiente = NULL;
    // ctor
}
NodoPila::NodoPila(Proceso proceso, NodoPila *sig)
{
    this->proceso = proceso;
    siguiente = sig;
}
NodoPila::~NodoPila()
{
    // dtor
}
