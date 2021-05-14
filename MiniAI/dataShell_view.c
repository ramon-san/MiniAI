//
//  dataShell_view.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataShell_view.h"

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
floatMatrix dataShell_view_menu(char *file){
    char option;
    FILE *fp;
    floatMatrix browser = {0, 0, 0, NULL};
    
//    system("clear");
    fp = dataShell_controller_openFile(file);
    browser = dataShell_controller_passBrowser(fp);

    getchar();
    printf("\n\tIf you want to print the file enter 'P', write anything else to skip this: ");
    scanf("%c", &option);
    if(option == 'p' || option == 'P'){
        dataShell_view_printMatrix(browser);
    }
    
    return(browser);
}

/*
 *
 * The function printMatrix prints the content of our matrix.
 *
 * @params
        browser (floatMatrix):
            This is the browser with our array's information.

 * @returns
        void
*/
void dataShell_view_printMatrix(floatMatrix browser){
    size_t i, j;
    char temp[4];
    
    system("clear");
    printf("\n     x: %d, y: %d, used: %zu [bytes]\n\n", browser.x, browser.y, browser.used);
    for(i=0; i<browser.y; i++){
        sprintf(temp, "%zu", i);
        printf("     %f;\t", browser.matrix[i*browser.x]);
        for(j=1; j<(browser.x); j++){
            sprintf(temp, "%zu", j);
            printf("x%s: %f\t", temp, browser.matrix[(i*browser.x)+j]);
        }
        printf("\n");
    }

}

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
void dataShell_view_getInfo(perceptron *my_perceptron, floatMatrix *browser){
    
    my_perceptron->targets = malloc(sizeof(float)*browser->y);
    my_perceptron->data = malloc(sizeof(float)*(browser->y)*(browser->x-2));
    
    dataShell_controller_storeInfo(&browser, &my_perceptron);
    
}
