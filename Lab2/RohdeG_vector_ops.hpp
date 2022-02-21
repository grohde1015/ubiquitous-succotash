
/* Gabbie Rohde
   February15, 2022
   Header file for functions that will 1.sum all elements of an array,
   2.subtracts one array from another element by element, and 3.divides 
   values of an array by a constant
*/ 

#ifndef YOBRO
#define YOBRO

#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>

// vectorstuff::vectors::
namespace vectorstuff {
    class vectors {
        public:

        float sum(std::vector<float> *data, int size);
        std::vector<float> subtract_arrays(std::vector<float> *array1, int size1, std::vector<float> *array2); 
        std::vector<float> divide(std::vector<float> *data, int size, float divider); 

        private: 
        float data_sum;
        std::vector<float> subtracted_arrays; 
        std::vector<float> divide_arrays; 

    };
    
}

#endif
