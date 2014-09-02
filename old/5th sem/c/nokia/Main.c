#include<stdio.h>
#include<stdlib.h>
int getSoln(int,int);
int arr[1001][1001];
void init();
void fillArr(int, int, int, int);
int main()
{
	int T,t,N,M;
	init();
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		scanf("%d %d",&N,&M);
		printf("%d\n",getSoln(N,M));
	}
	return 0;
}
void fillArr(int val, int count, int x, int y)
{
	
}
void init()
{
	arr[0][0]=2;arr[0][1]=-1;
	arr[1][0]=5;arr[1][0]=-1;
	arr[2][0]=8;arr[2][1]=9;arr[2][2]=-1;
	
}
int getSoln(const int n ,const int m)
{
	int soln=0;
	
	return soln;
}