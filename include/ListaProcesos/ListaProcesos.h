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
    int prioridad;

public:
    ListaProcesos();
    ListaProcesos(int prioridad);
    ListaProcesos(int pr, Proceso proceso, ListaProcesos *resto = new ListaProcesos());
    ~ListaProcesos();

    bool esVacia();

    ListaProcesos resto(ListaProcesos lista);
    ListaProcesos* restoPtr(ListaProcesos lista);
    Proceso primero(ListaProcesos lista);
    Proceso* primeroPtr();

    Proceso* obtenerNodo(int posicion);
    int obtenerPrioridad();
    ListaProcesos* eliminarNodo(int posicion);
    ListaProcesos* añadirIzquierda(Proceso proceso);
    ListaProcesos* añadirDerecha(Proceso proceso);
    int longitudListaProcesos();
    int sumaTiemposProcesos();
    float mediaTiempos();

    void mostrarListaProcesos();
    ListaProcesos obtenerOrdenadaPorPrioridad();
    
};
#endif // NODOCOLA_H