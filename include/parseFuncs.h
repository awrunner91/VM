/**
 * Header file for parseFuncs.
 * Contains all function prototypes for 
 * parsing instructions.
 * Author: Anthony Woods
 * Date: 2-24-2016
**/

#ifndef PARSE_FUNCS
#define PARSE_FUNCS

/**
 * Function to get the instruction code
 * from a string.
 * instr: Pointer to array that holds the instruction.
 * return: Instruction code (integer from 0-15).
**/
int get_instr_code(char *instr);

/**
 * Function to get the register code from
 * a string.
 * reg: Pointer to register string (R0,R1,..R15).
 * return: Register code (integer from 0-15). Long because using strtol.
**/
long int get_reg_code(char *reg);

/**
 * Function to get a constant number from a 
 * string (from instruction string).
 * num_str: Pointer to string containing the number.
 * return: Integer representation of number in string.
**/
int get_const(char *num_str);

/**
 * Function that accepts a result string and
 * op-code values and alters the string to contain
 * the corresponding hexadecimal instruction.
 * result: Pointer to result string (holds hex instruction).
 * op_codes: Array of op-code values.
 * return: Void
**/
void codes_to_hex(char *result,int op_codes[]);

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
void create_opcode_arr(char *input_str,int op_codes[]);

/**
 * Function to generate a hexadecimal instruction
 * string from an input line (from the assembly file).
 * input_str: Pointer to input string (from asm file).
 * result: Pointer to string that will contain hex instuct.
 * return: Void
**/
void create_hex_instr(char *input_str,char *result);

/**
 * Function to get the minimum of two integers.
 * a: First argument.
 * b: Second argument.
 * return: Integer size of smaller of a and b.
**/
int get_min(int a,int b);

#endif
