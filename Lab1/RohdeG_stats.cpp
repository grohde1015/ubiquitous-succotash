// hi
// 
#include "RohdeG_stats.hpp"

// 
int numDataPoints(float data[]){

    int length = sizeof(data)/sizeof(data[0]);
    return length;
}

float meanValue(float data[]){

    float sum = 0.0; 
    float mean = 0.0; 

    for(int i=0; i<sizeof(data);i++){
        sum = sum + data[i];
    }

    mean = sum / sizeof(data);

    return mean; 

}
float standardDev(float data[]){

    

}
float minVal(float data[]);
float maxValue(float data[]);