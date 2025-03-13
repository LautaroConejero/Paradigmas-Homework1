#include <iostream>
#include <vector>
#include "matrices.h"
using namespace std;

vector <vector<int>> CrearMatriz(int Numero) {
    vector <vector<int>> Matriz;
    int value = 1;
    for (int i = 0; i < Numero; i++) {
        vector<int> columna;
        Matriz.push_back(columna);
        for (int j = 0; j < Numero; j++) {
            Matriz[i].push_back(value);
            value++;
        }
    }
    return Matriz;
}

void ImprimirMatriz(vector<vector<int>> matriz, int Numero) {

    for (int i = Numero*Numero - 1; i >= 0; i--){
        cout <<"Matriz[" << i/Numero <<"][" << i%Numero << "] = " << matriz[i/Numero][i%Numero] << "\n";
    }
}

void correr_matriz(){
    cout << "Ingrese el tamaño de la matriz: ";
    int Numero;
    cin >> Numero;
    vector<vector<int>> Matriz = CrearMatriz(Numero);
    ImprimirMatriz(Matriz, Numero);
    return;
}