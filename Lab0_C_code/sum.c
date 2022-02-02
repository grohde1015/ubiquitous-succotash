// Gabbie Rohde
//

#include<stdio.h>
#include<stdlib.h>

int main(void){

	printf("\nHello\n");
	FILE *file;
	file = fopen("../random_numbers.txt","r");
	int numArray[20];
	int count;
        int sum=0; 
	float average = 0;	

	if (file == NULL) {
		printf("ERROR");
		return 0;
	}

	for(count=0; count<20;count++){
		fscanf(file,"%d\n", &numArray[count]);
	}
	for (count=0; count<20; count++){
		sum = sum+(numArray[count]);
	}
	
	fclose(file);

	printf("Sum: %d\n",sum);

	FILE * newFile;

	newFile = fopen("printSum.txt", "w");

	fprintf(newFile, "Sum of random data: %d",sum); 
	fclose(newFile); 


	return 1;
}
