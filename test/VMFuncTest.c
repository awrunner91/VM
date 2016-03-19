/**
 * Testing for VMFuncs.c
 * Author: Anthony Woods
 * Date: 3-12-2016
**/

#include "../include/VMFuncs.h"
#include <stdio.h>

int main()
{
	/* get_instr_num test */
	printf("GET INSTR NUM TEST!!\n");

	int halt = 0x0;		
	int load = 0x1123;
	int add  = 0x2123;
	int jump = 0xbb00;

	printf("DECODE FOR HALT: %d\n",get_instr_num(halt));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("DECODE FOR LOAD: %d\n",get_instr_num(load));
	printf("EXPECTED: 1\n");
	printf("\n");

	printf("DECODE FOR ADD: %d\n",get_instr_num(add));
	printf("EXPECTED: 2\n");
	printf("\n");

	printf("DECODE FOR JUMP: %d\n",get_instr_num(jump));
	printf("EXPECTED: 11\n");
	printf("\n");

	/* get_dr_num test */
	printf("GET DR NUM TEST!!\n");
	
	int drt1 = 0x0011;
	int drt2 = 0x1312;
	int drt3 = 0xaa21;
	int drt4 = 0xbfab;

	printf("DEST REG FOR 0x0011: %d\n",get_dr_num(drt1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("DEST REG FOR 0x1312: %d\n",get_dr_num(drt2));
	printf("EXPECTED: 3\n");
	printf("\n");

	printf("DEST REG FOR 0xaa21: %d\n",get_dr_num(drt3));
	printf("EXPECTED: 10\n");
	printf("\n");

	printf("DEST REG FOR 0xbfab: %d\n",get_dr_num(drt4));
	printf("EXPECTED: 15\n");
	printf("\n");

	/* get_argreg1_num test */
	printf("GET AGR REG 1 TEST!!\n");

	int r1t1 = 0xab01;
	int r1t2 = 0x115a;
	int r1t3 = 0xa7fa;

	printf("ARG REG 1 FOR 0xab01: %d\n",get_argreg1_num(r1t1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("ARG REG 1 FOR 0x115a: %d\n",get_argreg1_num(r1t2));
	printf("EXPECTED: 5\n");
	printf("\n");

	printf("ARG REG 1 FOR 0xa7fa: %d\n",get_argreg1_num(r1t3));
	printf("EXPECTED: 15\n");
	printf("\n");

	/* get_argreg2_num test */
	printf("ARG REG 2 TEST!!\n");
	
	int r2t1 = 0xaba0;
	int r2t2 = 0x0127;
	int r2t3 = 0x01bf;

	printf("ARG REG 2 FOR 0xaba0: %d\n",get_argreg2_num(r2t1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("ARG REG 2 FOR 0x0127: %d\n",get_argreg2_num(r2t2));
	printf("EXPECTED: 7\n");
	printf("\n");

	printf("ARG REG 2 FOR 0x01bf: %d\n",get_argreg2_num(r2t3));
	printf("EXPECTED: 15\n");
	printf("\n");

	/* get_cnst_num test */
	printf("GET CNST NUM TEST!!\n");
	
	int ct1 = 0xab00;
	int ct2 = 0x0107;
	int ct3 = 0x1fa0;
	int ct4 = 0xadff;

	printf("CNST NUM FOR 0xab00: %d\n",get_cnst_num(ct1));
	printf("EXPECTED: 0\n");
	printf("\n");

	printf("CNST NUM FOR 0x0107: %d\n",get_cnst_num(ct2));
	printf("EXPECTED: 7\n");
	printf("\n");
	
	printf("CNST NUM FOR 0x1fa0: %d\n",get_cnst_num(ct3));
	printf("EXPECTED: 160\n");
	printf("\n");

	printf("CNST NUM FOR 0xadff: %d\n",get_cnst_num(ct4));
	printf("EXPECTED: 255\n");
	printf("\n");

	/* execute_instr test */




	return 0;
}
