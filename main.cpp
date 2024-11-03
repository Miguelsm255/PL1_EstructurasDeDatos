#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include "Nucleo.h"
#include "Lista.h"
using namespace std;

void menuInicio();
void menuEjecucion();
void crearProcesosYEncolarlos();
void ejecutar(bool manual);
void detallesProcesosEjecucion();
void mostrarPila();
void definirProcesos();
void crearProcesos(int n);


Pila pila = Pila();
Pila procesosDisponibles = Pila();
Lista* listaNucleos = new Lista();

int sumaTiempos = 0;
int procesosEjecutados = 0;

int main(){
    
    //listaNucleos->añadirDerecha(Nucleo());

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

void ejecutar(bool manual)
{
    int contador = 0;
    int sumar = 0;

    while (!pila.esVacia() || (listaNucleos->longitudLista() != 1 && !listaNucleos->primeroPtr()->esVacio()))
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
            

            cout << "__________________________" << endl;
            cout << " * Minuto actual: " << contador << endl;
            cout << endl;

            mostrarPila();


            //Saco a los núcleos los procesos que arrancan en este minuto
            while (pila.cimaPila().tiempoInicio == contador && !pila.esVacia())
            {
                cout << "-----COMPRUEBO SI LOS NÚCLEOS ESTÁN LLENOS-----" << endl;
                cout << endl;

                // Compruebo si están todos llenos
                bool llenos = true;
                for (int j = 1; j <= listaNucleos->longitudLista(); j++)
                {
                    if (listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() < 3)
                    {
                        llenos = false;
                        cout << "Núcleo " << j << " no está lleno, tiene " << listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() << " procesos en cola." << endl;
                        cout << "Cola de núcleo " << j << ": ";
                        //listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
                        cout << endl;
                    }
                    
                }
                // Si es así, añado un nuevo núcleo
                if (llenos)
                {
                    listaNucleos = listaNucleos->añadirDerecha(Nucleo());
                    cout << "Están todos llenos, hemos añadido un nuevo núcleo" << endl;
                    cout << "Ahora hay " << listaNucleos->longitudLista() << " núcleos" << endl;
                }
                cout << endl;


                cout << "-----PARA ENCOLAR COMPRUEBO CUAL ES EL NÚCLEO CON MENOS COLA-----" << endl;

                                        //for (int j = 0; j < listaNucleos->longitudLista(); j++)
                                        //{
                                        //    cout << "Cola de núcleo " << j+1 << ": ";
                                        //    listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
                                        //    cout << endl;
                                        //}

                // Compruebo cual es el núcleo con menos procesos en cola y encolo
                Nucleo* menor = listaNucleos->obtenerNodo(1);
                for (int j = 1; j <= listaNucleos->longitudLista(); j++)
                {
                    
                    if (listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() < menor->NdeProcesosEnCola())
                    {
                        cout << "El núcleo " << j << " tiene menos procesos en cola" << endl;
                        menor = listaNucleos->obtenerNodo(j);
                    }
                }
                menor->encolarProceso(pila.cimaPila());
                cout << endl;
                cout << "Encolo en el menor" << endl;

                pila.desapilar();
            }
                                        //if (listaNucleos->longitudLista() < 0){
                                        //for (int j = 1; j <= listaNucleos->longitudLista(); j++)
                                        //{
                                        //    cout << "Cola de núcleo " << j << ": ";
                                        //    listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
                                        //    cout << endl;
                                        //}}

            for (int j = 1; j <= listaNucleos->longitudLista(); j++)
            {
                if (listaNucleos->obtenerNodo(j)->esVacio() && !listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->esVacia())
                {
                    cout << "Pongo a porcesar el proceso en el núcleo " << j << endl;
                    listaNucleos->obtenerNodo(j)->procesar(listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->desencolar());
                }
            }  

                                        //if (listaNucleos->longitudLista() < 0){
                                        //for (int j = 1; j <= listaNucleos->longitudLista(); j++)
                                        //{
                                        //    cout << "Cola de núcleo " << j << ": ";
                                        //    listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
                                        //    cout << endl;
                                        //}}


            if (!manual)
            {
                mostrarPila();
                                        //for (int j = 1; j <= listaNucleos->longitudLista(); j++)
                                        //{
                                        //    cout << "Cola de núcleo " << j << ": ";
                                        //    listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
                                        //    cout << endl;
                                        //}
                detallesProcesosEjecucion();
                cout << endl;
            }
            
                                        

            
            for (int j = 1; j <= listaNucleos->longitudLista(); j++)
            {
                int tiempo = listaNucleos->obtenerNodo(j)->actualizar();
                if (tiempo != 0)
                {
                    procesosEjecutados += 1;
                }
                sumaTiempos += tiempo;
            }

            for (int j = 1; j <= listaNucleos->longitudLista(); j++)
            {
                listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->actualizar();
            }
            

            if (pila.esVacia() && (listaNucleos->longitudLista() == 1 && listaNucleos->primeroPtr()->esVacio()))
            {
                break;
            }
            contador += 1;
        }
    }

    cout << "Se han necesitado " << contador + 1 << " minutos para procesar todos los procesos." << endl;
    cout << "Se han ejecutado " << procesosEjecutados << " procesos." << endl;

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
    for (int i = 0; i < listaNucleos->longitudLista(); i++)
    {
        cout << "- Proceso en ejecución en núcleo " << i+1 << ": " << endl;
        listaNucleos->obtenerNodo(i)->mostrarNucleo();
    }
}

void mostrarPila()
{
    cout << "La pila ahora es así: ", pila.mostrar();
    cout << endl;
}
