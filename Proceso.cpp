#include "Proceso.h"

Proceso::Proceso()
{
    // Constructor por defecto
}

// Implementación del constructor parametrizado
Proceso::Proceso(int PID, int prioridad, int tiempoInicio, int tiempoEjecucion) : prioridad(prioridad), PID(PID), tiempoInicio(tiempoInicio), tiempoEjecucion(tiempoEjecucion)
{
    // Inicialización de miembros con valores proporcionados
}

// Implementación del destructor
Proceso::~Proceso()
{
    // Destructor
}
