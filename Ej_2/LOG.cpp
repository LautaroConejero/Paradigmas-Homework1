#include <iostream>
#include <fstream>
#include <string>
#include "LOG.h"
#include <vector>
using namespace std;

string nivelToString(NivelSeveridad nivel){
    switch (nivel) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL"; 
        default: return "UNKNOWN";
    }
}

void logMessage(string mensaje, NivelSeveridad NivelSeveridad){
    ofstream Log ("Log.txt", ios::app);
    if (!Log){
        throw runtime_error("No se pudo abrir el archivo");
        return;
    }
    Log << "["<< nivelToString(NivelSeveridad) << "] <" <<mensaje <<">" << endl;
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
        cout<< "Debug [0] \nInfo [1] \nWarning [2] \nError [3] \nCritical [4] \nSecurity[5] \n"; 
        cout << "Ingrese el nivel de severidad: ";
        int valor;
        cin >> valor;
        cout << endl;
        if (valor <0 || valor > 5){
            throw runtime_error("El valor ingresado no es valido");
        }
        switch (valor){
            case 5:{
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
            default:{
                string Mensaje;
                cin.ignore();
                cout << "Ingrese el mensaje: ";
                getline(cin, Mensaje);
                NivelSeveridad nivel = static_cast<NivelSeveridad>(valor);
                logMessage(Mensaje, nivel);
            }
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