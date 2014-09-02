#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int n , a, b, c, min, *lookup;
int getCount(int num){
	if(num<0 || lookup[num]==-1)return -1;
	if(lookup[num]>1)return lookup[num];
	int c1=getCount(num-a);
	int c2=getCount(num-b);
	int c3=getCount(num-c);
	c1 = c1!=-1 ? c1+1 : -1;
	c2 = c2!=-1 ? c2+1 : -1;
	c3 = c3!=-1 ? c3+1 : -1;
	int max = c1>c2 ? c1 : c2 ;
	max = max>c3 ? max : c3 ;
	lookup[num]=max>lookup[num] ? max : lookup[num] ;
	lookup[num]=lookup[num]==0 ? -1 : lookup[num];
	return lookup[num];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	lookup=(int*)calloc(n+1,sizeof(int));
	if(a<=n)lookup[a]=1;
	if(b<=n)lookup[b]=1;
	if(c<=n)lookup[c]=1;
	min = a<b ? a : b ;
	min = min<c ? min : c ;
	int i=0;
	for(;i<min;++i)lookup[i]=-1;
	printf("%d\n",getCount(n));
	if(debug)for(i=0;i<n+1;++i)printf("%d:%d\n",i,lookup[i]);
	return 0;
}
