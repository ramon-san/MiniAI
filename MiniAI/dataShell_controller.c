//
//  dataShell_controller.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "dataShell_controller.h"

/*
 *
 * The function openFile opens the file the user entered and returns it's FILE*.
 *
 * @params
 *      fileName (string):
            This is the name of the file we're going to use.

 * @returns
        fp (FILE*)
            This is the file pointer of the file we just opened.
*/
FILE *dataShell_controller_openFile(char *fileName){
   FILE *fp;

   fp = fopen(fileName, "r");
   if(fp == NULL){
      printf("\n\tArchivo no disponible.");
      exit(1);
   }

return(fp);
}

/*
 *
 * The function verifyX verifies that the file's format is consistant in it's number of columns.
 *
 * @params
 *      i (int):
            This is the iteration we're in right now.
        xTemp (int):
            This is the number of columns in the current iteration
        xCurrent (int):
            When i=0 it takes the value of xTemp from that iteration an compares that number on the following iterations, it's the variable browser.x.

 * @returns
        fpConvert (FILE*)
            This is the file pointer of the new file we created.
*/
int dataShell_controller_verifyX(int i, int xTemp, int xCurrent){

   if(i==0) xCurrent = xTemp;
   if(xCurrent != xTemp){
      printf("\n\n\tInconsistent file, columns are not consistent.\n");
      exit(1);
   }

return(xCurrent);
}

/*
 *
 * The function passBrowser links our view with our motor.
 *
 * @params
 *      fp (*FILE):
            This is the location of the file we're using.

 * @returns
        browser (floatMatrix):
            This is the browser the info of our matrix.
*/
floatMatrix dataShell_controller_passBrowser(FILE *fp){
    floatMatrix browser;
    
    browser = dataShell_motor_readCSV(fp);
    
    return(browser);
}

/*
 *
 * The function storeInfo saves targets and data in separate arrays.
 *
 * @params
 *      browser (**floatMatrix):
            This is the browser the info of our matrix.
        my_perceptron (**perceptron):
            This is the browser with our perceptron's information.

 * @returns
        browser (floatMatrix):
            This is the browser with our array's information.
*/
void dataShell_controller_storeInfo(floatMatrix **browser, perceptron **my_perceptron){
    size_t i, j;
    int features = (*browser)->x;
    int params = (*browser)->y;
    
    for(i = 1; i<(params+1); i++){
        (*my_perceptron)->targets[i-1] = (*browser)->matrix[i*((*browser)->x)-1];
        for(j = 0; j<(features-1); j++){
            if(j == 0);
            else{
                if(i == 1) (*my_perceptron)->data[(j-1)] = (*browser)->matrix[j];
                else{
                    if(j == 1) (*my_perceptron)->data[(i-1)*(features-2)] = (*browser)->matrix[j+(i-1)*features];
                    else (*my_perceptron)->data[(features-2)*(i-1)+j-1] = (*browser)->matrix[j+(i-1)*features];
                }
            }
        }
    }
}
