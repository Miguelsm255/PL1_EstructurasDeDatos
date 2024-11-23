#ifndef ABB_PROCESOS_H
#define ABB_PROCESOS_H

#include "../ListaProcesos/ListaProcesos.h"
#include "../Proceso/Proceso.h"
#include <iostream>

class ABBProcesos
{
    private:
        ListaProcesos raiz;
        ABBProcesos* izquierda;
        ABBProcesos* derecha;
    public:
        ABBProcesos();
        ABBProcesos(int prioridad);
        ~ABBProcesos();

        bool esVacio();
        bool esHoja();

        ListaProcesos* obtenerRaiz();
        ABBProcesos* obtenerIzquierda();
        ABBProcesos* obtenerDerecha();
        void setRaiz(Proceso proceso);
        void setIzquierda(ABBProcesos*);
        void setDerecha(ABBProcesos*);

        void insertar(Proceso proceso);
        ListaProcesos obtenerPrioridadEspecifica(int prioridad);

        void mostrarInOrden();
        void mostrarPreOrden();
        void mostrarPostOrden();
        int obtenerAlutra();
};

#endif // ABB_PROCESOS_H
