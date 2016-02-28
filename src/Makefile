# Makefile for src code

CC=gcc
CFLAGS=-c

all: 

parseFuncs.o: parseFuncs.c
	$(CC) $(CFLAGS) parseFuncs.c

parser.o: parser.c parseFuncs.o
	$(CC) $(CFLAGS) parser.c parseFuncs.o 
