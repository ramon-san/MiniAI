//
//  main.c
//  MiniAI
//
//  Created by Ramon Orraca on 22/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "dataShell_view.h"

int main(int argc, const char * argv[]) {
    floatMatrix browser;
    
    system("clear");
    browser = dataShell_view_menu();
    
    return 0;
}
