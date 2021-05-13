//
//  main.c
//  MiniAI
//
//  Created by Ramon Orraca on 22/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "dataShell_view.h"
#include "perceptron_view.h"

int main(int argc, const char * argv[]) {
    floatMatrix browser;
    perceptron my_perceptron;
    float *result = NULL, *error = NULL;

//    system("clear");
    browser = dataShell_view_menu();
    dataShell_view_getInfo(&my_perceptron, &browser);
    perceptron_view_generator(browser.x-2, &my_perceptron);
    
    printf("\n\n\tData shape = (%lu, %lu) \n", sizeof(my_perceptron.data[0])*my_perceptron.n_params*browser.y/sizeof(my_perceptron.data[0]), sizeof(my_perceptron.data[0])/sizeof(my_perceptron.data[0])*my_perceptron.n_params);
    printf("\tTarget shape = (%lu, 0) \n\n", sizeof(my_perceptron.targets[0])*browser.y/sizeof(my_perceptron.targets[0])); // The second option is hard coded but will always be true in this program
    printf("\n\nWeights at random:\n");
    perceptron_view_getWeights(&my_perceptron);
    result = perceptron_motor_predict(my_perceptron.params, my_perceptron.batch_size, my_perceptron.n_params, my_perceptron.data);
    perceptron_motor_hebbian(my_perceptron.n_params, my_perceptron.params, my_perceptron.data, 1.0, my_perceptron.learning_rate);
    printf("\n\nWeights after Hebbian:\n");
    perceptron_view_getWeights(&my_perceptron);
    perceptron_view_printResult(result, my_perceptron.batch_size);
    error = perceptron_motor_fit(&my_perceptron);
    perceptron_view_printResult(error, my_perceptron.epochs);
    
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
