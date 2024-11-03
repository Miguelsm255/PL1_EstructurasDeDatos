#ifndef LISTA_H
#define LISTA_H
#include "Nucleo.h"
#include <iostream>

class Lista
{
private:
    Nucleo primeroLista;
    
    int longitud;
    bool vacia;
public:
Lista *restoListaPtr;
    Lista();
    Lista(Nucleo nucleo, Lista *resto = new Lista());
    ~Lista();
    bool esVacia();
    Lista resto(Lista lista);
    Lista* restoPtr(Lista lista);
    Nucleo primero(Lista lista);
    Nucleo* obtenerNodo(int posicion);
    Lista eliminarNodo(int posicion);
    Lista* añadirIzquierda(Nucleo nucleo);
    Lista* añadirDerecha(Nucleo nucleo);
    int longitudLista();
    Nucleo* primeroPtr();
    void mostrarLista(Lista lista);
};
#endif // NODOCOLA_H