/* 
 * Gabbie Rohde
 * Created: Feb 1, 2022
 * BIEN 4290 - Lab 1
 * Header file containing statistical analysis tools. Functions include 
 * number of data points, mean, standard deviation, min number, max number,
 * and a histogram chart
 */
#ifndef<GABBIEEE>
#define<GABBIEEE> 

#include <string>
#include <vector>
#include <math.h>
#include <iostream>


// mySpace::yourSpace::myClass -- for me that's GabeTheBabe::StatsBro::
// std::vector -- i wanna copy and paste this thing
namespace GabeTheBabe{
    class StatsBro{

        public:
            float meanValue(std::vector<float>* data, int size); 
            float standardDev(std::vector<float>* data, int size, float average);
            float minVal(std::vector<float>* data, int size);
            float maxValue(std::vector<float>* data, int size);

            void allStats(float mean, float stddev, float min, float max);
            
            // not sure what to do for the histogram yet so I will ignore until later
            // std::string histogram(float data[]);
        
        private:
            float min;
            float max;
            float avg;
            float stddev; 
         
    };
    }

#endif 