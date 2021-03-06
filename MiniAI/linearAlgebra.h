//
//  linearAlgebra.h
//  MiniAI
//
//  Created by Ramon Orraca on 12/05/21.
//

#ifndef linearAlgebra_h
#define linearAlgebra_h

#include "general.h"

/* Function prototypes. */

float *linearAlgebra_vector(size_t n_members);
/*
 *
 * The function vector creates a float vector (array) of size batch_size. This function was copied from Cesarín's code.
 *
 * @params
 *      n_members (size_t):
            This is value of batch_size.

 * @returns
        vector (*float):
            This variable is an array of size batch_size.
*/

passResult linearAlgebra_dotProduct(float *vector1, float *vector2, size_t n_params, size_t entry, int max);
/*
 *
 * The function dotProduct does the dot product operation between two arrays. And yet again, this function eas also copied from Cesarín's code.
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

size_t *linearAlgebra_vector_size_t(size_t n_members);
/*
 *
 * The function vector creates a size_t vector (array) of size batch_size.
 *
 * @params
 *      n_members (size_t):
            This is value of batch_size.

 * @returns
        vector (*size_t):
            This variable is an array of size batch_size.
*/

#endif /* linearAlgebra_h */
