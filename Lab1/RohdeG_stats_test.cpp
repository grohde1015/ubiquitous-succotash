// hey o
#include "RohdeG_stats.hpp"

using namespace GabeTheBabe::StatsBro

std::vector<float> vect; 

int main((int argc, char** argv)){

    printf("Program Name Is: %s\n",argv[0]);
    if(argc !=1){
        printf("Need to include file location oop\n");
        return 10; 
    }
    else{


        // using vectors: https://stackoverflow.com/questions/39629714/reading-component-vector-data-from-text-file-into-structure-array-c
        // https://en.cppreference.com/w/cpp/container/vector
        // need to get data from file at whatever location
/* 
        if (FILE *fp = fopen(argv[1], "r"))
        {
            
            std::string buffer;
            int data;
            std::getline(std::cin, buffer);
            std::istringstream iss(buffer);
            while (iss >> data)
            vec.push_back(data);


            while (size_t len = fread(fp))
            {
                
                v.insert(vec.end(), buf, buf + len);
            }
            fclose(fp);
}
not entirely sure how to work with vectors
*/ 


    }

}