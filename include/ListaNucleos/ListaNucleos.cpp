#include "ListaNucleos.h"
#include "../Proceso/Proceso.h"
#include "../Pila/Pila.h"
using namespace std;

ListaNucleos::ListaNucleos()  
{
    vacia = true;
    restoListaNucleosPtr = NULL;
    longitud = 0;
}

ListaNucleos::ListaNucleos(Nucleo nucleo, ListaNucleos *resto)
{
    vacia = false;
    primeroListaNucleos = nucleo;
    this->restoListaNucleosPtr = resto;
    longitud = resto->longitud + 1;
}

ListaNucleos::~ListaNucleos()
{
    
}


bool ListaNucleos::esVacia()
{
    return vacia;
}

Nucleo ListaNucleos::primero(ListaNucleos lista)  // devuelve el primer nodo
{
    if (!esVacia())   // si la lista no está vacía
    {
        return lista.primeroListaNucleos;  // devuelvo el primer nodo
    }
    else
    {
        return Nucleo();    // si la lista está vacía, devuelvo un núcleo vacío
    }
}

Nucleo* ListaNucleos::primeroPtr() // devuelve el puntero al primer nodo
{   
    if (!esVacia()) // si la lista no está vacía
    {
        return &this->primeroListaNucleos;   // devuelvo el puntero al primer nodo
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}

ListaNucleos ListaNucleos::resto(ListaNucleos lista) // devuelve el resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {   
        return *lista.restoListaNucleosPtr;    // devuelvo el resto de la lista
    }
    else
    {
        return ListaNucleos(); // si la lista está vacía, devuelvo una lista vacía
    }
}

ListaNucleos* ListaNucleos::restoPtr(ListaNucleos lista) // devuelve el puntero al resto de la lista
{
    if (!esVacia()) // si la lista no está vacía
    {
        return lista.restoListaNucleosPtr;   // devuelvo el puntero al resto de la lista
    }
    else
    {
        return NULL;    // si la lista está vacía, devuelvo NULL
    }
}


Nucleo* ListaNucleos::obtenerNodo(int posicion)    // obtiene un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        ListaNucleos* p = this;    // creo un puntero a la lista
        for (int i = 1; i < posicion; i++)  // recorro la lista hasta la posición
        {
            p = p->restoListaNucleosPtr;   // avanzo en la lista
        }
        return p->primeroPtr(); // devuelvo el puntero al primer nodo
    }
    else    // si la lista está vacía o la posición no existe
    {
        cout << "La posición no existe" << endl;    // muestro un mensaje de error
        return NULL;    // devuelvo NULL
    }
}

ListaNucleos* ListaNucleos::eliminarNodo(int posicion)    // elimina un nodo de la lista
{
    if (!esVacia() && posicion <= longitud) // si la lista no está vacía y la posición es menor o igual a la longitud
    {
        if (posicion == 1)  // si la posición es 1
            {
            ListaNucleos* temp = this->restoListaNucleosPtr;  // creo un puntero a la lista
            *this = *temp;  // la lista actual es igual a la lista siguiente
            delete temp;    
        }
        else if (posicion == 2) // si la posición es 2
        {
            ListaNucleos* temp = this->restoListaNucleosPtr->restoListaNucleosPtr;   // creo un puntero a la lista siguiente
            delete this->restoListaNucleosPtr; // elimino el nodo siguiente
            this->restoListaNucleosPtr = temp; // el siguiente nodo es el sigueinte del siguiente
            this->longitud--;   // resto 1 a la longitud
        }
        else    // si la posición es mayor que 2
        {   
            ListaNucleos* p = this;    // creo un puntero a la lista
            ListaNucleos* ultimo;      // declaro un puntero en el que guardaré el último nodo
            for (int i = 2; i < posicion; i++) // recorro la lista hasta la posición 
            {
                p->longitud--; // resto 1 a la longitud
                p = p->restoListaNucleosPtr;   // avanzo en la lista
                if (p->restoListaNucleosPtr->restoListaNucleosPtr == NULL)   // si el siguiente nodo es NULL
                {
                    ultimo = p; // "último" = el nodo actual
                }
            }

            if (p->restoListaNucleosPtr == NULL)   // si el siguiente nodo es NULL
            {
                delete p;   // elimino el nodo actual
                ultimo->restoListaNucleosPtr = NULL;   // el siguiente del último es NULL
            }
            else    // si el siguiente nodo no es NULL
            {
                ListaNucleos* q = p->restoListaNucleosPtr->restoListaNucleosPtr; // creo un puntero al siguiente del siguiente
                delete p->restoListaNucleosPtr;    // elimino el siguiente nodo
                p->restoListaNucleosPtr = q;   // el siguiente nodo es el siguiente del siguiente
            }
        }

    }
    if (longitud == 0)  // si la longitud es 0
    {
        vacia = true;   // la lista está vacía

    }
    return this;    // devuelvo la lista
}

