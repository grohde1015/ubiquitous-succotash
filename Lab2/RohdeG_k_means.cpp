#include "RohdeG_k_means.hpp"
#include "RohdeG_stats.hpp"

// clusterfrick::Cluster::

float clusterfrick::Cluster::distance(float point){
    float tempDistance = 0;
    tempDistance = ((this->mean) - point); // difference between mean and whatever point
    tempDistance = abs(tempDistance); // absolute value needed
    return tempDistance; 
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
std::string getName(){
    return this->name;
}
float getMean(){
    return this->mean; 
}
std::vector<float>* getData(){
    return this->clusterPoint;
}

// only needs one arg and it's name of datafile (log_ratio_input.dat)
int main(int argc, char* argv[]){

    clusterfrick::Cluster clusterstuff; 
    GabeTheBabe::StatsBro stats; 

    // make sure there are the correct amount of args
    if(argc>3){
        printf("Too many arguments\n");
        return 11; 
    }


    // https://stackoverflow.com/questions/46719183/c-using-ifstream-to-read-file
    // checking if file exists and reading in data from log ratio

    std::vector<float> logVector; 

    std::string fileName = argv[1]; 
    std::ifstream rfile;
    rfile.open(fileName); 
    std::string fileData;
    int count = 0;  

    if(rfile.is_open()){
        
        while(std::getline(rfile, fileData)){
            logVector.push_back(stof(fileData));
            count++; 
        }
    }
    else{
        printf("Log file cannot be found\n");
        return 10; 
    }

    // using gene list and reading data in 
    std::ifstream rfile2; 
    rfile2.open("gene_list.txt"); 
    std::string fileData2; 
    int count2 = 0; 
    std::vector<std::string> geneListVec;

    if(rfile2.is_open()){
        
        while(std::getline(rfile2, fileData2)){
            geneListVec.push_back((fileData2));
            count2++; 
        }
    }
    else{
        printf("Gene file cannot be found\n");
        return 10; 
    }

    // initializing 3 class instances for 3 kinds of clusters
    // some example code -- http://www.cplusplus.com/forum/general/155120/
    clusterfrick::Cluster SupressedCluster; // cluser 1
    clusterfrick::Cluster StationaryCluster; // cluster 2 
    clusterfrick::Cluster ExpressedCluster; // cluster 3

    // defining some variables for cluster means -- values based on lab handout
    float meanSupressed = -0.5;
    float meanStationary = 0;
    float meanExpressed = 0.5;

    // setting name and means for each cluster
    SupressedCluster.getName("supressed");
    SupressedCluster.getMean(meanSupressed); 

    StationaryCluster.getName("stationary");
    StationaryCluster.getMean(meanStationary); 

    ExpressedCluster.getName("expressed");
    ExpressedCluster.getMean(meanExpressed); 




}