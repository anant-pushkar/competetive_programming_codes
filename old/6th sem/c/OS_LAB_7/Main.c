/*
Project name : OS_LAB_7
Created on : Sat Apr 12 17:53:37 2014
Author : Anant Pushkar
calculate page replecement policy efficiency
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
void lf(FILE *fptr){
	int nPages , nFrames;
	fscanf(fptr,"%d",&nPages);
	fscanf(fptr,"%d",&nFrames);
	
	int i , p , j , count=0 , check , min;
	int list[nFrames] , freq[nFrames] , index=0;
	for(i=0;i<nFrames;++i){
		list[i]=-1;
		freq[i]=0;
	}
	for(i=0;i<nPages;++i){
		fscanf(fptr,"%d",&p);
		if(debug){
			printf("FRAMES : ");
			for(j=0;j<nFrames;++j)printf("%d  " , list[j]);
			printf("\n");
			printf("FREQ   : ");
			for(j=0;j<nFrames;++j)printf("%d  " , freq[j]);
			printf("\nLooking for : %d\n",p);
		}
		check=0;
		for(j=0;j<nFrames;++j)if(list[j]==p){
			if(debug)printf("Page found\n\n\n");
			check=1;
			++freq[j];
			break;
		}
		if(check)continue;
		if(debug)printf("Page not found\n\n\n");
		++count;
		min=1<<30;
		for(j=0;j<nFrames;++j)if(min>freq[j]){
			min=freq[j];
			index=j;
		}
		list[index]=p;
		freq[index]=1;
	}
	printf("LFU : Number of page faults : %d\n" , count);
}
void lr(FILE *fptr){
	int nPages , nFrames;
	fscanf(fptr,"%d",&nPages);
	fscanf(fptr,"%d",&nFrames);
	
	int i , p , j , count=0 , check , min;
	int list[nFrames] , freq[nFrames] , index=0;
	for(i=0;i<nFrames;++i){
		list[i]=-1;
		freq[i]=0;
	}
	for(i=0;i<nPages;++i){
		fscanf(fptr,"%d",&p);
		if(debug){
			printf("FRAMES : ");
			for(j=0;j<nFrames;++j)printf("%d  " , list[j]);
			printf("\n");
			printf("USE   : ");
			for(j=0;j<nFrames;++j)printf("%d  " , freq[j]);
			printf("\nLooking for : %d\n",p);
		}
		check=0;
		for(j=0;j<nFrames;++j)if(list[j]==p){
			if(debug)printf("Page found\n\n\n");
			check=1;
			freq[j] = i;
			break;
		}
		if(check)continue;
		if(debug)printf("Page not found\n\n\n");
		++count;
		min=1<<30;
		for(j=0;j<nFrames;++j)if(min>freq[j]){
			min=freq[j];
			index=j;
		}
		list[index]=p;
		freq[index]=1;
	}
	printf("LRU : Number of page faults : %d\n" , count);
}
void ff(FILE* fptr){
	int nPages , nFrames;
	fscanf(fptr,"%d",&nPages);
	fscanf(fptr,"%d",&nFrames);
	
	int i , p , j , count=0 , check;
	int list[nFrames] , index=0;
	for(i=0;i<nFrames;++i)list[i]=-1;
	for(i=0;i<nPages;++i){
		fscanf(fptr,"%d",&p);
		if(debug){
			printf("FRAMES : ");
			for(j=0;j<nFrames;++j)printf("%d " , list[j]);
			printf("\nLooking for : %d\n",p);
		}
		check=0;
		for(j=0;j<nFrames;++j)if(list[j]==p){
			if(debug)printf("Page found\n\n\n");
			check=1;
			break;
		}
		if(check)continue;
		if(debug)printf("Page not found\n\n\n");
		++count;
		list[index]=p;
		index=(index+1)%nFrames;
	}
	printf("FIFO : Number of page faults : %d\n" , count);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) {
		debug=1;
		argc--;
		argv++;
	}
	
	FILE *fptr;
	int index = argc;
	while(index>0){
		fptr = fopen(argv[1] , "r");
		char *algo = argv[--index];
		if(strcmp(algo , "FF")==0)ff(fptr);
		else if(strcmp(algo , "LF")==0)lf(fptr);
		else if(strcmp(algo , "LR")==0)lr(fptr);
		fclose(fptr);
	}
	
	return 0;
}
