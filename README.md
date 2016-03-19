# VM
C Assembler and VM with 15 instructions and 16 registers (R0-R15):

INSTRUCTIONS (and example syntax for use):
HALT (HALT)           : Halts the program.
LOAD (LOAD R1 #12)    : Loads the number 12 into register 1.
ADD  (ADD R0 R12 R3)  : Adds the values in R12 and R3 and stores the result in R0.
SUB  (SUB R1 R3 R5)   : Subtracts the value in R5 from R3 and stores the result in R1.
MULT (MULT R0 R1 R2)  : Multiplies the values in R1 and R2 and stores the result in R0.
DIV  (DIV R3 R6 R8)   : Divides (integer) the value in R6 by the value in R8 and stores the result in R3.
AND  (AND R1 R2 R3)   : Does bitwise AND between the values in R2 and R3 and stores the result in R1.
OR   (OR R7 R8 R9)    : Does bitwise OR between the values in R8 and R9 and stores the result in R7.
CMP  (CMP R1 R2 R3)   : Compares the values in R2 and R3. Stores (1,0,-1) in R1 if (R2 > R3, R2 = R3, R2 < R3).
GJMP (GJMP R3 R5 R7)  : Greater than conditional jump. Jumps to instruction addr in R3 if R5 > R7.
EJMP (EJMP R1 R2 R3)  : Equal conditional jump. Jumps to instruction addr in R1 if R2 = R3.
LJMP (LJMP R0 R7 R8)  : Less than consitional jump. Jumps to instruction addr in R0 if R7 < R8.
INC  (INC R2)         : Increments the value stored in R2 by 1.
NOT  (NOT R7)         : Bitwise not of the value stored in R7.
JUMP (JUMP R5)        : Jumps to instruction addr stored in R7.

To use the Assembler/VM, first generate a text file (such as input.txt) using the above syntax and store
in /src. To parse this and create the hexaecimal output, type in the following into the terminal:

./parser < input.txt

This will generate a file output.txt. Then, to run the instructions, type:

./VM < output.txt

Note that, by default, the value stored in R0 is printed at the end. Therefore, if you dont want to change
the src code, store your final result in this register.
