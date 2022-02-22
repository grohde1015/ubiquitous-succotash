#include "RohdeG_k_means.hpp"
#include "RohdeG_stats.hpp"

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
        printf("File cannot be found\n");
        return 10; 
    }





}