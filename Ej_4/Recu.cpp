#include "Recu.hpp"
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
        auto start = chrono::high_resolution_clock::now();
        bool Resultado = comp_recu_char(Palabra1, Palabra2);
        auto end = chrono::high_resolution_clock::now();
        if (Resultado){
            cout << "Las palabras son iguales" << endl;
        }
        else{
            cout << "Las palabras no son iguales" << endl;
        }
        cout << "El tiempo de ejecucion [OG] es: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " nanosegundos" << endl;
        delete[] Palabra1;
        delete[] Palabra2;
        return;
        }
        case 2:{
            int suma_demas = 0;
            int N = 100000;
            for (int i = 0; i < N; i++){
                auto start = chrono::high_resolution_clock::now();
                auto end = chrono::high_resolution_clock::now();
                auto ElapsedTime = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
                if (i < 10){
                    cout << ElapsedTime << endl;
                }
                if (i != 0){
                    suma_demas += ElapsedTime;
                }
            }
            suma_demas /= N;
            cout << "El tiempo de mas [G] es: " << suma_demas << " nanosegundos" << endl;
            
            constexpr const char* Text1 = "La tecnología ha avanzado de manera sorprendente en las últimas décadas,";
            constexpr const char* Text2 = "La tecnología ha avanzado de manera sorprendente en las últimas décadas,";
            int suma_comp = 0;
            for (int i = 0; i < N; i++){
                auto start = chrono::high_resolution_clock::now();
                constexpr bool Resultado_m = comp_recu_mod(Text1, Text2);
                auto end = chrono::high_resolution_clock::now();
                auto ElapsedTime = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
                if (i < 10){
                    cout << ElapsedTime << endl;
                }
                if (i != 0){
                    suma_comp += ElapsedTime;
                }
            }
            suma_comp /= N;
            cout << suma_comp << endl;
            cout << "El tiempo de compilacion con el 'tiempo de mas' [Mod] es: " << suma_comp << " nanosegundos" << endl;
            suma_comp -= suma_demas;
            cout << "El tiempo de compilacion sin el 'tiempo de mas' [Mod] es: " << suma_comp << " nanosegundos" << endl;


            char Palabra1[] = "La tecnología ha avanzado de manera sorprendente en las últimas décadas,";
            int suma_ejec = 0;
            for(int i = 0; i < N; i++){
                auto start = chrono::high_resolution_clock::now();
                bool Resultado_OG = comp_recu_char(Palabra1, Palabra1);
                auto end = chrono::high_resolution_clock::now();
                auto ElapsedTime = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
                if (i < 10){
                    cout << ElapsedTime << endl;
                }
                if (i != 0){
                suma_ejec += ElapsedTime;
                }
            }
            suma_ejec /= N;
            cout << "El tiempo de ejecucion con el 'tiempo de mas' [OG] es: " << suma_ejec << " nanosegundos" << endl;
            suma_ejec -= suma_demas;
            cout << "El tiempo de ejecucion sin el 'tiempo de mas' [OG] es: " << suma_ejec << " nanosegundos" << endl;
            bool Resultado_OG = comp_recu_char(Palabra1, Palabra1);
            if (Resultado_OG){
                cout << "Las palabras son iguales" << endl;
            }
            else{
                cout << "Las palabras no son iguales" << endl;
            }
            return;
        }
    }
}