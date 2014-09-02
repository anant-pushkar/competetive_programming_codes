/*
Project name : berland_bingo
Created on : Wed Dec 11 14:56:12 IST 2013
http://codeforces.com/contest/370/problem/B

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n,**list;scanf("%d",&n);
	list=(int**)calloc(n+1,sizeof(int));
	int i,m,j,a,c1,c2,c3,c4;
	int *a1=(int*)calloc(101,sizeof(int)),*a2=(int*)calloc(101,sizeof(int)),*a3=(int*)calloc(101,sizeof(int)),*a4=(int*)calloc(101,sizeof(int));
	for(i=1;i<=n;++i){
		scanf("%d",&m);
		list[i]=(int*)calloc(m+1,sizeof(int));
		list[i][0]=m;
		if(i<30){
			c1=1<<i;
			c2=0;
			c3=0;
			c4=0;
		}else if(i<60){
			c1=0;
			c2=1<<(i-30);
			c3=0;
			c4=0;
		}else if(i<90){
			c1=0;
			c2=0;
			c3=1<<(i-60);
			c4=0;
		}else{
			c1=0;
			c2=0;
			c3=0;
			c4=1<<(i-90);
		}
		for(j=0;j<m;++j){
			scanf("%d",&a);
			list[i][j+1]=a;
			a1[a]=a1[a]|c1;
			a2[a]=a2[a]|c2;
			a3[a]=a3[a]|c3;
			a4[a]=a4[a]|c4;
		}
	}
	int *lookup=(int*)calloc(n+1,sizeof(int));
	int mask;
	for(i=1;i<=n;++i){
		c1=-1;
		c2=-1;
		c3=-1;
		c4=-1;
		for(j=1;j<=list[i][0];++j){
			c1=c1&a1[list[i][j]];
			c2=c2&a2[list[i][j]];
			c3=c3&a3[list[i][j]];
			c4=c4&a4[list[i][j]];
		}
		if((i<30 && c1==(1<<i) && c2+c3+c4==0) || (i>=30 && i<60 && c1+c3+c4==0 && c2==(1<<(i-30)) || (i>=60 && i<90 && c1+c2+c4==0 && c3==1<<(i-60)) || (i>=90 && c1+c2+c3==0 && c4==i<<(i-90) )));
		else{
			for(j=1;j<30 && j<=n;++j){
				mask=1<<j;
				if(c1&mask && i!=j){
					lookup[j]=1;
				}
			}
			for(j=30;j<60 && j<=n;++j){
				mask=1<<(j-30);
				if(c2&mask && i!=j){
					lookup[j]=1;
				}
			}
			for(j=60;j<90 && j<=n;++j){
				mask=1<<(j-60);
				if(c3&mask && i!=j){
					lookup[j]=1;
				}
			}
			for(j=90;j<=n;++j){
				mask=1<<(j-90);
				if(c4&mask && i!=j){
					lookup[j]=1;
				}
			}
		}
	}
	for(i=1;i<=n;++i){
		if(lookup[i])printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
