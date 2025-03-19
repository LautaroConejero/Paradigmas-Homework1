#include "matrices.h"

// Función para crear una matriz de tamaño Numero x Numero
vector<vector<int>> CrearMatriz(int Numero) {
    vector<vector<int>> Matriz; // Declaración de la matriz como un vector de vectores de enteros
    int value = 1; // Inicialización del valor a insertar en la matriz
    for (int i = 0; i < Numero; i++) { 
        vector<int> columna; // Declaración de una columna como un vector de enteros
        Matriz.push_back(columna); // Añadir la columna a la matriz
        for (int j = 0; j < Numero; j++) {
            Matriz[i].push_back(value); // Añadir el valor a la columna actual
            value++; 
        }
    }
    return Matriz; 
}

// Función para imprimir la matriz en orden inverso
void ImprimirMatriz(vector<vector<int>> matriz, int Numero) {
    for (int i = Numero * Numero - 1; i >= 0; i--) { // Bucle para recorrer la matriz en orden inverso
        cout << "Matriz[" << i / Numero << "][" << i % Numero << "] = " << matriz[i / Numero][i % Numero] << "\n"; 
    }
}

// Función principal para correr el programa de matrices
void correr_matriz() {
    cout << "Ingrese el tamaño de la matriz: "; 
    int Numero;
    cin >> Numero; // Leer el tamaño de la matriz
    while (Numero <= 0 or Numero != int(Numero)) { 
        cout << "Ingrese un valor valido" << endl; // Solicitar un valor válido si la validación falla
        cout << "Valor: ";
        cin >> Numero; // Leer el tamaño de la matriz
    }
    vector<vector<int>> Matriz = CrearMatriz(Numero);
    ImprimirMatriz(Matriz, Numero); 
    return;
}