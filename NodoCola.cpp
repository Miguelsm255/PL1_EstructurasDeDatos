#include "NodoCola.h"
#include "Proceso.h"
NodoCola::NodoCola()
{
    Proceso proceso;
    siguiente = NULL;
    // constructor por defecto
}
NodoCola::NodoCola(Proceso Proceso, NodoCola *sig)
{
    proceso;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    // dtor
}