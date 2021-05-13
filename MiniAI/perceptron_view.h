//
//  perceptron_view.h
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#ifndef perceptron_view_h
#define perceptron_view_h

#include "perceptron_controller.h"
#include "general.h"

/* Function prototypes. */

void perceptron_view_generator(size_t n_params, perceptron *my_perceptron);
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

void perceptron_view_getWeights(perceptron *my_perceptron);
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

void perceptron_view_printResult(float *result, size_t batch_size);
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

#endif /* perceptron_view_h */
