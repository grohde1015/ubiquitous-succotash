
/* Gabbie Rohde
   Mini Project 0
   The function of this project is to hack time
*/ 

#ifndef GABBIE
#define GABBIE

#include <math.h>
#include <iostream> 
#include <vector>
#include <fstream> 
#include <unistd.h>

// UhhSomethingUnique::TimeHacking::
namespace UhhSomethingUnique{
    class TimeHacking{
        public:
            TimeHacking(std::string objectToHack);

            void setTimeToHack(int seconds);
            int getTimeToHack();
            std::string getObjectToHack();
            int hackTime();

        private:
            int time_to_hack;
            std::string objectToHack; 
    };
}

#endif