#include "Ej_1/matrices.cpp"
#include "Ej_2/LOG.cpp"
#include "Ej_3/lista.cpp"
#include "Ej_4/Recu.cpp"

int main(){
    cout << "Ejercicio 1 [1] \nEjercicio 2 [2] \nEjercicio 3 [3] \nEjercicio 4 [4] \nSalir [5]\n";
    cout << "Ingrese el ejercicio que desea correr: ";
    int Ejercicio;
    cin >> Ejercicio;
    while (Ejercicio < 1 || Ejercicio > 5){
        cout << endl;
        cout << "Ingrese un valor valido: ";
        cin >> Ejercicio;
    }
    cout << endl;
    switch (Ejercicio){
        case 1:{
            correr_matriz();
            break;
        }
        case 2:{  
            correr_log();
            break;
        }
        case 3:{
            correr_lista();
            break;
        }
        case 4:{
            correr_recu();
            break;
        }
    }
    return 0;

}