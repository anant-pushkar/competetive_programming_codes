#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t){
		int x1,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("line %d %d %d %d|",x1,y1,x1,y2);
		printf("line %d %d %d %d|",x1,y1,x2,y1);
		printf("line %d %d %d %d|",x2,y2,x1,y2);
		printf("line %d %d %d %d blue|",x2,y2,x1,y1);
		printf("line %d %d %d %d blue|",x1,y2,x2,y1);
		printf("point %d %d %d yellow|",(x1+x2)/2,(y1+y2)/2,10);
		printf("txt %d %d yo_yo|",(x1+x2)/2,(y1+y2)/2);
		printf("line %d %d %d %d",x2,y2,x2,y1);
		printf("\n");
		--t;
	}
	return 0;
}

