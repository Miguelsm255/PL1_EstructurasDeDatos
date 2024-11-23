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

void ABBProcesos::setIzquierda(ABBProcesos* nuevoIzquierda)
{
    this->izquierda = nuevoIzquierda;
}

void ABBProcesos::setDerecha(ABBProcesos* nuevoDerecha)
{
    this->derecha = nuevoDerecha;
}





ABBProcesos* buscarPosicion(ABBProcesos* arbol, int prioridad)
{
    if (arbol == nullptr) {
        return nullptr;
    } else {
        if (arbol->obtenerRaiz()->obtenerPrioridad() == prioridad) {
            return arbol;
        } else {
            if (prioridad <= arbol->obtenerRaiz()->obtenerPrioridad()) {
                return buscarPosicion(arbol->obtenerIzquierda(), prioridad);
            } else {
                return buscarPosicion(arbol->obtenerDerecha(), prioridad);
            }
        }
    }
}

ABBProcesos* buscarPadre(int prioridad, ABBProcesos* arbol)
{
    if (arbol == nullptr) {
        return nullptr;
    } else {
        if (prioridad <= arbol->obtenerRaiz()->obtenerPrioridad()) {
            if (arbol->obtenerIzquierda() == nullptr) {
                return arbol;
            } else {
                return buscarPadre(prioridad, arbol->obtenerIzquierda());
            }
        } else {
            if (arbol->obtenerDerecha() == nullptr) {
                return arbol;
            } else {
                return buscarPadre(prioridad, arbol->obtenerDerecha());
            }
        }
    }
}





ABBProcesos* crearNodo(ABBProcesos* arbol, int prioridad)
{
    if (prioridad <= arbol->obtenerRaiz()->obtenerPrioridad())
    {
        arbol->setIzquierda(new ABBProcesos(prioridad));
        return arbol->obtenerIzquierda();
    }
    else
    {
        arbol->setDerecha(new ABBProcesos(prioridad));
        return arbol->obtenerDerecha();
    }
}

ABBProcesos* insertarEn(ABBProcesos* arbol, int prioridad)
{
    ABBProcesos* raiz = buscarPosicion(arbol, prioridad);
    if (raiz == nullptr) {
        raiz = crearNodo(buscarPadre(prioridad, arbol), prioridad);
    }
    return raiz;
}

void ABBProcesos::insertar(Proceso proceso)
{
    insertarEn(this, proceso.prioridad)->setRaiz(proceso);
}
