//
//  perceptron_motor.c
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#include <stdio.h>
#include "perceptron_motor.h"

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
float *perceptron_motor_predict(float *params, size_t batch_size, size_t n_params, float *features){
    float *result = NULL;
    size_t observation;
    
    result = linearAlgebra_vector(batch_size);
    for(observation = 0; observation<batch_size; observation++) result[observation] = linearAlgebra_dotProduct(features, params, n_params);
    
    return(result);
}

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
void perceptron_motor_hebbian(size_t n_params, float *params, float *features, float error, float *hyper_param){
    size_t param;
    
    for(param = 0; param < n_params; param++) params[param] -= hyper_param[param]*error*features[param];
}

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
float *perceptron_motor_fit(perceptron *my_perceptron){
    float *error = NULL, *result = NULL;
    size_t epoch, observation;
    
    error = linearAlgebra_vector(my_perceptron->epochs);
    for(epoch = 0; epoch<my_perceptron->epochs; epoch++){
        result = perceptron_motor_predict(my_perceptron->params, my_perceptron->batch_size, my_perceptron->n_params, my_perceptron->data);
        error[epoch] = general_RMS(result, my_perceptron->targets, my_perceptron->batch_size);
        for(observation = 0; observation<my_perceptron->batch_size; observation++) perceptron_motor_hebbian(my_perceptron->n_params, my_perceptron->params, my_perceptron->data, error[epoch], my_perceptron->learning_rate);
    }
    
    return(error);
}
