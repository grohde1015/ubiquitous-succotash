/* 
 Gabbie Rohde
 Clustering of genes
 */ 

 #ifndef HEHEHEHE
 #define HEHEHEHE

#include <stdio.h>
#include <vector>
#include <cstdio>
#include <fstream>
#include <math.h> 
#include <iostream>
#include <string>

// clusterfrick::Cluster::
namespace clusterfrick{
    class Cluster{
        public:

        // takes in data point and returns distance from it to cluster object
        float distance(float point); 

        // setters 
        void setName(std::string nameObj);
        void setMean(float meanObj);
        void setData(std::vector<float> data); 

        // getters
        std::string getName();
        float getMean();
        std::vector<float>* getData(); 

        private:
        std::string name; 
        float mean;
        std::vector<float> clusterPoint; 

    }; 
}

#endif