//
//  perceptron_motor.h
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#ifndef perceptron_motor_h
#define perceptron_motor_h

#include "linearAlgebra.h"
#include "general.h"

/* Function prototypes. */

float *perceptron_motor_predict(float *params, size_t batch_size, size_t n_params, float *features);
/*
 *
 * The function predict runs the perceptron to get the dot product of every iteration of our batch size. This function was also copied from Cesarín's code.
 *
 * @params
 *      params (*float):
            This array contains all the weights.
        batch_size (size_t):
            This is the value of batch_size.
        n_params (size_t):
            This is the amount of weights.
        features (*float):
            This is our data.

 * @returns
        result (*float):
            This variable is an array with the result.
*/

void perceptron_motor_hebbian(size_t n_params, float *params, float *features, float error, float *hyper_param);
/*
 *
 * The function does the Hebbian learning equation.
 *
 * @params
 *      n_params (size_t):
            This is the amount of weights.
        params (*float):
            This array contains all the weights.
        features (*float):
            This is our data.
        error (float):
            This is error we assigned for the first iteration.
        hyper_param (*float):
            This is array learning_rate.

 * @returns
        void
*/

float *perceptron_motor_fit(perceptron *my_perceptron);
/*
 *
 * The function fit trains our perceptron more. The concept was also copied from Cesarín's code.
 *
 * @params
 *      my_perceptron (*perceptron):
            This is the browser with our perceptron's information.

 * @returns
        _error (*float):
            This are the new error values.
*/

#endif /* perceptron_motor_h */
