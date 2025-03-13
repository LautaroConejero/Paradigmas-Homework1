#include <iostream>
#include <string>
#include "Recu.hpp"
#include <chrono>
using namespace std;

bool comp_recu(string variable1, string variable2){
    if (variable1.size() != variable2.size()){
        return false;
    }
    if (variable1.empty() && variable2.empty(   )){
        return true;
    }
    if (variable1[variable1.size()-1] != variable2[variable1.size() -1]){
        return false;
    }
    cout << variable1 << " " << variable2 << endl;
    return comp_recu(variable1.substr(0, variable1.size()-1), variable2.substr(0, variable2.size()-1));
}
bool comp_recu_char(char* variable1, char* variable2){
    if (*variable1 == '\0' && *variable2 == '\0'){
        return true;
    }
    if (*variable1 != *variable2){
        return false;
    }
    cout << variable1 << " " << variable2 << endl;
    return comp_recu_char(variable1+1, variable2+1);
}
void tiempo_ejecucion_string(string variable1, string variable2){
    auto start = chrono::high_resolution_clock::now();
    comp_recu(variable1, variable2);
    auto end = chrono::high_resolution_clock::now();
    cout << "El tiempo de ejecucion es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
    return;
}
void tiempo_ejecucion_char(char* variable1, char* variable2){
    auto start = chrono::high_resolution_clock::now();
    comp_recu_char(variable1, variable2);
    auto end = chrono::high_resolution_clock::now();
    cout << "El tiempo de ejecucion es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
    return;
}
void correr_recu(){
    cout << "string[1] o char[2]" << endl;
    int opcion;
    cin >> opcion;
    while (opcion != 1 && opcion != 2){
        cout << "Ingrese un valor valido: ";
        cin >> opcion;
    }
    if (opcion == 1){
        cout << "Ingrese la primera palabra: "<< endl;
        string Palabra1;
        cin >> Palabra1;
        cout << "Ingrese la segunda palabra: "<< endl;
        string Palabra2;
        cin >> Palabra2;
        if (comp_recu(Palabra1, Palabra2)){
            cout << "Las palabras son iguales" << endl;
        }
        else{
            cout << "Las palabras no son iguales" << endl;
        }
        tiempo_ejecucion_string(Palabra1, Palabra2);
        return;
    }
    cout << "Ingrese la primera palabra: "<< endl;
    char* Palabra1= new char[100];
    cin >> Palabra1;
    cout << "Ingrese la segunda palabra: "<< endl;
    char* Palabra2 = new char[100]; 
    cin >> Palabra2;
    if (comp_recu_char(Palabra1, Palabra2)){
        cout << "Las palabras son iguales" << endl;
    }
    else{
        cout << "Las palabras no son iguales" << endl;
    }
    tiempo_ejecucion_char(Palabra1, Palabra2);
    delete[] Palabra1;
    delete[] Palabra2;
    return;
}