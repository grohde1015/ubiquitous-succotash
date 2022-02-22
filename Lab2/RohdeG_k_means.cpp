#include "RohdeG_k_means.hpp"

// clusterfrick::Cluster::

float clusterfrick::Cluster::distance(float point){

}

// setters 
void setName(std::string nameObj){
    this->name = nameObj;
}
void setMean(float meanObj){
    this->mean = meanObj; 
}
void setData(std::vector<float> data){
    this->clusterPoint = data; 
}

// getters
std::string getName();
float getMean();
std::vector<float>* getData(); 

private:
std::string name; 
float mean;
std::vector<float> clusterPoint; 

