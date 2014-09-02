#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 127
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) {
		debug=1;
		--argc;
		++argv;
	}
	srand(time(NULL));
	int n=atoi(argv[1]),max,temp;
	int i,arr[n];
	if(debug)printf("Numbers generated : ");
	max=0;
	for(i=0;i<n;++i){
		arr[i]=rand()%MAX+1;
		if(debug)printf("%d ",arr[i]);
		max=max<arr[i]?arr[i]:max;
	}
	printf("\n");
	int interval=n,start=0;
	int pid=fork();
	if(pid==0)goto child;
	else{
		printf("Max calculated iteratively : %d\n",max);
		wait(&max);
		printf("Max calculated by the process tree %d\n",max>>8);
	}
	printf("Press any key to exit.\n");
	scanf("%d",&n);
	return 0;
	child:
	if(interval<10){
		max=0;
		int lim = n < start+interval ? n : start+interval ;
		for(i=start;i<lim;++i)max=max<arr[i]?arr[i]:max;
		exit(max);
	}else{
		interval=interval/2;
		pid=fork();
		if(pid==0)goto child;
		start+=interval;
		pid=fork();
		if(pid==0)goto child;
		wait(&max);max=max>>8;
		wait(&temp);temp=temp>>8;
		max=max<temp?temp:max;
		exit(max);
	}
}
