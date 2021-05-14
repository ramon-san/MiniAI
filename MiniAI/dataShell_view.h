//
//  dataShell_view.h
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#ifndef dataShell_view_h
#define dataShell_view_h

#include "dataShell_controller.h"
#include "general.h"

/* Function prototypes. */

floatMatrix dataShell_view_menu(char *file);
/*
 *
 * The function menu gives the user action posibilities.
 *
 * @params
        file (*char):
            This variable contains the file's name.

 * @returns
        void
*/


void dataShell_view_printMatrix(floatMatrix browser);
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

void dataShell_view_getInfo(perceptron *my_perceptron, floatMatrix *browser);
/*
 *
 * The function getInfo separates data and targets.
 *
 * @params
        my_perceptron (*perceptron):
            This is the browser with our perceptron's information.
        browser (floatMatrix):
            This is the browser with our array's information.

 * @returns
        void
*/

#endif /* dataShell_view_h */
