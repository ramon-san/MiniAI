//
//  general.h
//  MiniAI
//
//  Created by Ramon Orraca on 29/04/21.
//

#ifndef general_h
#define general_h

typedef float (*FLOAT_FUNCTION)(float);

typedef struct perceptron_browser{
    float *params;
    size_t n_params;
    float *error;
    size_t epochs;
    float *learning_rate;
    size_t batch_size;
    
    float *targets;
    float *data; // This are our features
    
    FLOAT_FUNCTION activation;
    
}perceptron;

typedef struct matrix_browser{
    int x, y;
    size_t used;
    float *matrix;
}floatMatrix;

/* Function prototypes. */

float general_RMS(float *predict, float *target, size_t n_values);
/*
 *
 * The function RMS does the root mean square of the values of the array that we entered. This function was also done by Cesarín.
 *
 * @params
 *      predict (*float):
            This array contains the results we predicted.
        target (*target):
            This array contains the results we needed.
        n_values (size_t):
            This is the value of batch_size, it gives the number of iterations.

 * @returns
        sqrt(result) (float):
            This variable is the square root of all the result sumation.
*/

#endif /* general_h */
