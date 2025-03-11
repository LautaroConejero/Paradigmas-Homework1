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
    Log << "[Security] <" <<Usuario <<">" << mensaje << endl;
    Log.close();
}

void logMessage(string Mensage_de_Error, string Archivo, int Linea_de_Codigo){
    ofstream Log ("Log.txt", ios::app);
    Log << "[ERROR] <" << Mensage_de_Error << "> Archivo: " << Archivo << " Linea: " << Linea_de_Codigo << endl;
    Log.close();
}
