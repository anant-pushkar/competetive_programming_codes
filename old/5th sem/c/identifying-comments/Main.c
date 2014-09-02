#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	char c;
	int state=0;
	while( scanf( "%c", &c)) {
		if(feof(stdin))break;
		switch(c){
		case '/':
			printf("/");
			if(state==0 || state==1){
				++state;
			}
			if(state==4){	
				scanf( "%c", &c);
				if(c=='\n')printf("\n");
				state=0;
			}
			break;
		case '*':
			printf("*");
			if(state==1 || state==4){
				state=3;
			}
			if(state==3){
				state=4;
			}
			break;
		default:
			if(state==2){
				printf("%c",c);
				if(c=='\n')state=0;
			}
			if(state==3){
				printf("%c",c);
			}
			if(state==4){
				printf("%c",c);
				state=3;
			}
			break;
		}
	}
	return 0;
}
