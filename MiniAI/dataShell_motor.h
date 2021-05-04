//
//  dataShell_motor.h
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#ifndef dataShell_motor_h
#define dataShell_motor_h

#include "general.h"

/* Function prototypes. */

floatMatrix dataShell_motor_readCSV(FILE *fp);
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

void dataShell_motor_appendToMatrix(char *number, floatMatrix browser, int xCurrent);
/*
 *
 * The function appendToMatrix sends the information we read from the file to a matrix.
 *
 * @params
 *      number (string):
            This is the number we want to add to the matrix as a string.
        browser (browserFloatMatrix):
            This is the first memory location of our matrix.
        xCurrent (int):
            This is the column we're in right now.

 * @returns
        void
*/

int dataShell_motor_verifyX(int i, int xTemp, int xCurrent);
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

#endif /* dataShell_motor_h */
