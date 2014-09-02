#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int * * grid;
	int * * dist;
	int deadline , x , y , m , n;
}Dungeon;
#define MAX 100000
void init(Dungeon *d){
	scanf("%d %d" , &d->m , &d->n );
	d->grid = (int**)calloc(d->m , sizeof(int*) );
	d->dist = (int**)calloc(d->m , sizeof(int*) );
	int i=0,j;
	for(;i<d->m;++i){
		d->grid[i] = (int*)calloc(d->n , sizeof(int) );
		d->dist[i] = (int*)calloc(d->n , sizeof(int) );
	}
	for(i=0 ; i<d->m ; ++i){
		for(j=0 ; j<d->n ; ++j){
			scanf("%d",&d->grid[i][j]);
		}
	}
	scanf("%d %d %d", &d->x , &d->y , &d->deadline);
	--d->x;--d->y;
	for(i=0 ; i<d->m ; ++i){
		for(j=0 ; j<d->n ; ++j){
			d->dist[i][j]=MAX;
		}
	}
	d->dist[0][0] = 0;
	d->dist[1][0] = d->grid[0][0];
	d->dist[0][1] = d->grid[0][0];
}
int relax(Dungeon *d){
	int k,i,j,dist,new,count=0;
	for(i=0;i<d->m;++i){
		for(j=0;j<d->n;++j){
			if(i+1<d->m){
				dist = d->dist[i+1][j];
				new  = d->dist[i][j] + d->grid[i][j] ;
				if(new<dist){
					//printf("at %d,%d from %d,%d , %d->%d\n",i+1,j,i,j,dist,new);
					d->dist[i+1][j] = new ;
					++count;
				}
			}
			if(i-1>-1){
				dist = d->dist[i-1][j];
				new  = d->dist[i][j] + d->grid[i][j] ;
				if(new<dist){
					//printf("at %d,%d from %d,%d , %d->%d\n",i-1,j,i,j,dist,new);
					d->dist[i-1][j] = new ;
					++count;
				}
			}
			if(j+1<d->n){
				dist = d->dist[i][j+1];
				new  = d->dist[i][j] + d->grid[i][j] ;
				if(new<dist){
					//printf("at %d,%d from %d,%d , %d->%d\n",i,j+1,i,j,dist,new);
					d->dist[i][j+1] = new ;
					++count;
				}
			}
			if(j-1>-1){
				dist = d->dist[i][j-1];
				new  = d->dist[i][j] + d->grid[i][j] ;
				if(new<dist){
					//printf("at %d,%d from %d,%d , %d->%d\n",i,j-1,i,j,dist,new);
					d->dist[i][j-1] = new ;
					++count;
				}
			}
		}
	}
	return count;
}
void print_dist(Dungeon *d){
	int i,j;
	for(i=0;i<d->m;++i){
		for(j=0;j<d->n;++j){
			printf("%d\t",d->dist[i][j]);
		}
		printf("\n");
	}
}
int solve(Dungeon *d){
	int count;
	do{
		//print_dist(d);
		count=relax(d);
		//printf("count:%d\n\n",count);
	}while(count!=0);
	//print_dist(d);
	return d->deadline-d->dist[d->x][d->y]-d->grid[d->x][d->y];
}
int main()
{
	int t,time;scanf("%d",&t);
	Dungeon d;
	while(t){
		init(&d);
		time=solve(&d);
		if(time>0){
			printf("YES\n%d\n",time);
		}else{
			printf("NO\n");
		}
		--t;
	}
	return 0;
}
