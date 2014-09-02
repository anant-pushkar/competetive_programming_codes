#pragma once
#include<time.h>
#include<stdlib.h>
typedef struct{
	double x;
	double y;
}Point;
typedef struct{
	int i1,i2;
	double dist;
} Soln;
Soln findClosest(Point *plane , int start , int end);
double distance(Point p1 , Point p2);
int compX(const void *p1 , const void *p2);
int compX(const void *p1 , const void *p2);
Point* getStrip(Point *plane , int start , int end);
Point *generatePlane(int n);