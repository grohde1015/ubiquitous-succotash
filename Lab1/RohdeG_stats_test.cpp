
#include "RohdeG_stats.hpp"
#include "RohdeG_stats.cpp"

using namespace GabeTheBabe;


int main(int argc, char** argv){

    GabeTheBabe::StatsBro statsdata; // variable for stats data
    std::vector<float> fileDataH;

    // putting data from input file as a vector
    std::vector<float> fileData;

    // string variable for data
    std::string fileLocation; 

    // used for histogram data returned from stats.cpp
    std::vector<float> dataH;

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

    // float meanVal = GabeTheBabe::StatsBro::meanValue(&fileData, sizeOfFile); --> this does not work lol
    float meanVal = statsdata.meanValue(&fileData, sizeOfFile);
    float standdev = statsdata.standardDev(&fileData, sizeOfFile, meanVal); 
    float min = statsdata.minVal(&fileData, sizeOfFile); 
    float max = statsdata.maxValue(&fileData, sizeOfFile); 


    // printing out values to terminal
    std::cout << "Mean Value: " << meanVal << std::endl;
    std::cout << "Standard Deviation: " << standdev << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Datapoints: " << sizeOfFile << std::endl;
    std::cout << "Histogram: \n";

    // histogram vector data 
    dataH = statsdata.getHist(&fileData, sizeOfFile, meanVal, standdev);

    // this is for each line aka each bin that we wanted printed out
    for(int i=0; i<9; i++){
        std::cout<< '|';

        // for each datapoint in whatever i bin 
        // if there are values in the dataH vector at i, then = is printed out 
        for(int j=0; j<dataH[i]; j++){
            std::cout<< '=';
        }
        std::cout<<'\n';
    }

    // prints out what the = means with regards to the data 
    std::cout<< "each = represents 10 data points \n";
}