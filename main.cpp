#include <iostream>

#include "Cola.h"
#include "Pila.h"


using namespace std;

int main(){

    Pila pila = Pila();
    Cola cola = Cola();

    Proceso p1 = Proceso(1, 1, 1, 1);
    Proceso p2 = Proceso(2, 2, 2, 2);
    Proceso p3 = Proceso(3, 3, 3, 3);
    Proceso p4 = Proceso(4, 4, 4, 4);
    Proceso p5 = Proceso(5, 5, 5, 5);

    pila.insertarTiempo(p5);pila.mostrar();
    pila.insertarTiempo(p4);pila.mostrar();
    pila.insertarTiempo(p2);pila.mostrar();
    pila.insertarTiempo(p3);pila.mostrar();
    pila.insertarTiempo(p1);pila.mostrar();

    while(!pila.esVacia()){
        cola.encolar(pila.cimaPila());
        pila.desapilar();
        
    }

    return 0;
}
