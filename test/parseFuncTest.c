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
	//Tests for get_instr_code
	printf("\n");
	printf("INSTRUCTION CODE TEST\n");

	char *c1 = "HALT";
	char *c2 = "LOAD";
	char *c3 = "ADD";

	printf("INSTRUCTION CODE FOR HALT: %d\n",get_instr_code(c1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("INSTRUCTION CODE FOR LOAD: %d\n",get_instr_code(c2));
	printf("EXPECTED: 1\n");
	printf("\n");

	printf("INSTRUCTION CODE FOR ADD: %d\n",get_instr_code(c3));
	printf("EXPECTED: 2\n");
	printf("\n");

	//Tests for get_reg_code
	printf("REGISTER CODE TEST\n");

	char *r0 = "R0";
	char *r1 = "R1";
	char *r2 = "R2";
	char *r3 = "R3";

	printf("REGISTER CODE FOR R0: %d\n",get_reg_code(r0));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("REGISTER CODE FOR R1: %d\n",get_reg_code(r1));
	printf("EXPECTED: 1\n");
	printf("\n");

	printf("REGISTER CODE FOR R2: %d\n",get_reg_code(r2));
	printf("EXPECTED: 2\n");
	printf("\n");

	printf("REGISTER CODE FOR R3: %d\n",get_reg_code(r3));
	printf("EXPECTED: 3\n");
	printf("\n");

	//Tests for get_const
	printf("GET CONSTANT TEST\n");
	
	char *n0 = "#0";
	char *n1 = "#7";
	char *n2 = "#12";
	char *n3 = "#144";
	char *n4 = "";

	printf("NUMBER FOR %s: %d\n",n4,get_const(n4));
	printf("EXPECTED: 0\n");
	printf("\n");

	//Tests for codes_to_hex and create_opcode_arr
	printf("CODE TO HEX TEST AND CREATE OPCODE ARR TEST\n");

	//Tests for create_hex_instr
	char i1[] = "HALT";
	char i2[] = "LOAD R0 R3 R2";
	char i3[] = "ADD R1 R3 R2";
	char i4[] = "LOAD R3 #188";

	char hex_result[20];

	//test1
	create_hex_instr(i1,hex_result);
	printf("INSTRUCTION: %s\n",hex_result);
	printf("EXPECTED: 0x0\n");
	printf("\n");

	//test2
	create_hex_instr(i2,hex_result);
	printf("INSTRUCTION: %s\n",hex_result);
	printf("EXPECTED: 0x1032\n");
	printf("\n");

	//test3
	create_hex_instr(i3,hex_result);
	printf("INSTRUCTION: %s\n",hex_result);
	printf("EXPECTED: 0x2132\n");
	printf("\n");

	//test4
	create_hex_instr(i4,hex_result);
	printf("INSTRUCTION: %s\n",hex_result);
	printf("EXPECTED: 0x13bc\n");
	printf("\n");
	
	return 0;


}
