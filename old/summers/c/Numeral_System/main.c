/*
Project name : Numeral_System
Created on : Thu Jun 12 14:37:37 2014
Author : Anant Pushkar
http://www.spoj.com/problems/NSYSTEM/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
char symbol[4] = {'i','x','c','m'};
int getVal(char mcxi[9]){
	if(debug)printf("Getting Val for %s\n",mcxi);
	int val=0 , place=3 , placeVal=1000 , faceVal , i=0 , len = strlen(mcxi);
	while(i<len){
		if(mcxi[i]==symbol[place]){
			faceVal = 1;
		}else if(mcxi[i]>='0' && mcxi[i]<='9' && mcxi[i+1]==symbol[place]){
			faceVal = mcxi[i]-'0';
			++i;
		}else{
			faceVal = 0;
			--i;
		}
		val += faceVal*placeVal;
		placeVal /= 10;
		--place;
		++i;
	}
	if(debug)printf("returning %d\n",val);
	return val;
}
char *getMCXI(int val){
	if(debug)printf("Getting MCXI for %d\n",val);
	int  faceVal[4]={0,0,0,0} , place=0;
	while(val>0){
		faceVal[place] = val%10;
		++place;
		val /= 10;
	}
	if(debug){
		int i;
		printf("faceVal : ");
		for(i=3;i>-1;--i)printf("%d ",faceVal[i]);
		printf("\n");
	}
	char *mcxi = (char*) calloc(9,sizeof(char));
	int index=0;
	place=3;
	while(place>-1){
		if(faceVal[place]!=0){
			if(faceVal[place]>1){
				mcxi[index++] = (char)(faceVal[place]+'0');
			}
			mcxi[index++] = symbol[place];
		}
		--place;
	}
	return mcxi;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , val1 , val2 ;
	scanf("%d",&t);
	char mcxi1[9] , mcxi2[9] , *mcxiSum;
	while(t--){
		scanf("%s",mcxi1);
		scanf("%s",mcxi2);
		
		val1 = getVal(mcxi1);
		val2 = getVal(mcxi2);
		
		mcxiSum = getMCXI(val1+val2);
		printf("%s\n",mcxiSum);
		free(mcxiSum);
	}
	return 0;
}
