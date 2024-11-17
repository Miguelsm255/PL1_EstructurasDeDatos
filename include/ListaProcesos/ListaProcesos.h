#ifndef LISTA_PROCESOS_H
#define LISTA_PROCESOS_H
#include "../Proceso/Proceso.h"
#include <iostream>

class ListaProcesos
{
private:
    Proceso primeroListaProcesos;
    ListaProcesos* restoListaProcesosPtr;
    int longitud;
    bool vacia;
public:
    ListaProcesos();
    ListaProcesos(Proceso proceso, ListaProcesos *resto = new ListaProcesos());
    ~ListaProcesos();
    bool esVacia();
    ListaProcesos resto(ListaProcesos lista);
    ListaProcesos* restoPtr(ListaProcesos lista);
    Proceso primero(ListaProcesos lista);
    Proceso* obtenerNodo(int posicion);
    ListaProcesos* eliminarNodo(int posicion);
    ListaProcesos* añadirIzquierda(Proceso proceso);
    ListaProcesos* añadirDerecha(Proceso proceso);
    int longitudListaProcesos();
    Proceso* primeroPtr();
    void mostrarListaProcesos(ListaProcesos lista);
};
#endif // NODOCOLA_H