#include <iostream>
#include "../include/Proceso/Proceso.h"
#include "../include/Pila/Pila.h"
#include "../include/Nucleo/Nucleo.h"
#include "../include/Lista/Lista.h"
using namespace std;

void menuInicio();
void menuEjecucion();
void crearProcesosYEncolarlos();
void detallesProcesosEjecucion();
void mostrarPila();
void definirProcesos();
void crearProcesos(int n);

void ejecutar(bool manual);
void desencolarYProcesar();
void hacerHueco();
void encolarEnElMenor();
Nucleo* NucleoConMenosProcesos();
void actualizarColasyNucleos();
void eliminarNucleosVacios();
void mostrarColasDeNucleos();
bool nucleosVacios();


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

void detallesProcesosEjecucion()
{
    for (int i = 1; i <= listaNucleos->longitudLista(); i++) // por cada núcleo
    {
        cout << "- Proceso en ejecución en núcleo " << i << ": " << endl;
        listaNucleos->obtenerNodo(i)->mostrarNucleo(); // Imprime el proceso en ejecución
    }
}

void mostrarPila()
{
    cout << "La pila ahora es así: ", pila.mostrar();
    cout << endl;
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
                detallesProcesosEjecucion();
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

            mostrarPila(); // SOLO VISUAL
            desencolarYProcesar();

            //Saco a los núcleos los procesos que arrancan en este minuto
            while (pila.cimaPila().tiempoInicio == contador && !pila.esVacia())
            {
                cout << "++++++++++ SALE EL PROCESO NÚMERO " << pila.cimaPila().PID << " ++++++++++" << endl << endl;
                hacerHueco();
                encolarEnElMenor();
                pila.desapilar();
            }

            // SOLO VISUAL
            if (!manual)
            {
                mostrarColasDeNucleos();
                mostrarPila();
                detallesProcesosEjecucion();
                cout << endl;
            }

            actualizarColasyNucleos();
            eliminarNucleosVacios();

            vacio = nucleosVacios();
            
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

void desencolarYProcesar()
{
    // Si el nucleo está vacío y su lista tiene procesos esperando, pongo el primero a procesar
    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada núcleo
    {
        // aquí se hace la comprobación de si el núcleo está vacío y tiene procesos en cola
        if (listaNucleos->obtenerNodo(j)->esVacio() && !listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->esVacia())
        {
            cout << "Pongo a porcesar el proceso en el núcleo " << j << endl;
            listaNucleos->obtenerNodo(j)->procesar(listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->desencolar());
        }
    }
    cout << endl;
}

void hacerHueco()
{
    cout << "-----COMPRUEBO SI LOS NÚCLEOS ESTÁN LLENOS-----" << endl;
    cout << endl;
    // Compruebo si están todos llenos
    bool llenos = true;
    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada núcleo
    {
        if (listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() < 3) // si un nucleo tiene - de 3 procesos (no lleno)
        {
            llenos = false; // no están todos llenos
            cout << "Núcleo " << j << " no está lleno, tiene " << listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() << " procesos en cola." << endl;
            cout << "Cola de núcleo " << j << ": ";
            listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
            cout << endl;
        }
        
    }

    // Si están todos llenos, añado un nuevo núcleo
    if (llenos)
    {
        listaNucleos = listaNucleos->añadirDerecha(Nucleo()); // añado núcleo nuevo
        cout << "Están todos llenos, hemos añadido un nuevo núcleo" << endl;
        cout << "Ahora hay " << listaNucleos->longitudLista() << " núcleos" << endl;
    }
    cout << endl;
}

void encolarEnElMenor()
{
    cout << "-----PARA ENCOLAR COMPRUEBO CUAL ES EL NÚCLEO CON MENOS COLA-----" << endl;
    mostrarColasDeNucleos(); // SOLO VISUAL

    Nucleo* menor = NucleoConMenosProcesos(); // obtengo el núcleo con menos procesos en cola

    if (menor->NdeProcesosEnCola() == 0 && menor->esVacio())
    {
        menor->procesar(pila.cimaPila()); // lo pongo a procesar directamente
        cout << "Como no tiene cola y está vacío, lo meto en el núcleo." << endl;
    }
    else
    {
        menor->encolarProceso(pila.cimaPila()); // encolo el proceso en el núcleo menor
        cout << "Encolo en el menor" << endl;
    }
    mostrarColasDeNucleos(); // SOLO VISUAL        
    cout << endl;
}

Nucleo* NucleoConMenosProcesos()
{
    // Compruebo cual es el núcleo con menos procesos en cola y encolo
    Nucleo* menor = listaNucleos->obtenerNodo(1); // por defecto cogemos el primero
    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada núcleo
    {
        // si el núcleo j tiene menos procesos en cola que el núcleo menor
        if (listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() <= menor->NdeProcesosEnCola())
        {
            if (listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() == menor->NdeProcesosEnCola() && listaNucleos->obtenerNodo(j)->esVacio())
            {
                cout << "El núcleo " << j << " tiene menos procesos en cola" << endl;
                menor = listaNucleos->obtenerNodo(j); // el núcleo j es el nuevo menor
            }
            else if (listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() < menor->NdeProcesosEnCola())
            {
                cout << "El núcleo " << j << " tiene menos procesos en cola" << endl;
                menor = listaNucleos->obtenerNodo(j); // el núcleo j es el nuevo menor
            }
        }
    }
    cout << endl;
    return menor;
}

void actualizarColasyNucleos()
{
    // actualizo los núcleos
    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada núcleo
    {
        // actualizar suma 1 al tiempo que lleva ejecutado y al tiempo en SO
        // si el proceso ha terminado, devuelve el tiempo que ha estado en el SO
        // si no devuelve 0
        int tiempo = listaNucleos->obtenerNodo(j)->actualizar(); 

        // si el tiempo es distinto de 0, es que ha terminado, sumo 1 a procesosEjecutados
        if (tiempo != 0)
        {
            procesosEjecutados += 1;
        }
        sumaTiempos += tiempo; // sumo el timepo que me ha devuelto al tiempo total
    }

    // actualizar las colas: esto solo suma 1 al tiempo en SO.
    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada nucleo
    {
        listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->actualizar(); // accedo a su cola y actualizo
    }
}

void eliminarNucleosVacios()
{
    // Para comprobar cuántos núcleos vacíos hay, y si hay más de 2, elimino hasta que queden 2.
    int nucleosVacios = 0;

    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada núcleo
    {
        // si está vacío y su cola está vacía
        if (listaNucleos->obtenerNodo(j)->esVacio() && listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->esVacia())
        {
            nucleosVacios += 1; // sumo 1 a nucleosVacios
        }
    }

    // compruebo el valor de nucleosVacios. Si hay más de 2, elimino núcleos vacíos hasta que queden 2
    for (int j = 1; j <= listaNucleos->longitudLista(); j++) // por cada núcleo
    {
        // si está vacío y nucleosVacios es mayor que 2
        if (listaNucleos->obtenerNodo(j)->esVacio() && listaNucleos->obtenerNodo(j)->obtenerColaNucleo()->esVacia() && nucleosVacios > 2)
        {
            cout << "Elimino núcleo " << j << endl;
            listaNucleos = listaNucleos->eliminarNodo(j); // elimino el núcleo
            nucleosVacios -= 1; // resto 1 a nucelosVacios
        }
    }
}

void mostrarColasDeNucleos()
{
    if (listaNucleos->longitudLista() > 0){
        for (int j = 1; j <= listaNucleos->longitudLista(); j++)
        {
            cout << "Cola de núcleo " << j << ": ";
            listaNucleos->obtenerNodo(j)->mostrarColaNucleo();
            
        }
        cout << endl;
    }
    else
    {
        cout << "No hay núcleos" << endl;
        cout << endl;
    }
}

bool nucleosVacios()
{
    // Compruebo si todos los núcleos están vacíos
    bool vacio = true;
    for (int j = 1; j <= listaNucleos->longitudLista(); j++)
    {
        cout << "Núcleo " << j << " tiene " << listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() << " procesos en cola." << endl;
        cout << "Núcleo " << j << " está vacío: ";
        if (listaNucleos->obtenerNodo(j)->esVacio())
        {
            cout << "Sí" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        cout << endl;
        if (!pila.esVacia() || listaNucleos->obtenerNodo(j)->NdeProcesosEnCola() != 0 || !listaNucleos->obtenerNodo(j)->esVacio())
        {
            vacio = false;
        }
    }
    return vacio;
}