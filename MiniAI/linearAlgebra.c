//
//  linearAlgebra.c
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "linearAlgebra.h"

/*
 *
 * The function vector creates a float vector (array) of size batch_size. This function was copied from Cesarín's code.
 *
 * @params
 *      n_members (size_t):
            This is value of batch_size.

 * @returns
        vector (*float):
            This variable is an array of size batch_size
*/
float *linearAlgebra_vector(size_t n_members){
    float *my_vector = NULL;
    
    my_vector = calloc(n_members, sizeof(float));
    
    return(my_vector);
}

/*
 *
 * The function dotProduct does the dot product operation between two arrays. And yet again, this function was also copied from Cesarín's code.
 *
 * @params
 *      vector1 (*float):
            This array the info of one vector.
        vector2 (*float):
            This array contains the info of another vector.
        n_params (size_t):
            This is the amount of weights.

 * @returns
        result (float):
            This variable is the result of the current iteration.
*/
float linearAlgebra_dotProduct(float *vector1, float *vector2, size_t n_params, size_t entry, int max){
    size_t i=0;
    float result = 0;
    
    for(i=0; i<n_params; i++){
        result += vector1[i+(n_params*entry)]*vector2[i];
    }
    
    return(result);
}
