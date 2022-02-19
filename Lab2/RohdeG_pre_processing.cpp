

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
    if(argc > 6){
        printf("Incorrect number of arguments. Need 6 arguments\n");
        return 10;
    }

    // making sure all the files exist and if it does then read in line by line
    // if file doesn't exist then 
    if(stream1.is_open()){
        // reading data in -- need to do
        while()

    }
    else{
        // exiting since file is no exist
        printf("File 1 does not exist sorry\n");
        return 9; 
    }


  

}