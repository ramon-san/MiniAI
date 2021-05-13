//
//  perceptron_controller.h
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#ifndef perceptron_controller_h
#define perceptron_controller_h

#include "perceptron_motor.h"
#include "general.h"

/* Function prototypes. */

void perceptron_controller_setLearningRate(perceptron **my_perceptron);
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

void perceptron_controller_setWeights(perceptron *my_perceptron);
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

float perceptron_controller_relu(float x);
/*
 *
 * The function relu sets our activation function.
 *
 * @params
 *      x (float):
            This variable contains... This function was copied from Cesarín's code.

 * @returns
        void
*/

#endif /* perceptron_controller_h */
