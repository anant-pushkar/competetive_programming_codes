#include<stdio.h>
#include"nearestpt.h"
int main()
{
	int n;
	//printf("Enter number of points: ");
	scanf("%d",&n);
	Point *plane=generatePlane(n);
	Soln s=findClosest(plane,0,n);
	//printf("%f\n",dist);
	//printf("point %d %d 5 green|",(int)plane[s.i1].x,(int)plane[s.i1].y);
	//printf("point %d %d 5 green|",(int)plane[s.i2].x,(int)plane[s.i2].y);
	printf("txt 150 150 %f|",s.dist);
	printf("line %d %d %d %d red\n",(int)plane[s.i1].x,(int)plane[s.i1].y,(int)plane[s.i2].x,(int)plane[s.i2].y);
	free(plane);
	return 0;
}
