//
//  dataShell_view.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dataShell_motor.h"
#include "dataShell_view.h"

/*
 *
 * The function menu gives the user action posibilities.
 *

 * @returns
        void
*/
void dataShell_menu(void){
   char option = '0';
   char file[25];
   FILE *fp;
   int verifier = 0;
    browserFloatMatrix browser = {0, 0, 0, NULL};
    
//    system("clear");
    while(option != 'E'){
        printf("\n\tPlease select one of the following options and click [Enter]: ");
        printf("\n\t  [S]elect file\n\t  [P]rint data\n\t  [E]xit\n -> ");
        scanf(" %c", &option);
        option = toupper(option);

        if(option == 'E'){
            printf("\n\tProgram terminated\n");
            if(verifier == 1) free(browser.matrix);
        }
        else if(option == 'S'){
            if(verifier == 0){
                printf("\n\tPlease enter the name of the file you'll transform (CSV with floats)\n -> ");
                scanf(" %s", file);
                fp = dataShell_openFile(file);
                browser = dataShell_readCSV(fp);
                verifier = 1;
            }
            else{
//                system("clear");
                printf("\n\n\tThis demo is only capable of reading one file.\n\n");
            }
        }
        else if(option == 'P'){
            if(verifier != 0){
                dataShell_printMatrix(browser);
            }
            else{
                system("clear");
                printf("\n\tYou first have to enter a file.\n\n");
            }
        }
    }
    
    return;
}
