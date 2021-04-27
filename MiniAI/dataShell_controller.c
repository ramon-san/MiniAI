//
//  dataShell_controller.c
//  MiniAI
//
//  Created by Ramon Orraca on 24/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "dataShell_controller.h"

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
int dataShell_verifyX(int i, int xTemp, int xCurrent){

   if(i==0) xCurrent = xTemp;
   if(xCurrent != xTemp){
      printf("\n\n\tInconsistent file, columns are not consistent.\n");
      exit(1);
   }

return(xCurrent);
}
