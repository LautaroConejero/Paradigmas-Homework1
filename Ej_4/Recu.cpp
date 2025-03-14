#include <iostream>
#include <string>
#include "Recu.hpp"
#include <chrono>
using namespace std;
// Revisar este 
bool comp_recu_char(char* variable1, char* variable2){
    if (*variable1 == '\0' && *variable2 == '\0'){
        return true;
    }
    if (*variable1 != *variable2){
        return false;
    } 
    return comp_recu_char(variable1+1, variable2+1);
}
void tiempo_ejecucion_char(char* variable1, char* variable2){
    auto start = chrono::high_resolution_clock::now();
    bool Resultado = comp_recu_char(variable1, variable2);
    auto end = chrono::high_resolution_clock::now();
    if (Resultado){
        cout << "Las palabras son iguales" << endl;
    }
    else{
        cout << "Las palabras no son iguales" << endl;
    }
    cout << "El tiempo de ejecucion [OG] es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
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
    cout << "El tiempo de ejecucion [Mod] es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
    return;
}
void correr_recu(){
    cout << "Que prefieres hacer?" << endl;
    cout << "1. comparar palabras ingresadas" << endl;
    cout << "2. comparar tiempos entre funcion de ejecucion y funcion de compilacion" << endl;
    int Decision;
    cin >> Decision;
    while (Decision != 1 && Decision != 2){
        cout << "Ingrese una opcion valida" << endl;
        cin >> Decision;
    }
    switch (Decision){
        case 1:{
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
        case 2:{
            bool Resultado = comp_recu_mod("La tecnología ha avanzado de manera sorprendente en las últimas décadas, permitiendo grandes innovaciones en diversas áreas como la medicina, la comunicación y el entretenimiento. Gracias a estos avances, la humanidad ha logrado mejorar su calidad de vida y expandir sus conocimientos. En el ámbito de la medicina, por ejemplo, el desarrollo de nuevas herramientas y tratamientos ha permitido curar enfermedades que antes eran consideradas incurables. La inteligencia artificial también ha comenzado a desempeñar un papel clave en el diagnóstico temprano de diversas condiciones, aumentando la esperanza de vida de muchas personas.", "La tecnología ha avanzado de manera sorprendente en las últimas décadas, permitiendo grandes innovaciones en diversas áreas como la medicina, la comunicación y el entretenimiento. Gracias a estos avances, la humanidad ha logrado mejorar su calidad de vida y expandir sus conocimientos. En el ámbito de la medicina, por ejemplo, el desarrollo de nuevas herramientas y tratamientos ha permitido curar enfermedades que antes eran consideradas incurables. La inteligencia artificial también ha comenzado a desempeñar un papel clave en el diagnóstico temprano de diversas condiciones, aumentando la esperanza de vida de muchas personas.");
            tiempo_ejecucion_mod(Resultado);
            char Palabra1[] = "La tecnología ha avanzado de manera sorprendente en las últimas décadas, permitiendo grandes innovaciones en diversas áreas como la medicina, la comunicación y el entretenimiento. Gracias a estos avances, la humanidad ha logrado mejorar su calidad de vida y expandir sus conocimientos. En el ámbito de la medicina, por ejemplo, el desarrollo de nuevas herramientas y tratamientos ha permitido curar enfermedades que antes eran consideradas incurables. La inteligencia artificial también ha comenzado a desempeñar un papel clave en el diagnóstico temprano de diversas condiciones, aumentando la esperanza de vida de muchas personas.";
            tiempo_ejecucion_char(Palabra1, Palabra1);

        }
    }
}