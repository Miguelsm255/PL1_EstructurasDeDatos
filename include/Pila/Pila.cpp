#include "Pila.h"
#include "NodoPila.h"
#include "../Proceso/Proceso.h"
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

void Pila::apilar(Proceso p)    // apila un proceso
{
    pnodo nuevo = new NodoPila(p, cima);    // creo un nuevo nodo con el proceso y que apunte a la cima
    // comienzo de la pila nevo nodo
    cima = nuevo;   // la cima es el nuevo nodo
}

void Pila::desapilar()  // desapila un proceso
{
    pnodo nodo; // puntero aux para manipular el nodo
    if (cima)   // si la pila no está vacía
    {
        nodo = cima;    // el nodo auxiliar es la cima
        cima = nodo->siguiente; // la cima es el siguiente nodo
        delete nodo;    // borro el nodo
    }
    
}

void Pila::mostrar()    // muestra la pila
{   
    if (!esVacia()) // si la pila no está vacía
    {
        NodoPila *aux = cima;   // nodo auxiliar para recorrer la pila
        while (aux != NULL)     // mientras el nodo auxiliar no sea nulo
        {
            cout << aux->proceso.PID << " ";    // muestro el PID del proceso
            aux = aux->siguiente;               // avanzo al siguiente nodo
        }
        cout << endl;
    }
    else    // si la pila está vacía
    {
        cout << "La pila está vacía." << endl;  // muestro que la pila está vacía
    }
}

Proceso Pila::cimaPila()    // devuelve el proceso de la cima
{
    if (!esVacia()) // si la pila no está vacía
    {
        return cima->proceso;   // devuelvo el proceso de la cima
    }
    return Proceso();   // si la pila está vacía devuelvo un proceso vacío
}

void Pila::insertarTiempo(Proceso proceso)  // inserta un proceso en la pila según su tiempo de inicio
{
    if (esVacia())  // si la pila está vacía
    {
        apilar(proceso);    // apilo el proceso
    }
    else    // si la pila no está vacía
    {
        Pila *aux = new Pila(); // pila auxiliar
        // mientras la pila no esté vacía y el tiempo de inicio del proceso sea menor o igual al tiempo de inicio del proceso de la cima
        while (!esVacia() && cimaPila().tiempoInicio <= proceso.tiempoInicio)   
        {
            aux->apilar(cimaPila());    // apilo el proceso de la cima en la pila auxiliar
            desapilar();        // desapilo el proceso de la cima
        }

        apilar(proceso);    // apilo el proceso

        while (!aux->esVacia()) // mientras la pila auxiliar no esté vacía
        {
            apilar(aux->cimaPila());    // apilo el proceso de la cima de la pila auxiliar
            aux->desapilar();        // desapilo el proceso de la cima de la pila auxiliar
        }
        delete aux;
    }

}
