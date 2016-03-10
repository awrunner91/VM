# Makefile for src code

CC=gcc
CFLAGS=-c

all: parser

parser: parser.o parseFuncs.o
	$(CC) -o parser parser.o parseFuncs.o

parser.o: parser.c
	$(CC) $(CFLAGS) parser.c

parseFuncs.o: parseFuncs.c
	$(CC) $(CFLAGS) parseFuncs.c
