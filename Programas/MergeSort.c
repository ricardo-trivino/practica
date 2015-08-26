/*******************************************************
 * FILE NAME: MergeSort.c                              *
 *                                                     *
 * PURPOSE:Programa que se encarga de ordenar una      *
 *         lista de numeros con el algoritmo de        *
 *         MergeSort                                   *
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
 *       el archivo mergeC.txt                         *
 *                                                     *
 * Copyright (C) 21-08-2015                            * 
 * Distributed under terms of the MIT license.         *
 *******************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>


/*******************************************************
 * FUNCTION NAME: merge                                *
 * PURPOSE: funcion que implementa   la fase de mezcla *
 *         en el algoritmo de mergeSort                *
 * ARGUMENTS: length <int>, longitud de la lista a     *
 *                          ordenar                    *
 *            numbers <int*> lista a ordenar           *
 * RETURN: void                                        *
 *******************************************************/
void merge(int *numbers, int low, int middle, int high) {

    int leftTam = middle-low+1;
    int rightTam = high - middle;
    int *left = (int *) malloc(sizeof(int)*leftTam);
    int *right = (int *) malloc(sizeof(int)*rightTam);
    int i, j, idx;
    for (i = 0; i < leftTam; i++) {
        *(left+i) = *(numbers+low+ i);
    }
    for (i = 0; i < rightTam; i++) {
        *(right+i) = *(numbers+middle+ i+1);
    }
    i = 0;
    j = 0;
    idx = low;
    while (i < leftTam && j < rightTam) {
        if(*(left + i) <= *(right + j)) {
            *(numbers + idx) = *(left+ i);
            i++;
        } else {
            *(numbers + idx) = *(right + j);
            j++; 
        }
        idx++; 
    }
    while (i < leftTam){
        *(numbers + idx) = *(left + i);
        i++;
        idx++;
    }
    while (j < rightTam) {
        *(numbers + idx) = *(right + j);
        j++;
        idx++;
    }
}
/*******************************************************
 * FUNCTION NAME: partition                            *
 * PURPOSE: funcion que implementa la fase de particion*
 *         en el algoritmo de mergeSort                *
 * ARGUMENTS: numbers<int*>, lista a ordenar           *
 *            low<int> inicio de la particion          *
 *            high<int> fin de la particion            *
 * RETURN: void                                        *
 *******************************************************/
void partition(int *numbers, int low, int high) {
    int middle;
    if(low < high) {
        middle = (low+high)/2;
        partition(numbers, low, middle);
        partition(numbers,middle+1,high);
        merge(numbers, low, middle, high);
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
    }
    return numbers;

}


int main(int argc, char **argv) {
    //Declaracion de variables 
    int ret1, ret2; //Control de parseo
    int arg1, arg2; //Parseo de argumento
    FILE *file; //Archivo para guardar tiempo de ejecucion
    double time_spent; //Variable que guarda el tiempo neto de ejecucion
    int *numbers; //Lista temporal de secuencia de numeros
    int i,counter; //Indices auxiliares



    //Verificación de argumentos
    if (argc != 3 ) {
        printf("*********************<USO>*******************\n");
        printf("Forma de uso, %s #tamInicial #tamFinal\n",argv[0]);
        printf("Donde tamInicial es la longitud de la muestra inicial\n");
        printf("y tamFinal es la longitud de la muestra final\n");
        printf("*********************<USO>*******************\n");
        exit(1);
    }

    ret1 = sscanf(argv[1], "%d", &arg1);
    ret2 = sscanf(argv[2], "%d", &arg2);
    if (ret1  != 1 || ret2 != 1) {
        printf("*********************<ERROR>*******************\n");
        printf("Error al leer los parametros, recuerda que son numeros\n");
        printf("*********************<ERROR>*******************\n");

    }
    file = fopen("mergeC.txt" , "w");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    for(counter = arg1; counter < arg2; counter++) {
        clock_t begin, end; //Inicio y final del tiempo de ejecucion
        numbers = createRandom(counter);
        begin = clock();
        partition(numbers, 0, counter-1);
        end = clock();
        time_spent = (double)(end - begin) / (CLOCKS_PER_SEC /1000); 
        for(i = 0; i < counter-1; i++)
            assert(*(numbers+i+1) >= *(numbers+ i)); 
        fprintf(file, "%d %lf\n", counter, time_spent);
    }
    fclose(file);
}





