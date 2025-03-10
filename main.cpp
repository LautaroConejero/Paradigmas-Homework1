#include <iostream>
#include <vector>
#include <string>
#include "Ej_1/matrices.hpp"
using namespace std;

int main(){
    cout << "Ingrese el tamaño de la matriz: ";
    int Numero;
    cin >> Numero;
    vector<vector<int>> Matriz = CrearMatriz(Numero);
    ImprimirMatriz(Matriz, Numero);


    return 0;

}