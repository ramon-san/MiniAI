//
//  dataShell_motor.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataShell_motor.h"

/*
 *
 * The function readCSV reads the .csv file the user entered and converts it to a .txt, it returns the FILE* of the created file.
 *
 * @params
 *      fp (FILE*):
            This is the file pointer of the file we're reading.

 * @returns
        fpConvert (FILE*)
            This is the file pointer of the new file we created.
*/
floatMatrix dataShell_motor_readCSV(FILE *fp){
    floatMatrix browser;
    char line[200], *temp;
    int xTemp;

    browser.matrix = malloc(sizeof(float)*BUFSIZ);
    browser.used = 0;
    browser.y = 0;
    while(fgets(line, 200, fp) != NULL){
        if(browser.used >= sizeof(float)*BUFSIZ) browser.matrix = realloc(browser.matrix, browser.used+BUFSIZ/2);
        xTemp=0;
        temp = strtok(line, ",");
        while(temp != NULL){
            browser.used += sizeof(float);
            dataShell_motor_appendToMatrix(temp, browser, xTemp);
            temp = strtok(NULL, ",");
            xTemp++;
        }
        browser.x = dataShell_motor_verifyX(browser.y, xTemp, browser.x);
        browser.y++;
    }
    fclose(fp);
    
    return(browser);
}

/*
 *
 * The function appendToMatrix sends the information we read from the file to a matrix.
 *
 * @params
 *      number (string):
            This is the number we want to add to the matrix as a string.
        matrix (float*):
            This is the first memory location of our matrix.
        xCurrent (int):
            This is the column we're in right now.

 * @returns
        void
*/
void dataShell_motor_appendToMatrix(char *number, floatMatrix browser, int xCurrent){

    if(browser.y == 0) browser.matrix[xCurrent] = strtof(number, NULL);
    else browser.matrix[((browser.y*browser.x)+xCurrent)] = strtof(number, NULL);
    
    return;
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
int dataShell_motor_verifyX(int i, int xTemp, int xCurrent){

   if(i==0) xCurrent = xTemp;
   if(xCurrent != xTemp){
      printf("\n\n\tInconsistent file, columns are not consistent.\n");
      exit(1);
   }

return(xCurrent);
}
