#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> Nivel= {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

void logMessage(string mensaje, int NivelSeveridad);

void logMessage(string Mensage_de_Error, string Archivo, int Linea_de_Codigo);

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario);


int correr_log();