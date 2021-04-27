//
//  dataShell_motor.h
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#ifndef dataShell_motor_h
#define dataShell_motor_h


typedef struct browser{
   int x, y;
   size_t used;
   float *matrix;
}browserFloatMatrix;

/* Function prototypes. */

FILE *dataShell_openFile(char *fileName);
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

browserFloatMatrix dataShell_readCSV(FILE *fp);
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

void dataShell_appendToMatrix(char *number, browserFloatMatrix browser, int xCurrent);
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

void dataShell_printMatrix(browserFloatMatrix browser);
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

#endif /* dataShell_motor_h */
