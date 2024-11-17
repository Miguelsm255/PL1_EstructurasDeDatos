#ifndef LISTA_H
#define LISTA_H
#include "../Nucleo/Nucleo.h"
#include <iostream>

class ListaNucleos
{
private:
    Nucleo primeroListaNucleos;
    ListaNucleos* restoListaNucleosPtr;
    int longitud;
    bool vacia;
public:
    ListaNucleos();
    ListaNucleos(Nucleo nucleo, ListaNucleos *resto = new ListaNucleos());
    ~ListaNucleos();
    bool esVacia();
    ListaNucleos resto(ListaNucleos lista);
    ListaNucleos* restoPtr(ListaNucleos lista);
    Nucleo primero(ListaNucleos lista);
    Nucleo* obtenerNodo(int posicion);
    ListaNucleos* eliminarNodo(int posicion);
    ListaNucleos* añadirIzquierda(Nucleo nucleo);
    ListaNucleos* añadirDerecha(Nucleo nucleo);
    int longitudListaNucleos();
    Nucleo* primeroPtr();
    void mostrarListaNucleos(ListaNucleos lista);
};
#endif // NODOCOLA_H