#include "Nucleo.h"
#include "Proceso.h"
#include "Cola.h"
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
    if (esVacio())  // si el núcleo está libre
    {
        proceso = p;    // el proceso del núcleo es el proceso que se le pasa
        libre = false;  // el núcleo ya no está libre
    }
}

void Nucleo::quitarProceso()    // quita el proceso del núcleo
{
    if(!esVacio())  // si el núcleo no está vacío
    {
        proceso = Proceso();    // el proceso del núcleo es un proceso vacío
        libre = true;           // el núcleo está libre
    }
}   

void Nucleo::mostrarNucleo()    // muestra el proceso del núcleo
{
    if(!esVacio())  
    {
        cout << "      PID: " << proceso.PID << endl;
        cout << "      PPID: " << proceso.PPID << endl;
        cout << "      Prioridad: " << proceso.prioridad << endl;
        cout << "      Minuto de entrada en el sistema: " << proceso.tiempoInicio << endl;
        cout << "      Tiempo que tarda en ejecutarse: " << proceso.tiempoEjecucion << endl;
        cout << "      Tiempo que lleva en el sistema operativo: " << proceso.tiempoEnSO +1 << endl;
        cout << endl;
    }
    else
    {
        cout << "      Núcleo vacío" << endl;
        cout << endl;
    }
}


int Nucleo::actualizar()    // actualiza el proceso
{
    if(!esVacio())  // si el núcleo no está vacío
    {
        proceso.tiempoEnSO += 1;    // aumento el tiempo que lleva en el SO
        tiempoProcesado += 1;       // aumento el tiempo procesado en 1
        
        if (proceso.tiempoEjecucion == tiempoProcesado) // si el tiempo de ejecución del proceso es igual al tiempo procesado
        {
            int tiempoTotalProceso = proceso.tiempoEnSO;    // el tiempo total del proceso es el tiempo que lleva en el SO
            cout << "El proceso con PID " << proceso.PID << " ha terminado! Ha estado " << tiempoTotalProceso << " minutos en el SO."<< endl;
            cout << endl;
            quitarProceso();    // quito el proceso del núcleo
            tiempoProcesado = 0;    // el tiempo procesado es 0
            return tiempoTotalProceso;  // devuelvo el tiempo total del proceso
        }else   // si el tiempo de ejecución del proceso no es igual al tiempo procesado
        {
            return 0;   // devuelvo 0
        }
    }else{
        return 0;
    }
}

int Nucleo::NdeProcesosEnCola() // devuelve el número de procesos en la cola
{
    return colaProcesos->colaLongitud();    
}

void Nucleo::encolarProceso(Proceso p)  // encola un proceso
{
    colaProcesos->encolarPrioridad(p);
}

Cola* Nucleo::obtenerColaNucleo()   // devuelve la cola de procesos del núcleo
{
    return colaProcesos;
}

void Nucleo::mostrarColaNucleo()    // muestra la cola de procesos del núcleo
{
    colaProcesos->mostrarCola();
}

int Nucleo::getID() // devuelve el ID del núcleo
{
    return ID;
}
