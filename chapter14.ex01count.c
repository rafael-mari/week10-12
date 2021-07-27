#include <stdio.h>
#include <stdlib.h>

const char file1[] = "input.txt"; //the file I create where I write some stuff
const char file2[] = "output.txt";//the file that the program will create where the number of characters will be printed

int main()
{
	int num = 0;//the integer number starts with 0
	FILE *in_file; //ingreso del archivo

	int character; //To check each one of the characters in the file

	in_file = fopen(file1, "r"); //I open the file1, which I defined at the beginning as input.txt

	if (in_file == NULL) { //If there is no file named input.txt
		printf("The file '%s' was not found\n", file1);
		exit(8); //If this happens it will finish the program
	}
	while (1) {
		character = fgetc(in_file); 
		if (character == EOF)  //If while scanning the file we get to the EOF (end of file), break the loop and finish the count.
			break;
		++num; //But if there isn't the EOF yet, it will add 1 to the count in the va
	}

	printf("Number of characters in %s is %d\n", file1, num); //I print the number of characters of the input file, which is stored in the variable num
	fclose(in_file); //Close the first file
  FILE *out_file;
  out_file = fopen(file2, "wr"); //Open a new file where I will print the same thing as before
  fprintf(out_file,"Number of characters in %s is %d\n", file1, num); //I print the number of characters of the input file, which is stored in the variable num but now in the new file named output.txt
  fclose(out_file); //Close the second file
	return 0;
}
