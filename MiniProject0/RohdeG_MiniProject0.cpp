
/* Gabbie Rohde
   Mini Project 0
   The function of this project is to hack time
*/ 

#include "RohdeG_MiniProject0.hpp"
using namespace UhhSomethingUnique; 

TimeHacking::TimeHacking(std::string objectToHack){
    // constructor
}

    // setter 
    void UhhSomethingUnique::TimeHacking::setTimeToHack(int seconds){
            this->time_to_hack = seconds;
    }

    // getter
    int UhhSomethingUnique::TimeHacking::getTimeToHack(){
        return time_to_hack;

    }
    std::string UhhSomethingUnique::TimeHacking::getObjectToHack(){
        return objectToHack;
    }
    int UhhSomethingUnique::TimeHacking::hackTime(){
        sleep(time_to_hack); 
    }

int main(int argc, char** arg){
    int time_hacked;
    char hack_object[100];
    std::string hackSTRING; 

    // user input for what object should be hacked and for how long
    printf("Hack object: ");
    scanf("%s", hack_object);

    // weird conversion between char array and string 
    hackSTRING = hack_object; 

    printf("\nHack time: ");
    scanf("%i", &time_hacked); 

    UhhSomethingUnique::TimeHacking hackysack(hackSTRING); // defining object

    // setters for hacked time 
    hackysack.setTimeToHack(time_hacked);
    hackysack.getTimeToHack(); 
    hackysack.getObjectToHack();

    // start hacking time
    printf("Hacking of object is starting\n");
    hackysack.hackTime(); 

    printf("Okayyy we done hacking\n");
    return 0; 
}