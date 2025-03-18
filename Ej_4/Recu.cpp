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
constexpr bool comp_recu_mod(const char* variable1,const char* variable2){
    if (*variable1 == '\0' && *variable2 == '\0'){
        return true;
    }
    if (*variable1 != *variable2){
        return false;
    }
    return comp_recu_mod(variable1+1, variable2+1);
}

void correr_recu(){
//     cout << "Que prefieres hacer?" << endl;
//     cout << "1. comparar palabras ingresadas" << endl;
//     cout << "2. comparar tiempos entre funcion de ejecucion y funcion de compilacion" << endl;
//     int Decision;
//     cin >> Decision;
//     while (Decision != 1 && Decision != 2){
//         cout << "Ingrese una opcion valida" << endl;
//         cin >> Decision;
//     }
//     switch (Decision){
//         case 1:{
//         cout << "Ingrese la primera palabra: "<< endl;
//         char* Palabra1= new char[100];
//         cin >> Palabra1;
//         cout << "Ingrese la segunda palabra: "<< endl;
//         char* Palabra2 = new char[100]; 
//         cin >> Palabra2;
        
//         auto start = chrono::high_resolution_clock::now();
//         bool Resultado = comp_recu_char(Palabra1, Palabra2);
//         auto end = chrono::high_resolution_clock::now();
//         if (Resultado){
//             cout << "Las palabras son iguales" << endl;
//         }
//         else{
//             cout << "Las palabras no son iguales" << endl;
//         }
//         cout << "El tiempo de ejecucion [OG] es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
//         delete[] Palabra1;
//         delete[] Palabra2;
//         return;
//         }
//         case 2:{
//             auto start = chrono::high_resolution_clock::now();
//             auto end = chrono::high_resolution_clock::now();
//             auto ElapsedTime = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
//             cout << "El tiempo de compilacion [G] es: " << ElapsedTime << " nanosegundos" << endl;
//             constexpr const char* Text1 = "La tecnología ha avanzado de manera sorprendente en las últimas décadas,";
//             constexpr const char* Text2 = "La tecnología ha avanzado de manera sorprendente en las últimas décadas,";
//             auto startm = chrono::high_resolution_clock::now();
//             constexpr bool Resultado_m = comp_recu_mod(Text1, Text2);
//             auto endm = chrono::high_resolution_clock::now();
//             auto ElapsedTime_m = chrono::duration_cast<chrono::nanoseconds>(endm-startm).count();
//             if (Resultado_m){
//                 cout << "Las palabras son iguales" << endl;
//             }
//             else{
//                 cout << "Las palabras no son iguales" << endl;
//             }
            
//             cout << "El tiempo de ejecucion [Mod] es: " << ElapsedTime_m << " nanosegundos" << endl;
//             char Palabra1[] = "La tecnología ha avanzado de manera sorprendente en las últimas décadas,";
//             auto start_OG = chrono::high_resolution_clock::now();
//             bool Resultado_OG = comp_recu_char(Palabra1, Palabra1);
//             auto end_OG = chrono::high_resolution_clock::now();
//             auto ElapsedTime_OG = chrono::duration_cast<chrono::nanoseconds>(end_OG-start_OG).count();
//             cout << "El tiempo de ejecucion [OG] es: " << ElapsedTime_OG << " nanosegundos" << endl;
//             return;

//         }
//     }
// }
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

    auto ElapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Tiempo de ejecución vacío: " << ElapsedTime << " nanosegundos" << endl;

    return;
}