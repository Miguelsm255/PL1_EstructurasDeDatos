#include <iostream>

#include "Cola.h"
#include "Pila.h"
#include "Nucleo.h"


using namespace std;

int main(){

    int contador = 0;

    Pila pila = Pila();
    Cola cola = Cola();

    Nucleo n1 = Nucleo();
    Nucleo n2 = Nucleo();
    Nucleo n3 = Nucleo();

    Proceso a = Proceso(1, 1, 1, 6);
    Proceso b = Proceso(2, 6, 18, 4);
    Proceso c = Proceso(3, 9, 24, 2);
    Proceso d = Proceso(4, 4, 13, 3);
    Proceso e = Proceso(5, 4, 24, 4);
    Proceso f = Proceso(6, 8, 5, 5);
    Proceso g = Proceso(7, 1, 17, 1);
    Proceso h = Proceso(8, 9, 21, 7);
    Proceso i = Proceso(9, 2, 27, 2);
    Proceso j = Proceso(10, 7, 13, 5);
    Proceso k = Proceso(11, 8, 24, 4);
    Proceso l = Proceso(12, 3, 5, 5);
    Proceso m = Proceso(13, 5, 15, 5);
    Proceso n = Proceso(14, 6, 19, 1);
    Proceso o = Proceso(15, 4, 17, 1);
    Proceso p = Proceso(16, 2, 23, 9);
    Proceso q = Proceso(17, 3, 13, 3);
    Proceso r = Proceso(18, 8, 14, 4);
    Proceso s = Proceso(19, 2, 24, 5);
    Proceso t = Proceso(20, 5, 14, 7);
    Proceso u = Proceso(21, 6, 18, 1);
    Proceso v = Proceso(26, 1, 13, 7);
    Proceso w = Proceso(23, 3, 2, 2);
    Proceso x = Proceso(24, 3, 3, 3);
    Proceso y = Proceso(25, 8, 4, 4);
    Proceso z = Proceso(26, 6, 5, 5);

    pila.insertarTiempo(a);
    pila.insertarTiempo(b);
    pila.insertarTiempo(c);
    pila.insertarTiempo(d);
    pila.insertarTiempo(e);
    pila.insertarTiempo(f);
    pila.insertarTiempo(g);
    pila.insertarTiempo(h);
    pila.insertarTiempo(i);
    pila.insertarTiempo(j);
    pila.insertarTiempo(k);
    pila.insertarTiempo(l);
    pila.insertarTiempo(m);
    pila.insertarTiempo(n);
    pila.insertarTiempo(o);
    pila.insertarTiempo(p);
    pila.insertarTiempo(q);
    pila.insertarTiempo(r);
    pila.insertarTiempo(s);
    pila.insertarTiempo(t);
    pila.insertarTiempo(u);
    pila.insertarTiempo(v);
    pila.insertarTiempo(w);
    pila.insertarTiempo(x);
    pila.insertarTiempo(y);
    pila.insertarTiempo(z);
    

    cout << "La pila AL PRINCIPIO es así: ", pila.mostrar();

    int sumar;

    while (!cola.esVacia() || !pila.esVacia() || !n1.esVacio() || !n2.esVacio() || !n3.esVacio())
    {
        cout << "Ingrese el tiempo a sumar: ";
        cin >> sumar;

        for (int i = 0; i < sumar; i++)
        {
            contador += 1;

            cout << "Momento actual: " << contador << endl;

            while (pila.cimaPila().tiempoInicio == contador && !pila.esVacia())
            {
                cola.encolarPrioridad(pila.cimaPila());
                pila.desapilar();
            }

            cout << "La pila ahora es así: ", pila.mostrar();
            cout << "La cola ahora es así: ", cola.mostrarCola();
            
            cout << "NUCLEOS ANTES DE ACTUALIZAR" << endl;
            cout << "Núcleo 1: ", n1.mostrarColaNucleo();
            cout << "Núcleo 2: ", n2.mostrarColaNucleo();
            cout << "Núcleo 3: ", n3.mostrarColaNucleo();

            n1.actualizar();
            n2.actualizar();
            n3.actualizar();
            
            cout << "NUCLEOS DESPUÉS DE ACTUALIZAR" << endl;
            cout << "Núcleo 1: ", n1.mostrarColaNucleo();
            cout << "Núcleo 2: ", n2.mostrarColaNucleo();
            cout << "Núcleo 3: ", n3.mostrarColaNucleo();

            if (n1.esVacio() && !cola.esVacia()){
                n1.procesar(cola.desencolar());
            }
            if (n2.esVacio() && !cola.esVacia()){
                n2.procesar(cola.desencolar());
            }
            if (n3.esVacio() && !cola.esVacia()){
                n3.procesar(cola.desencolar());
            }
            cout << "NUCLEOS DESPUÉS DE ASIGNAR" << endl;
            cout << "Núcleo 1: ", n1.mostrarColaNucleo();
            cout << "Núcleo 2: ", n2.mostrarColaNucleo();
            cout << "Núcleo 3: ", n3.mostrarColaNucleo();
        }

    }

    cola.mostrarCola();
    n1.mostrarColaNucleo();
    n2.mostrarColaNucleo();
    n3.mostrarColaNucleo();

    return 0;
}



