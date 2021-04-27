//
//  dataShell_motor.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataShell_controller.h"
#include "dataShell_motor.h"

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
FILE *dataShell_openFile(char *fileName){
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
 * The function readCSV reads the .csv file the user entered and converts it to a .txt, it returns the FILE* of the created file.
 *
 * @params
 *      fp (FILE*):
            This is the file pointer of the file we're reading.

 * @returns
        fpConvert (FILE*)
            This is the file pointer of the new file we created.
*/
browserFloatMatrix dataShell_readCSV(FILE *fp){
    browserFloatMatrix browser;
    char line[25], *temp;
    int xTemp;

    browser.matrix = malloc(sizeof(float)*BUFSIZ);
    browser.used = 0;
    browser.y = 0;
    while(fgets(line, 25, fp) != NULL){
       if(browser.used == sizeof(float)*BUFSIZ) browser.matrix = realloc(browser.matrix, sizeof(int)*BUFSIZ/2);
       xTemp=0;
       temp = strtok(line, ",");
       while(temp != NULL){
           dataShell_appendToMatrix(temp, browser, xTemp);
          temp = strtok(NULL, ",");
          xTemp++;
       }
       browser.x = dataShell_verifyX(browser.y, xTemp, browser.x);
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
void dataShell_appendToMatrix(char *number, browserFloatMatrix browser, int xCurrent){

    if(browser.y == 0) browser.matrix[xCurrent] = strtof(number, NULL);
    else browser.matrix[((browser.y*browser.x)+xCurrent)] = strtof(number, NULL);
    
    return;
}

/*
 *
 * The function printMatrix prints the content of our matrix.
 *
 * @params
        browser (browserFloatMatrix):
            This is the browser with our array's information.

 * @returns
        void
*/
void dataShell_printMatrix(browserFloatMatrix browser){
   int i;

    system("clear");
    printf("\n     x: %d, y: %d, used: %zu [bytes]\n\n", browser.x, browser.y, browser.used);
    for(i=0; i<browser.y*browser.x; i++){
        printf("     ID: %f\t value: %f\n", browser.matrix[i], browser.matrix[i+1]);
        i++;
    }

return;
}
