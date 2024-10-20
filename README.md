# PL1_EstructurasDeDatos


# SIMULACIÓN DEL CONTROL DE PROCESOS EN UN SISTEMA OPERATIVO

## Parte I – Planificador con Colas de Prioridad[¹]
En esta práctica se pretende simular el funcionamiento de un planificador de procesos de un sistema operativo. En esta primera parte, simularemos el funcionamiento de un planificador con tres núcleos. El objetivo será calcular el tiempo medio que los procesos pasan en el sistema. Como resultado final se busca calcular el tiempo medio que los procesos se encuentran vivos dentro del sistema operativo.

El programa principal simulará el funcionamiento de un planificador de procesos,implementando[²] los núcleos, procesos, Pila (con sus operaciones habituales) y Cola (con sus operaciones habituales y el método insertar por prioridad).

Cada **proceso** que se inicio dentro del sistema operativo tendrá los siguientes datos:

* __Identificador del proceso__ (PID).
* __Identificador del proceso padre (PPID)__. Por defecto init con PID 1.
* __Inicio del proceso__ (en minutos desde las 00:00).
* __Tiempo de vida__ (en minutos). Los procesos deben indicar cuanto tiempo se encontrarán en ejecución.
* __Prioridad del proceso__ (cuanto menor es el valor de prioridad, mayor prioridad tiene el proceso). Las prioridades de los procesos vendrán dadas por un rango número entre 0 y 9.
* __Núcleo asignado__ para la ejecución cuando se le asigne tiempo de CPU.

El programa funcionará creando manualmente en el código un mínimo de 10 procesos, que se almacenarán en una pila ordenada por hora de inicio de cada proceso. Los procesos se atenderán por orden de prioridad en función de sus características, similar a una cola de prioridad.


#### Ejemplo de ejecución:
* Inicio de un proceso: El proceso será asignado a un núcleo libre o se añadirá a la cola de espera si todos los núcleos están ocupados.
* Finalización de un proceso: Cuando un proceso termina su ejecución, el núcleo quedará disponible para el proceso con mayor prioridad en la cola de espera.


El programa funcionará mediante un menú con, al menos, las siguientes opciones:

1. __Crear la pila de procesos__ que se iniciarán en el sistema. Los datos se crearán manualmente en el código.
2. __Mostrar__ los proceoss que se iniciarán (__pila de procesos__).
3. __Borrar__ la __pila de procesos__ que se van a ejecutar en el sistema operativo.
4. __Mostrar__ la __cola de espera__ de procesos.
5. __Mostrar__ los detalles de los procesos que se encuentran __en ejecución en cada uno de los nucleos.__ (PID del proceso, PPID del proceso, y tiempo)
6. Simular que han pasado __N minutos__ (N leído de teclado). Se simulará el paso del tiempo, escribiendo en pantalla los datos de los eventos de llegada y/o salida de procesos que vayan realizándose (minuto, PID, PPID, id del núcleo que ejecuta el proceso, estado de los distintos núcleos en ese momento).
7. Simular el __funcionamiento y ejecución de todos los procesos__ que se encuentran en el sistema operativo, es decir, hasta que no quede ningún proceso sin ejecutarse ni en espera. Se simulará el paso del tiempo, escribiendo en pantalla los datos de los eventos de inicio y/o finalización de procesos que vayan realizándose (minuto, PID, PPID, id del núcleo que ejecuta el proceso, estado de los distintos núcleos en ese momento). Al finalizar se mostrará el tiempo medio de estancia en el sistema operativo.



## Parte II – Listas

En esta segunda parte se implementará el TAD lista para gestionar los núcleos (cores) del sistema operativo, de forma que en cada momento se utilicen tantos cores como sea necesario. Simulando un entorno en la nube con capacidad de elasticidad y adaptabilidad.

Gestionándose de esta forma una lista de núcleos (cores)que se adaptará a la carga del sistema, añadiendo o eliminando núcleos según la necesidad.

Cada núcleo incluirá, además de su id y el proceso (PID) que está siendo ejecutado, una cola de procesos en espera. Cuando se produzca un evento de llegada, el proceso entrará directamente (en función de su prioridad y sin pasar por una cola previa) en el núcleo cuya cola sea más corta en ese momento (no teniendo por qué ser la cola que menos tarde en ejecutarse). Y será atendido cuando le corresponda en ese núcleo. Los procesos no pueden cambiarse de núcleo, y por tanto de cola, aunque haya núcleos vacíos.

Se recomienda a fin de guardar de manera coherente toda la información, ordenar la listapor el código identificativo de los núcleos.

#### Se pide implementar las siguientes operaciones:

* Añadir un núcleo cuando todos los núcleos tienen más de 2 procesos en espera.
* Eliminar núcleos vacíos cuando haya al menos dos núcleos libres. (la lista siempre debe tener un núcleo)
* Consultar en cualquier momento cuál es el núcleo más ocupado y el que tiene menos procesos.
* Consultar el número total de núcleos operativos.

El programa funcionará ahora mediante un __menú__ con, al menos, las siguientes opciones:

1. __Crear la pila de procesos__ que se ejecutaran en el sistema operativo, los datos se crearán manualmente en el código.
2. __Mostrar__ los proceoss que se iniciarán en el sistema operativo (__pila de procesos__).
3. __Borrar__ la __pila de procesos__ que llegarán al sistema opeartivo.
4. Simular que han pasado __N minutos__ (N leído de teclado). Se simulará el paso del tiempo, escribiendo en pantalla los datos de los eventos de inicio y/o fin de procesos que vayan realizándose (PID, PPID, id del núcleo que ejecuta el proceso, estado de los distintos núcleos en ese momento).
5. __Mostrar__ los datos de la __lista de núcleos__ (id del núcleo, proceso que esta siendo ejecutado, tiempo restante de ejecución, procesos que están a la espera de ser ejecutados)
6. __Consultar__ en cualquier momento que __núcleo__ tiene __menos procesos__ y cuál es el __más ocupado__.
7. __Consultar__ en cualquier momento el __número de núcleos__ de atención __operativos__.
8. Simular el __funcionamiento del sistema operativo ejecutando todos los procesos__, es decir, hasta que no quede ingún proceso sin ser ejecutado y en espera. Se simulará el paso del tiempo, escribiendo en pantalla los datos de los proceos de inicio y/o fin de procesos que vyan realizandose (PID, PPID, núcleo en el que entra/sale, estado de los distintos núcleos en ese momento). Al finalizar, se mostará el tiempo medio de estancia de los procesos en el sistema operativo.


## OBSERVACIONES:
* Ambas partes deben funcionar por separado, se recomienda implementar la primera y que funcione correctamente antes de comenzar la segunda.
* Aquí se está describiendo el funcionamiento básico del programa y las estructuras correspondientes, los alumnos deben tomar decisiones sobre los datos, su implementación, la interfaz del programa, etc, que deben ser justificadas en la documentación.
* Es decisión de cada grupo la forma en que se mostrará en pantalla el contenido de las estructuras y la información sobre el funcionamiento de la simulación, se valorará la claridad de la misma.
* Una vez entregada la práctica, se realizará una defensa en la que el programa debe funcionar correctamente con los datos de prueba que se facilitarán. La defensa, individual y obligatoria para ser calificado, constará de dos partes: o Defensa escrita (se realiza sin máquina) se puede traer, si se desea, el código en papel. o Defensa oral: para su realización es necesario traer el código entregado en el portátil o en un pen drive (en caso de no traer el portátil).