#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
#define LStart 1
#define LEnd 2
#define SStart 3
#define SEnd 4
#define None 0
typedef struct{
	int val , type , other;
} Cell;
Cell *board;
void refresh(){
	int i=1;
	for(;i<101;++i){
		board[i].val = 100;
		board[i].type= None;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,nSnakes,nLadders,start,end,i,j,min,index;scanf("%d",&t);
	board = (Cell*)calloc(101,sizeof(Cell));
	while(t--){
		refresh();
		scanf("%d,%d",&nSnakes,&nLadders);
		while(nLadders--){
			scanf("%d,%d",&start,&end);
			board[start].type = LStart;
			board[end].other  = start;
			board[end].type   = LEnd;
		}
		while(nSnakes--){
			scanf("%d,%d",&start,&end);
			board[start].type = SStart;
			board[end].other  = start;
			board[end].type   = SEnd;
		}
		board[1].val=0;
		int check=0;
		while(check==0){
			check=1;
			for(i=2;i<101;++i){
				min=100;index=-1;
				for(j=i-1;j>0 && j>=i-6;--j)if(board[j].type!=SStart && board[j].type!=LStart){
					if(min>board[j].val+1){
						min=board[j].val+1;
						index=j;
					}
				}
				if(board[i].type==SEnd && min>board[board[i].other].val){
					min=board[board[i].other].val;
					index=board[i].other;
				}
				if(board[i].val>min){
					board[i].val=min;
					check=0;
				}
				if(debug)printf("%d:%d from %d\n",i,min,index);
			}
			for(i=2;i<101;++i){
				if(board[i].type==LEnd && board[i].val>board[board[i].other].val){
					board[i].val=board[board[i].other].val;
					check=0;
				}
			}
		}
		printf("%d\n",board[100].val);
	}
	return 0;
}
