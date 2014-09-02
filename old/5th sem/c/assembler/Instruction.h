#pragma once
#include"symboltable.h"
#include<stdio.h>
#include<stdlib.h>
struct _instruction{
	char label[20];
	char op[20];//OPeration to be performed
	char operand[20];
	int  lineNum;//line number for error reporting
	long int loc;//location counter value
	char address[6];
	struct _instruction *next;
	char objCode[10];
	char error[100];
};
typedef struct _instruction Instruction;
struct _macro{
	Instruction *start;
	Instruction *end;
	char *label;
	char *operand;
	hashtable_t *symbol_table;
};
typedef struct _macro Macro;
struct _macro_lookup{
	int size;
	hashtable_t* label_table;
	Macro * arr;
};
typedef struct _macro_lookup MacroLookup;
Instruction *generateScanner(FILE*);
Instruction *getConverter(FILE*);
