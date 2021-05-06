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

floatMatrix dataShell_view_menu(void);
/*
 *
 * The function menu gives the user action posibilities.
 *

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

#endif /* dataShell_view_h */
