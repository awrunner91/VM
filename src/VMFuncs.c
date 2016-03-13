/**
 * Implementation file for VMFuncs.h
 * Author: Anthony Woods
 * Date: 3-12-2016
**/

#include <stdio.h>
#include <stdlib.h>
#include "../include/VMFuncs.h"
#include <stdbool.h>

#define ERROR -1					//For error in decoding.

/**
 * Function that accepts a instruction code
 * and returns the instruction number (0-15).
 * code_num: Integer representation of hex code.
 * return: Instruction number (0-15). INVALID (-1)
 * if not a valid instruction.
**/
int get_instr_num(int code_num)
{
	int instr_num = (code_num & 0xF000) >> 12;	//Last 4 bits.

	if (instr_num < 0 || instr_num > 15)
	{
		return ERROR;
	}
	else
	{
		return instr_num;
	}
}

/**
 * Function that accepts a instruction code
 * and returns the destination register number
 * (0-15).
 * code_num: Integer representation of hex code.
 * return: Destination register number (0-15). INVALID
 * (-1) if not a valid register.
**/
int get_dr_num(int code_num)
{
	int dr = (code_num & 0xF00) >> 8;		//Bits 8-11.

	if (dr < 0 || dr > 15)
	{
		return ERROR;
	}
	else
	{
		return dr;
	}
}

/**
 * Function that accepts a instruction code
 * and returns the first argument register
 * number (0-15).
 * code_num: Integer representation of hex code.
 * return: Argument register1 number (0-15). INVALID
 * (-1) if not a valid register.
**/
int get_argreg1_num(int code_num)
{
	int arg_reg1_num = (code_num & 0xF0) >> 4;	//Bits 4-7

	if (arg_reg1_num < 0 || arg_reg1_num > 15)
	{
		return ERROR;
	}
	else
	{
		return arg_reg1_num;
	}
}

/**
 * Function that accepts a instruction code
 * and returns the second argument register
 * number (0-15).
 * code_num: Integer representation of hex code.
 * return: Argument register2 number (0-15). INVALID
 * (-1) if not a valid register.
**/
int get_argreg2_num(int code_num)
{
	int arg_reg2_num = (0xF & code_num);		//Bits 0-3

	if (arg_reg2_num < 0 || arg_reg2_num > 15)
	{
		return ERROR;
	}
	else
	{
		return arg_reg2_num;
	}
}

/**
 * Function that accepts a instruction code
 * and returns the constant number argument
 * from the instruction.
 * code_num: Integer representation of hex code.
 * return: Constant number argument from instruction.
**/
int get_cnst_num(int code_num)
{
	int cnst_num = (0xFF & code_num);		//Bits 0-7

	return cnst_num;
}

/**
 * Function that executes an instruction.
 * code: Integer hex code.
 * reg_arr: Register array.
 * done: Pointer to done boolean (terminates program).
 * pc: Pointer to program counter.
 * return: None.
**/
void execute_instr(int code, int reg_arr[], int *done, int *pc)
{
	/* Decode */
	int instr_num = get_instr_num(code);
	int dest_reg = get_dr_num(code);
	int arg_reg1 = get_argreg1_num(code);
	int arg_reg2 = get_argreg2_num(code);
	int cnst_val = get_cnst_num(code);

	int res;				//Result of computation for add,mul..

	switch(instr_num)
	{
		/* HALT */
		case 0:
			*done = true;
			printf("PROGRAM FINISHED\n");
			break;
		
		/* LOAD */
		case 1:
			reg_arr[dest_reg] = cnst_val;
			break;

		/* ADD */
		case 2:
			res = reg_arr[arg_reg1] + reg_arr[arg_reg2];
			reg_arr[dest_reg] = res;
			break;

		/* SUB */
		case 3:
			res = reg_arr[arg_reg1] - reg_arr[arg_reg2];
			reg_arr[dest_reg] = result;
			break;

		/* MULT */
		case 4:
			res = reg_arr[arg_reg1] * reg_arr[arg_reg2];
			reg_arr[dest_reg] = result;
			break;

		/* DIV */
		case 5:
			res = reg_arr[arg_reg1] / reg_arr[arg_reg2];
			reg_arr[dest_reg] = res;
			break;

		/* AND */
		case 6:
			res = reg_arr[arg_reg1] & reg_arr[arg_reg2];
			reg_add[dest_reg] = res;
			break;

		/* OR */
		case 7:
			res = reg_arr[arg_reg1] | reg_arr[arg_reg2];
			reg_add[dest_reg] = res;
			break;
	}
}

