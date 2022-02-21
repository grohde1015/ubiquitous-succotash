#include "RohdeG_vector_ops.hpp"

// vectorstuff::vectors::

float vectorstuff::vectors::sum(std::vector<float> *data, int size){

    float data_sum = 0;

    for(int i=0; i<size; i++){
        data_sum = data_sum + (*data)[i];
    }

    return data_sum;
}

std::vector<float> vectorstuff::vectors::subtract_arrays(std::vector<float> *array1, int size1, std::vector<float> *array2){

    int i=0, j=0;
    std::vector<float> subtracted_array;

    // filling subtracted away with size of vector from input
    for(i=0;i<size1;i++){
        subtracted_arrays.push_back(0);
    }

    for(j=0;j<size1;j++){
        subtracted_arrays[j] = ((*array1)[j] - (*array2)[j]);
    }

    return subtracted_arrays; 
}
std::vector<float> vectorstuff::vectors::divide(std::vector<float> *data, int size, float divider){

    int i=0, j=0;
    std::vector<float> divide_arrays;
    printf("Test");
    // filling subtracted away with size of vector from input
    for(i=0; i<size; i++){
        divide_arrays.push_back(0);
    }

    for(j=0;j<size;j++){
        divide_arrays[j] = ((*data)[j] / divider);  
    }

    return divide_arrays; 
    
}