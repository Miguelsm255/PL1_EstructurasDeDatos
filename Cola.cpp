#include "Cola.h"
#include "Proceso.h"
using namespace std;

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() // Destructor de la clase Cola
{
}

void Cola::encolar(Proceso p)
{
    NodoCola *nuevo = new NodoCola(p);
    if (esVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}

Proceso Cola::desencolar()
{
    if (!esVacia())
    {
        Proceso proceso = primero->proceso;
        NodoCola *aux = primero;

        if ((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete aux;
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete aux;
        }
        longitud--;
        return proceso;
    }
}

Proceso Cola::inicio()
{
    if (!esVacia())
    {
        return primero->proceso;
    }
}

Proceso Cola::fin()
{
    if (!esVacia())
    {
        return ultimo->proceso;
    }
}

int Cola::colaLongitud()
{
    return longitud;
}

bool Cola::esVacia()
{
    return (primero == NULL) && (ultimo == NULL);
}

void Cola::mostrarCola()
{
    NodoCola *aux = primero;
    while (aux != NULL)
    {
        cout << aux->proceso.PID << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

void Cola::encolarPrioridad(Proceso p)
{
    NodoCola *nuevo = new NodoCola(p);
    if (esVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        Cola *Cola_aux = new Cola();
        while (primero->proceso.prioridad >= p.prioridad)
        {
            Cola_aux->encolar(desencolar());
        }
        Cola_aux->encolar(p);
        while (!esVacia())
        {
            Cola_aux->encolar(desencolar());
        }
        while (!Cola_aux->esVacia())
        {
            encolar(Cola_aux->desencolar());
        }
        delete (Cola_aux);
    }
    longitud++;
}