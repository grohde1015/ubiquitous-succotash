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

    // reading file data into variable -- need a stats class instance as next step
    if(fileData.is_open()){
        // class stuff

        fileData.close();
    }
    else{
        std::cout << "Cannot open file soory\n"
        return 10; 
    }

    // stats classes set to variable values
    
}