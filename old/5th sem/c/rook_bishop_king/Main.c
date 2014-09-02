/*
Project name : rook_bishop_king
Created on : Wed Dec 11 14:35:16 IST 2013
http://codeforces.com/contest/370/problem/A

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int debug=0;
int r1,r2,c1,c2;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	int rm,bm,km;
	
	rm=(r1==r2?0:1) + (c1==c2?0:1);
	
	bm= (r1+r2+c1+c2)%2==1 ? 0 : abs(r2-r1)==abs(c2-c1) ? 1 : 2;
	
	km = (abs(r2-r1)>abs(c2-c1)?(int)abs(r2-r1):(int)abs(c2-c1));
	
	printf("%d %d %d\n",rm,bm,km);
	
	return 0;
}
