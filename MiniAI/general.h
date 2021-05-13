//
//  general.h
//  MiniAI
//
//  Created by Ramon Orraca on 29/04/21.
//

#ifndef general_h
#define general_h

typedef struct perceptron_browser{
    float *params;
    size_t n_params;
    float *error;
    size_t n_epochs;
    float *learning_rate;
    size_t batch_size;
    
    float *targets;
    float *data;
}perceptron;

typedef struct matrix_browser{
    int x, y;
    size_t used;
    float *matrix;
}floatMatrix;

#endif /* general_h */
