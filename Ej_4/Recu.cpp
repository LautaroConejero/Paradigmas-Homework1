#include <iostream>
#include <string>
#include "Recu.hpp"
#include <chrono>
using namespace std;

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
void tiempo_ejecucion_char(char* variable1, char* variable2){
    auto start = chrono::high_resolution_clock::now();
    comp_recu_char(variable1, variable2);
    auto end = chrono::high_resolution_clock::now();
    cout << "El tiempo de ejecucion es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
    return;
}
constexpr bool comp_recu_mod(const char* variable1,const char* variable2){
    if (*variable1 == '\0' && *variable2 == '\0'){
        return true;
    }
    if (*variable1 != *variable2){
        return false;
    }
    return comp_recu_mod(variable1+1, variable2+1);
}
void tiempo_ejecucion_mod(const bool Resultado){
    auto start = chrono::high_resolution_clock::now();
    if (Resultado){
        cout << "Las palabras son iguales" << endl;
    }
    else{
        cout << "Las palabras no son iguales" << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "El tiempo de ejecucion es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
    return;
}
void correr_recu(){
    const bool Res= comp_recu_mod("Palabra", "Palabra");
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
    cout << "\nAhora Usando la version constexpr" << endl;
    tiempo_ejecucion_mod(Res);
    delete[] Palabra1;
    delete[] Palabra2;
    return;
}