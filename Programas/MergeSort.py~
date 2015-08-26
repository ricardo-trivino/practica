#! /usr/bin/env python
#-*- coding: utf-8 -*-

 #######################################################
 # FILE NAME: MergeSort.py                             #
 #                                                     #
 # PURPOSE:Programa que se encarga de ordenar una      #
 #         lista de numeros con el algoritmo de        #
 #         MergeSort                                   #
 #                                                     #
 #@author Norma Veronica Trinidad Hernandez            #
 #       <nvth28@gmail.com>                            #
 #                                                     #
 #@author Jose de Jesus Vargas Muñoz                   #
 #        <j.vargas.munoz@gmail.com >                  #
 #                                                     #
 #                                                     #
 #@author Vilchis Dominguez Miguel Alonso              #
 #       <mvilchis@ciencias.unam.mx>                   #
 #                                                     #
 #                                                     #
 # NOTAS: recibe como argumento la longitud de         # 
 #       la primer lista aleatoria que ordenara        #
 #       el segundo argumento es la longitud de la     # 
 #       ultima lista aleatoria que ordenara,se iterara#  
 #       desde la primera hasta la ultima longitud     #    
 #       y los tiempos de ejecucion se almacenaran en  # 
 #       el archivo mergePython.txt                    # 
 #                                                     #
 #                                                     #
 # Copyright (C) 21-08-2015                            # 
 # Distributed under terms of the MIT license.         #
 #######################################################
import sys
import random
import time
"""*****************************************************
 * FUNCTION NAME: merge                                *
 * PURPOSE: funcion que implementa   la fase de mezcla *
 *         en el algoritmo de mergeSort                *
 * ARGUMENTS: numbers lista a ordenar                  *
 *            low indice del comienzo de la particion  *
 *            middle indice de la mitad de la particion*
 *            high indice del final de la particion    *
 * RETURN: void                                        *
 ****************************************************"""
def merge(numbers, low, middle, high):
     left = [x for x in numbers[low:middle+1]]
     right =[x for x in numbers[middle+1:high+1]]
     idx = low
     i = 0
     j = 0
     while (i < len(left)) and (j < len(right)):
         if (left[i] <= right[j]):
             numbers[idx] = left[i]
             i = i+1
         else:
             numbers[idx] = right[j]
             j = j+1
         idx = idx+1

     while (i < len(left)):
         numbers[idx] = left[i]
         i = i+1
         idx = idx+1
     while (j < len(right)):
         numbers[idx] = right[j]
         j = j+1
         idx = idx +1
"""*****************************************************
 * FUNCTION NAME: partition                            *
 * PURPOSE: funcion que implementa la fase de particion*
 *         en el algoritmo de mergeSort                *
 * ARGUMENTS: numbers lista a ordenar                  *
 *            low indice del comienzo de la particion  *
 *            high indice del final de la particion    *
 * RETURN: void                                        *
 ****************************************************"""
def partition(numbers, low, high):
    if(low < high):
        middle = (low+high)/2
        partition(numbers, low, middle)
        partition(numbers,middle+1,high)
        merge(numbers, low, middle, high)
"""*****************************************************
 * FUNCTION NAME:createRandom                          *
 * PURPOSE: Crear una lista de numeros aleatorios      *
 * ARGUMENTS: length longitud de la lista              * 
 * RETURN: lista numeros a ordenar de longitud length  *
 ****************************************************""" 
def createRandom(length):
    numbers =[random.randint(-500000, 500000) for i in range(length)]
    return numbers


def main():
    #Verificación de argumentos
    if (len(sys.argv) != 3 ):
        print("*********************<USO>*******************\n")
        print("Forma de uso, %s #tamInicial #tamFinal\n"%sys.argv[0])
        print("Donde tamInicial es la longitud de la muestra inicial\n")
        prinf("y tamFinal es la longitud de la muestra final")
        print("*********************<USO>*******************\n")
        exit(1)
    arg1 = int(sys.argv[1])
    arg2 = int(sys.argv[2])
    f = open('mergePython.txt', 'w')
    for counter  in range(arg1, arg2):
        numbers = createRandom(counter)
        begin = time.time()
        partition(numbers, 0, counter)
        time_spent = (time.time() - begin)*1000  
        for idx in  range(counter-1):
            assert numbers[idx+1] >= numbers[idx]
        f.write(str(counter) + " "+ str(time_spent)+ "\n") 
    f.close()
if __name__ == "__main__":
    main()




