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
void mostrarPilayCola();
void definirProcesos();
void crearProcesos(int n);


Pila pila = Pila();
Pila procesosDisponibles = Pila();
Cola cola = Cola();

Nucleo n1 = Nucleo();
Nucleo n2 = Nucleo();
Nucleo n3 = Nucleo();

int sumaTiempos = 0;
int procesosEjecutados = 0;

int main(){
    
    bool salir = false;
    definirProcesos();

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

    Proceso a = Proceso(1, 1, 1, 1);
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

void ejecutar(bool manual)
{
    int contador = 0;
    int sumar = 0;

    while (!cola.esVacia() || !pila.esVacia() || !n1.esVacio() || !n2.esVacio() || !n3.esVacio())
    {
        if(manual)
        {
            menuEjecucion();

            int opcion = 0;
            cin >> opcion;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                opcion = 0;
            }

            switch (opcion)
            {
            case 1:
                detallesProcesosEjecucion();
                sumar = 0;
                break;
            case 2:
                sumar = 1;
                break;
            case 3:
                cout << "Ingrese el tiempo a sumar: ";
                cin >> sumar;
                cout << endl;
                break;
            case 4:
                manual = false;
                sumar = 0;
                break;
            
            default:
                cout << "Opción no válida" << endl;
                cout << endl;
                break;
            }
        }else{
            sumar = 1;
        }

        for (int i = 0; i < sumar; i++)
        {
            contador += 1;

            cout << "__________________________" << endl;
            cout << " * Minuto actual: " << contador << endl;
            cout << endl;
            
            //Saco a la cola los procesos que arrancan en este minuto
            while (pila.cimaPila().tiempoInicio == contador && !pila.esVacia())
            {
                cola.encolarPrioridad(pila.cimaPila());
                pila.desapilar();
            }

            // Asigno procesos a los núcleos si están libres
            if (n1.esVacio() && !cola.esVacia()){
                n1.procesar(cola.desencolar());
            }
            if (n2.esVacio() && !cola.esVacia()){
                n2.procesar(cola.desencolar());
            }
            if (n3.esVacio() && !cola.esVacia()){
                n3.procesar(cola.desencolar());
            }

            if (!manual)
            {
                mostrarPilayCola();
                detallesProcesosEjecucion();
                cout << endl;
            }

            int t1 = n1.actualizar();
            int t2 = n2.actualizar();
            int t3 = n3.actualizar();


            

            sumaTiempos += t1 + t2 + t3;

            if (t1 != 0)
            {
                procesosEjecutados += 1;
            }
            if (t2 != 0)
            {
                procesosEjecutados += 1;
            }
            if (t3 != 0)
            {
                procesosEjecutados += 1;
            }

            cola.actualizar(); 

            if (cola.esVacia() && pila.esVacia() && n1.esVacio() && n2.esVacio() && n3.esVacio())
            {
                break;
            }
        }
    }

    cout << "Se han necesitado " << contador << " minutos para procesar todos los procesos." << endl;
    cout << "Se han ejecutado " << procesosEjecutados << " procesos." << endl;

    if (procesosEjecutados != 0)
    {
        cout << "El tiempo medio de estancia de los procesos en el sistema operativo ha sido de " << sumaTiempos/procesosEjecutados << " minutos." << endl;
    }else{
        cout << "No se ha ejecutado ningún proceso." << endl;
    }

    // Reinicio de variables para una posible nueva iteración
    contador = 0;
    sumaTiempos = 0;
    procesosEjecutados = 0;
    definirProcesos();
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

void detallesProcesosEjecucion()
{
    cout << "- Proceso en ejecución en núcleo 1: " << endl;
    n1.mostrarNucleo();
    cout << "- Proceso en ejecución en núcleo 2: " << endl;
    n2.mostrarNucleo();
    cout << "- Proceso en ejecución en núcleo 3: " << endl;
    n3.mostrarNucleo();
    cout << endl;
}

void mostrarPilayCola()
{
    cout << "La pila ahora es así: ", pila.mostrar();
    cout << "La cola ahora es así: ", cola.mostrarCola();
    cout << endl;
}
