#ifndef LISTA_H
#define LISTA_H
#include "Nucleo.h"
#include <iostream>

class Lista
{
private:
    Nucleo primeroLista;
    Lista *restoListaPtr;
    int longitud;
public:
    Lista();
    Lista(Nucleo nucleo, Lista *resto = new Lista());
    ~Lista();
    bool esVacia();
    Lista resto(Lista lista);
    Nucleo primero(Lista lista);
    Lista eliminarNodo(int posicion);
    Lista añadirIzquierda(Nucleo nucleo);
    int longitudLista();
};
#endif // NODOCOLA_H