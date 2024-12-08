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

void ABBProcesos::setRaiz(ListaProcesos listaProcesos)
{
    this->raiz = listaProcesos;
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
            if (arbol->obtenerIzquierda() == nullptr || prioridad == arbol->obtenerIzquierda()->obtenerRaiz()->obtenerPrioridad()) {
                return arbol;
            } else {
                return buscarPadre(prioridad, arbol->obtenerIzquierda());
            }
        } else {
            if (arbol->obtenerDerecha() == nullptr || prioridad == arbol->obtenerDerecha()->obtenerRaiz()->obtenerPrioridad()) {
                return arbol;
            } else {
                return buscarPadre(prioridad, arbol->obtenerDerecha());
            }
        }
    }
}






ABBProcesos* ABBProcesos::obtenerNodoMenor()
{
    ABBProcesos* min = this;
    if (min->obtenerRaiz()->obtenerPrioridad() == -1) {
        min = min->obtenerDerecha();
    }
    while(min->obtenerIzquierda() != nullptr)
    {
        min = min->obtenerIzquierda();
    }
    return min;
}

ABBProcesos* ABBProcesos::obtenerNodoMayor()
{
    ABBProcesos* max = this;
    while(max->obtenerDerecha() != nullptr)
    {
        max = max->obtenerDerecha();
    }
    return max;
}

ABBProcesos* ABBProcesos::obtenerNodoEspecifico(int prioridad)
{
    return buscarPosicion(this, prioridad);
}

int ABBProcesos::obtenerPrioridadMenor()
{
    return this->obtenerNodoMenor()->obtenerRaiz()->obtenerPrioridad();
}

int ABBProcesos::obtenerPrioridadMayor()
{
    return this->obtenerNodoMayor()->obtenerRaiz()->obtenerPrioridad();
}

ListaProcesos* ABBProcesos::obtenerPrioridadEspecifica(int prioridad)
{
    ABBProcesos* nodo = buscarPosicion(this, prioridad);
    if (nodo != nullptr) {
        return nodo->obtenerRaiz();
    } else {
        return nullptr;
    }
}







