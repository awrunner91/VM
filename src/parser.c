/**
 * This file parses the assembly file
 * and generates an output file (output.txt)
 * that contains the hexadecimal instructions
 * for each instruction in the assembly file.
 * Author: Anthony Woods
 * Date: 2-27-2016
**/

#include "../include/parseFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFSIZE 32

int main()
{
	char *buffer;			//Buffer to hold instructions from assembly file.
	char hex_instr[BUFFSIZE];	//Will hold parsed instruction.
	FILE *outfile;			//Will point to the output file to write to.

	/* Set aside memory for buffer. */
	buffer = (char *)malloc(BUFFSIZE * sizeof(char));

	/* Make sure allocated. */
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer memory!\n");
		exit(1);
	}

	/* Create the output file to write hex to. */
	outfile = fopen("output.txt","w+");

	/* Loop and write hex instr to output. */
	while (fgets(buffer,BUFFSIZE,stdin) != NULL)
	{
		create_hex_instr(buffer,hex_instr);
		fprintf(outfile,"%s\n",hex_instr);
	}

	/* Free memory and close the file. */
	free(buffer);
	fclose(outfile);

	return(0);
}		
