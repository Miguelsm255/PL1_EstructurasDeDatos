#include "NodoCola.h"
#include "Proceso.h"

NodoCola::NodoCola()
{
    Proceso proceso;
    siguiente = NULL;
    // constructor por defecto
}
NodoCola::NodoCola(Proceso proceso, NodoCola *sig)
{
    this->proceso = proceso;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    // dtor
}