ABBProcesos* crearNodo(ABBProcesos* arbol, int prioridad)
{
    if (prioridad <= arbol->obtenerRaiz()->obtenerPrioridad()) {
        arbol->setIzquierda(new ABBProcesos(prioridad));
        return arbol->obtenerIzquierda();
    } else {
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
    insertarEn(this, proceso.prioridad)->obtenerRaiz()->añadirDerecha(proceso);
}

void ABBProcesos::borrarNodo(int prioridad, ABBProcesos* arbol)
{
    ABBProcesos* hijo = buscarPosicion(arbol, prioridad);
    if (hijo != nullptr) {
        ABBProcesos* padre = buscarPadre(prioridad, arbol);
        if (hijo->esHoja()) {
            if(prioridad <= padre->obtenerRaiz()->obtenerPrioridad()) {
                padre->setIzquierda(nullptr);
            } else {
                padre->setDerecha(nullptr);
            }
            delete hijo;
        } else if (hijo->obtenerIzquierda() == nullptr) {
            ABBProcesos* aux = hijo->obtenerDerecha();
            *hijo = *hijo->obtenerDerecha();
            delete aux;
        } else if (hijo->obtenerDerecha() == nullptr) {
            ABBProcesos* aux = hijo->obtenerIzquierda();
            *hijo = *hijo->obtenerIzquierda();
            delete aux;
        } else {
            ABBProcesos* max = hijo->obtenerIzquierda()->obtenerNodoMayor();
            ListaProcesos raizMax = *max->obtenerRaiz();
            borrarNodo(max->obtenerRaiz()->obtenerPrioridad(), hijo);
            hijo->setRaiz(raizMax);
        }
    }
}

ABBProcesos ABBProcesos::copiarArbol(ABBProcesos* arbol)
{
    ABBProcesos copia = ABBProcesos();
    copia.setRaiz(*arbol->obtenerRaiz());
    if (arbol->obtenerDerecha() != nullptr) {
        copia.setDerecha(new ABBProcesos(copiarArbol(arbol->obtenerDerecha())));
    }
    if (arbol->obtenerIzquierda() != nullptr) {
        copia.setIzquierda(new ABBProcesos(copiarArbol(arbol->obtenerIzquierda())));
    }
    return copia;
}







int siguienteInOrden(ABBProcesos* arbol, int actual = -1)
{
    ABBProcesos ABBaux = arbol->copiarArbol(arbol);
    while (ABBaux.obtenerPrioridadMenor() != actual)
    {
        ABBaux.borrarNodo(ABBaux.obtenerPrioridadMenor(), &ABBaux);
    }
    ABBaux.borrarNodo(ABBaux.obtenerPrioridadMenor(), &ABBaux);
    return ABBaux.obtenerPrioridadMenor();
}

void ABBProcesos::mostrarInOrden()
{
    cout << "InOrden: " << endl;
    int prioridadActual = this->obtenerPrioridadMenor();
    while (prioridadActual != this->obtenerPrioridadMayor())
    {
        this->obtenerPrioridadEspecifica(prioridadActual)->mostrarListaProcesos();
        prioridadActual = siguienteInOrden(this, prioridadActual);
    }
    this->obtenerPrioridadEspecifica(prioridadActual)->mostrarListaProcesos();
}

void ABBProcesos::mostrarPromedioPreOrden()
{
    ABBProcesos* aux = this;
    if (aux != nullptr) {
        if (aux->obtenerRaiz()->obtenerPrioridad() == -1) {
            aux = aux->obtenerDerecha();
        }
        cout << "Prioridad: " << aux->obtenerRaiz()->obtenerPrioridad() << " Tiempo promedio: " << aux->obtenerRaiz()->mediaTiempos() << " minutos" << endl;
        aux->obtenerIzquierda()->mostrarPromedioPreOrden();
        aux->obtenerDerecha()->mostrarPromedioPreOrden();
    }
}






int ABBProcesos::numProcesosEjecutados()
{
    int actual = this->obtenerPrioridadMenor();
    int n = 0;
    while (actual != this->obtenerPrioridadMayor())
    {
        n += this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos();
        actual = siguienteInOrden(this, actual);
    }
    n += this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos();
    return n;
}

float ABBProcesos::mediaTiempos()
{
    if (this->numProcesosEjecutados() == 0) {
        return 0;
    } else {
        int actual = this->obtenerPrioridadMenor();
        int m = 0;
        while (actual != this->obtenerPrioridadMayor())
        {
            m += this->obtenerPrioridadEspecifica(actual)->sumaTiemposProcesos();
            actual = siguienteInOrden(this, actual);
        }
        m += this->obtenerPrioridadEspecifica(actual)->sumaTiemposProcesos();

        float media = (float)m/(float)this->numProcesosEjecutados();
        return media;
    }
}

int ABBProcesos::mayorNumProcesos()
{
    int mayor = this->obtenerPrioridadMenor();
    int actual = this->obtenerPrioridadMenor();
    while (actual != this->obtenerPrioridadMayor())
    {
        if (this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos() > mayor) {
            mayor = this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos();
        }
        actual = siguienteInOrden(this, actual);
    }
    if (this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos() > mayor) {
        mayor = this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos();
    }
    return mayor;
}

int ABBProcesos::menorNumProcesos()
{
    int menor = this->obtenerPrioridadMenor();
    int actual = this->obtenerPrioridadMenor();
    while (actual != this->obtenerPrioridadMayor())
    {
        if (this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos() < menor) {
            menor = this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos();
        }
        actual = siguienteInOrden(this, actual);
    }
    if (this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos() < menor) {
        menor = this->obtenerPrioridadEspecifica(actual)->longitudListaProcesos();
    }
    return menor;
}
