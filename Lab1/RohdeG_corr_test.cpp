

#include "RohdeG_stats.hpp"
#include "RohdeG_corr.hpp"
#include "RohdeG_corr.cpp"
#include "RohdeG_stats.cpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//using namespace GabeTheBabeCorr;
//using namespace GabeTheBabe; 

int main(int argc, char** argv){

    GabeTheBabeCorr::CorrelationHehe corrdata; // variable for stats data
    //GabeTheBabe::StatsBro statsdata;

    // putting data from input file as vectors
    std::vector<float> fileData1;
    std::vector<float> fileData2;

    // string variable for data
    std::string fileLocation1; 
    std::string fileLocation2; 

    // testing cmd line to make sure there are enough arguments
    if(argc > 3){
        std::cout <<"Error! Need 2 argument for running stats file\n.";
        std::cout <<"Need to be formatted as: [file location] [file location]\n";
        return 10; 
    }

    fileLocation1 = argv[1]; 
    fileLocation2 = argv[2]; 

    // https://www.cplusplus.com/reference/fstream/ifstream/
    std::ifstream iHopeThisWorks1; 
    iHopeThisWorks1.open(fileLocation1);

    int sizeOfFile1 = 0;

    if(iHopeThisWorks1.is_open()){
        while(std::getline(iHopeThisWorks1, fileLocation1)){
            fileData1.push_back(stof(fileLocation1));
            sizeOfFile1++; 
        }
    }

    else {
        std::cout << "Unable to open file1. \n";
        return 9; 
    }

    std::ifstream iHopeThisWorks2; 
    iHopeThisWorks2.open(fileLocation2);

    int sizeOfFile2 = 0;

    if(iHopeThisWorks2.is_open()){
        while(std::getline(iHopeThisWorks2, fileLocation2)){
            fileData2.push_back(stof(fileLocation2));
            sizeOfFile2++; 
        }
    }

    else {
        std::cout << "Unable to open file2. \n";
        return 9; 
    }
    int bothCount = 0;

    // making sure both are same size
    if(sizeOfFile1 == sizeOfFile2){
        bothCount = sizeOfFile1; 
    }
    else{
        std::cout <<"Error files need to be same length.\n";
        return 11; 
    }

    float correlationFloat = 0.0; 

    correlationFloat = corrdata.correlationCalc(&fileData1, &fileData2, bothCount);

    printf("%f\n", correlationFloat);
}