#include <iostream>
#include <memory>
#include <vector>
#include <string> 

// https://man7.org/linux/man-pages/man2/flock.2.html

void locking(){

    // accessing the files based on ingredient 
    FILE *sugar; 

    char sugar_location[] = "/warehouse/sugar";
    // char sugar_location[] = "/lab/bien4290/warehouse/sugar"; 

    sugar = fopen(sugar_location, "r+");

    printf("sugar: %s\n", sugar);

    if(sugar == NULL){
        printf("Error\n");
    }

    if ((flock(sugar, LOCK_EX) == 0)){ 
        printf("File is locked\n"); 
    }
    if ((flock(sugar, LOCK_UN) == 0)) {
        printf("File is unlocked\n");
    }

}

int main(){
    locking();
    return 0; 
}