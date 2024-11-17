#include "ListaNucleos.h"
#include "../Proceso/Proceso.h"
#include "../Pila/Pila.h"
using namespace std;

ListaNucleos::ListaNucleos()  
{
    vacia = true;
    restoListaNucleosPtr = NULL;
    longitud = 0;
}

ListaNucleos::ListaNucleos(Nucleo nucleo, ListaNucleos *resto)
{
    vacia = false;
    primeroListaNucleos = nucleo;
    this->restoListaNucleosPtr = resto;
    longitud = resto->longitud + 1;
}

bool ListaNucleos::esVacia()
{
    return vacia;
}

ListaNucleos* ListaNucleos::añadirIzquierda(Nucleo nucleo)    // añade un nodo a la izquierda
{
    return new ListaNucleos(nucleo, this);     // crea una lista nueva con el núcleo a la izquierda y la
}                                       // lista antigua como resto y lo devuelve
       

ListaNucleos* ListaNucleos::añadirDerecha(Nucleo nucleo)   // añade un nodo a la derecha
{
    if (esVacia())  // si la lista está vacía
    {
        primeroListaNucleos = nucleo;  // el primer nodo es el núcleo
        restoListaNucleosPtr = new ListaNucleos();    // el resto es una lista vacía
        vacia = false;  // la lista ya no está vacía
        longitud = 1;   // la longitud es 1
    }
    else    // si la lista no está vacía
    {
        ListaNucleos* p = this;    // creo un puntero a la lista

        // mientras que el siguiente nodo no sea NULL y la lista no esté vacía (hasta que no llego al final)
        while (p->restoListaNucleosPtr != NULL && !p->restoListaNucleosPtr->esVacia())    
        {
            p->longitud++; // aumento la longitud a cada uno de los nodos
            p = p->restoListaNucleosPtr;   // avanzo en la lista
            
        }
        p->longitud++;
        p->restoListaNucleosPtr = new ListaNucleos(nucleo, new ListaNucleos());  // añado el núcleo al final de la lista
    }
    return this;    // devuelvo la lista
}

Nucleo ListaNucleos::primero(ListaNucleos lista)  // devuelve el primer nodo
{
    if (!esVacia())   // si la lista no está vacía
    {
        return lista.primeroListaNucleos;  // devuelvo el primer nodo
    }
    else
    {
        return Nucleo();    // si la lista está vacía, devuelvo un núcleo vacío
    }
}

ListaNucleos ListaNucleos::resto(ListaNucleos lista) // devuelve el resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {   
        return *lista.restoListaNucleosPtr;    // devuelvo el resto de la lista
    }
    else
    {
        return ListaNucleos(); // si la lista está vacía, devuelvo una lista vacía
    }
}


ListaNucleos* ListaNucleos::eliminarNodo(int posicion)    // elimina un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        if (posicion == 1)  // si la posición es 1
            {
            ListaNucleos* temp = this->restoListaNucleosPtr;  // creo un puntero a la lista
            *this = *temp;  // la lista actual es igual a la lista siguiente
            delete temp;    
        }
        else if (posicion == 2) // si la posición es 2
        {
            ListaNucleos* temp = this->restoListaNucleosPtr->restoListaNucleosPtr;   // creo un puntero a la lista siguiente
            delete this->restoListaNucleosPtr; // elimino el nodo siguiente
            this->restoListaNucleosPtr = temp; // el siguiente nodo es el sigueinte del siguiente
            this->longitud--;   // resto 1 a la longitud
        }
        else    // si la posición es mayor que 2
        {   
            ListaNucleos* p = this;    // creo un puntero a la lista
            ListaNucleos* ultimo;      // declaro un puntero en el que guardaré el último nodo
            for (int i = 2; i < posicion; i++) // recorro la lista hasta la posición 
            {
                p->longitud--; // resto 1 a la longitud
                p = p->restoListaNucleosPtr;   // avanzo en la lista
                if (p->restoListaNucleosPtr->restoListaNucleosPtr == NULL)   // si el siguiente nodo es NULL
                {
                    ultimo = p; // "último" = el nodo actual
                }
            }

            if (p->restoListaNucleosPtr == NULL)   // si el siguiente nodo es NULL
            {
                delete p;   // elimino el nodo actual
                ultimo->restoListaNucleosPtr = NULL;   // el siguiente del último es NULL
            }
            else    // si el siguiente nodo no es NULL
            {
                ListaNucleos* q = p->restoListaNucleosPtr->restoListaNucleosPtr; // creo un puntero al siguiente del siguiente
                delete p->restoListaNucleosPtr;    // elimino el siguiente nodo
                p->restoListaNucleosPtr = q;   // el siguiente nodo es el siguiente del siguiente
            }
        }

    }
    if (longitud == 0)  // si la longitud es 0
    {
        vacia = true;   // la lista está vacía

    }
    return this;    // devuelvo la lista
}

ListaNucleos* ListaNucleos::restoPtr(ListaNucleos lista) // devuelve el puntero al resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {
        return lista.restoListaNucleosPtr;   // devuelvo el puntero al resto de la lista
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}

void ListaNucleos::mostrarListaNucleos(ListaNucleos lista)   // muestra la lista
{
    while (!lista.esVacia())    // mientras que la lista no esté vacía
    {
        cout << lista.primero(lista).getID() << ", ";   // muestro el ID del primer nodo
        lista = lista.resto(lista); // la lista es el resto de la lista
    }
    cout << endl;   // salto de línea
}


Nucleo* ListaNucleos::obtenerNodo(int posicion)    // obtiene un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        ListaNucleos* p = this;    // creo un puntero a la lista
        for (int i = 1; i < posicion; i++)  // recorro la lista hasta la posición
        {
            p = p->restoListaNucleosPtr;   // avanzo en la lista
        }
        return p->primeroPtr(); // devuelvo el puntero al primer nodo
    }
    else    // si la lista está vacía o la posición no existe
    {
        cout << "La posición no existe" << endl;    // muestro un mensaje de error
        return NULL;    // devuelvo NULL
    }
}

int ListaNucleos::longitudListaNucleos()  // devuelve la longitud de la lista
{
    return longitud;    // devuelvo la longitud
}

ListaNucleos::~ListaNucleos()
{
    
}

Nucleo* ListaNucleos::primeroPtr() // devuelve el puntero al primer nodo
{   
    if (!esVacia()) // si la lista no está vacía
    {
        return &this->primeroListaNucleos;   // devuelvo el puntero al primer nodo
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}
