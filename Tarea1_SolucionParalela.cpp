// Tarea1_SolucionParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

int main() {
     //Estableciendo el tamaño de los arreglos
    const int size = 1000;
    int array1[size], array2[size], result[size];

    // Inicializar los arreglos
    for (int i = 0; i < size; ++i) {
        array1[i] = rand() % 11;
        array2[i] = rand() % 11;
    }
    int num_threads;

    // Paralelizar la suma utilizando OpenMP
#pragma omp parallel
    {
        num_threads = omp_get_num_threads();
#pragma omp for
        for (int i = 0; i < size; ++i) {
            result[i] = array1[i] + array2[i];
        }
    }
    
    // Imprimir el número de hilos utilizados
    std::cout << "Numero de hilos utilizados: " << num_threads << std::endl;

    // Imprimir las primeras 20 entradas de los arreglos y la salida
    std::cout << "Primeras 20 entradas de array1: ";
    for (int i = 0; i < 20; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Primeras 20 entradas de array2: ";
    for (int i = 0; i < 20; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Primeras 20 entradas de la salida: ";
    for (int i = 0; i < 20; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}