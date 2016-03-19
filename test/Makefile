#Makefile for all tests

CC=gcc
CFLAGS=-o

all: parseFuncTest VMFuncTest

parseFuncTest: parseFuncTest.c ../src/parseFuncs.o
	$(CC) $(CFLAGS) parseFuncTest parseFuncTest.c ../src/parseFuncs.o

VMFuncTest: VMFuncTest.c ../src/VMFuncs.o
	$(CC) $(CFLAGS) VMFuncTest VMFuncTest.c ../src/VMFuncs.o
