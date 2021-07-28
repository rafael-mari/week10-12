/********************************************************
 * Ex05 -- Prime number *
 * *
 * Author: Rafael Marí. *
 * *
 * Purpose: Compute a program that tells if a number is prime or not. *
 * *
 * Usage: *
 * Run the program, enter number and it appears if it is prime or not. *
 * *
 * Updates *
 * Don't ask the user to enter a number, scan the number from a file and then tell whether it is a prime number or not. *
 ********************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const char file1[] = "number2.txt"; //I create a file with a number

int truth(int numero); // I define variables
int main(void) {
int number; // define the variable number
char bvb[100]; //To read up to 100 characters the user enters

FILE *num;
char *line = NULL;   
size_t  len = 0;   //current length
num = fopen(file1,"r"); //I open the file number.txt
if (num == NULL) {
		printf("The file '%s' was not found\n",file1); //If there is no file with that name, it will display that it wasn't found
		exit(8);
	}
  while (getline(&line, &len, num) != -1){ //a while loop to read all the lines
		sscanf(line, "%d", &number); //it reads each line one by one

  if (truth(number)) { //If the condition described below is reached it is a prime number
    printf("It is a prime number");
  } else {
    printf("It is not a prime number"); //If the condition is not reached, it is not a prime number
  }
  return 0;
  }
}

int truth(int number) {
  if (number==0||number==1) return 0; // If the number is 0 or 1, it is not a prime number, they are considered neither prime nor composed numbers
  if (number==4) return 0; // If the number is 4, it is not a prime number
  for (int x=2; x<number/2; x++) { // We create a loop from 2 to half the entered number
    if (number%x==0) return 0; //If the number can be divided with a remainder of 0, then it is not a prime number
  }
  return 1; //If none of those conditions was reached, the number is prime
}
