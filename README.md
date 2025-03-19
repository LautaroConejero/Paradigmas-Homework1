# Paradigmas-Homeworks

COMO CORRER EL CODIGO?
El codigo contiene un archivo "main", es decir que dentro de ahi podes correr todo.
Para facilitarte la cosa escribis "make" en la terminal donde ejecuta el archivo
En la terminal se va dar la opcion de poder hacer un ejercicio de los 4 o salir.
Ahi, depende tu eleccion va a correr el ejercicio indicado.

#Ejercicio 1
No tiene ningun misterio, mas que uso un vector de vectores. Dsp es todo lo mismo

#Ejercicio 2
Aca uso el Enum que piden usar, y en este caso my Try lo uso en la funcion para correr el ejercicio completo.
Es decir, los "errores" que throwea y catchea son errores que pueden ocurrir en tiempo de runtime.
Ejemplos son, que un input de un valor sea incorrecto dentro de un rango, o que pasen mal la informacion desde terminal.

#Ejercicio 3
En este meti un par de funcioncitas de mas (No es nada de otro mundo igual, nomas queria ahorrarme mas lineas)
meti la funcion size(), pop_back, clear_list que nomas ayudan a unas cositas.

#Ejercicio 4
Este me hizo pensar lindo. 
Primero JUSTIFICO que uso char* en vez de string, porque habiendo probado/investigado, te das cuenta que el tiempo de ejecucion es un toque mas rapido. capaz es mas iterativo y simple usar string, ya que tenes todas las funciones de <string>, pero me convencio la velocidad, aunque sea poca, de char*

Ahora para comparar el tiempo de ejecucion y compilacion tube un lindo quilombo.
Que pasa, con mi computadora enchufada (es una laptop), y sin aplicacion abiertas en segundo plano, cuando hago literalmente esto:
                auto start = chrono::high_resolution_clock::now();
                auto end = chrono::high_resolution_clock::now();
                auto ElapsedTime = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
El valor de ElapsedTime decide ser LITERALMENTE aproximademnte 170000 nanosegundos. Me esta tardando, porque si ese tiempo de base.
Okey, entonces a base de repetir esa misma cuentita y el valor de ElapsedTime sumarlo una N cantidad de veces en un valor suma_demas
que:
1) El promedio de ese tiempo "De mas" termina redondeadose en unos 400 y pico de nanosegundos
2) QUE SOLO EL PRIMER VALOR ESTA LOCO, osea el primer daba algo totalmente absurdo, pero el segundo ya baja de 1000 nanosegundos, increible. El tema que no es solo para cuando hago el "De mas", sino que tambien pasa para todos, osea para el modificado y original.
SOLUCION:
1) que la suma de N veces el ElapsedTime no considere el primer valor, eso hace que no reciba un outlier gratis
2) que imprima dos valores distintos para la comparacion, Uno que es el promedio de cada uno y otro que se le resta el "tiempo de mas"
Entonces ahi si me terminan dando cosas bastantes razonables, como si diga que el tiempo de compilacion, considerando el "tiempo de mas" ronda alrededor de 400 y pico, y el de ejecucion esta en 7000-8000, lo que es totalmente logico
(Puede ser que aveces el tiempo de compilacion sin la parte "de mas" de negativo, es por eso que imprime las dos)
voy a dejar la opcion para que se vea lo de los valores que se van de mambo.      