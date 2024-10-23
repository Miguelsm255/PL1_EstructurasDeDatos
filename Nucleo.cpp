#include "Nucleo.h"
#include "Proceso.h"
#include "Cola.h"
using namespace std;

Nucleo::Nucleo()
{
    colaNucleo = Cola();
}

Nucleo::~Nucleo()
{

}

bool Nucleo::esVacio()
{
    return colaNucleo.esVacia();
}

void Nucleo::procesar(Proceso proceso)
{
    if (esVacio())
    {
        colaNucleo.encolar(proceso);
    }
}

void Nucleo::quitarProceso()
{
    colaNucleo.desencolar();
}   

void Nucleo::mostrarColaNucleo()
{
    colaNucleo.mostrarCola();
}
