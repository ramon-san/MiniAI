//
//  perceptron_controller.c
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "perceptron_controller.h"

/*
 *
 * The function generator fills in all the perceptron's basic information.
 *
 * @params
 *      my_perceptron (**perceptron):
            This is the browser with our perceptron's information.

 * @returns
        void
*/
void perceptron_controller_setLearningRate(perceptron **my_perceptron){
    float learning_rate=-1;
    size_t i;
    
    while(learning_rate < 0 || learning_rate > 1){
        printf("\n\tEnter learning rate: ");
        scanf(" %f", &learning_rate);
    }
    for(i = 0; i<(*my_perceptron)->n_params; i++) (*my_perceptron)->learning_rate[i] = learning_rate;
}

/*
 *
 * The function setWeights gives a random number to each weight. This function was copied from Cesarín's code.
 *
 * @params
 *      my_perceptron (*perceptron):
            This is the browser with our perceptron's information.

 * @returns
        void
*/
void perceptron_controller_setWeights(perceptron *my_perceptron){
    size_t n_params = my_perceptron->n_params, w;
    float *new_params = calloc(n_params, sizeof(float));

    srand((unsigned int)time(NULL));
    my_perceptron->params = NULL;
    my_perceptron->params = new_params;
    for(w = 0; w<n_params; w++) my_perceptron->params[w] = (float)rand()/RAND_MAX;
}
