#include "ListaProcesos.h"
#include "../Proceso/Proceso.h"
#include "../Pila/Pila.h"
using namespace std;

ListaProcesos::ListaProcesos()  
{
    vacia = true;
    restoListaProcesosPtr = NULL;
    longitud = 0;
    prioridad = -1;
}

ListaProcesos::ListaProcesos(int pr)  
{
    vacia = true;
    restoListaProcesosPtr = NULL;
    longitud = 0;
    prioridad = pr;
}

ListaProcesos::ListaProcesos(int pr, Proceso proceso, ListaProcesos *resto)
{
    vacia = false;
    primeroListaProcesos = proceso;
    this->restoListaProcesosPtr = resto;
    longitud = resto->longitud + 1;
    prioridad = pr;
}

bool ListaProcesos::esVacia()
{
    return vacia;
}

ListaProcesos* ListaProcesos::añadirIzquierda(Proceso proceso)    // añade un nodo a la izquierda
{
    // crea una lista nueva con el núcleo a la izquierda y la
    // lista antigua como resto y lo devuelve
    return new ListaProcesos(proceso.prioridad, proceso, this);
}


ListaProcesos* ListaProcesos::añadirDerecha(Proceso proceso)   // añade un nodo a la derecha
{
    if (esVacia()) {
        primeroListaProcesos = proceso;     // el primer nodo es el núcleo
        restoListaProcesosPtr = new ListaProcesos(proceso.prioridad);    // el resto es una lista vacía
        vacia = false;                      // la lista ya no está vacía
        longitud = 1;                       // la longitud es 1
    } else {
        ListaProcesos* p = this;            // creo un puntero a la lista

        // mientras que el siguiente nodo no sea NULL y la lista no esté vacía (hasta que no llego al final)
        while (p->restoListaProcesosPtr != NULL && !p->restoListaProcesosPtr->esVacia())    
        {
            p->longitud++;                  // aumento la longitud a cada uno de los nodos
            p = p->restoListaProcesosPtr;   // avanzo en la lista
            
        }
        p->longitud++;
        p->restoListaProcesosPtr = new ListaProcesos(proceso.prioridad, proceso, new ListaProcesos(p->prioridad));  // añado el núcleo al final de la lista
    }
    return this;                            // devuelvo la lista
}

Proceso ListaProcesos::primero(ListaProcesos lista)  // devuelve el primer nodo
{
    if (!esVacia()) {
        return lista.primeroListaProcesos;  // devuelvo el primer nodo
    } else {
        return Proceso();                   // si la lista está vacía, devuelvo un núcleo vacío
    }
}

ListaProcesos ListaProcesos::resto(ListaProcesos lista) // devuelve el resto de la lista
{
    if (!esVacia()) {   
        return *lista.restoListaProcesosPtr;  // devuelvo el resto de la lista
    } else {
        return ListaProcesos(-1);             // si la lista está vacía, devuelvo una lista vacía
    }
}


ListaProcesos* ListaProcesos::eliminarNodo(int posicion)    // elimina un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) {
        if (posicion == 1) {
            ListaProcesos* temp = this->restoListaProcesosPtr;  // creo un puntero a la lista
            *this = *temp;  // la lista actual es igual a la lista siguiente
            delete temp;    
        } else if (posicion == 2) {
            ListaProcesos* temp = this->restoListaProcesosPtr->restoListaProcesosPtr;   // creo un puntero a la lista siguiente
            delete this->restoListaProcesosPtr; // elimino el nodo siguiente
            this->restoListaProcesosPtr = temp; // el siguiente nodo es el sigueinte del siguiente
            this->longitud--;                   // resto 1 a la longitud
        } else {   
            ListaProcesos* p = this;    // creo un puntero a la lista
            ListaProcesos* ultimo;      // declaro un puntero en el que guardaré el último nodo
            for (int i = 2; i < posicion; i++) // recorro la lista hasta la posición 
            {
                p->longitud--;                  // resto 1 a la longitud
                p = p->restoListaProcesosPtr;   // avanzo en la lista
                if (p->restoListaProcesosPtr->restoListaProcesosPtr == nullptr) {
                    ultimo = p;                 // "último" = el nodo actual
                }
            }

            if (p->restoListaProcesosPtr == nullptr) {
                delete p;   // elimino el nodo actual
                ultimo->restoListaProcesosPtr = nullptr;   // el siguiente del último es NULL
            } else {
                ListaProcesos* q = p->restoListaProcesosPtr->restoListaProcesosPtr; // creo un puntero al siguiente del siguiente
                delete p->restoListaProcesosPtr;    // elimino el siguiente nodo
                p->restoListaProcesosPtr = q;       // el siguiente nodo es el siguiente del siguiente
            }
        }

    }
    if (longitud == 0) {
        vacia = true;   // la lista está vacía
    }
    return this;        // devuelvo la lista
}

