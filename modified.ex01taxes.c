/********************************************************
 * Ex04 -- Added taxes. *
 * *
 * Author: Rafael Marí. *
 * *
 * Purpose: Calculate the amount of money after taxes and round it to the nearest penny. *
 * *
 * Usage: *
 * Run the program, enter the amount of money and the new amount after taxes and rounded to the nearest penny appears. *
 * *
 * Updates *
 * Store the result in a new file *
 ********************************************************/

#include <stdio.h>
#include <math.h>

int main(void) {
  float a; // the original ampunt of money
  float b; // the amount of money after taxes
  char bvb[100]; //To read up to 100 characters the user enters
   
  printf("Enter the original amount of money.\n"); //I ask for the amount of money
  fgets(bvb, sizeof(bvb), stdin);
  sscanf(bvb, "%f",&a); // I read the amount provided

  b=a*1.08; //I do the calculations

  FILE *money; //I introduce the pointer to file that will be created
  money = fopen("total.txt", "w"); //I open the file total.txt
  printf("The amount of money after taxes is $%.2f",b); //I print the new value
  fprintf(money, "The amount of money after taxes is $%.2f", b); //print the number in the file total.txt

  return 0;
}
