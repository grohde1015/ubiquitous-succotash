// Gabbie Rohde
// Mini project 1 -- speed of swallow stuff

#include "/home/rohdeg/Git/ubiquitous-succotash/Lab1/RohdeG_stats.hpp"

int main(int argc, char* argv[]){
    // checking for file input from command line
    if(argc != 2){
        std::cout << "Incorrect number of arguments.\n"
        return 10; 
    }

    // file name 
    std::string fileName = argv[1]; 
    std::ifstream fileData(fileName); 

    // defining class name
    GabeTheBabe::StatsBro statsData; 

    // temp data 
    float speedValue; 

    // reading file data into variable -- need a stats class instance as next step
    if(fileData.is_open()){
        // class stuff loading data
        while(fileData >> speedValue){
            statsData.addData(speedValue);
        }

        fileData.close();
    }
    else{
        std::cout << "Cannot open file soory\n"
        return 10; 
    }

    // stats classes set to variable values
    float minValue = statsData.minVal();
    float maxValue = statsData.maxValue();
    float average = statsData.meanValue();
    float standDev = statsData.standardDev();

    return 0; 
    
}