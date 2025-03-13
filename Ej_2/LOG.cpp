#include <iostream>
#include <fstream>
#include <string>
#include "LOG.h"
#include <vector>
using namespace std;

    void logMessage(string mensaje, int NivelSeveridad){
        ofstream Log ("Log.txt", ios::app);
        if (!Log){
            throw runtime_error("No se pudo abrir el archivo");
            return;
        }
        string nivel_mensaje = Nivel[NivelSeveridad];
        Log << "["<< nivel_mensaje << "] <" <<mensaje <<">" << endl;
        Log.close();
    }

    void logMessage(string mensaje, string Usuario){
        ofstream Log ("Log.txt", ios::app);
        if (!Log){
            throw runtime_error("No se pudo abrir el archivo");
            return;
        }
        Log << "[Security] <" <<Usuario <<"> " << mensaje << endl;
        Log.close();
    }

    void logMessage(string Mensage_de_Error, string Archivo, int Linea_de_Codigo){
        ofstream Log ("Log.txt", ios::app);
        if (!Log){
            throw runtime_error("No se pudo abrir el archivo");
            return;
        }
        Log << "[ERROR] <" << Mensage_de_Error << "> Archivo: " << Archivo << " Linea: " << Linea_de_Codigo << endl;
        Log.close();
    }

    int correr_log(){
        try{
            cout << "Ingrese el nivel de severidad: " << endl;
            cout<< "Debug [0] \nInfo [1] \nWarning [2] \nError [3] \nCritical [4] \nSecurity[5] \nNuevo Evento[6] \n";  
            int valor;
            cin >> valor;
            if (valor <0 || valor > 6){
                throw runtime_error("El valor ingresado no es valido");
            }

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
                string Usuario;
                cout << "Ingrese el nombre de usuario: ";
                cin >> Usuario;
                if (Usuario == ""){
                    throw runtime_error("El nombre de usuario no puede estar vacio");
                    return 0;
                }
                string Mensaje_acc;
                cout << "Ingrese el mensaje de acceso: ";
                cin.ignore();
                getline(cin, Mensaje_acc);
                if (Mensaje_acc == ""){
                    throw runtime_error("El mensaje de acceso no puede estar vacio");
                    return 0;
                }
                logMessage(Mensaje_acc, Usuario);
            }
        }
        catch (const exception& e){
            logMessage(e.what(), __FILE__, __LINE__);
            return 1;
        }
        catch (...){
            logMessage("Error desconocido", __FILE__, __LINE__);
            return 1;
        }
        return 0;
    }