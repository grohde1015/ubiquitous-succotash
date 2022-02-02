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

// mySpace::yourSpace::myClass

namespace GabeTheBabe{
    class StatsBro{

        public:
            int numDataPoints(float data[]); 
            float meanValue(float data[]); 
            float standardDev(float data[]);
            float minVal(float data[]);
            float maxValue(float data[]);
            std::string histogram(float data[]);
        
        private:
            float data[];
         
    }
    }

 }

#endif 