ListaProcesos* ListaProcesos::restoPtr(ListaProcesos lista) // devuelve el puntero al resto de la lista
{
    if (!esVacia()) {
        return lista.restoListaProcesosPtr; // devuelvo el puntero al resto de la lista
    } else {
        return nullptr;                     // si la lista está vacía, devuelvo NULL
    }
}

void ListaProcesos::mostrarListaProcesos()   // muestra la lista
{
    if (!esVacia()) {
        cout << "Procesos con prioridad " << prioridad << ": " << endl;
        cout << "  PID " << primeroListaProcesos.PID << ": ";
        cout << "ha vivido en el sistema: " << primeroListaProcesos.tiempoEnSO << " minutos." << endl;

        ListaProcesos* p = this->restoListaProcesosPtr;  // creo un puntero a la lista
        while (p->primero(*p).PID != -1) {                             // mientras que el puntero no sea NULL
            cout << "  PID " << p->primeroListaProcesos.PID << ": ";
            cout << "ha vivido en el sistema: " << p->primeroListaProcesos.tiempoEnSO << " minutos." << endl;
            p = p->restoListaProcesosPtr;                   // avanzo en la lista
        }
        cout << endl;
    } else {
        cout << "La lista está vacía" << endl;  // si la lista está vacía, muestro un mensaje
    }
}


Proceso* ListaProcesos::obtenerNodo(int posicion)    // obtiene un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) {
        ListaProcesos* p = this;            // creo un puntero a la lista
        for (int i = 1; i < posicion; i++)  // recorro la lista hasta la posición
        {
            p = p->restoListaProcesosPtr;   // avanzo en la lista
        }
        return p->primeroPtr();             // devuelvo el puntero al primer nodo
    } else {
        cout << "La posición no existe" << endl;   
        return nullptr;                     // devuelvo NULL
    }
}

int ListaProcesos::longitudListaProcesos()
{
    return longitud;    // devuelvo la longitud
}

ListaProcesos::~ListaProcesos()
{
    
}

Proceso* ListaProcesos::primeroPtr() // devuelve el puntero al primer nodo
{   
    if (!esVacia()) {
        return &this->primeroListaProcesos; // devuelvo el puntero al primer nodo
    } else {
        return nullptr;                     // si la lista está vacía, devuelvo NULL
    }
}

int ListaProcesos::sumaTiemposProcesos()
{
    int suma = 0;
    int l = this->longitudListaProcesos();

    for (int i = 1; i <= l; i++)
    {
        suma += this->obtenerNodo(i)->tiempoEnSO;
    }
    return suma;
}

float ListaProcesos::mediaTiempos()
{
    if (this->longitudListaProcesos() == 0) {
        return 0;
    } else {
        return (float)this->sumaTiemposProcesos()/(float)this->longitudListaProcesos();
    }
}

ListaProcesos copiarLista(ListaProcesos* lista)
{
    ListaProcesos copia = ListaProcesos(lista->obtenerPrioridad());
    for (int i = lista->longitudListaProcesos(); i >= 1; i++)
    {
        copia.añadirDerecha(*lista->obtenerNodo(i));
    }
    return copia;
}

// ListaProcesos ListaProcesos::obtenerOrdenadaPorPrioridad()
// {
//     ListaProcesos aux = copiarLista(this);
//     ListaProcesos listaOrdenada = ListaProcesos(aux.obtenerPrioridad());
// 
//     Proceso* mayor = aux.obtenerNodo(1);
//     ListaProcesos* p = &aux;
//     
//     while (!p->esVacia())
//     {
//         int posicionABorrar = 1;
//         int pos = 1;
//         while (p != nullptr)
//         {
//             if (p->prioridad > mayor->prioridad) {
//                 mayor = p->obtenerNodo(pos);
//                 posicionABorrar = pos;
//             }
//             pos++;
//             p = p->restoListaProcesosPtr;
//         }
//         listaOrdenada.añadirDerecha(*mayor);
//         aux.eliminarNodo(posicionABorrar);
//         p = &aux;
//     }
//     return listaOrdenada;
// }

int ListaProcesos::obtenerPrioridad()
{
    return prioridad;
}
