#include <stdio.h>
#include <string.h>

char *datafile = "data.txt"; ////I create a file with a list of data
int main(void) {
	FILE *data_ptr; //the pointer
	char info[100];        
	int place;         

	data_ptr = fopen(datafile, "r"); //I open the file
	if (data_ptr == NULL) {
		fprintf(stderr, "file '%s' not found\n", datafile); //If there is no file with that name, it will display that it wasn't found
		return(8);
	}

	place = 0;
	while (fgets(info, sizeof(info), data_ptr)) { //I start the while loop that will be reading the file until the EOF (end of file)
		if (info[0] == '\n') { //If there is a line break
			printf("\n"); //It will print it and continue with the loop
			place = 0;
			continue;
		}

		info[strlen(info) - 1] = '\0';        
		switch (place) { ////a swith case depending on the position of the line
			case 1:
			case 2:
			case 5:
			case 6:
				printf("%s\n", info); //this four cases will be in the same line (1, 2, 5, 6)
				break;
			case 0:
			case 4:
				printf("%s ", info); //the same with this 2
				break;
			case 3:
				printf("%s, ", info); //only one line
				break;
			default:
				printf("This field is not defined\n"); //If there is any case aside the previous ones
		}
		++place; //add 1 to place

	}
	fclose(data_ptr); //close the file

	return(0);
}
