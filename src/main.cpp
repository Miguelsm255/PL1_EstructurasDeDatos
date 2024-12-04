#include <iostream>
#include "../include/Proceso/Proceso.h"
#include "../include/Pila/Pila.h"
#include "../include/Nucleo/Nucleo.h"
#include "../include/ListaNucleos/ListaNucleos.h"
using namespace std;

void menuInicio();
void menuEjecucion();
void definirProcesos();
void crearProcesos(int n);
void imprimirPila();
void ejecutar(bool manual);


Pila pila = Pila();
Pila procesosDisponibles = Pila();
ListaNucleos* listaNucleos = new ListaNucleos();

int sumaTiempos = 0;
int procesosEjecutados = 0;

int main(){
    
    //listaNucleos->añadirDerecha(Nucleo());

    bool salir = false;
    definirProcesos();
    listaNucleos->añadirDerecha(Nucleo());
    listaNucleos->añadirDerecha(Nucleo());
    
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            opcion = 0;
        }

        int cuantos = 0;
        switch (opcion)
        {
        case 1:

            cout << "Ingrese la cantidad de procesos a crear: ";
            cin >> cuantos;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cuantos = 0;
            }else{
                crearProcesos(cuantos);
            }
            break;
        case 2:
            cout << endl;
            cout << "La pila actual es esta: " << endl ,
            pila.mostrar();
            break;
        case 3:
            while (!pila.esVacia())
            {
                pila.desapilar();;
            }
            cout << "La pila ha sido borrada." << endl;
            if (procesosDisponibles.esVacia())
            {
                definirProcesos();
                cout << "Se han redefinido los procesos" << endl;
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



void imprimirPila()
{
    cout << "La pila actual es esta: " << endl;
    pila.mostrar();
    cout << endl;
}

void menuInicio()
{
    cout << endl;
    cout << "#-#-#-# Menú de opciones #-#-#-#" << endl;
    cout << "   1. Ingresar proceso" << endl;
    cout << "   2. Mostrar procesos" << endl;
    cout << "   3. Borrar pila de procesos" << endl;
    cout << "   4. Ejecutar manualmente" << endl;
    cout << "   5. Ejecutar automáticamente" << endl;
    cout << "   6. Salir" << endl;
    cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << endl;
    cout << endl;
    cout << "Ingrese una opción: ";
}

void definirProcesos()
{

    Proceso b = Proceso(2, 6, 18, 4);
    Proceso a = Proceso(1, 1, 1, 1);
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
    Proceso aa = Proceso(27, 99, 27, 6);

    // Proceso p1 = Proceso(1, 1, 0, 5);
    // Proceso p2 = Proceso(2, 2, 0, 3);
    // Proceso p3 = Proceso(3, 9, 0, 6);
    // Proceso p4 = Proceso(4, 5, 0, 7);
    // Proceso p5 = Proceso(5, 1, 0, 6);
    // Proceso p6 = Proceso(6, 3, 0, 8);

    while (!procesosDisponibles.esVacia())
    {
        procesosDisponibles.desapilar();
    }

    procesosDisponibles.insertarTiempo(a);
    procesosDisponibles.insertarTiempo(b);
    procesosDisponibles.insertarTiempo(c);
    procesosDisponibles.insertarTiempo(d);
    procesosDisponibles.insertarTiempo(e);
    procesosDisponibles.insertarTiempo(f);
    procesosDisponibles.insertarTiempo(g);
    procesosDisponibles.insertarTiempo(h);
    procesosDisponibles.insertarTiempo(i);
    procesosDisponibles.insertarTiempo(j);
    procesosDisponibles.insertarTiempo(k);
    procesosDisponibles.insertarTiempo(l);
    procesosDisponibles.insertarTiempo(m);
    procesosDisponibles.insertarTiempo(n);
    procesosDisponibles.insertarTiempo(o);
    procesosDisponibles.insertarTiempo(p);
    procesosDisponibles.insertarTiempo(q);
    procesosDisponibles.insertarTiempo(r);
    procesosDisponibles.insertarTiempo(s);
    procesosDisponibles.insertarTiempo(t);
    procesosDisponibles.insertarTiempo(u);
    procesosDisponibles.insertarTiempo(v);
    procesosDisponibles.insertarTiempo(w);
    procesosDisponibles.insertarTiempo(x);
    procesosDisponibles.insertarTiempo(y);
    procesosDisponibles.insertarTiempo(z);
    procesosDisponibles.insertarTiempo(aa);

    // procesosDisponibles.insertarTiempo(p1);
    // procesosDisponibles.insertarTiempo(p2);
    // procesosDisponibles.insertarTiempo(p3);
    // procesosDisponibles.insertarTiempo(p4);
    // procesosDisponibles.insertarTiempo(p5);
    // procesosDisponibles.insertarTiempo(p6);
}

void crearProcesos(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!procesosDisponibles.esVacia())
        {
            pila.insertarTiempo(procesosDisponibles.cimaPila());
            procesosDisponibles.desapilar();
            if(procesosDisponibles.esVacia())
            {
                cout << "Ya se ha añadido el máximo número de porcesos." << endl;
            }
        }else{
            cout << "No hay más procesos disponibles :(" << endl;
            break;
        }
    }
    
}

