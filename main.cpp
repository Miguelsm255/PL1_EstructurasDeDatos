#include <iostream>

#include "Cola.h"
#include "Pila.h"


using namespace std;

int main(){

    Pila pila = Pila();
    Cola cola = Cola();

    Proceso p1 = Proceso(1, 1);
    Proceso p2 = Proceso(2, 2);
    Proceso p3 = Proceso(3, 3);
    Proceso p4 = Proceso(4, 4);
    Proceso p5 = Proceso(5, 5);

    pila.apilar(p1);
    pila.apilar(p5);
    pila.apilar(p2);
    pila.apilar(p4);
    pila.apilar(p3);


    while(!pila.esVacia()){
        cola.encolarPrioridad(pila.cimaPila());
        pila.desapilar();
    }

    cola.mostrarCola();

    return 0;
}