int ListaNucleos::longitudListaNucleos()  // devuelve la longitud de la lista
{
    return longitud;    // devuelvo la longitud
}

Nucleo* ListaNucleos::NucleoConMenosProcesos()
{
    // Compruebo cual es el núcleo con menos procesos en cola y encolo
    Nucleo* menor = this->obtenerNodo(1); // por defecto cogemos el primero
    for (int j = 1; j <= this->longitudListaNucleos(); j++) // por cada núcleo
    {
        // si el núcleo j tiene menos procesos en cola que el núcleo menor
        if (this->obtenerNodo(j)->NdeProcesosEnCola() <= menor->NdeProcesosEnCola())
        {
            if (this->obtenerNodo(j)->NdeProcesosEnCola() == menor->NdeProcesosEnCola() && this->obtenerNodo(j)->esVacio())
            {
                cout << "El núcleo " << j << " tiene menos procesos en cola" << endl;
                menor = this->obtenerNodo(j); // el núcleo j es el nuevo menor
            }
            else if (this->obtenerNodo(j)->NdeProcesosEnCola() < menor->NdeProcesosEnCola())
            {
                cout << "El núcleo " << j << " tiene menos procesos en cola" << endl;
                menor = this->obtenerNodo(j); // el núcleo j es el nuevo menor
            }
        }
    }
    cout << endl;
    return menor;
}


ListaNucleos* ListaNucleos::añadirIzquierda(Nucleo nucleo)    // añade un nodo a la izquierda
{
    return new ListaNucleos(nucleo, this); // crea una lista nueva con el núcleo a la izquierda y la
}                                          // lista antigua como resto y lo devuelve
       
ListaNucleos* ListaNucleos::añadirDerecha(Nucleo nucleo)   // añade un nodo a la derecha
{
    if (esVacia())  // si la lista está vacía
    {
        primeroListaNucleos = nucleo;  // el primer nodo es el núcleo
        restoListaNucleosPtr = new ListaNucleos();    // el resto es una lista vacía
        vacia = false;  // la lista ya no está vacía
        longitud = 1;   // la longitud es 1
    }
    else    // si la lista no está vacía
    {
        ListaNucleos* p = this;    // creo un puntero a la lista

        // mientras que el siguiente nodo no sea NULL y la lista no esté vacía (hasta que no llego al final)
        while (p->restoListaNucleosPtr != NULL && !p->restoListaNucleosPtr->esVacia())    
        {
            p->longitud++; // aumento la longitud a cada uno de los nodos
            p = p->restoListaNucleosPtr;   // avanzo en la lista
            
        }
        p->longitud++;
        p->restoListaNucleosPtr = new ListaNucleos(nucleo, new ListaNucleos());  // añado el núcleo al final de la lista
    }
    return this;    // devuelvo la lista
}


