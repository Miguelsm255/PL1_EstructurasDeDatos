#include "Lista.h"
#include "Proceso.h"
using namespace std;

Lista::Lista()
{
    restoListaPtr = NULL;
    longitud = 0;
}

Lista::Lista(Nucleo nucleo, Lista *resto)
{
    primeroLista = nucleo;
    this->restoListaPtr = resto;
    longitud = resto->longitud + 1;
}

bool Lista::esVacia()
{
    return restoListaPtr == NULL;
}

Lista Lista::añadirIzquierda(Nucleo nucleo)
{
    return Lista(nucleo, this);
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

Lista Lista::eliminarNodo(int posicion)
{
    if (!esVacia() && posicion <= longitud)
    {
        Lista aux = Lista();
        while (posicion > 0)
        {
            aux = aux.añadirIzquierda(primero(*this));
            *this = resto(*this);
            posicion--;
        }
        aux = resto(aux);
        while (aux.esVacia())
        {
            *this = this->añadirIzquierda(primero(aux));
            aux = resto(aux);
        }
        this->longitud -= 1;
    }
    else if(posicion > longitud)
    {
        cout << "La posición no existe" << endl;
    }
    return *this;
}

Nucleo* Lista::obtenerNodo(int posicion)
{
    if (!esVacia() && posicion <= longitud)
    {
        Lista aux = Lista();
        while (posicion > 1)
        {
            aux = aux.añadirIzquierda(primero(*this));
            *this = resto(*this);
            posicion--;
        }
        Nucleo* ptrNucleo = primeroPtr(*this);
        while (aux.esVacia())
        {
            *this = this->añadirIzquierda(primero(aux));
            aux = resto(aux);
        }
        return ptrNucleo;
    }
    else if(posicion > longitud)
    {
        cout << "La posición no existe" << endl;
        return NULL;
    }
    return NULL;
}

int Lista::longitudLista()
{
    return longitud;
}

Lista::~Lista()
{
    
}

Nucleo* Lista::primeroPtr(Lista lista)
{
    if (!esVacia())
    {
        return &lista.primeroLista;
    }
    else
    {
        return NULL;
    }
}
