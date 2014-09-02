#pragma once
#include <igraph.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"
double ** label_arr;
double ** pre_cpy;
int* get_condition();
int* degree;
int* cId;
void init_label();
void free_label();
void propogate();
