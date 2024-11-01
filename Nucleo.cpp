#include "Nucleo.h"
#include "Proceso.h"
#include "Cola.h"
using namespace std;

Nucleo::Nucleo()
{
    proceso = Proceso();
    libre = true;
    colaProcesos = Cola();
    tiempoProcesado = 0;
}

Nucleo::~Nucleo()
{

}

bool Nucleo::esVacio()
{
    return libre;
}

void Nucleo::procesar(Proceso p)
{
    if (esVacio())
    {
        proceso = p;
        libre = false;
    }
}

void Nucleo::quitarProceso()
{
    if(!esVacio())
    {
        proceso = Proceso();
        libre = true;
    }
}   

void Nucleo::mostrarNucleo()
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


int Nucleo::actualizar()
{
    if(!esVacio())
    {
        proceso.tiempoEnSO += 1;
        tiempoProcesado += 1;
        
        if (proceso.tiempoEjecucion == tiempoProcesado)
        {
            int tiempoTotalProceso = proceso.tiempoEnSO;
            cout << "El proceso con PID " << proceso.PID << " ha terminado! Ha estado " << tiempoTotalProceso << " minutos en el SO."<< endl;
            cout << endl;
            quitarProceso();
            tiempoProcesado = 0;
            return tiempoTotalProceso;
        }else
        {
            return 0;
        }
    }else{
        return 0;
    }
}

int Nucleo::NdeProcesosEnCola()
{
    return colaProcesos.colaLongitud();
}

void Nucleo::encolarProceso(Proceso p)
{
    colaProcesos.encolarPrioridad(p);
}

Cola* Nucleo::obtenerColaNucleo()
{
    return &colaProcesos;
}