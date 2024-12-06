#ifndef LISTA_NUCLEOS_H
#define LISTA_NUCLEOS_H
#include "../Nucleo/Nucleo.h"
#include "../Pila/Pila.h"
#include "../ABBProcesos/ABBProcesos.h"
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
    Nucleo primero(ListaNucleos lista);
    Nucleo* primeroPtr();
    ListaNucleos resto(ListaNucleos lista);
    ListaNucleos* restoPtr(ListaNucleos lista);
    
    Nucleo* obtenerNodo(int posicion);
    ListaNucleos* eliminarNodo(int posicion);
    int longitudListaNucleos();
    Nucleo* nucleoConMenosProcesos();
    Nucleo* nucleoConMasProcesos();

    ListaNucleos* añadirIzquierda(Nucleo nucleo);
    ListaNucleos* añadirDerecha(Nucleo nucleo);
    
    bool nucleosVacios();

    void mostrarListaNucleos(ListaNucleos lista);
    void mostrarColasDeNucleos();
    void eliminarNucleosVacios();
    void actualizarColasyNucleos(ABBProcesos* arbolProcesos);
    void encolarEnElMenor(Pila* pila);
    void hacerHueco();
    void desencolarYProcesar();
    void detallesProcesosEjecucion();
    void mostrarMenosOcupado();
    void mostrarMasOcupado();
};
#endif // NODOCOLA_H