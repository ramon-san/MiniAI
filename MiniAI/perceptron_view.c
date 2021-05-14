//
//  perceptron_view.c
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "perceptron_view.h"

/*
 *
 * The function generator fills in all the perceptron's basic information.
 *
 * @params
 *      n_params (size_t):
            This is number of weights.
        my_perceptron (*perceptron):
            This is the browser with our perceptron's information.

 * @returns
        void
*/
void perceptron_view_generator(size_t n_params, perceptron *my_perceptron){

    my_perceptron->n_params = n_params;
    printf("\n\tEnter batch size: ");
    scanf(" %zu", &my_perceptron->batch_size);
    printf("\n\tEnter number of epochs: ");
    scanf(" %zu", &my_perceptron->epochs);
    my_perceptron->learning_rate = malloc(sizeof(float)*n_params);
    my_perceptron->error = malloc(sizeof(float)*my_perceptron->batch_size);
    perceptron_controller_setLearningRate(&my_perceptron);
    perceptron_controller_setWeights(my_perceptron);
    my_perceptron->activation = perceptron_motor_relu;
}

/*
 *
 * The function prints the weights. This function was copied from Cesarín's code.
 *
 * @params
 *      my_perceptron (*perceptron):
            This is the browser with our perceptron's information.
 
 * @returns
        void
*/
void perceptron_view_getWeights(perceptron *my_perceptron){
    size_t n_p = my_perceptron->n_params, w;
    
    for(w=0; w<n_p; w++) printf("\tw[%zu] = %f \n", w, my_perceptron->params[w]);
    
}

/*
 *
 * The function printResult prints the values of the result array. This function was also done by Cesarín.
 *
 * @params
 *      result (*float):
            This array contains the results.
        batch_size (size_t):
            This is the value of batch_size.

 * @returns
        result (*float):
            This variable is an array with the result.
*/
void perceptron_view_printResult(float *result, size_t batch_size){
    size_t element;
    
    printf("\n\nPerceptron results!\n\n");
    for(element = 0; element<batch_size; element++) printf("\t %zu = %f \n", element, result[element]);
}
