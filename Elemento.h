#ifndef ELEMENTO_H
#define ELEMENTO_H

struct Elemento
{
    int prioridad;
    int PID;

    Elemento(); // Constructor por defecto
    Elemento(int p, int PID);
    ~Elemento(); // Destructor
};

#endif // ELEMENTO_H