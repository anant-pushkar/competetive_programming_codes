#include"wave.h"
#include<time.h>
#include<math.h>
#include<stdlib.h>
extern int window_width , window_height;
const int freq_scale=2 , const_freq_scale=200;
int freq[5];
void create_original(){
	int i;
	original.n_points=window_width;
	original.x=(int*)calloc(original.n_points,sizeof(int));
	original.y=(int*)calloc(original.n_points,sizeof(int));
	
	//generate 5 sets of waves
	int x1[original.n_points],y1[original.n_points];
	srand(time(NULL));
		int r =  rand()%(window_height);
		int s =  rand()%10;
		s = s*freq_scale+1;
		freq[0]=10*s;
		int t =  rand()%10+1;
	for (i = 0; i < window_width; ++i)
	{
		x1[i] = i;
		y1[i] = r*sin(((0.31415926*i)/s) + (0.31415926/t));
	}
	
	int x2[original.n_points],y2[original.n_points];
	//srand(time(NULL));
		r =  rand()%(window_height/2);
		s =  rand()%10;
		s = s*freq_scale+1;
		freq[1]=10*s;
		t =  rand()%10+1;
	for (i = 0; i < window_width; ++i)
	{
		x2[i] = i;
		y2[i] = r*sin(((0.31415926*i)/s) + (0.31415926/t));
	}

	int x3[original.n_points],y3[original.n_points];
	//srand(time(NULL));
		r =  rand()%(window_height/2);
		s =  rand()%10;
		s = s*freq_scale+1;
		freq[2]=10*s;
		t =  rand()%10+1;
	for (i = 0; i < window_width; ++i)
	{
		x3[i] = i;
		y3[i] = r*sin(((0.31415926*i)/s) + (0.31415926/t));
	}

	int x4[original.n_points],y4[original.n_points];
	//srand(time(NULL));
		r =  rand()%(window_height/2);
		s =  rand()%10;
		s = s*freq_scale+1;
		freq[3]=10*s;
		t =  rand()%10+1;
	for (i = 0; i < window_width; ++i)
	{
		x4[i] = i;
		y4[i] = r*sin(((0.31415926*i)/s) + (0.31415926/t));
	}
	int x5[original.n_points],y5[original.n_points];
	//srand(time(NULL));
		r =  rand()%(window_height/2);
		s =  rand()%10;
		s = s*freq_scale+1;
		freq[4]=10*s;
		t =  rand()%10+1;
	for (i = 0; i < window_width; ++i)
	{
		x5[i] = i;
		y5[i] = r*sin(((0.31415926*i)/s) + (0.31415926/t));
	}
	for(i=0;i<original.n_points;++i){
		original.x[i]=i;
		original.y[i]=(y1[i]+y2[i]+y3[i]+y4[i]+y5[i])/5+window_height/2;
	}
	
}