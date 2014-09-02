/*
Project name : Pyramids
Created on : Wed May 28 14:42:32 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PIR/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	int u , v , w , U , V , W;
	double x , y , z , X , Y , Z , a , b , c , d , vol;
	while(t--){
		scanf("%d %d %d %d %d %d" , &U , &V , &w , &W , &v , &u);
		
		X = (w-U+v)*(U+v+w);
		x = (U-v+w)*(v-w+U);
		
		Y = (u-V+w)*(u+V+w);
		y = (V-w+u)*(w-u+V);
		
		Z = (v-W+u)*(v+W+u);
		z = (W-u+v)*(u-v+W);
		
		a = sqrt(x*Y*Z);
		b = sqrt(y*Z*X);
		c = sqrt(z*X*Y);
		d = sqrt(x*y*z);
		
		if(debug){
			printf("X %lf\n",X);
			printf("x %lf\n",x);
			printf("Y %lf\n",Y);
			printf("y %lf\n",y);
			printf("Z %lf\n",Z);
			printf("z %lf\n",z);
			printf("a %lf\n",a);
			printf("b %lf\n",b);
			printf("c %lf\n",c);
			printf("d %lf\n",d);
		}
		
		vol = sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192*u*v*w);
		printf("%f\n",(float)vol);
	}
	return 0;
}