bool ListaNucleos::nucleosVacios()
{
    // Compruebo si todos los núcleos están vacíos
    bool vacio = true;
    for (int j = 1; j <= this->longitudListaNucleos(); j++)
    {
        cout << "Núcleo " << j << " tiene " << this->obtenerNodo(j)->NdeProcesosEnCola() << " procesos en cola." << endl;
        cout << "Núcleo " << j << " está vacío: ";
        if (this->obtenerNodo(j)->esVacio())
        {
            cout << "Sí" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        cout << endl;
        if (this->obtenerNodo(j)->NdeProcesosEnCola() != 0 || !this->obtenerNodo(j)->esVacio())
        {
            vacio = false;
        }
    }
    return vacio;
}


void ListaNucleos::mostrarListaNucleos(ListaNucleos lista)   // muestra la lista
{
    while (!lista.esVacia())    // mientras que la lista no esté vacía
    {
        cout << lista.primero(lista).getID() << ", ";   // muestro el ID del primer nodo
        lista = lista.resto(lista); // la lista es el resto de la lista
    }
    cout << endl;   // salto de línea
}

void ListaNucleos::mostrarColasDeNucleos()
{
    if (this->longitudListaNucleos() > 0){
        for (int j = 1; j <= this->longitudListaNucleos(); j++)
        {
            cout << "Cola de núcleo " << j << ": ";
            this->obtenerNodo(j)->mostrarColaNucleo();
            
        }
        cout << endl;
    }
    else
    {
        cout << "No hay núcleos" << endl;
        cout << endl;
    }
}

void ListaNucleos::eliminarNucleosVacios()
{
    // compruebo el valor de nucleosVacios. Si hay más de 2, elimino núcleos vacíos hasta que queden 2
    for (int j = 1; j <= this->longitudListaNucleos(); j++) // por cada núcleo
    {
        // si está vacío y nucleosVacios es mayor que 2
        if (this->obtenerNodo(j)->esVacio() && this->obtenerNodo(j)->obtenerColaNucleo()->esVacia() && this->longitudListaNucleos() > 2)
        {
            cout << "Elimino núcleo " << j << endl;
            this->eliminarNodo(j); // elimino el núcleo
        }
    }
}

void ListaNucleos::actualizarColasyNucleos(int* sumaTiempos, int* procesosEjecutados)
{
    // actualizo los núcleos
    for (int j = 1; j <= this->longitudListaNucleos(); j++) // por cada núcleo
    {
        // actualizar suma 1 al tiempo que lleva ejecutado y al tiempo en SO
        // si el proceso ha terminado, devuelve el tiempo que ha estado en el SO
        // si no devuelve 0
        int tiempo = this->obtenerNodo(j)->actualizar(); 

        // si el tiempo es distinto de 0, es que ha terminado, sumo 1 a procesosEjecutados
        if (tiempo != 0)
        {
            *procesosEjecutados += 1;
        }
        *sumaTiempos += tiempo; // sumo el timepo que me ha devuelto al tiempo total
    }

    // actualizar las colas: esto solo suma 1 al tiempo en SO.
    for (int j = 1; j <= this->longitudListaNucleos(); j++) // por cada nucleo
    {
        this->obtenerNodo(j)->obtenerColaNucleo()->actualizar(); // accedo a su cola y actualizo
    }
}

void ListaNucleos::encolarEnElMenor(Pila* pila)
{
    cout << "-----PARA ENCOLAR COMPRUEBO CUAL ES EL NÚCLEO CON MENOS COLA-----" << endl;
    this->mostrarColasDeNucleos(); // SOLO VISUAL

    Nucleo* menor = NucleoConMenosProcesos(); // obtengo el núcleo con menos procesos en cola

    if (menor->NdeProcesosEnCola() == 0 && menor->esVacio())
    {
        menor->procesar(pila->cimaPila()); // lo pongo a procesar directamente
        cout << "Como no tiene cola y está vacío, lo meto en el núcleo." << endl;
    }
    else
    {
        menor->encolarProceso(pila->cimaPila()); // encolo el proceso en el núcleo menor
        cout << "Encolo en el menor" << endl;
    }
    this->mostrarColasDeNucleos(); // SOLO VISUAL        
    cout << endl;
}

void ListaNucleos::hacerHueco()
{
    cout << "-----COMPRUEBO SI LOS NÚCLEOS ESTÁN LLENOS-----" << endl;
    cout << endl;
    // Compruebo si están todos llenos
    bool llenos = true;
    for (int j = 1; j <= this->longitudListaNucleos(); j++) // por cada núcleo
    {
        if (this->obtenerNodo(j)->NdeProcesosEnCola() < 3) // si un nucleo tiene - de 3 procesos (no lleno)
        {
            llenos = false; // no están todos llenos
            cout << "Núcleo " << j << " no está lleno, tiene " << this->obtenerNodo(j)->NdeProcesosEnCola() << " procesos en cola." << endl;
            cout << "Cola de núcleo " << j << ": ";
            this->obtenerNodo(j)->mostrarColaNucleo();
            cout << endl;
        }
        
    }

    // Si están todos llenos, añado un nuevo núcleo
    if (llenos)
    {
        this->añadirDerecha(Nucleo()); // añado núcleo nuevo
        cout << "Están todos llenos, hemos añadido un nuevo núcleo" << endl;
        cout << "Ahora hay " << this->longitudListaNucleos() << " núcleos" << endl;
    }
    cout << endl;
}

void ListaNucleos::desencolarYProcesar()
{
    // Si el nucleo está vacío y su lista tiene procesos esperando, pongo el primero a procesar
    for (int j = 1; j <= this->longitudListaNucleos(); j++) // por cada núcleo
    {
        // aquí se hace la comprobación de si el núcleo está vacío y tiene procesos en cola
        if (this->obtenerNodo(j)->esVacio() && !this->obtenerNodo(j)->obtenerColaNucleo()->esVacia())
        {
            cout << "Pongo a porcesar el proceso en el núcleo " << j << endl;
            this->obtenerNodo(j)->procesar(this->obtenerNodo(j)->obtenerColaNucleo()->desencolar());
        }
    }
    cout << endl;
}

void ListaNucleos::detallesProcesosEjecucion()
{
    for (int i = 1; i <= this->longitudListaNucleos(); i++) // por cada núcleo
    {
        cout << "- Proceso en ejecución en núcleo " << i << ": " << endl;
        this->obtenerNodo(i)->mostrarNucleo(); // Imprime el proceso en ejecución
    }
}
