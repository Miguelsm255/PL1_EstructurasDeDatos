#include "Pila.h"
#include "NodoPila.h"
#include "Proceso.h"
using namespace std;

Pila::Pila()
{
    cima = NULL;
}

Pila::~Pila()
{
    while (cima)
        desapilar();
}

bool Pila::esVacia()
{
    return cima == NULL;
}

void Pila::apilar(Proceso p)
{
    pnodo nuevo = new NodoPila(p, cima);
    // comienzo de la pila nevo nodo
    cima = nuevo;
}

void Pila::desapilar()
{
    pnodo nodo; // puntero aux para manipular el nodo
    if (cima)
    {
        nodo = cima;
    }
    cima = nodo->siguiente;
    delete nodo;
}

int Pila::mostrar()
{
    if (esVacia())
    {
        cout << "Pila vacia" << endl;
    }
    else
    {
        cout << "Cima pila: " << cima->proceso.PID << endl;
    }
    return 0;
}