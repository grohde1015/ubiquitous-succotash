/* 
 * Gabbie Rohde
 * Created: Feb 1, 2022
 * BIEN 4290 - Lab 1
 * Header file containing statistical analysis tools. Functions include 
 * number of data points, mean, standard deviation, min number, max number,
 * and a histogram chart
 */
#ifndef GABBIEEE
#define GABBIEEE

//#include <string>
//#include <vector>
//#include <math.h>
//#include <iostream>
#include <stdio.h>

#include <vector>
#include <cstdio>
#include <fstream>
#include <math.h> 
#include <unistd.h>
#include <iostream>
#include <string>


// mySpace::yourSpace::myClass -- for me that's GabeTheBabe::StatsBro::
// std::vector -- i wanna copy and paste this thing
namespace GabeTheBabe{
    class StatsBro{

        public:
            float meanValue(std::vector<float>* data, int size); 
            float standardDev(std::vector<float>* data, int size, float average);
            float minVal(std::vector<float>* data, int size);
            float maxValue(std::vector<float>* data, int size);

            void allStats(float avg, float stddev, float min, float max);
            
            std::vector <float> getHist(std::vector<float>* data, int n, float mean, float STD);
        
        private: 
            float min;
            float max;
            float avg;
            float stddev; 
         
    };
}

#endif 