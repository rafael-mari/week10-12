#include <stdio.h> //Define the library
#define array1 10 //Define the number of elements in the array
int main(void)
{
	int val[array1] = {1, 3, 5, 9, 11, 12, 15, 25, 74, 258}; //I assign an initial value to each element of the array
	int *val_ptr; //pointer to the adress of the variable val, where the data of the array is stored
	for (val_ptr = &val[0]; val_ptr <= &val[array1]; ++val_ptr) { //The variable val starts with the first element of the arrays and ends with the last one, to do this I use a for loop, it adds 1 to the count until it is equal to the number of values we have
		*val_ptr = 0; //We will change the value of every element to 0
	};
	for (int i = 1; i <= array1; ++i) //The variable i is to identify each one of the ten values we have in the array as it will display all of them.
		printf("element %d = %d\n", i, val[i]); //I show the numbers and their respective value
	return 0;
}
