#include "ListaProcesos.h"
#include "../Proceso/Proceso.h"
#include "../Pila/Pila.h"
using namespace std;

ListaProcesos::ListaProcesos()  
{
    vacia = true;
    restoListaProcesosPtr = NULL;
    longitud = 0;
    prioridad = -1;
}

ListaProcesos::ListaProcesos(int pr)  
{
    vacia = true;
    restoListaProcesosPtr = NULL;
    longitud = 0;
    prioridad = pr;
}

ListaProcesos::ListaProcesos(int pr, Proceso proceso, ListaProcesos *resto)
{
    vacia = false;
    primeroListaProcesos = proceso;
    this->restoListaProcesosPtr = resto;
    longitud = resto->longitud + 1;
    prioridad = pr;
}

bool ListaProcesos::esVacia()
{
    return vacia;
}

ListaProcesos* ListaProcesos::añadirIzquierda(Proceso proceso)    // añade un nodo a la izquierda
{
    return new ListaProcesos(proceso.prioridad, proceso, this);     // crea una lista nueva con el núcleo a la izquierda y la
}                                       // lista antigua como resto y lo devuelve
       

ListaProcesos* ListaProcesos::añadirDerecha(Proceso proceso)   // añade un nodo a la derecha
{
    if (esVacia())  // si la lista está vacía
    {
        primeroListaProcesos = proceso;  // el primer nodo es el núcleo
        restoListaProcesosPtr = new ListaProcesos(proceso.prioridad);    // el resto es una lista vacía
        vacia = false;  // la lista ya no está vacía
        longitud = 1;   // la longitud es 1
    }
    else    // si la lista no está vacía
    {
        ListaProcesos* p = this;    // creo un puntero a la lista

        // mientras que el siguiente nodo no sea NULL y la lista no esté vacía (hasta que no llego al final)
        while (p->restoListaProcesosPtr != NULL && !p->restoListaProcesosPtr->esVacia())    
        {
            p->longitud++; // aumento la longitud a cada uno de los nodos
            p = p->restoListaProcesosPtr;   // avanzo en la lista
            
        }
        p->longitud++;
        p->restoListaProcesosPtr = new ListaProcesos(proceso.prioridad, proceso, new ListaProcesos(p->prioridad));  // añado el núcleo al final de la lista
    }
    return this;    // devuelvo la lista
}

Proceso ListaProcesos::primero(ListaProcesos lista)  // devuelve el primer nodo
{
    if (!esVacia())   // si la lista no está vacía
    {
        return lista.primeroListaProcesos;  // devuelvo el primer nodo
    }
    else
    {
        return Proceso();    // si la lista está vacía, devuelvo un núcleo vacío
    }
}

ListaProcesos ListaProcesos::resto(ListaProcesos lista) // devuelve el resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {   
        return *lista.restoListaProcesosPtr;    // devuelvo el resto de la lista
    }
    else
    {
        return ListaProcesos(-1); // si la lista está vacía, devuelvo una lista vacía
    }
}


ListaProcesos* ListaProcesos::eliminarNodo(int posicion)    // elimina un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        if (posicion == 1)  // si la posición es 1
            {
            ListaProcesos* temp = this->restoListaProcesosPtr;  // creo un puntero a la lista
            *this = *temp;  // la lista actual es igual a la lista siguiente
            delete temp;    
        }
        else if (posicion == 2) // si la posición es 2
        {
            ListaProcesos* temp = this->restoListaProcesosPtr->restoListaProcesosPtr;   // creo un puntero a la lista siguiente
            delete this->restoListaProcesosPtr; // elimino el nodo siguiente
            this->restoListaProcesosPtr = temp; // el siguiente nodo es el sigueinte del siguiente
            this->longitud--;   // resto 1 a la longitud
        }
        else    // si la posición es mayor que 2
        {   
            ListaProcesos* p = this;    // creo un puntero a la lista
            ListaProcesos* ultimo;      // declaro un puntero en el que guardaré el último nodo
            for (int i = 2; i < posicion; i++) // recorro la lista hasta la posición 
            {
                p->longitud--; // resto 1 a la longitud
                p = p->restoListaProcesosPtr;   // avanzo en la lista
                if (p->restoListaProcesosPtr->restoListaProcesosPtr == NULL)   // si el siguiente nodo es NULL
                {
                    ultimo = p; // "último" = el nodo actual
                }
            }

            if (p->restoListaProcesosPtr == NULL)   // si el siguiente nodo es NULL
            {
                delete p;   // elimino el nodo actual
                ultimo->restoListaProcesosPtr = NULL;   // el siguiente del último es NULL
            }
            else    // si el siguiente nodo no es NULL
            {
                ListaProcesos* q = p->restoListaProcesosPtr->restoListaProcesosPtr; // creo un puntero al siguiente del siguiente
                delete p->restoListaProcesosPtr;    // elimino el siguiente nodo
                p->restoListaProcesosPtr = q;   // el siguiente nodo es el siguiente del siguiente
            }
        }

    }
    if (longitud == 0)  // si la longitud es 0
    {
        vacia = true;   // la lista está vacía

    }
    return this;    // devuelvo la lista
}

ListaProcesos* ListaProcesos::restoPtr(ListaProcesos lista) // devuelve el puntero al resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {
        return lista.restoListaProcesosPtr;   // devuelvo el puntero al resto de la lista
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}

void ListaProcesos::mostrarListaProcesos(ListaProcesos lista)   // muestra la lista
{
    while (!lista.esVacia())    // mientras que la lista no esté vacía
    {
        cout << lista.primero(lista).PID << ", ";   // muestro el ID del primer nodo
        lista = lista.resto(lista); // la lista es el resto de la lista
    }
    cout << endl;   // salto de línea
}


Proceso* ListaProcesos::obtenerNodo(int posicion)    // obtiene un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        ListaProcesos* p = this;    // creo un puntero a la lista
        for (int i = 1; i < posicion; i++)  // recorro la lista hasta la posición
        {
            p = p->restoListaProcesosPtr;   // avanzo en la lista
        }
        return p->primeroPtr(); // devuelvo el puntero al primer nodo
    }
    else    // si la lista está vacía o la posición no existe
    {
        cout << "La posición no existe" << endl;    // muestro un mensaje de error
        return NULL;    // devuelvo NULL
    }
}

int ListaProcesos::longitudListaProcesos()  // devuelve la longitud de la lista
{
    return longitud;    // devuelvo la longitud
}

ListaProcesos::~ListaProcesos()
{
    
}

Proceso* ListaProcesos::primeroPtr() // devuelve el puntero al primer nodo
{   
    if (!esVacia()) // si la lista no está vacía
    {
        return &this->primeroListaProcesos;   // devuelvo el puntero al primer nodo
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}

int ListaProcesos::obtenerPrioridad()
{
    return prioridad;
}
