/**
 * Implementation file for parseFuncs.h
 * Author: Anthony Woods
 * Date: 2-24-2016
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMCODES 11				//Number of instructions
#define NUMREGS 16				//Number of registers
#define SAME 0					//Used to strncmp
#define ERROR -1				//Used if invalid instruction/register

/* Define possible instructions. */
char *instructs[] = {"HALT","LOAD","ADD","SUB","MULT","DIV","AND","XOR","JUMP","CJMP","INC"};

/**
 * Function to get the minimum of two integers.
 * a: First argument.
 * b: Second argument.
 * return: Integer size of smaller of a and b.
**/
int get_min(int a,int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

/**
 * Function to get the instruction code
 * from the buffer.
 * instr: Pointer to array that holds the instruction.
 * return: Instruction code (integer from 0-15).
**/
int get_instr_code(char *instr)
{
	int instr_size = strlen(instr);		//Length of argument string.
	int MAXCHARS;				//Will hold max number of chars for strncmp.

	/* Iterate and find index for instruction */
	for (int codeNum = 0; codeNum < NUMCODES; codeNum++) 
	{
		MAXCHARS = get_min(instr_size,strlen(instructs[codeNum]));
	
		if (strncmp(instr,instructs[codeNum],MAXCHARS) == SAME) 
		{
			return codeNum;
		}
	}

	return ERROR;	
}

/**
 * Function to get the register code from
 * a string.
 * reg: Pointer to register string (R0,R1,..R15).
 * return: Register code (integer from 0-15). Long because using strtol.
**/
long int get_reg_code(char *reg)
{
	long reg_code;				//Will hold register code.
	char *ptr;				//Used with strtol.
	int BASE = 10;				//Used with strtol.
	
	/* Deal with empty case. */
	if (reg[0] == '\0') {
		return 0;
	}
	else
	{
		/* Grab the reg num - starts at index 1. */
		reg_code = strtol(&reg[1],&ptr,BASE);	
	}

	/* Error check. */
	if (reg_code < 0 || reg_code > 15)
	{
		return ERROR;
	}
	else
	{
		return reg_code;
	}	
}

/**
 * Function to get a constant number from a 
 * string (from instruction string).
 * num_str: Pointer to string containing the number.
 * return: Long int representation of number in string.
**/
long int get_const(char *num_str)
{
	int size = strlen(num_str);		//Size of str. Used for strncpy.
	char num[size + 1];			//Will hold the number str w/out # character.
	char *ptr;				//Used in calling strtol

	/* Deal with empty case. */
	if (num_str[0] == '\0') {
		return 0;
	}

	/* Cpy over string w/out # character. */
	strncpy(num,num_str + 1,size);		//Start from 1 since first char is #.
	num[size] = '\0';

	return strtol(num,&ptr,10);
}

/**
 * Function that accepts an input string (corresponding
 * to a single instruction line) and creates an array
 * containing the necessary op-codes for the resulting
 * hexadecimal instruction.
 * NOTE: op-code array in form {const_val,arg_reg1,
 * arg_reg2,dest_reg,instr}
 * input_str: Pointer to input string to parse for op-codes.
 * op_codes: Array of op-code values from input.
 * return: Void
**/
void create_opcode_arr(char *input_str,int op_codes[])
{
	/* Char array sizes for parsing. */
	int MAXINSTRSIZE = 4;			//Max instruction length. 
	int MAXREGSIZE = 3;			//Max register length.
	int MAXCNSTSIZE = 4;			//Max constant length.

	/* Char arrays for parsed input. */	
	char instr[MAXINSTRSIZE];		//Will hold instruction.
	char dest_reg[MAXREGSIZE];		//Will hold destination register.
	char arg_reg1[MAXREGSIZE];		//Will hold argument 1 register.
	char arg_reg2[MAXREGSIZE];		//Will hold argument 2 register.
	char cnst_num[MAXCNSTSIZE];		//Will hold the constant.

	/* Numbers for op-codes. */
	int instr_code;				//Op-code for instruction.
	int dest_reg_code;			//Op-code for destination register.
	int arg_reg1_code;			//Op-code for argument 1 register.
	int arg_reg2_code;			//Op-code for argument 2 register.
	int cnst_code;				//Op-code for constant number.

	/* Misc. */
	char *token;				//Token for parsing the input.

	/* Get the instruction op-code. */
	token = strtok(input_str," ");		//Assume space separated.
	strncpy(instr,token,strlen(token));
	instr_code = get_instr_code(instr);

	
	return;
	
}


/**
 * Function that accepts a result string and
 * op-code values and alters the string to contain
 * the corresponding hexadecimal instruction.
 * result: Pointer to result string (holds hex instruction).
 * op_codes: Array of op code values. In form {const_val..
 * ,arg_reg1,arg_reg2,dest_reg,instr}.
 * return: Void
**/
void codes_to_hex(char *result, int op_codes[])
{
	int arr_size = 5;			//5 op-codes total in array.
	int power;				//Will hold power used in multiplying op-code
	int res_num = op_codes[0];		//Holds resulting num to convert to hex. Init const val.
	long int factor;			//Will hold factor to multiply op-code by.
		
	/* Iterate through op_code array and compute hex equivalent. */
	for (int index = 1; index < arr_size; index++)
	{
		power = index - 1;		//Start w/ 16^0, then 16^1...
		factor = pow(16,power);

		res_num += op_codes[index] * factor;
	}

	/* Now copy hex result to result string. */
	sprintf(result,"0x%x",res_num);

	return;	
}

/*
 * Function to generate a hexadecimal instruction
 * string from an input line (from the assembly file).
 * input_str: Pointer to input string (from asm file).
 * result: Pointer to string that will contain hex instuct.
 * return: Void
**/
void create_hex_instr(char *input_str,char *result)
{
	int op_codes[5];			//Holds op-codes for instruction

	/* Generate the op-codes and result. */
	create_opcode_arr(input_str,op_codes);
	codes_to_hex(result,op_codes);

	return;
}	
	
	
