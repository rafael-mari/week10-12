#include <stdio.h>
#include <stdlib.h>

const char file1[] = "input.txt"; //the file I create where I write some stuff
const char file2[] = "output.txt";//the file that the program will create where the number of characters will be printed

int main(void)
{
	int lines = 0; //the integer lines starts with 0
	FILE *in_file; //I enter the file

	int character; //To check each one of the characters in the file

	in_file = fopen(file1, "r"); //I open the file1, which I defined at the beginning as input.txt

	if (in_file == NULL) { //If there is no file named input.txt
		printf("The file '%s' was not found\n", file1);
		exit(8); //If this happens it will finish the program
	}

	lines = 0; //the integer lines starts with 0
	for (character = getc(in_file); character != EOF; character = getc(in_file)) { //while the current character is not the end of file, do the following:
		if (character == '\n') //if the character is a backslash n (a line break), do the following
			++lines; //add 1 to the count of lines
	}

	printf("The number of lines in %s is %d\n", file1, lines+1); //I print the number of lines of the input file, which is stored in the variable lines, I add 1 to the variable lines because even when you don't end a text with a line break, it is still a line
	fclose(in_file); //Close the first file
  FILE *out_file;
  out_file = fopen(file2, "wr"); //Open a new file where I will print the same thing as before
  fprintf(out_file,"The number of lines in %s is %d\n", file1, lines+1); //I print the number of lines of the input file, which is stored in the variable lines but now in the new file named output.txt
  fclose(out_file); //Close the second file
	return 0;
}
