#ifndef ELEMENTO_H
#define ELEMENTO_H

struct Proceso
{
    int prioridad;
    int PID;

    Proceso(); // Constructor por defecto
    Proceso(int p, int PID);
    ~Proceso(); // Destructor
};

#endif // ELEMENTO_H