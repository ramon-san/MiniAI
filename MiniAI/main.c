//
//  main.c
//  MiniAI
//
//  Created by Ramon Orraca on 22/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataShell_view.h"
#include "perceptron_view.h"

int main(int argc, const char * argv[]) {
    floatMatrix browser;
    perceptron my_perceptron;
    char file[25], file_to_plot[35];
    float *result = NULL, *error = NULL;

//    system("clear");
    printf("\n\tPlease enter the name of the file you want to learn from (CSV with floats): ");
    scanf("%s", file);
    browser = dataShell_view_menu(file);
    dataShell_view_getInfo(&my_perceptron, &browser);
    perceptron_view_generator(browser.x-2, &my_perceptron);
    printf("\n\n\tData shape = (%lu, %lu) \n", sizeof(my_perceptron.data[0])*my_perceptron.n_params*browser.y/sizeof(my_perceptron.data[0]), sizeof(my_perceptron.data[0])/sizeof(my_perceptron.data[0])*my_perceptron.n_params);
    printf("\tTarget shape = (%lu, 0) \n\n", sizeof(my_perceptron.targets[0])*browser.y/sizeof(my_perceptron.targets[0])); // The second option is hard coded but will always be true in this program
    printf("\n\nWeights at random:\n");
    perceptron_view_getWeights(&my_perceptron);
    result = perceptron_motor_predict(my_perceptron.params, my_perceptron.batch_size, my_perceptron.n_params, my_perceptron.data, browser.y);
    perceptron_motor_hebbian(my_perceptron.n_params, my_perceptron.params, my_perceptron.data, 1.0, my_perceptron.learning_rate, browser.y);
    printf("\n\nWeights after Hebbian:\n");
    perceptron_view_getWeights(&my_perceptron);
    perceptron_view_printResult(result, my_perceptron.batch_size);
    error = perceptron_motor_fit(&my_perceptron, browser.y);
    perceptron_view_printResult(error, my_perceptron.epochs);
    sprintf(file_to_plot, "to_plot_%s", file);
    general_saveToPlot(error, my_perceptron.epochs, file_to_plot);
    
    free(my_perceptron.learning_rate);
    free(my_perceptron.params);
    free(my_perceptron.error);
    free(browser.matrix);
    free(my_perceptron.targets);
    free(my_perceptron.data);
    free(result);
    free(error);
        
    return 0;
}
