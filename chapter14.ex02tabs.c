#include <stdio.h>                
#include <stdlib.h>               

int main(void)
{             
    char input[] = "input2.txt"; //the file I create where I write some stuff
    char output[] = "output2.txt"; //the file that the program will create where the change will be made
    FILE *in_file; //I enter both files
    FILE *out_file;
    int character; //To check each one of the characters in the file
    int i;
    int num = 1; //a variable that I will use later that will be equal to 1

    in_file = fopen(input, "r"); //I open the file input.txt
    if (in_file == NULL) { //If there is no file with that name then...
        fprintf(stderr, "The file '%s' was not found\n", input); //It will display that it wasn't found
        exit(8); //And will end the program
    }

    out_file = fopen(output, "w");
    if (out_file == NULL) {
        fprintf(stderr, "The file '%s' was not found\n", output);//The same thing as before, if it isn't found it will say so
        exit(8);
    }

    while (1) {
        character = fgetc(in_file);
        if (character == ' ') { //If there is any whitespace in the file, like tabs, it will change them in the following way (see the for loop)
            character = ' '; //a whitespace will be added until i is equal to the variable num, which I defined as 1
            for (i = 0; i <= num; i++) {
                fputc(character, out_file);
            }
        }
        if (character == EOF) //When it reaches the EOF (end of file), break the loop and finish the count.
            break;

        fputc(character, out_file);
    }

    fclose(in_file); 
    fclose(out_file); //I close both files
    printf("The change has been made in the file 'output2.txt'.");

    return 0;
}
