#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include "Nucleo.h"
using namespace std;

void menuInicio();
void menuEjecucion();
void crearProcesosYEncolarlos();
void ejecutar(bool manual);
void detallesProcesosEjecucion();


Pila pila = Pila();
Cola cola = Cola();

Nucleo n1 = Nucleo();
Nucleo n2 = Nucleo();
Nucleo n3 = Nucleo();



int main(){
    
    bool salir = false;

    while(salir == false)
    {
        menuInicio();

        //1. Ingresar proceso
        //2. Mostrar procesos
        //3. Borrar pila de procesos
        //4. Ejecutar manualmente
        //5. Ejecutar automáticamente
        //6. Salir

        int opcion = 0;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            crearProcesosYEncolarlos();
            break;
        case 2:
            pila.mostrar();
            break;
        case 3:
            while (!pila.esVacia())
            {
                pila.desapilar();;
            }
            break;
        case 4:
            ejecutar(true);
            break;
        case 5:
            ejecutar(false);
            break;
        case 6:
            salir = true;
            break;
    
        default:
            cout << "Opción no válida" << endl;
            break;
        }
    }
    return 0;
}





void menuInicio()
{
    cout << "1. Ingresar proceso" << endl;
    cout << "2. Mostrar procesos" << endl;
    cout << "3. Borrar pila de procesos" << endl;
    cout << "4. Ejecutar manualmente" << endl;
    cout << "5. Ejecutar automáticamente" << endl;
    cout << "6. Salir" << endl;
}

void crearProcesosYEncolarlos()
{
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
}

void ejecutar(bool manual)
{
    int contador = 0;
    int sumar;

    while (!cola.esVacia() || !pila.esVacia() || !n1.esVacio() || !n2.esVacio() || !n3.esVacio())
    {
        if(manual)
        {
            menuEjecucion();

            int opcion = 0;
            cin >> opcion;
            
            switch (opcion)
            {
            case 1:
                detallesProcesosEjecucion();
                break;
            case 2:
                sumar = 1;
                break;
            case 3:
                cout << "Ingrese el tiempo a sumar: ";
                cin >> sumar;
                break;
            case 4:
                manual = false;
                break;
            
            default:
                break;
            }
        }else{
            sumar = 1;
        }

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

        if(!manual){
            cout << "Se han necesitado " << contador << " unidades de tiempo para procesar todos los procesos." << endl;
        }
    }
}

void menuEjecucion()
{
    cout << "1. Mostrar detalles de procesos en ejecución" << endl;
    cout << "2. Continuar" << endl;
    cout << "3. Continuar N minutos" << endl;
    cout << "4. Terminar Automáticamente" << endl;
}

void detallesProcesosEjecucion()
{

}
