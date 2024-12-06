#include "Nucleo.h"
#include "../Proceso/Proceso.h"
#include "../Cola/Cola.h"
#include "../ABBProcesos/ABBProcesos.h"
using namespace std;

Nucleo::Nucleo()
{
    proceso = Proceso();
    libre = true;
    colaProcesos = new Cola();
    tiempoProcesado = 0;
    ID = 0;
}

Nucleo::Nucleo(int id)
{
    proceso = Proceso();
    libre = true;
    colaProcesos = new Cola();
    tiempoProcesado = 0;
    ID = id;
}

Nucleo::~Nucleo()
{

}

bool Nucleo::esVacio()  // devuelve si el núcleo está vacío
{
    return libre;   // devuelve si el núcleo está libre
}

void Nucleo::procesar(Proceso p)    // procesa un proceso
{
    if (esVacio()) {
        proceso = p;    // el proceso del núcleo es el proceso que se le pasa
        libre = false;  // el núcleo ya no está libre
    }
}

void Nucleo::quitarProceso()    // quita el proceso del núcleo
{
    if (!esVacio()) {
        proceso = Proceso();    // el proceso del núcleo es un proceso vacío
        libre = true;           // el núcleo está libre
    }
}   

void Nucleo::mostrarNucleo()    // muestra el proceso del núcleo
{
    if (!esVacio()) {
        cout << "      PID: " << proceso.PID << endl;
        cout << "      PPID: " << proceso.PPID << endl;
        cout << "      Prioridad: " << proceso.prioridad << endl;
        cout << "      Minuto de entrada en el sistema: " << proceso.tiempoInicio << endl;
        cout << "      Tiempo que tarda en ejecutarse: " << proceso.tiempoEjecucion << endl;
        cout << "      Tiempo que lleva en el sistema operativo: " << proceso.tiempoEnSO +1 << endl << endl;
    } else {
        cout << "      Núcleo vacío" << endl << endl;
    }
}


void Nucleo::actualizar(ABBProcesos* arbolProcesos)    // actualiza el proceso
{
    if (!esVacio()) {
        proceso.tiempoEnSO += 1;    // aumento el tiempo que lleva en el SO
        tiempoProcesado += 1;       // aumento el tiempo procesado en 1
        
        // si el tiempo de ejecución del proceso es igual al tiempo procesado
        if (proceso.tiempoEjecucion == tiempoProcesado) {
            cout << "El proceso con PID " << proceso.PID << " ha terminado! Ha estado " << proceso.tiempoEnSO << " minutos en el SO."<< endl << endl;
            arbolProcesos->insertar(proceso);   // inserto el proceso en el árbol
            quitarProceso();                    // quito el proceso del núcleo
            tiempoProcesado = 0;                // el tiempo procesado es 0
        }
    }
}

int Nucleo::NdeProcesosEnCola()         // devuelve el número de procesos en la cola
{
    return colaProcesos->colaLongitud();    
}

void Nucleo::encolarProceso(Proceso p)  // encola un proceso
{
    colaProcesos->encolarPrioridad(p);
}

Cola* Nucleo::obtenerColaNucleo()       // devuelve la cola de procesos del núcleo
{
    return colaProcesos;
}

void Nucleo::mostrarColaNucleo()        // muestra la cola de procesos del núcleo
{
    colaProcesos->mostrarCola();
}

int Nucleo::getID()                     // devuelve el ID del núcleo
{
    return ID;
}
