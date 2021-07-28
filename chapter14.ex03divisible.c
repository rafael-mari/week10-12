#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char file1[] = "numbers.txt"; //I create a file with a list of numbers

int main(void)
{
	int  number; 
	FILE *num; 
	FILE *div; 
	FILE *non_div; 
	char *line = NULL;   
	size_t  len = 0;   //current length
	num = fopen(file1,"r"); //I open the file numbers.txt
	div = fopen("divisible.txt", "w"); //I open the file divisible.txt
	non_div = fopen("non-divisible.txt", "w"); //I open the file non-divisible.txt
	if (num == NULL) {
		printf("The file '%s' was not found\n",file1); //If there is no file with that name, it will display that it wasn't found
		exit(8);
	}
	while (getline(&line, &len, num) != -1){ //a while loop to read all the lines
		sscanf(line, "%d", &number); //it reads each line one by one
		if ((number % 3) == 0) //If the number is divisible by 3 and the result is 0
			fprintf(div, "%d\n", number); //print the number in the file divisible.txt
		else
			fprintf(non_div, "%d\n", number); //if not, print the number in the file non-divisible.txt
	}
	free(line);
	fclose(num);
	fclose(div);
	fclose(non_div); //I close the files
  printf("The numbers have been classified in divisible by 3 and non-divisible by 3. Two new files have been created with each classification: 'divisible.txt' and 'non-divisible.txt'\n");  //I print a message to explain what happened
	return 0;
}
