#include "Proceso.h"

Proceso::Proceso()
{
    // Constructor por defecto
}

// Implementación del constructor parametrizado
Proceso::Proceso(int p, int PID) : prioridad(p), PID(PID)
{
    // Inicialización de miembros con valores proporcionados
}

// Implementación del destructor
Proceso::~Proceso()
{
    // Destructor
}