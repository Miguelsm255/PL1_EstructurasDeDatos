#include "NodoCola.h"
#include "Elemento.h"
NodoCola::NodoCola()
{
    Elemento elemento;
    siguiente = NULL;
    // constructor por defecto
}
NodoCola::NodoCola(Elemento Elemento, NodoCola *sig)
{
    elemento;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    // dtor
}