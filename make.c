#include <stdio.h>
#include <stdlib.h>

#define ERROROUT -1

int main(int argc, char *argv[])
{	
	char *filename;
	int len_filename = 0;

	if(argc > 2){
		printf("Too many arguments!\n");
		return ERROROUT;
	}

	filename = argv[1]; 

	for(len_filename; filename[len_filename] != '\0'; len_filename++);

	if(len_filename < 3 || (filename[len_filename - 2] != '.' || filename[len_filename - 1] != 'c'))
	{
		printf("Not \'.c\'-like file\n");
		return ERROROUT;
	}
		
	char ofilename[len_filename - 1];//output file

	int i = 0;

	while(i < (len_filename - 2))
	{
		ofilename[i] = filename[i];
		i++;
	}	
	ofilename[i] = '\0';
	
	char command[50];
	
	snprintf(command, sizeof(command), "gcc -g %s -o %s", filename, ofilename);
	system(command);

	return 0;

}





