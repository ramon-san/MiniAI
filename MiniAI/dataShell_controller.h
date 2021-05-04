//
//  dataShell_controller.h
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#ifndef dataShell_controller_h
#define dataShell_controller_h

#include "dataShell_motor.h"
#include "general.h"

/* Function prototypes. */

FILE *dataShell_controller_openFile(char *fileName);
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

int dataShell_controller_verifyX(int i, int xTemp, int xCurrent);
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

floatMatrix dataShell_controller_passBrowser(FILE *fp);
/*
 *
 * The function passBrowser passes our filled browser variable to our view.
 *
 * @params
 *      fp (FILE*):
            This is the file pointer of the file we're reading.

 * @returns
        fpConvert (FILE*)
            This is the file pointer of the new file we created.
*/

#endif /* dataShell_controller_h */
