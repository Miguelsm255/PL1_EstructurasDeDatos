#include <iostream>
#include "../include/Proceso/Proceso.h"
#include "../include/Pila/Pila.h"
#include "../include/Nucleo/Nucleo.h"
#include "../include/ListaNucleos/ListaNucleos.h"
#include "../include/ABBProcesos/ABBProcesos.h"
using namespace std;

void menuInicio();
void menuEjecucion();
void menuFinal();
void definirProcesos();
void crearProcesos(int n);
void imprimirPila();
void ejecutar(bool manual);
void crearProcesoManualYAñadirlo();


Pila pila = Pila();
Pila procesosDisponibles = Pila();

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
            } else {
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
            if (procesosDisponibles.esVacia()) {
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

void crearProcesoManualYAñadirlo(ABBProcesos* arbolProcesos)
{
    int PID = 0;
    int prioridad = 0;
    bool salir = false;
    
    cout  << "Ingrese el PID del proceso a añadir: ";
    cin >> PID;
    while (!salir)
    {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << endl << "PID no válido. Inténtelo de nuevo: ";
        } else {
            salir = true;
        }
    }
    
    salir = false;

    while (!salir)
    {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << endl << "Prioridad no válida. Inténtelo de nuevo: ";
        } else {
            salir = true;
        }
    }
    arbolProcesos->insertar(Proceso(PID, prioridad, 0, 0));
    cout << "Proceso añadido correctamente." << endl;
}

void menuEjecucion()
{
    cout << endl;
    cout << "--------------- Menú de ejecución ---------------" << endl;
    cout << "   1. Mostrar detalles de procesos en ejecución" << endl;
    cout << "   2. Continuar" << endl;
    cout << "   3. Mostrar núcleo menos ocupado y más ocupado" << endl;
    cout << "   4. Añadir un proceso al árbol" << endl;
    cout << "   5. Continuar N minutos" << endl;
    cout << "   6. Terminar Automáticamente" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese una opción: ";
}

void menuFinal(ABBProcesos* arbolProcesos)
{
    bool salir = false;
    while (!salir)
    {
        cout << endl;
        cout << "--------------- Menú Final ---------------" << endl;
        cout << "   1. Mostrar los procesoso en orden" << endl;
        cout << "   2. Mostrar procesos con una prioridad específica" << endl;
        cout << "   3. Mostrar prioridades con más procesos y con menos procesos" << endl;
        cout << "   4. Tiempo promedio de una prioridad específica" << endl;
        cout << "   5. Mostrar el tiempo promedio en PreOrden" << endl;
        cout << "   6. Insertar proceso en el árbol" << endl;
        cout << "   7. Salir" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "Ingrese una opción: ";

        int opcion = 0;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            opcion = 0;
        }

        switch (opcion)
        {
        case 1:             // mostrar los procesos en orden
            arbolProcesos->mostrarInOrden();
            break;
        case 2:             // mostrar los procesos con una prioridad específica
            cout << "Introduce la prioridad: ";
            int p;
            cin >> p;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Opción no válida" << endl;
            } else {
                cout << endl;
                ListaProcesos* l = arbolProcesos->obtenerPrioridadEspecifica(p);
                if (l != nullptr) {
                    l->mostrarListaProcesos();
                } else {
                    cout << "No hay procesos con esa prioridad" << endl;
                }
            }
            break;
        case 3:             // mostrar prioridad con más y menos procesos
            cout << "Prioridad con más procesos: " << arbolProcesos->mayorNumProcesos() << endl;
            cout << "Prioridad con menos procesos: " << arbolProcesos->menorNumProcesos() << endl;
            break;
        case 4:             // tiempo promedio de una prioridad especifica
            cout << "Introduce la prioridad: ";
            int p2;
            cin >> p2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Opción no válida" << endl;
            } else {
                ListaProcesos* l2 = arbolProcesos->obtenerPrioridadEspecifica(p2);
                if (l2 != nullptr) {
                    cout << "Tiempo promedio de estancia: " << l2->mediaTiempos() << " minutos" << endl;
                } else {
                    cout << "No hay procesos con esa prioridad" << endl;
                }
            }
            break;
        case 5:             // mostrar el tiempo promedio en preorden
            cout << "PreOrden: " << endl;
            arbolProcesos->mostrarPromedioPreOrden();
            break;
        case 6:             // insertar proceso en el árbol
            crearProcesoManualYAñadirlo(arbolProcesos);
            break;
        case 7:
            salir = true;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
        }  
    }
}

void ejecutar(bool manual)
{
    ListaNucleos* listaNucleos = new ListaNucleos();
    listaNucleos->añadirDerecha(Nucleo());
    listaNucleos->añadirDerecha(Nucleo());

    ABBProcesos* arbolProcesos = new ABBProcesos();

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
            case 1:                     // mostrar los detalles de los procesos en ejecución
                listaNucleos->detallesProcesosEjecucion();
                sumar = 0;
                break;
            case 2:                     // mostrar los detalles del núcleo más ocupado y del menos ocupado
                listaNucleos->mostrarMenosOcupado();
                listaNucleos->mostrarMasOcupado();
                sumar = 0;
                break;
            case 3:                     // añadir un proceso al arbol
                crearProcesoManualYAñadirlo(arbolProcesos);
                break;
            case 4:                     // avanzar un minuto
                sumar = 1;
                break;
            case 5:                     // avanzar n minutos
                cout << "Ingrese el tiempo a sumar: ";
                cin >> sumar;
                cout << endl;
                break;
            case 6:                     // cambiar a modo automático
                manual = false;
                sumar = 0;
                break;
            
            default:                    // mostrar un mensaje de error
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

            listaNucleos->actualizarColasyNucleos(arbolProcesos);
            listaNucleos->eliminarNucleosVacios();

            vacio = listaNucleos->nucleosVacios() && pila.esVacia();
            
            // Sumo 1 al contador (ha pasado un minuto)
            contador += 1;
        }
    }
    // Sale de aquí cuando termina de ejecutar todos los procesos

    cout << "Se han necesitado " << contador + 1 << " minutos para procesar todos los procesos." << endl;
    cout << "Se han ejecutado " << arbolProcesos->numProcesosEjecutados() << " procesos." << endl;

    // simple comprobación para que no divida por 0.
    if (arbolProcesos->numProcesosEjecutados() != 0)
    {
        cout << "El tiempo medio de estancia de los procesos en el sistema operativo ha sido de " << arbolProcesos->mediaTiempos() << " minutos." << endl;
    }else{
        cout << "No se ha ejecutado ningún proceso." << endl;
    }


    int opcion = 0;
    cout  << "Ejecución terminada. Quiere ver detalles? (1: Sí, 2: No): ";
    cin >> opcion;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        opcion = 0;
    }

    switch (opcion)
    {
    case 1:
        menuFinal(arbolProcesos);
        break;
    case
        2: break;
    }




    

    // Reinicio de variables para una posible nueva iteración
    contador = 0;
    delete arbolProcesos;
    definirProcesos();
}
