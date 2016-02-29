/**
 * Tests for functions defined in parseFuncs.h
 * Author: Anthony Woods
 * Date: 2-24-2016
**/

#include <stdio.h>
#include <stdlib.h>
#include "../include/parseFuncs.h"

int main()
{
	
	//get_instr_code test
	char c1[] = "HALT";
	char c2[] = "LOAD";
	char c3[] = "XOR";
	char c4[] = "CJMP";
	char c5[] = "INC";

	printf("INSTRUCTION CODE FOR HALT: %d\n",get_instr_code(c1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("INSTRUCTION CODE FOR LOAD: %d\n",get_instr_code(c2));
	printf("EXPECTED: 1\n");
	printf("\n");

	printf("INSTRUCTION CODE FOR XOR: %d\n",get_instr_code(c3));
	printf("EXPECTED: 7\n");
	printf("\n");

	printf("INSTRUCTION CODE FOR CJMP: %d\n",get_instr_code(c4));
	printf("EXPECTED: 9\n");
	printf("\n");

	printf("INSTRUCTION CODE FOR INC: %d\n",get_instr_code(c5));
	printf("EXPECTED: 10\n");
	printf("\n");

	//get_reg_code test
	char r1[] = "R0";
	char r2[] = "R7";
	char r3[] = "R13";
	char r4[] = "R15";
	char r5[] = "R16";

	printf("REG CODE FOR R0: %ld\n",get_reg_code(r1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("REG CODE FOR R7: %ld\n",get_reg_code(r2));
	printf("EXPECTED: 7\n");
	printf("\n");

	printf("REG CODE FOR R13: %ld\n",get_reg_code(r3));
	printf("EXPECTED: 13\n");
	printf("\n");

	printf("REG CODE FOR R15: %ld\n",get_reg_code(r4));
	printf("EXPECTED: 15\n");
	printf("\n");

	printf("REG CODE FOR R16: %ld\n",get_reg_code(r5));
	printf("EXPECTED: -1\n");
	printf("\n");

	//get_const test
	char cn1[] = "#0";
	char cn2[] = "#7";
	char cn3[] = "#13";
	char cn4[] = "#128";
	char cn5[] = "#255";

	printf("CNST CODE FOR #0: %d\n",get_const(cn1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("CNST CODE FOR #7: %d\n",get_const(cn2));
	printf("EXPECTED: 7\n");
	printf("\n");

	printf("CNST CODE FOR #13: %d\n",get_const(cn3));
	printf("EXPECTED: 13\n");
	printf("\n");

	printf("CNST CODE FOR #128: %d\n",get_const(cn4));
	printf("EXPECTED: 128\n");
	printf("\n");

	printf("CNST CODE FOR #255: %d\n",get_const(cn5));
	printf("EXPECTED: 255\n");
	printf("\n");

	//create_opcode_arr test
	char i1[] = "HALT";
	char i2[] = "LOAD R2 #158";
	char i3[] = "MULT R2 R5 R13";
	char i4[] = "LOAD R15 #17";

	//create_hex_instr test.
	char res[6];

	create_hex_instr(i3,res);
	printf("HEX INSTR FOR MULT R2 R5 R13: %s\n",res);
	printf("EXPECTED: 0x425d\n");
	



	return 0;


}
