#include "RohdeG_pre_processing.hpp"
#include "RohdeG_vector_ops.hpp"
#include "RohdeG_stats.hpp"

void preprocessdata::preprocess::preData(float ratio){

    this->ratio = ratio; 

}

// https://www.geeksforgeeks.org/array-at-function-in-c-stl/
void preprocessdata::preprocess::logFunction(std::vector<float>*spordata, int sporsize, std::vector<float>*nonspordata, std::vector<float>* ratio){

    // iterates through sporulating data to initialzie vector
    for(int i=0; i<sporsize; i++){
        ratio->push_back(0);
    }

    // based on size of spordata, takes log_10 of data to get ratio
    for(int j=0; j<sporsize; j++){
        ratio->at(j) = log10(((*spordata)[j] / (*nonspordata)[j])); 
    }
}

/* arguments for my own sanity (or lack of):
    1. name of red spor file
    2. name of red background
    3. name of non spor green
    4. name of green background
    5. name of output file
    6. number of genes 
*/ 
int main(int argc, char* argv[]){

    preprocessdata::preprocess pre;
    vectorstuff::vectors vecky; 
    GabeTheBabe::StatsBro stats; 

    // argument names to file names
    std::string redsporfile = argv[1];
    std::string redbackfile = argv[2];
    std::string greennonfile = argv[3]; 
    std::string greenbackfile = argv[4];
    std::string outputfile = argv[5];
    std::string numberofgenes = argv[6]; // need to convert this to an int

    // stream for files https://www.cplusplus.com/reference/fstream/ifstream/
    std::ifstream stream1; 
    std::ifstream stream2; 
    std::ifstream stream3; 
    std::ifstream stream4; 

    // opens files based on stream
    stream1.open(redsporfile);
    stream2.open(redbackfile); 
    stream3.open(greennonfile);
    stream4.open(greenbackfile); 


    // checking for correct number of arguments
    if(argc > 8){
        printf("Incorrect number of arguments. Need 6 arguments\n");
        return 10;
    }

    /* ------------FILE 1------------ */ 
    // variables for while statements below (RED)
    std::vector<float> testarray1;
    std::string teststr1; 
    int count1=0;


    // making sure all the files exist and if it does then read in line by line
    // if file doesn't exist then exit
    if(stream1.is_open()){
        // reading data in
        while(std::getline(stream1, teststr1)){
            testarray1.push_back(stof(teststr1));
            count1++; 
        }
    }
    else{
        // exiting since file is no exist
        printf("File 1 does not exist sorry\n");
        return 9; 
    }

    /* ------------FILE 2------------ */ 
    // variables for while statements below (RED)
    std::vector<float> testarray2;
    std::string teststr2; 
    int count2=0;

    // making sure all the files exist and if it does then read in line by line
    // if file doesn't exist then exit
    if(stream2.is_open()){
        // reading data in 
        while(std::getline(stream2, teststr2)){
            testarray2.push_back(stof(teststr2));
            count2++; 
        }
    }
    else{
        // exiting since file is no exist
        printf("File 2 does not exist sorry\n");
        return 9; 
    }

   /* ------------FILE 3------------ */ 
    // variables for while statements below (GREEN)
    std::vector<float> testarray3;
    std::string teststr3; 
    int count3=0;

    // making sure all the files exist and if it does then read in line by line
    // if file doesn't exist then exit
    if(stream3.is_open()){
        // reading data in
        while(std::getline(stream3, teststr3)){
            testarray3.push_back(stof(teststr3));
            count3++; 
        }
    }
    else{
        // exiting since file is no exist
        printf("File 3 does not exist sorry\n");
        return 9; 
    }

   /* ------------FILE 4------------ */ 
    // variables for while statements below (GREEN)
    std::vector<float> testarray4;
    std::string teststr4; 
    int count4=0;

    // making sure all the files exist and if it does then read in line by line
    // if file doesn't exist then exit
    if(stream4.is_open()){
        // reading data in
        while(std::getline(stream4, teststr4)){
            testarray4.push_back(stof(teststr4));
            count4++; 
        }
    }
    else{
        // exiting since file is no exist
        printf("File 4 does not exist sorry\n");
        return 9; 
    }

    // getting number of genes from arg 6 
    int numGenes = std::stoi(numberofgenes);

    // make sure data stays under 6118 + 1
    if(numGenes > 6118){
        printf("Too many genes. Max number is 6118\n");
        return 8; 
    }

    // making sure size of vectors for both red and green are same size
    int redSize = 0;
    if(count1 == count2){
        redSize = count1;
    }
    else{
        printf("Red files are not same size\n");
        return 7;
    }

    int greenSize = 0; 
    if(count3 == count4){
        greenSize = count3; 
    }
    else{
        printf("Green files are not same size\n");
        return 7;
    }

    // subtracting background intensityies from red and green datasets 

    // red data
    std::vector<float> redSubtract; 
    redSubtract = vecky.subtract_arrays(&testarray1, redSize, &testarray2); 

    // green data
    std::vector<float> greenSubtract; 
    greenSubtract = vecky.subtract_arrays(&testarray3, greenSize, &testarray4);

    // calculating means of corrected green and red datasets ////// these are the corrected datasets right lol
    float redMean = stats.meanValue(&redSubtract, redSize);
    float greenMean = stats.meanValue(&greenSubtract, greenSize);

    // normalizing green and red data (using mean) with division
    std::vector<float> redNormal;
    std::vector<float> greenNormal; 


    redNormal = vecky.divide(&redSubtract, redSize, redMean);
    greenNormal = vecky.divide(&greenSubtract, greenSize, greenMean); 

    // calculate log intensity ratio 

    // sizes of the two should be the same as specified above

    std::vector<float> ratio;
    if(redSize = 6118){
        pre.logFunction(&redNormal, redSize, &greenNormal, &ratio);
    }


    int i=0;
    // print output of log ratio to input file specified 
    std::string out(outputfile);
    std::ofstream getHerGoing;
    getHerGoing.open(out); 

    if(getHerGoing.is_open()){
        for(i=0; i<redSize;i++){
            getHerGoing << ratio[i];
            getHerGoing << "\n"; 
        }
    }
    else{
        printf("Log file don't be existin sorry bestie\n"); 
        return 7; 
    }

    // closing the log file
    getHerGoing.close();
    return 0; 


}