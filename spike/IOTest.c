#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	FILE *infile;
	char *mode = "r";
	char* p;
	FILE *outfile;

	//Set aside memory for input buffer
	buffer = (char *)malloc(bufsize * sizeof(char));

	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	//Create output file
	outfile = fopen("output.txt","w+");

	//Read file content and write to output
	while (fgets(buffer,bufsize,stdin) != NULL)
	{
		printf("%s\n",buffer);
		fprintf(outfile,"%s",buffer);
	}

	free(buffer);
	fclose(outfile);	
	return(0);
}	
