# Makefile for src code

CC=gcc
CFLAGS=-c

all: parser VMFuncs.o VM

parser: parser.o parseFuncs.o
	$(CC) -o parser parser.o parseFuncs.o

parser.o: parser.c
	$(CC) $(CFLAGS) parser.c

parseFuncs.o: parseFuncs.c
	$(CC) $(CFLAGS) parseFuncs.c

VMFuncs.o: VMFuncs.c
	$(CC) $(CFLAGS) VMFuncs.c

VM: VM.o VMFuncs.o
	$(CC) -o VM VM.o VMFuncs.o
VM.o: VM.c
	$(CC) $(CFLAGS) VM.c
