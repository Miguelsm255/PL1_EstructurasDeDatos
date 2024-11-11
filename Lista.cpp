#include "Lista.h"
#include "Proceso.h"
#include "Pila.h"
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
        p->longitud++; // aumento la longitud a cada uno de los nodos
        p->restoListaPtr = new Lista(nucleo, new Lista());  // añado el núcleo al final de la lista
        
    }
    return this;
}

Nucleo Lista::primero(Lista lista)
{
    if (!esVacia())
    {
        return lista.primeroLista;
    }
    else
    {
        return Nucleo();
    }
}

Lista Lista::resto(Lista lista)
{
    if (!esVacia())
    {
        return *lista.restoListaPtr;
    }
    else
    {
        return Lista();
    }
}


Lista* Lista::eliminarNodo(int posicion)
{
    if (!esVacia() && posicion <= longitud)
    {
        if (posicion == 1)
        {
            Lista* temp = this->restoListaPtr;
            *this = *temp;
            delete temp;
        }
        else if (posicion == 2)
        {
            Lista* temp = this->restoListaPtr->restoListaPtr;
            delete this->restoListaPtr;
            this->restoListaPtr = temp;
            this->longitud--;
        }
        else
        {
            Lista* p = this;
            Lista* ultimo;
            for (int i = 2; i < posicion; i++)
            {
                p->longitud--;
                p = p->restoListaPtr;
                if (p->restoListaPtr->restoListaPtr == NULL)
                {
                    ultimo = p;
                }
            }

            if (p->restoListaPtr == NULL)
            {
                delete p;
                ultimo->restoListaPtr = NULL;
            }
            else
            {
                Lista* q = p->restoListaPtr->restoListaPtr;
                delete p->restoListaPtr;
                p->restoListaPtr = q;
            }
        }

    }
    if (longitud == 0)
    {
        vacia = true;

    }
    return this;
}

Lista* Lista::restoPtr(Lista lista)
{
    if (!esVacia())
    {
        return lista.restoListaPtr;
    }
    else
    {
        return NULL;
    }
}

void Lista::mostrarLista(Lista lista)
{
    while (!lista.esVacia())
    {
        cout << lista.primero(lista).getID() << ", ";
        lista = lista.resto(lista);
    }
    cout << endl;
}


Nucleo* Lista::obtenerNodo(int posicion)
{
    if (!esVacia() && posicion <= longitud)
    {
        Lista* p = this;
        for (int i = 1; i < posicion; i++)
        {
            p = p->restoListaPtr;
        }
        return p->primeroPtr();
    }
    else
    {
        cout << "La posición no existe" << endl;
        return NULL;
    }
}

int Lista::longitudLista()
{
    return longitud;
}

Lista::~Lista()
{
    
}

Nucleo* Lista::primeroPtr()
{
    if (!esVacia())
    {
        return &this->primeroLista;
    }
    else
    {
        return NULL;
    }
}
