#include "Cola.h"
#include "Elemento.h"
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

void Cola::encolar(Elemento e)
{
    NodoCola *nuevo = new NodoCola(e);
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

Elemento Cola::desencolar()
{
    if (!esVacia())
    {
        Elemento elemento = primero->elemento;
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
        return elemento;
    }
}

Elemento Cola::inicio()
{
    if (!esVacia())
    {
        return primero->elemento;
    }
}

Elemento Cola::fin()
{
    if (!esVacia())
    {
        return ultimo->elemento;
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
        cout << aux->elemento.PID << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

void Cola::encolarPrioridad(Elemento e)
{
    NodoCola *nuevo = new NodoCola(e);
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