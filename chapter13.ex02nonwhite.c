#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *nonwhite(char *string1); // This function is going to help us find the first nonwhite character (a nonwhite character is any character but a whitespace " ")
int main(void)
{
	char string1[] = "       Random stuff as an example string"; //I write an example string with some whitespaces at the beginning
	printf("The first nonwhite character in the string is: '%c'\n", *nonwhite(string1)); //It will display what the first nonwhite character in the string is
	return 0;
}
char *nonwhite(char *string1) //I start the function here
{
	while (*string1 != '\0') { //I create a while loop to check all the characters in the string
		if (! isspace(*string1)) //If the character is nonwhite
			return string1; //Return pointer to this character
		++string1;
	}
	return string1;
}
