/*******************************************************
 * FILE NAME: InsertionSort.c                          *
 *                                                     *
 * PURPOSE:Programa que se encarga de ordenar una      *
 *         lista de numeros con el algoritmo de        *
 *         InsertionSort                               *
 *                                                     *
 *@author Norma Veronica Trinidad Hernandez            *
 *       <nvth28@gmail.com>                            *
 *                                                     *
 *@author Jose de Jesus Vargas Muñoz                   *
 *        <j.vargas.munoz@gmail.com >                  *
 *                                                     *
 *                                                     *
 *@author Vilchis Dominguez Miguel Alonso              *
 *       <mvilchis@ciencias.unam.mx>                   *
 *                                                     *
 *                                                     *
 * NOTES: recibe como argumento la longitud de         * 
 *       la primer lista aleatoria que ordenara        *
 *       el segundo argumento es la longitud de la     * 
 *       ultima lista aleatoria que ordenara,se iterara*  
 *       desde la primera hasta la ultima longitud     *    
 *       y los tiempos de ejecucion se almacenaran en  * 
 *       el archivo insertionC.txt                     *
 *                                                     *
 * Copyright (C) 21-08-2015                            * 
 * Distributed under terms of the MIT license.         *
 *******************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>


/*******************************************************
 * FUNCTION NAME: insertionSort                        *
 * PURPOSE: insertion sort, funcion que implementa     *
 *          el algoritmo de insercion                  *
 * ARGUMENTS: length <int>, longitud de la lista a     *
 *                          ordenar                    *
 *            numbers <int*> lista a ordenar           *
 * RETURN: void                                        *
 *******************************************************/
void insertionSort(int length, int *numbers) {
    int idx = 1, i;
    int key;
    for(idx = 1; idx < length; idx++) {
        key = *(numbers+idx);
        i = idx-1;
        while (i >= 0 && *(numbers+i) >= key) {
            *(numbers+i+1) = *(numbers+i);
            i--;
        }
        *(numbers +i+1) = key;
    }
}


/*******************************************************
 * FUNCTION NAME:createRandom                          *
 * PURPOSE: Crear una lista de numeros aleatorios      *
 * ARGUMENTS: length <int>, longitud de la lista  num  * 
 * RETURN: <int*> numeros a ordenar de longitud length *
 *******************************************************/ 
int* createRandom(int length) {
    srand(time(NULL));
    int *numbers = (int*) malloc(sizeof(int)*length);
    int idx = 0;
    for(idx = 0; idx < length; idx++) {
        *(numbers + idx) = rand();
        *(numbers + idx) = idx;

    }
    return numbers; 
}


int main(int argc, char **argv) {
    //Declaracion de variables 
    int ret1, ret2; //Control de parseo
    int arg1, arg2, arg3; //Parseo de argumento
    FILE *file; //Archivo para guardar tiempo de ejecucion
    double time_spent; //Variable que guarda el tiempo neto de ejecucion
    int *numbers; //Lista temporal de secuencia de numeros
    int i, counter; //Indices auxiliares 

    //Verificación de argumentos
    if (argc != 3 ) {
        printf("*********************<USO>*******************\n");
        printf("Forma de uso, %s #tamInicial #tamFinal \n",argv[0]);
        printf("Donde tamInicial es la longitud de la muestra inicial\n");
        printf("y tamFinal es la longitud de la muestra final\n");
        printf("*********************<USO>*******************\n");
        exit(1);
    }

    ret1 = sscanf(argv[1], "%d", &arg1);
    ret2 = sscanf(argv[2], "%d", &arg2);
    if (ret1  != 1 || ret2 != 1 ) {
        printf("*********************<ERROR>*******************\n");
        printf("Error al leer los parametros, recuerda que son numeros\n");
        printf("*********************<ERROR>*******************\n");

    }
    file = fopen("insertionC.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    for(counter = arg1; counter < arg2; counter = counter + 500000) {
        clock_t begin, end; //Inicio y final del tiempo de ejecucion
        numbers = createRandom(counter);
        begin = clock();
        insertionSort(counter, numbers);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
        for(i = 0; i < counter-1; i++)
            assert(*(numbers+i+1) >= *(numbers+ i)); 
        fprintf(file, "%d %lf\n", counter,time_spent);
    }
    fclose(file);
} 
