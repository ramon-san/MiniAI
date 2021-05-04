//
//  dataShell_view.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "dataShell_view.h"

/*
 *
 * The function menu gives the user action posibilities.
 *

 * @returns
        void
*/
void dataShell_view_menu(void){
    char file[25];
    FILE *fp;
    floatMatrix browser = {0, 0, 0, NULL};
    
//    system("clear");
    printf("\n\tPlease enter the name of the file you want to learn from (CSV with floats): ");
    scanf("%s", file);
    fp = dataShell_controller_openFile(file);
    browser = dataShell_controller_passBrowser(fp);
    dataShell_view_printMatrix(browser);
    
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
void dataShell_view_printMatrix(floatMatrix browser){
    int i;

    system("clear");
    printf("\n     x: %d, y: %d, used: %zu [bytes]\n\n", browser.x, browser.y, browser.used);
    for(i=0; i<browser.y*browser.x; i++){
        printf("     ID: %f\t value: %f\n", browser.matrix[i], browser.matrix[i+1]);
        i++;
    }

    return;
}
