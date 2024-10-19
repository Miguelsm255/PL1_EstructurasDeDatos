#include "NodoCola.h"
#include "Elemento.h"
NodoCola::NodoCola()
{
    Elemento e = Elemento(0, 0);
    siguiente = NULL;
    // constructor por defecto
}
NodoCola::NodoCola(Elemento e, NodoCola *sig)
{
    Elemento e = Elemento(0, 0);
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    // dtor
}