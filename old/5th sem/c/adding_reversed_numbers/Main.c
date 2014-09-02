/*
Project name : adding_reversed_numbers
Created on : Fri Dec  6 15:45:20 IST 2013
http://poj.org/problem?id=1504

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int  remove_zeros(int n){
	while(n%10==0)n=n/10;
	return n;
}
int reverse(int n){
	int m=0;
	remove_zeros(n);
	while(n>0){
		m=10*m+n%10;
		n=n/10;
	}
	return m;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n,a,b,c,d,s;scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		c=reverse(a);
		d=reverse(b);
		s=c+d;
		s=reverse(s);
		printf("%d\n",s);
	}
	return 0;
}
