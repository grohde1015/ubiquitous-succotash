// Gabbie Rohde
// Mini project 1 -- speed of swallow stuff
// due April 13 2022

#include "/home/rohdeg/Git/ubiquitous-succotash/Lab1/RohdeG_stats.cpp"

using namespace GabeTheBabe;

int main(int argc, char* argv[]){
    // checking for file input from command line
    if(argc != 2){
        printf("Incorrect number of arguments.\n");
        return 10; 
    }

    // file name 
    std::string fileName = argv[1]; 

    // defining class name
    GabeTheBabe::StatsBro statsData; // variable for stats data
    std::vector<float> fileData;

    std::ifstream iHopeThisWorks; 
    iHopeThisWorks.open(fileName);

    int sizeOfFile = 0;

    if(iHopeThisWorks.is_open()){
        while(std::getline(iHopeThisWorks, fileName)){
            fileData.push_back(stof(fileName));
            sizeOfFile++; 
        }
    }

    else {
        std::cout << "Unable to open file. \n";
        return 9; 
    }

    // stats classes set to variable values
    float minValue = statsData.minVal(&fileData, sizeOfFile);
    float maxValue = statsData.maxValue(&fileData, sizeOfFile);
    float average = statsData.meanValue(&fileData, sizeOfFile);
    float standDev = statsData.standardDev(&fileData, sizeOfFile, average);

    // prints values to terminal
    printf("Min value: %f\n", minValue);
    printf("Max value: %f\n", maxValue);
    printf("Average value: %f\n", average);
    printf("Standard deiation value: %f\n", standDev);

    return 0; 
    
}