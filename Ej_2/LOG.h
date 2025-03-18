#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum NivelSeveridad {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
};
string nivelToString(NivelSeveridad nivel);

void logMessage(string mensaje, NivelSeveridad NivelSeveridad);

void logMessage(string Mensage_de_Error, string Archivo, int Linea_de_Codigo);

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario);


int correr_log();