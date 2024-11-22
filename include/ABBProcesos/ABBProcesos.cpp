#include "ABBProcesos.h"
#include "../ListaProcesos/ListaProcesos.h"
#include "../Proceso/Proceso.h"
using namespace std;

ABBProcesos::ABBProcesos()
{
    raiz = ListaProcesos(-1);
    izquierda = nullptr;
    derecha = nullptr;
}

ABBProcesos::ABBProcesos(int prioridad)
{
    raiz = ListaProcesos(prioridad);
    izquierda = nullptr;
    derecha = nullptr;
}

ABBProcesos::~ABBProcesos()
{

}




bool ABBProcesos::esVacio()
{
    return raiz.esVacia();
}

bool ABBProcesos::esHoja()
{
    return (izquierda == nullptr && derecha == nullptr);
}




ListaProcesos* ABBProcesos::obtenerRaiz()
{
    return &raiz;
}


ABBProcesos* ABBProcesos::obtenerIzquierda()
{
    return izquierda;
}

ABBProcesos* ABBProcesos::obtenerDerecha()
{
    return derecha;
}

void ABBProcesos::setRaiz(Proceso proceso)
{
    this->obtenerRaiz()->añadirDerecha(proceso);
}

void ABBProcesos::setProcesoIzquierda(Proceso proceso)
{
    this->izquierda = new ABBProcesos(proceso.prioridad);
    this->obtenerIzquierda()->obtenerRaiz()->añadirDerecha(proceso);
}

void ABBProcesos::setProcesoDerecha(Proceso proceso)
{
    this->derecha = new ABBProcesos(proceso.prioridad);
    this->obtenerDerecha()->obtenerRaiz()->añadirDerecha(proceso);
}

void ABBProcesos::setArbolIzquierda(ABBProcesos* nuevoIzquierda)
{
    this->izquierda = nuevoIzquierda;
}

void ABBProcesos::setArbolDerecha(ABBProcesos* nuevoDerecha)
{
    this->derecha = nuevoDerecha;
}





ABBProcesos* insertarRecursivo(ABBProcesos* arbol, Proceso proceso)
{
    if (arbol->obtenerRaiz()->obtenerPrioridad() == proceso.prioridad)
    {
        arbol->setRaiz(proceso);
    }
    else
    {
        if (proceso.prioridad <= arbol->obtenerRaiz()->obtenerPrioridad())
        {
            if (arbol->obtenerIzquierda() == nullptr)
            {
                arbol->setProcesoIzquierda(proceso);
            }
            else
            {
                ABBProcesos* nuevaIzquierda = insertarRecursivo(arbol->obtenerIzquierda(), proceso);
                arbol->setArbolIzquierda(nuevaIzquierda);
            }
        }
        else
        {
            if (arbol->obtenerDerecha() == nullptr)
            {
                arbol->setProcesoDerecha(proceso);
            }
            else
            {
                ABBProcesos* nuevaDerecha = insertarRecursivo(arbol->obtenerDerecha(), proceso);
                arbol->setArbolDerecha(nuevaDerecha);
            }
        }
    }
    return arbol;
}

void ABBProcesos::insertar(Proceso proceso)
{
    ABBProcesos* arbolInsertado = insertarRecursivo(this, proceso);
    this->raiz = arbolInsertado->raiz;
    this->izquierda = arbolInsertado->izquierda;
    this->derecha = arbolInsertado->derecha;
}
