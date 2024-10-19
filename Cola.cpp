#include "Cola.h"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() // Destructor de la clase Cola
{
}

void Cola::encolar(char e)
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

char Cola::desencolar()
{
    if (!esVacia())
    {
        char elemento = primero->elemento;
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

char Cola::inicio()
{
    if (!esVacia())
    {
        return primero->elemento;
    }
}

char Cola::fin()
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
        std::cout << aux->elemento << " ";
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}