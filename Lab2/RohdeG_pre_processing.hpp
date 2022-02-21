
#ifndef PREPROCESS
#define PREPROCESS

#include <stdio.h>
#include <vector>
#include <cstdio>
#include <fstream>
#include <math.h> 
#include <iostream>
#include <string>


// preprocessdata::preprocess::
namespace preprocessdata{
    class preprocess {
        public: 

        void logFunction(std::vector<float>*spordata, int sporsize, std::vector<float>*nonspordata, std::vector<float>* ratio);

        // setter 
        void preData(float ratio); 

        private:
        float ratio; 
    };
}





#endif