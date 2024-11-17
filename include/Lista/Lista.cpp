#include "Lista.h"
#include "../Proceso/Proceso.h"
#include "../Pila/Pila.h"
using namespace std;

Lista::Lista()  
{
    vacia = true;
    restoListaPtr = NULL;
    longitud = 0;
}

Lista::Lista(Nucleo nucleo, Lista *resto)
{
    vacia = false;
    primeroLista = nucleo;
    this->restoListaPtr = resto;
    longitud = resto->longitud + 1;
}

bool Lista::esVacia()
{
    return vacia;
}

Lista* Lista::añadirIzquierda(Nucleo nucleo)    // añade un nodo a la izquierda
{
    return new Lista(nucleo, this);     // crea una lista nueva con el núcleo a la izquierda y la
}                                       // lista antigua como resto y lo devuelve
       

Lista* Lista::añadirDerecha(Nucleo nucleo)   // añade un nodo a la derecha
{
    if (esVacia())  // si la lista está vacía
    {
        primeroLista = nucleo;  // el primer nodo es el núcleo
        restoListaPtr = new Lista();    // el resto es una lista vacía
        vacia = false;  // la lista ya no está vacía
        longitud = 1;   // la longitud es 1
    }
    else    // si la lista no está vacía
    {
        Lista* p = this;    // creo un puntero a la lista

        // mientras que el siguiente nodo no sea NULL y la lista no esté vacía (hasta que no llego al final)
        while (p->restoListaPtr != NULL && !p->restoListaPtr->esVacia())    
        {
            p = p->restoListaPtr;   // avanzo en la lista
            
        }
        
        p->restoListaPtr = new Lista(nucleo, new Lista());  // añado el núcleo al final de la lista
        longitud++; // aumento la longitud a cada uno de los nodos
    }
    return this;    // devuelvo la lista
}

Nucleo Lista::primero(Lista lista)  // devuelve el primer nodo
{
    if (!esVacia())   // si la lista no está vacía
    {
        return lista.primeroLista;  // devuelvo el primer nodo
    }
    else
    {
        return Nucleo();    // si la lista está vacía, devuelvo un núcleo vacío
    }
}

Lista Lista::resto(Lista lista) // devuelve el resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {   
        return *lista.restoListaPtr;    // devuelvo el resto de la lista
    }
    else
    {
        return Lista(); // si la lista está vacía, devuelvo una lista vacía
    }
}


Lista* Lista::eliminarNodo(int posicion)    // elimina un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        if (posicion == 1)  // si la posición es 1
            {
            Lista* temp = this->restoListaPtr;  // creo un puntero a la lista
            *this = *temp;  // la lista actual es igual a la lista siguiente
            delete temp;    
        }
        else if (posicion == 2) // si la posición es 2
        {
            Lista* temp = this->restoListaPtr->restoListaPtr;   // creo un puntero a la lista siguiente
            delete this->restoListaPtr; // elimino el nodo siguiente
            this->restoListaPtr = temp; // el siguiente nodo es el sigueinte del siguiente
            this->longitud--;   // resto 1 a la longitud
        }
        else    // si la posición es mayor que 2
        {   
            Lista* p = this;    // creo un puntero a la lista
            Lista* ultimo;      // declaro un puntero en el que guardaré el último nodo
            for (int i = 2; i < posicion; i++) // recorro la lista hasta la posición 
            {
                p->longitud--; // resto 1 a la longitud
                p = p->restoListaPtr;   // avanzo en la lista
                if (p->restoListaPtr->restoListaPtr == NULL)   // si el siguiente nodo es NULL
                {
                    ultimo = p; // "último" = el nodo actual
                }
            }

            if (p->restoListaPtr == NULL)   // si el siguiente nodo es NULL
            {
                delete p;   // elimino el nodo actual
                ultimo->restoListaPtr = NULL;   // el siguiente del último es NULL
            }
            else    // si el siguiente nodo no es NULL
            {
                Lista* q = p->restoListaPtr->restoListaPtr; // creo un puntero al siguiente del siguiente
                delete p->restoListaPtr;    // elimino el siguiente nodo
                p->restoListaPtr = q;   // el siguiente nodo es el siguiente del siguiente
            }
        }

    }
    if (longitud == 0)  // si la longitud es 0
    {
        vacia = true;   // la lista está vacía

    }
    return this;    // devuelvo la lista
}

Lista* Lista::restoPtr(Lista lista) // devuelve el puntero al resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {
        return lista.restoListaPtr;   // devuelvo el puntero al resto de la lista
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}

void Lista::mostrarLista(Lista lista)   // muestra la lista
{
    while (!lista.esVacia())    // mientras que la lista no esté vacía
    {
        cout << lista.primero(lista).getID() << ", ";   // muestro el ID del primer nodo
        lista = lista.resto(lista); // la lista es el resto de la lista
    }
    cout << endl;   // salto de línea
}


Nucleo* Lista::obtenerNodo(int posicion)    // obtiene un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        Lista* p = this;    // creo un puntero a la lista
        for (int i = 1; i < posicion; i++)  // recorro la lista hasta la posición
        {
            p = p->restoListaPtr;   // avanzo en la lista
        }
        return p->primeroPtr(); // devuelvo el puntero al primer nodo
    }
    else    // si la lista está vacía o la posición no existe
    {
        cout << "La posición no existe" << endl;    // muestro un mensaje de error
        return NULL;    // devuelvo NULL
    }
}

int Lista::longitudLista()  // devuelve la longitud de la lista
{
    return longitud;    // devuelvo la longitud
}

Lista::~Lista()
{
    
}

Nucleo* Lista::primeroPtr() // devuelve el puntero al primer nodo
{   
    if (!esVacia()) // si la lista no está vacía
    {
        return &this->primeroLista;   // devuelvo el puntero al primer nodo
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}
