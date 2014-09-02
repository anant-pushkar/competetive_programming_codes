#pragma once
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
struct _nfa{
	queue **states;
	int *quants;
	int nStates;
};
typedef struct _nfa nfa;
nfa* createNFA(char *regex);
void printNFA(nfa *automata);