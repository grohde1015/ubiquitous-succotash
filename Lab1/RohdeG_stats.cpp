// hi
// 
#include "RohdeG_stats.hpp"

// 

float GabeTheBabe::StatsBro::meanValue(std::vector<float>* data, int size){

    float sum = 0, average = 0; 
    int i =0;

    for(i=0; i<size; i++){
        sum = sum + (*data)[i]; 
    }
    average = sum / size; 
    return average;

}
float GabeTheBabe::StatsBro::standardDev(std::vector<float>* data, int size, float average){

    float stddev = 0, sum = 0, calculations = 0;
    int i = 0; 

    for(i=0; i < size; i++){
        calculations = pow(((*data[i]) - average),2);
        sum = sum + calculations;
    }
    float new_avg = new_avg / size; 

    stddev = sqrt(new_avg);
    return stddev;

}
float GabeTheBabe::StatsBro::minVal(std::vector<float>* data, int size);
float GabeTheBabe::StatsBro::maxValue(std::vector<float>* data, int size);