
#include "RohdeG_stats.hpp"
#include "RohdeG_stats.cpp"

using namespace GabeTheBabe;


int main(int argc, char** argv){

    GabeTheBabe::StatsBro statsdata; // variable for stats data

    // putting data from input file as a vector
    std::vector<float> fileData;

    // string variable for data
    std::string fileLocation; 

    // testing cmd line to make sure there are enough arguments
    if(argc > 2){
        std::cout <<"Error! Need 1 argument for running stats file\n.";
        std::cout <<"Need to be formatted as: [file location]\n";
        return 10; 
    }

    fileLocation = argv[1]; 

    // https://www.cplusplus.com/reference/fstream/ifstream/
    std::ifstream iHopeThisWorks; 
    iHopeThisWorks.open(fileLocation);

    int sizeOfFile = 0;

    if(iHopeThisWorks.is_open()){
        while(std::getline(iHopeThisWorks, fileLocation)){
            fileData.push_back(stof(fileLocation));
            sizeOfFile++; 
        }
    }

    else {
        std::cout << "Unable to open file. \n";
        return 9; 
    }

    // float meanVal = GabeTheBabe::StatsBro::meanValue(&fileData, sizeOfFile); 
    float meanVal = statsdata.meanValue(&fileData, sizeOfFile);
    float standdev = statsdata.standardDev(&fileData, sizeOfFile, meanVal); 
    float min = statsdata.minVal(&fileData, sizeOfFile); 
    float max = statsdata.maxValue(&fileData, sizeOfFile); 

    printf("Mean: %f\n",meanVal);
    printf("standard deviation: %f\n",standdev);
    printf("Min: %f\n",min);
    printf("Max: %f\n",max);
    printf("Datapoints: %i\n", sizeOfFile);


}