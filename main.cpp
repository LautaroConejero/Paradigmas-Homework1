#include <iostream>
#include <vector>
#include <string>
#include "Ej_1/matrices.cpp"
#include "Ej_2/LOG.cpp"
using namespace std;

int main(){
    cout << "Ejercicio 1 [1] \nEjercicio 2 [2] \nEjercicio 3 [3] \nEjercicio 4 [4] \nSalir [5]\n";
    int Respuesta;
    cin >> Respuesta;
    if (Respuesta == 1){
        cout << "Ingrese el tamaño de la matriz: ";
        int Numero;
        cin >> Numero;
        vector<vector<int>> Matriz = CrearMatriz(Numero);
        ImprimirMatriz(Matriz, Numero);
    }
    if (Respuesta== 2){  
        try{
            cout << "Ingrese el nivel de severidad: " << endl;
            cout<< "Debug [0] \nInfo [1] \nWarning [2] \nError [3] \nCritical [4] \nSecurity[5] \nNuevo Evento[6] \n";  
            int valor;
            cin >> valor;

            while (valor < 0 || valor > 6) {
                cout << "Ingrese un valor valido: ";
                cin >> valor;
            }

            if (valor >= 0 && valor <= 4){
                string Mensaje;
                cin.ignore();
                cout << "Ingrese el mensaje: ";
                getline(cin, Mensaje);
                logMessage(Mensaje, valor);
            }
            else if (valor == 5){
                string Mensaje_acc;
                cout << "Ingrese el mensaje de acceso: ";
                cin.ignore();
                getline(cin, Mensaje_acc);
                string Usuario;
                cout << "Ingrese el nombre de usuario: ";
                cin >> Usuario;
                logMessage(Mensaje_acc, Usuario);
            }
        }
        catch (const exception& e){
            logMessage(e.what(), __FILE__, __LINE__);
            return 1;
        }
    }
    return 0;

}