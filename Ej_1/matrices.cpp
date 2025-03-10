#include <iostream>
#include <vector>
#include "matrices.hpp"
using namespace std;

vector <vector<int>> CrearMatriz(int Numero) {
    vector<vector<int>> Matriz(Numero, vector<int>(Numero));
    int value = 1;
    for (int i = 0; i < Numero; i++) {
        for (int j = 0; j < Numero; j++) {
            Matriz[i][j] = value;
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