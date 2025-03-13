#include <iostream>
#include <fstream>
#include <string>
#include "LOG.h"
#include <vector>
using namespace std;

void logMessage(string mensaje, int NivelSeveridad){
    ofstream Log ("Log.txt", ios::app);
    string nivel_mensaje = Nivel[NivelSeveridad];
    Log << "["<< nivel_mensaje << "] <" <<mensaje <<">" << endl;
    Log.close();
}

void logMessage(string mensaje, string Usuario){
    ofstream Log ("Log.txt", ios::app);
    Log << "[Security] <" <<Usuario <<"> " << mensaje << endl;
    Log.close();
}

void logMessage(string Mensage_de_Error, string Archivo, int Linea_de_Codigo){
    ofstream Log ("Log.txt", ios::app);
    Log << "[ERROR] <" << Mensage_de_Error << "> Archivo: " << Archivo << " Linea: " << Linea_de_Codigo << endl;
    Log.close();
}

int correr_log(){
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
    return 0;
}