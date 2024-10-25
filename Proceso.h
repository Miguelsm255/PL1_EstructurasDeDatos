#ifndef ELEMENTO_H
#define ELEMENTO_H

class Proceso
{
public:
    int prioridad;
    int PID;
    int PPID;
    int tiempoInicio;
    int tiempoEjecucion;
    int tiempoEnSO;

    Proceso(); // Constructor por defecto
    Proceso(int PID, int prioridad, int tiempoInicio, int tiempoEjecucion); // Constructor parametrizado
    ~Proceso(); // Destructor
};

#endif // ELEMENTO_H