void menuEjecucion()
{
    cout << endl;
    cout << "--------------- Menú de ejecución ---------------" << endl;
    cout << "   1. Mostrar detalles de procesos en ejecución" << endl;
    cout << "   2. Continuar" << endl;
    cout << "   3. Continuar N minutos" << endl;
    cout << "   4. Terminar Automáticamente" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese una opción: ";
}

void ejecutar(bool manual)
{
    int contador = 0;
    int sumar = 0;
    bool vacio = false;

    // Mientras que existan procesos en la pila o en los núcleos
    while (!pila.esVacia() || !vacio)
    {
        if(manual) // si es manual, se muestra el menú
        {
            menuEjecucion(); // se muestra el menú

            int opcion = 0; // se crea una variable para guardar la opción
            cin >> opcion;  // se lee la opción
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                opcion = 0;
            }   // por si falla la lectura (metes otra cosa que no sea int)

            switch (opcion) 
            {
            case 1: // si la opción es 1, se muestran los detalles de los procesos en ejecución
                listaNucleos->detallesProcesosEjecucion();
                sumar = 0;
                break;
            case 2: // si la opción es 2, se avanza un minuto
                sumar = 1;
                break;
            case 3: // si la opción es 3, se avanza n minutos
                cout << "Ingrese el tiempo a sumar: ";
                cin >> sumar;
                cout << endl;
                break;
            case 4: // si la opción es 4, se cambia a modo automático
                manual = false;
                sumar = 0;
                break;
            
            default:    // si la opción no es ninguna de las anteriores, se muestra un mensaje de error
                cout << "Opción no válida" << endl;
                cout << endl;
                break;
            }
        }
        else
        {  // si es automático (no manual), se avanza un minuto
            sumar = 1;
        }

        // Por cada minuto que se avance
        for (int i = 0; i < sumar; i++)
        {
            cout << "__________________________" << endl;
            cout << " * Minuto actual: " << contador << endl;
            cout << endl;

            imprimirPila();
            listaNucleos->desencolarYProcesar();

            //Saco a los núcleos los procesos que arrancan en este minuto
            while (!pila.esVacia() && pila.cimaPila().tiempoInicio == contador)
            {
                cout << "++++++++++ SALE EL PROCESO NÚMERO " << pila.cimaPila().PID << " ++++++++++" << endl << endl;
                listaNucleos->hacerHueco();
                listaNucleos->encolarEnElMenor(&pila);
                pila.desapilar();
            }

            // SOLO VISUAL
            if (!manual)
            {
                listaNucleos->mostrarColasDeNucleos();
                imprimirPila();
                listaNucleos->detallesProcesosEjecucion();
                cout << endl;
            }

            listaNucleos->actualizarColasyNucleos(&sumaTiempos, &procesosEjecutados);
            listaNucleos->eliminarNucleosVacios();

            vacio = listaNucleos->nucleosVacios() && pila.esVacia();
            
            // Sumo 1 al contador (ha pasado un minuto)
            contador += 1;
        }
    }
    // Sale de aquí cuando termina de ejecutar todos los procesos

    cout << "Se han necesitado " << contador + 1 << " minutos para procesar todos los procesos." << endl;
    cout << "Se han ejecutado " << procesosEjecutados << " procesos." << endl;

    // simple comprobación para que no divida por 0.
    if (procesosEjecutados != 0)
    {
        cout << "El tiempo medio de estancia de los procesos en el sistema operativo ha sido de " << (float)sumaTiempos/(float)procesosEjecutados << " minutos." << endl;
    }else{
        cout << "No se ha ejecutado ningún proceso." << endl;
    }

    // Reinicio de variables para una posible nueva iteración
    contador = 0;
    sumaTiempos = 0;
    procesosEjecutados = 0;
    definirProcesos();
}
