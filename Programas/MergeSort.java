import java.util.Random;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * FILE NAME: MergeSort.java                           
 *                                                     
 * PURPOSE:Programa que se encarga de ordenar una      
 *         lista de numeros con el algoritmo de        
 *         MergeSort                                   
 *                                                     
 *@author Norma Veronica Trinidad Hernandez            
 *       <nvth28@gmail.com>                            
 *                                                     
 *@author Jose de Jesus Vargas Muñoz                   
 *        <j.vargas.munoz@gmail.com >                  
 *                                                     
 *                                                     
 *@author Vilchis Dominguez Miguel Alonso              
 *       <mvilchis@ciencias.unam.mx>                   
 *                                                     
 *                                                     
 * NOTES: recibe como argumento la longitud de         
 *       la primer lista aleatoria que ordenara        
 *       el segundo argumento es la longitud de la     
 *       ultima lista aleatoria que ordenara,se iterara
 *       desde la primera hasta la ultima longitud     
 *       y los tiempos de ejecucion se almacenaran en  
 *       el archivo mergeJava.txt                     
 *                                                     
 * Copyright (C) 21-08-2015                            
 * Distributed under terms of the MIT license.      
 */ 

public class MergeSort{
    /**  Constructor por default */
    public MergeSort() {}
    /**
     * FUNCTION NAME: merge                                
     * PURPOSE: funcion que implementa   la fase de mezcla 
     *         en el algoritmo de mergeSort                
     * @param numbers <int*> lista a ordenar
     * @param low <int> indice del inicio de la paraticion
     * @param middle <int> indice del la mitad de la particion
     * @param high <int> indice del final de la particion
     */
    public void merge(int numbers[], int low, int middle, int high){ 
        int leftTam = middle-low+1;
        int rightTam = high - middle;
        int left[] = new int [leftTam];
        int right[] = new int [rightTam];
        int i, j, idx;
        for (i = 0; i < leftTam; i++) {
            left[i] = numbers[low+ i];
        }
        for (i = 0; i < rightTam; i++) {
            right[i] = numbers[middle+ i+1];
        }
        i = 0;
        j = 0;
        idx = low;
        while (i < leftTam && j < rightTam) {
            if(left [i] <= right [j]) {
                numbers [idx] = left[ i];
                i++;
            } else {
                numbers[idx] = right[j];
                j++;

            }
            idx++; 
        }
        while (i < leftTam){
            numbers[idx] = left[i];
            i++;
            idx++;
        }
        while (j < rightTam) {
            numbers [idx] = right [j];
            j++;
            idx++;
        }
    }
    /**
     *Metodo que implementa la fase de particion           
     * en el algoritmo de mergeSort             
     * @param numbers <int*> lista a ordenar
     * @param high <int> indice del final de la particion
     * @param low <int> indice del inicio de la paraticion
     */ 
    public void partition(int numbers[], int low, int high) {
        int middle;
        if(low < high) {
            middle = (low+high)/2;
            partition(numbers, low, middle);
            partition(numbers,middle+1,high);
            merge(numbers, low, middle, high);
        }
    }

    /**
     * Metodo que crea una lista de numeros aleatorios      
     *@param length <int>, longitud de la lista  num 
     *@param rnd <Random> generador de numeros random
     * @return  <int[]> numeros a ordenar de longitud length 
     */ 
    public int[] createRandom(int length, Random rnd) {
        int numbers[] = new int [length];
        int idx = 0;
        for(idx = 0; idx < length; idx++) {
            numbers [idx] = rnd.nextInt();
        }
        return numbers;

    }


    public static void  main(String [] args) {
        //Declaracion de variables 
        int arg1=0, arg2=0; //Parseo de argumento
        int i, idx; //Indices auxiliares
        int argc = args.length;
        double time_spent, begin;
        int numbers[]; 
        Random rnd = new Random();
        MergeSort algorithm = new MergeSort();


        //Verificación de argumentos
        if (argc != 2 ) {
            System.out.print("*********************<USO>*******************\n");
            System.out.print("Forma de uso java MergeSort #tamInicial #tamFinal\n" );
            System.out.print("Donde tamInicial es la longitud de la muestra inicial\n");
            System.out.print("y tamFinal es la longitud de la muestra final\n");
            System.out.print("*********************<USO>*******************\n");
            System.exit(1);
        }

        try{
            arg1 = Integer.parseInt(args[0]);
            arg2 = Integer.parseInt(args[1]);

        } catch (NumberFormatException e) {
            System.out.print("*********************<ERROR>*******************\n");
            System.out.print("Error al leer los parametros, recuerda que son numeros\n");
            System.out.print("*********************<ERROR>*******************\n");
            System.exit(1);

        } 
        try {
            File file = new File("mergeJava.txt");

            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);

            for(int counter = arg1; counter < arg2; counter++) { 
                numbers = algorithm.createRandom(counter,rnd);
                begin = System.nanoTime(); 
                algorithm.partition(numbers, 0, counter-1);
                time_spent = (System.nanoTime() - begin)/1000000; //Milisegundos 
                for(i = 0; i < counter-1; i++)
                    assert(numbers[i+1]) >= (numbers[ i]); 
                bw.write(counter + " "+ time_spent+"\n");
            } 
            bw.close(); 
        } catch (IOException e) {
            e.printStackTrace();
        } 
    }
}





