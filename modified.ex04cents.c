/********************************************************
 * Ex04 -- Cents *
 * *
 * Author: Rafael Marí. *
 * *
 * Purpose: Calculate how many of each coin you need to reach the total amount of money in cents. *
 * *
 * Usage: *
 * Run the program, enter the amount of money needed and the reult appears *
 * *
 * Updates *
 * Don't ask the user to enter a number, scan the number from a file. *
 ********************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const char file1[] = "cents.txt"; //I create a file with a list of different amounts of cents

int main(void){ //Define the variables
  int mon;
  int qrt;
  int dim;
  int nck;
  int pen;
  char bvb[100];

  FILE *coins; //create the pointer to the file cents.txt
  char *line = NULL;   
  size_t  len = 0;   //current length
  coins = fopen(file1,"r"); //I open the file number.txt
  if (coins == NULL) {
		printf("The file '%s' was not found\n",file1); //If there is no file with that name, it will display that it wasn't found
		exit(8);
	}
  while (getline(&line, &len, coins) != -1){ //a while loop to read all the lines
		sscanf(line, "%d", &mon); //it reads each line one by one

    if ((mon>=0)&&(mon<=100)){ //If the value is between this range, do the following to define the value of each denomination of coin
      qrt=trunc(mon/25);
      dim=trunc((mon-qrt*25)/10);
      nck=trunc((mon-qrt*25-dim*10)/5);
      pen=trunc(mon-qrt*25-dim*10-nck*5);

      printf("You need %d quarter(s), %d dime(s), %d nickle(s) and %d penny(ies).\n",qrt,dim,nck,pen); //It returns how many coins of each denomination you need to get the exact amount of money
    }
    else{
      printf("The file must provide an amount between 0 and 100 cents.\n"); //If it is out of the range, ask for another file
    }
  }
  return 0;
}
