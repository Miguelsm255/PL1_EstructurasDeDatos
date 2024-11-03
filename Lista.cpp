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

Lista* Lista::añadirIzquierda(Nucleo nucleo)
{
    return new Lista(nucleo, this);
    // Lista *nuevaLista = new Lista(nucleo, this);
    // *this = *nuevaLista;
    // delete nuevaLista;
    // this->longitud += 1;
    
}

Lista* Lista::añadirDerecha(Nucleo nucleo)
{
    if (esVacia())
    {
        primeroLista = nucleo;
        restoListaPtr = new Lista();
        vacia = false;
        longitud = 1;
    }
    else
    {
        Lista* p = this;
        while (p->restoListaPtr != NULL && !p->restoListaPtr->esVacia())
        {
            p = p->restoListaPtr;
        }
        p->restoListaPtr = new Lista(nucleo, new Lista());
        longitud++;
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

// Lista Lista::eliminarNodo(int posicion)
// {
//     if (!esVacia() && posicion <= longitud)
//     {
//         Lista aux = Lista();
//         while (posicion > 1)
//         {
//             aux = aux.añadirIzquierda(primero(*this));
//             *this = resto(*this);
//             posicion--;
//         }
//         aux = resto(aux);
//         while (!aux.esVacia())
//         {
//             this->longitud -= 1;
//             *this = this->añadirIzquierda(primero(aux));
//             aux = resto(aux);
//         }
        
//     }
//     else if(posicion > longitud)
//     {
//         cout << "La posición no existe" << endl;
//     }
//     return *this;
// }

// FALTA IR RESTANDO 1 A LA LONGITUD DE LAS LISTAS POR LAS QUE VOY PASANDO
Lista Lista::eliminarNodo(int posicion)
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
    return *this;
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



// Nucleo* Lista::obtenerNodo(int posicion)
// {

//     if (!esVacia() && posicion <= longitud)
//     {
//         Lista aux = Lista();
//         while (posicion > 1)
//         {
//             aux = aux.añadirIzquierda(primero(*this));
//             *this = resto(*this);
//             posicion--;
//         }

//         Nucleo* ptrNucleo = primeroPtr();

//         while (!aux.esVacia())
//         {
//             *this = this->añadirIzquierda(primero(aux));
//             aux = resto(aux);
//         }
//         return ptrNucleo;
//     }
//     else if(posicion > longitud)
//     {
//         cout << "La posición no existe" << endl;
//         return NULL;
//     }
//     return NULL;
// }

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
