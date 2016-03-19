/**
 * Header file for VMFuncs.
 * Contains all function prototypes for 
 * VM functions.
 * Author: Anthony Woods
 * Date: 3-11-2016
**/

#ifndef VM_FUNCS
#define VM_FUNCS

#include <stdbool.h>

/**
 * Function that accepts a instruction code
 * and returns the instruction number (0-15).
 * code_num: Integer representation of hex code.
 * return: Instruction number (0-15). INVALID (-1)
 * if not a valid instruction.
**/
int get_instr_num(int code_num);

/**
 * Function that accepts a instruction code
 * and returns the destination register number
 * (0-15).
 * code_num: Integer representation of hex code.
 * return: Destination register number (0-15). INVALID
 * (-1) if not a valid register.
**/
int get_dr_num(int code_num);

/**
 * Function that accepts a instruction code
 * and returns the first argument register
 * number (0-15).
 * code_num: Integer representation of hex code.
 * return: Argument register1 number (0-15). INVALID
 * (-1) if not a valid register.
**/
int get_argreg1_num(int code_num);

/**
 * Function that accepts a instruction code
 * and returns the second argument register
 * number (0-15).
 * code_num: Integer representation of hex code.
 * return: Argument register2 number (0-15). INVALID
 * (-1) if not a valid register.
**/
int get_argreg2_num(int code_num);

/**
 * Function that accepts a instruction code
 * and returns the constant number argument
 * from the instruction.
 * code_num: Integer representation of hex code.
 * return: Constant number argument from instruction.
**/
int get_cnst_num(int code_num);

/**
 * Function that executes an instruction.
 * code: Integer hex code.
 * reg_arr: Register array.
 * done: Pointer to done boolean (terminates program).
 * pc: Pointer to program counter.
 * return: None.
**/
void execute_instr(int code, int reg_arr[], bool *done, int *pc);


#endif
