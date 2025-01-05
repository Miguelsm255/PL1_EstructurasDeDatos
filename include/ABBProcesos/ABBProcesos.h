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
        void setRaiz(ListaProcesos listaProcesos);
        void setIzquierda(ABBProcesos*);
        void setDerecha(ABBProcesos*);

        void insertar(Proceso proceso);
        void borrarNodo(int prioridad, ABBProcesos* arbol);
        ABBProcesos copiarArbol(ABBProcesos* arbol);

        ABBProcesos* obtenerNodoMenor();
        ABBProcesos* obtenerNodoMayor();
        ABBProcesos* obtenerNodoEspecifico(int prioridad);
        int obtenerPrioridadMenor();
        int obtenerPrioridadMayor();
        ListaProcesos* obtenerPrioridadEspecifica(int prioridad);

        int numProcesosEjecutados();
        float mediaTiempos();
        int mayorNumProcesos();
        int menorNumProcesos();

        void mostrarInOrden();
        void mostrarPromedioPreOrden();
};

#endif // ABB_PROCESOS_H
