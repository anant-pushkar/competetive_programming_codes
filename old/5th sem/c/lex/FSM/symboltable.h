#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
//each entry of symbol table
struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};
typedef struct entry_s entry_t;
//data structure for symboltable
struct hashtable_s {
	int size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;
hashtable_t *ht_create(int);
char *ht_get(hashtable_t*,char*);
void print_table(hashtable_t*,FILE*);
void ht_set(hashtable_t*,char*,char*);
hashtable_t *create_from_file(FILE *);