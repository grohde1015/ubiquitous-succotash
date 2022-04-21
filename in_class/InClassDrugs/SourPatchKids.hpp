#include <iostream>
#include <memory>
#include <vector>

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

}

int main(){
    locking();
    return 0; 
}