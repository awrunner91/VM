/**
 * Implementation file for parseFuncs.h
 * Author: Anthony Woods
 * Date: 2-24-2016
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
	int SAME = 0;				//Used for str comparisons.
	int ERROR = -1;				//Used if instruction not found.
	int NUMCODES = 3;			//Number of instructions/codes. CHANGE!!!!
	int instr_size = strlen(instr);		//Length of argument string.
	int MAXCHARS;				//Will hold max number of chars for strncmp.
	char *codes[] = {"HALT","LOAD","ADD"};	//Array of instructions.

	/* Iterate and find index for instruction */
	for (int codeNum = 0; codeNum < NUMCODES; codeNum++) 
	{
		MAXCHARS = get_min(instr_size,strlen(codes[codeNum]));	
	
		if (strncmp(instr,codes[codeNum],MAXCHARS) == SAME) 
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
 * return: Register code (integer from 0-15).
**/
int get_reg_code(char *reg)
{
	int SAME = 0;				//Used for str comparisons.
	int ERROR = -1;				//Used if register number is invalid.
	int NUMREGS = 4;			//Number of possible registers. CHANGE!!!!
	int MAXCHARS;				//Will hold max number of chars for strncmp.
	int reg_size = strlen(reg);		//Length of argument string.
	char *regs[] = {"R0","R1","R2","R3"};	//Array of registers.

	/* Deal with empty case. */
	if (reg[0] == '\0') {
		return 0;
	}

	/* Iterate and find index of register. */
	for (int regNum = 0; regNum < NUMREGS; regNum++) 
	{
		MAXCHARS = get_min(reg_size,strlen(regs[regNum]));

		if (strncmp(reg,regs[regNum],MAXCHARS) == SAME)
		{
			return regNum;
		}
	}

	return ERROR;
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
	/* Constants for initializing arrays. */
	const int MAXINSTRSIZE = 4;			//Max instruction length
	const int MAXREGSIZE = 3;			//Max register length
	const int MAXCONSTSIZE = 4;			//Max const number length
	
	/* Arrays to hold tokens. */
	char instr[MAXINSTRSIZE];			//Holds instruction
	char dest_reg[MAXREGSIZE];			//Holds destination register
	char arg_reg1[MAXREGSIZE];			//Holds argument register 1
	char arg_reg2[MAXREGSIZE];			//Holds argument register 2
	char cnst_num[MAXCONSTSIZE];			//Holds constant number from input

	/* Op-code variables. */
	int instr_code;					//Holds instruction code
	int dest_reg_code;				//Holds destination register code
	int arg_reg1_code;				//Holds argument register 1 code
	int arg_reg2_code;				//Holds argument register 2 code
	int cnst_num_code;				//Holds the constant number from instr
	
	/* Misc variables. */
	char *token;					//Will hold tokens from parsing input.
	int SAME = 0;					//Used for string comparison.
	int cmp_size;					//Used in strncmp.
	int cpy_size;					//Used in strncpy.

	/* Get instruction. */
	token = strtok(input_str," ");
	strncpy(instr,token,MAXINSTRSIZE);
	token = strtok(NULL," ");

	/* If HALT, other set op-codes to 0. */
	cmp_size = get_min(strlen(instr),strlen("HALT"));
	if (strncmp(instr,"HALT",cmp_size) == SAME)
	{
		instr_code = 0;
		dest_reg_code = 0;
		arg_reg1_code = 0;
		arg_reg2_code = 0;
		cnst_num_code = 0;
	}

	/* Not HALT, so get other codes. */	
	else
	{	
		strncpy(dest_reg,token,MAXREGSIZE);
		token = strtok(NULL," ");

		/* If no arg registers, get cnst_num. */
		if (strstr(token,"#") != NULL)
		{
			strncpy(cnst_num,token,MAXCONSTSIZE);
			printf("CNST: %s\n",cnst_num);
			arg_reg1[0] = '\0';
			arg_reg2[0] = '\0';
		}

		/* Grab arg registers if no cnst_num. */
		else
		{
			strncpy(arg_reg1,token,MAXREGSIZE);
			printf("REG 1 token: %s\n",token);
			token = strtok(NULL," ");
			printf("REG 2 token: %s\n",token);
			strncpy(arg_reg2,token,MAXREGSIZE);
			cnst_num[0] = '\0';
		}

		/* Generate op-codes and put in op_codes. */
		instr_code = get_instr_code(instr);
		dest_reg_code = get_reg_code(dest_reg);
		arg_reg1_code = get_reg_code(arg_reg1);
		arg_reg2_code = get_reg_code(arg_reg2);
		cnst_num_code = get_const(cnst_num);

	}

	/* Set all vals in op_code arr. */
	op_codes[0] = cnst_num_code;
	op_codes[1] = arg_reg2_code;
	op_codes[2] = arg_reg1_code;
	op_codes[3] = dest_reg_code;
	op_codes[4] = instr_code;

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
	
	
