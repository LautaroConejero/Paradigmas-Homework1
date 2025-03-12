#include <iostream>
#include <vector>
#include <string>
#include "Ej_1/matrices.cpp"
#include "Ej_2/LOG.cpp"
#include "Ej_3/lista.cpp"
#include <memory>
using namespace std;

int main(){
    cout << "Ejercicio 1 [1] \nEjercicio 2 [2] \nEjercicio 3 [3] \nEjercicio 4 [4] \nSalir [5]\n";
    int Ejercicio;
    cin >> Ejercicio;
    while (Ejercicio < 1 || Ejercicio > 5){
        cout << "Ingrese un valido: " << endl;
        cin >> Ejercicio;
    }
    switch (Ejercicio){
        case 1:{
            cout << "Ingrese el tamaño de la matriz: ";
            int Numero;
            cin >> Numero;
            vector<vector<int>> Matriz = CrearMatriz(Numero);
            ImprimirMatriz(Matriz, Numero);
            break;
        }
        case 2:{  
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
            break;
        }
        case 3:{
            int Decision;
            while (Decision != 9){
                cout<< "Que desea hacer con la lista" << endl;
                cout<< "Insertar al inicio [1]" << endl;
                cout<< "Insertar al final [2]" << endl;
                cout<< "Insertar en una posicion deseada [3]" << endl;
                cout<< "Eliminar el primer elemento [4]" << endl;
                cout<< "Eliminar un elemento en una posicion deseada [5]" << endl;
                cout<< "Imprimir la lista [6]" << endl;
                cout<< "Imprimir el tamaño de la lista [7]" << endl;
                cout<< "Crear una nueva lista [8]" << endl;
                cout<< "Salir [9]" << endl;
                cin >> Decision;
                shared_ptr<List> Lista = create_list();
                switch (Decision){
                    case 1:{
                        int Numero;
                        cout << "Ingrese el numero que desea insertar: ";
                        cin >> Numero;
                        push_front(Lista, Numero);
                        break;
                    }
                    case 2:{
                        int Numero;
                        cout << "Ingrese el numero que desea insertar: ";
                        cin >> Numero;
                        push_back(Lista, Numero);
                        break;
                    }
                    case 3:{
                        int Numero;
                        cout << "Ingrese el numero que desea insertar: ";
                        cin >> Numero;
                        int Posicion;
                        cout << "Ingrese la posicion en la que desea insertar: ";
                        cin >> Posicion;
                        insert(Lista, Numero, Posicion);
                        break;
                    }
                    case 4:{
                        pop_front(Lista);
                        break;
                    }
                    case 5:{
                        int Posicion;
                        cout << "Ingrese la posicion que desea eliminar: ";
                        cin >> Posicion;
                        erase(Lista, Posicion);
                        break;
                    }
                    case 6:{
                        print_list(Lista);
                        break;
                    }
                    case 7:{
                        cout << "El tamaño de la lista es: " << size(Lista) << endl;
                        break;
                    }
                    case 8:{
                        if (size(Lista) != 0){
                            clear_list(Lista);
                        }
                        shared_ptr<List> Lista = create_list();
                        break;
                    }
                    case 9:{
                        return 0;
                        break;
                    }
                    default:{
                        cout << "Ingrese un valor valido" << endl;
                        break;
                    }
                }
            }
        }
        case 4:{
            break;
        }

    }
    return 0;

}