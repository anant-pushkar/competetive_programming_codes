#include<stdio.h>
#include<stdlib.h>
#include"hull.h"
int main()
{
	int n;
	printf("Enter number of points : ");
	scanf("%d",&n);
	
	Point *plane=generatePlane(n);
	Hull  *hull=getHull(plane,0,n);
	printf("Hull generated with test value : %d\n\n",testHull(plane,n,hull));
	
	return 0;
}
