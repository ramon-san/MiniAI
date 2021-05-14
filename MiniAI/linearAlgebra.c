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
passResult linearAlgebra_dotProduct(float *vector1, float *vector2, size_t n_params, size_t entry, int max){
    size_t i=0, rand_i = rand() % (max-1);
    float result = 0;
    passResult my_result;
    
    my_result.predict_location = rand_i;
    printf("\nPredict in DOT %zu: %zu", entry, my_result.predict_location);
    rand_i *= n_params;
    if(vector1 == NULL || vector2 == NULL) result = (float)0xFFFFFFFF;
    else for(i=0; i<n_params; i++){
        result += vector1[rand_i]*vector2[i];
        rand_i++;
        if(rand_i >= max*n_params){
            printf("\n\nMemory overload, something went wrong!");
            exit(1);
        }
    
//        printf("\nResult %zu: %f * %f = %f", i, vector1[i+(n_params*entry)], vector2[i], result);
    }
    return(my_result);
}

/*
 *
 * The function vector_size_t creates a size_t vector (array) of size batch_size.
 *
 * @params
 *      n_members (size_t):
            This is value of batch_size.

 * @returns
        vector (*size_t):
            This variable is an array of size batch_size.
*/
size_t *linearAlgebra_vector_size_t(size_t n_members){
    size_t *my_vector = NULL;
    
    my_vector = calloc(n_members, sizeof(size_t));
    
    return(my_vector);
}
