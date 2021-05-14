//
//  perceptron_motor.c
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#include <stdio.h>
#include <stdlib.h>
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
float *perceptron_motor_predict(float *params, size_t batch_size, size_t n_params, float *features, int max, randomLocations **my_randoms){
    float *result = NULL;
    size_t *predict_location = NULL;
    size_t observation;
    passResult my_result;
    
    result = linearAlgebra_vector(batch_size);
    predict_location = linearAlgebra_vector_size_t(batch_size);
    if((*my_randoms)->predict_location == NULL) (*my_randoms)->predict_location = linearAlgebra_vector_size_t(batch_size);
    
    for(observation = 0; observation<batch_size; observation++){
        my_result = linearAlgebra_dotProduct(features, params, n_params, observation, max);
        result[observation] = my_result.result;
        predict_location[observation] = my_result.predict_location;
    }
    
    (*my_randoms)->result = result;
    (*my_randoms)->predict_location = predict_location;
    
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
void perceptron_motor_hebbian(size_t n_params, float *params, float *features, float error, float *hyper_param, int max){
    size_t param = 0, rand_i = rand() % (max-1);

    rand_i *= n_params;
    for(param = 0; param < n_params; param++){
        params[param] -= hyper_param[param]*perceptron_motor_relu(error*features[rand_i]);
        param++;
        rand_i++;
        if(rand_i >= max*n_params){
            printf("\n\nMemory overload, something went wrong!");
            exit(1);
        }
    }
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
float *perceptron_motor_fit(perceptron *my_perceptron, int max, randomLocations *my_results){
    float *error = NULL, *result = NULL;
    size_t epoch, observation;
    
    error = linearAlgebra_vector(my_perceptron->epochs);
    
    for(epoch = 0; epoch<my_perceptron->epochs; epoch++){
        result = perceptron_motor_predict(my_perceptron->params, my_perceptron->batch_size, my_perceptron->n_params, my_perceptron->data, max, &my_results);
        error[epoch] = general_RMS(result, my_results->predict_location, my_perceptron->targets, my_perceptron->batch_size);
        for(observation = 0; observation<my_perceptron->batch_size; observation++) perceptron_motor_hebbian(my_perceptron->n_params, my_perceptron->params, my_perceptron->data, error[epoch], my_perceptron->learning_rate, max);
    }

    return(error);
}

/*
 *
 * The function relu sets our activation function. This function was copied from Cesarín's code.
 *
 * @params
 *      x (float):
            This variable contains... This function was copied from Cesarín's code.

 * @returns
        void
*/
float perceptron_motor_relu(float x){
    return x>0?x:-.01; // If x>0 return x; -0.01 otherwise.
}
