//
//  general.c
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "general.h"

/*
 *
 * The function RMS does the root mean square of the values of the array that we entered. This function was also done by Cesarín.
 *
 * @params
 *      predict (*float):
            This array contains the results we predicted.
        target (*target):
            This array contains the results we needed.
        n_values (size_t):
            This is the value of batch_size, it gives the number of iterations.

 * @returns
        sqrt(result) (float):
            This variable is the square root of all the result sumation.
*/
float general_RMS(float *predict, float *target, size_t n_values){
    float result = 0;
    size_t i;
    
    for(i=0; i<n_values; i++){
        result += powf((predict[i]-target[i]), 2);
    }
    
    return sqrt(result);
}

/*
 *
 * The function printToFile writes info in a file as coordinates "x" and "y" for graphing.
 *
 * @params
 *      values_y (*float):
            This file contains the values of "y"..
        n_entries (size_t):
            This variable contains the total number of entries for the file.

 * @returns
        void
*/
void general_saveToPlot(float* values_y, size_t n_entries, char *file){
    size_t x=0;
    FILE *fp;
    
    fp = fopen(file, "w");
    if(fp == NULL){
       printf("\n\tArchivo no disponible.");
       exit(1);
    }
    for(x=0; x<n_entries; x++){
        fprintf(fp, "%zu\t%f\n", x, values_y[x]);
    }
    fclose(fp);
}
