#include "Cola.h"
#include "NodoCola.h"
#include "../Proceso/Proceso.h"
using namespace std;

Cola::Cola()
{
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

Cola::~Cola() // Destructor de la clase Cola
{
}

void Cola::encolar(Proceso p) // encola
{
    NodoCola *nuevo = new NodoCola(p);  // Crear un nuevo nodo
    if (esVacia())  {
        primero = nuevo;                // El primer nodo es el nuevo nodo
        ultimo = nuevo;                 // El último nodo es el nuevo nodo
    } else {
        ultimo->siguiente = nuevo;      // El siguiente del último nodo es el nuevo nodo
        ultimo = nuevo;                 // El último nodo es el nuevo nodo
    }
    longitud++;                         // Aumentar la longitud de la cola
}

Proceso Cola::desencolar() // desencola
{
    if (!esVacia()) {
        Proceso proceso = primero->proceso; // Guardar el proceso del primer nodo
        NodoCola *aux = primero;            // Crear un nodo auxiliar que apunte al primer nodo

        if ((primero == ultimo) && (primero->siguiente == nullptr)) {
            primero = nullptr;
            ultimo = nullptr;
            aux->siguiente = nullptr;
            delete aux;
        } else {
            primero = primero->siguiente;   // El primer nodo es el siguiente del primer nodo
            aux->siguiente = nullptr;       // El siguiente del nodo auxiliar es NULL
            delete aux;
        }
        longitud--;     // Disminuir la longitud de la cola
        return proceso; // Devolver el proceso
    }
    return Proceso();   // Si la cola está vacía, devolver un proceso vacío
}

Proceso Cola::inicio()  // devuelve el proceso del primer nodo
{
    if (!esVacia()) {
        return primero->proceso;
    }
    return Proceso();
}

Proceso Cola::fin()     // devuelve el proceso del último nodo
{
    if (!esVacia()) {
        return ultimo->proceso;
    }
    return Proceso();
}

int Cola::colaLongitud()    // devuelve la longitud de la cola
{
    if (esVacia()) {
        return 0;                   // Devolver 0
    } else {
        int l = 1;                  // Inicializar la longitud en 1
        NodoCola *aux = primero;    // Crear un nodo auxiliar que apunte al primer nodo
        while (aux != ultimo)       // Mientras que el nodo auxiliar no sea el último
        {
            l++;                    // Aumentar la longitud
            aux = aux->siguiente;   // El nodo auxiliar es el siguiente nodo
        }
        return l;                   // Devolver la longitud
    }
}

bool Cola::esVacia()        // devuelve si la cola está vacía
{
    return (primero == nullptr) && (ultimo == nullptr);   // Devolver si el primer y último nodo son NULL
}

void Cola::mostrarCola()    // muestra la cola
{
    if (!esVacia()) {
        NodoCola *aux = primero;     // Crear un nodo auxiliar que apunte al primer nodo
        while (aux != nullptr)       // Mientras que el nodo auxiliar no sea NULL
        {
            cout << aux->proceso.PID << " ";    // Mostrar el PID del proceso
            aux = aux->siguiente;               // El nodo auxiliar es el siguiente nodo
        }
        cout << endl;
    } else {
        cout << "La cola está vacía." << endl;
    }
}


void Cola::encolarPrioridad(Proceso p)      // encola con prioridad
{
    NodoCola *nuevo = new NodoCola(p);      // Crear un nuevo nodo
    if (esVacia()) {
        primero = nuevo;                    // El primer nodo es el nuevo nodo
        ultimo = nuevo;                     // El último nodo es el nuevo nodo
    } else {
        Cola *Cola_aux = new Cola();        // Crear una cola auxiliar

        // Mover elementos a Cola_aux hasta encontrar la posición correcta para p
        while (primero != nullptr && primero->proceso.prioridad <= p.prioridad)
        {
            Cola_aux->encolar(desencolar());    // Encolar el proceso desencolado
        }

        Cola_aux->encolar(p);               // Encolar el nuevo proceso p

        // Mover el resto de los elementos a Cola_aux
        while (!esVacia())
        {
            Cola_aux->encolar(desencolar());
        }

        // Mover todos los elementos de Cola_aux de vuelta a la cola original
        while (!Cola_aux->esVacia())
        {
            encolar(Cola_aux->desencolar());
        }
        delete Cola_aux;
    }
    longitud++;    // Aumentar la longitud de la cola
}

void Cola::actualizar() // actualiza el tiempo en SO de los procesos
{
    if (!esVacia()) {
        NodoCola *aux = primero;        // Crear un nodo auxiliar que apunte al primer nodo
        while (aux != nullptr)             // Mientras que el nodo auxiliar no sea NULL
        {
            aux->proceso.tiempoEnSO++;  // Aumentar el tiempo en SO del proceso
            aux = aux->siguiente;       // El nodo auxiliar es el siguiente nodo
        }
    }
}