#include "LOG.h"

// Función para convertir el nivel de severidad a una cadena de texto
string nivelToString(NivelSeveridad nivel) {
    switch (nivel) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL"; 
        default: return "UNKNOWN";
    }
}

// Función para registrar un mensaje con un nivel de severidad
void logMessage(string mensaje, NivelSeveridad nivel) {
    ofstream Log("Log.txt", ios::app); // Abrir el archivo de log en modo append, asi, si esta creado, puedo modificarlo
    if (!Log) {
        throw runtime_error("No se pudo abrir el archivo"); // Ejemplo de excepcion capturada en runtime
        return;
    }
    Log << "[" << nivelToString(nivel) << "] <" << mensaje << ">" << endl; // Escribir el mensaje en el archivo de log
    Log.close(); 
}

// Función para registrar un mensaje de seguridad con un usuario
void logMessage(string mensaje, string Usuario) {
    ofstream Log("Log.txt", ios::app); 
    if (!Log) {
        throw runtime_error("No se pudo abrir el archivo");
        return;
    }
    Log << "[Security] <" << Usuario << "> " << mensaje << endl; // Escribir el mensaje en el archivo de log
    Log.close(); 
}

// Función para registrar un mensaje de error con información del archivo y línea de código
void logMessage(string Mensaje_de_Error, string Archivo, int Linea_de_Codigo) {
    ofstream Log("Log.txt", ios::app); // Abrir el archivo de log en modo append
    if (!Log) {
        throw runtime_error("No se pudo abrir el archivo");
        return;
    }
    Log << "[ERROR] <" << Mensaje_de_Error << "> Archivo: " << Archivo << " Linea: " << Linea_de_Codigo << endl; // Escribir el mensaje en el archivo de log
    Log.close();
}

// Función principal para correr el programa de logging
int correr_log() {
    try {
        cout << "Debug [0] \nInfo [1] \nWarning [2] \nError [3] \nCritical [4] \nSecurity[5] \n"; 
        cout << "Ingrese el nivel de severidad: ";
        int valor;
        cin >> valor; // Leer el nivel de severidad
        cout << endl;
        if (valor < 0 || valor > 5) { 
            throw runtime_error("El valor ingresado no es valido"); // esto es uno de los ejemplos de errores capturados en runtime, todos siguen el mismo esquema
        }
        switch (valor) {
            case 5: { // Caso para mensajes de seguridad
                string Usuario;
                cout << "Ingrese el nombre de usuario: ";
                cin >> Usuario;
                if (Usuario == "") {
                    throw runtime_error("El nombre de usuario no puede estar vacio");
                    return 0;
                }
                string Mensaje_acc;
                cout << "Ingrese el mensaje de acceso: ";
                cin.ignore();
                getline(cin, Mensaje_acc);
                if (Mensaje_acc == "") {
                    throw runtime_error("El mensaje de acceso no puede estar vacio");
                    return 0;
                }
                logMessage(Mensaje_acc, Usuario); // recibis ambas variables desde a terminal, y se registra en el LOG
                return 0;
            }
            default: { // Caso para los niveles de severidad defaults 
                string Mensaje;
                cin.ignore();
                cout << "Ingrese el mensaje: ";
                getline(cin, Mensaje);
                NivelSeveridad nivel = static_cast<NivelSeveridad>(valor); // se convierte la eleccion en un nivel de severidad
                logMessage(Mensaje, nivel); // Registrar el mensaje con el nivel de severidad
            }
        }
    }
    catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__); // Registrar el mensaje de excepción
        return 1;
    }
    catch (...) {
        logMessage("Error desconocido", __FILE__, __LINE__); // Registrar un mensaje de error desconocido
        return 1;
    }
    return 0;
}