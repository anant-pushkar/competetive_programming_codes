#pragma once
#include<stdlib.h>
typedef struct{
	double x;
	double y;
} Point;
typedef struct{
	Point *ptSet;
	int   count;
	int   present;
} Hull;
Point *generatePlane(int);
Hull  *getHull(Point*,int,int);
int    testHull(Point*,int,Hull*);