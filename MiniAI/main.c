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
    perceptron my_perceptron;
    float *learning_rate;
    
    printf("\n\tEnter batch size: ");
    scanf(" %zu", &my_perceptron.batch_size);

//    system("clear");
    browser = dataShell_view_menu();
    dataShell_view_getInfo(&my_perceptron, &browser);
    
    learning_rate = malloc(sizeof(float)*browser.x);
    
    free(learning_rate);
    free(browser.matrix);
    free(my_perceptron.targets);
    free(my_perceptron.data);
        
    return 0;
}
