/**
 * Implementation file for the virtual
 * machine. Has a total of 12 instructions
 * and 16 registers.
 * Author: Anthony Woods
 * Date: 3-11-2016
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/VMFuncs.h"

#define MAXINSTRS 256			//Maximum number of instructions to be executed.
#define NUMREGS 16			//Number of registers for VM.
#define BUFFSIZE 32			//Buffer size for getting hex instructions.
#define NUMCODES 5			//Number of codes in single hex instruction

int main()
{
	int registers[NUMREGS];		//Holds registers.
	int instr_array[MAXINSTRS];	//Holds all hex instructions.
	char *buffer;			//Buffer for getting hex instrs.
	int hex_val;			//Value for hex code.
	int pc = 0;			//Program counter.
	int index = 0;			//Used for getting hex values for instr_array.
	bool finished = false;		//Used for determining when program is finished.
	int codes[NUMCODES];		//Used for storing codes from hex instruction.

	/* Set aside memory for buffer. */
	buffer = (char *)malloc(BUFFSIZE * sizeof(char));
	
	/* Make sure allocated. */
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer memory!\n");
		exit(1);
	}

	/* Loop and get hex instr. Convert and add to array. */
	while (fgets(buffer,BUFFSIZE,stdin) != NULL)
	{
		hex_val = (int)strtol(buffer,NULL,0);
		instr_array[index] = hex_val;
		index += 1;
	}

	/* Now iterate through instructions and execute. */
	while (!finished)
	{
		hex_val = instr_array[pc];
		execute_instr(hex_val,registers,&finished,&pc);
		pc += 1;
	}

	free(buffer);
	return 0;
}	
	

		
