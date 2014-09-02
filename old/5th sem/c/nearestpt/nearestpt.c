#include"nearestpt.h"
#include<stdio.h>
#include<math.h>
Soln findClosest(Point *plane , int start , int end)
{
	if(end-start==3){
		double d1 = distance(plane[start]  , plane[start+1]);
		double d2 = distance(plane[start]  , plane[start+2]);
		double d3 = distance(plane[start+1], plane[start+2]);
		Soln s;
		if(d1<d2){
			s.dist=d1;
			s.i1=start;
			s.i2=start+1;
		}else{
			s.dist=d2;
			s.i1=start;
			s.i2=start+2;
		}
		if(s.dist>d3){
			s.dist=d3;
			s.i1=start+1;
			s.i2=start+2;
		}
		//printf("Returning from %d,%d with 3 points\n",start,end);
		return s;
	}
	if(end-start==2){
		//printf("Returning from %d,%d with 2 points\n",start,end);
		Soln s;
		s.dist=distance(plane[start] , plane[start+1]);
		s.i1=start;
		s.i2=start+1;
		return s;
	}
	//printf("findClosest called on %d,%d\n",start,end);
	int mid   = (start+end)>>1 , il=-1 , ir=-1 , i ;
	
	Soln sl=findClosest(plane,start,mid),sr=findClosest(plane,mid,end),s;
	double d;
	if(sl.dist<sr.dist){
		d=sl.dist;
		s=sl;
	}else{
		d=sr.dist;
		s=sr;
	}
	if(d==0)return s;
	
	for(i=start;i<end;i++){
		//printf("Finding Strip.\n");
		if(il==-1 && plane[i].x >= plane[mid].x-d) il=i;
		if(ir==-1 && plane[i].x >  plane[mid].x+d) {ir=i;break;}
	}
	
	if(il==-1 || ir==-1){
		//printf("Returning findClosest on %d,%d with %f because of empty strip.\n",start,end,d);
		return s;
	}
	Point *leftStrip  = getStrip(plane, il, mid);
	Point *rightStrip = getStrip(plane,mid, ir );
	int i1,i2;
	
	int indexL = 0 , indexR=0 , span=0;
	double dist= d , temp;
	while(indexL<mid-il && indexR<ir-mid){
		span=0;
		while(indexR<ir-mid && rightStrip[indexR].y < leftStrip[indexL].y-d) indexR++;
		 //printf("Traversing Strip at %d,%d within limit %d,%d.\n",indexL,indexR,mid-il,ir-mid);
		while(indexR+span<ir-mid && rightStrip[indexR+span].y <= leftStrip[indexL].y+d){
			temp = distance(rightStrip[indexR+span],leftStrip[indexL]);
			span++;
			if(dist > temp){
				dist=temp ;
				i1=indexR+span;
				i2=indexL;
			}
			//printf("dist assigned to %f\n",dist);
		}
		if(dist==0) break;
		indexL++;
	}
	//printf("Returning findClosest on %d,%d with %f\n",start,end,dist);
	if(dist==d)return s;
	else{
		s.dist=dist;
		int it=start;
		for(;it<end;++it){
			if(plane[it].x==rightStrip[i1].x && plane[it].y==rightStrip[i1].y)i1=it;
			if(plane[it].x==leftStrip[i2].x && plane[it].y==leftStrip[i2].y)i2=it;
		}
		s.i1=i1;
		s.i2=i2;
		return s;
	}
}
double distance(Point p1 , Point p2)
{
	double dist=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
	if(dist<0);//printf("dist between %d,%d and %d,%d found to be %f\n",p1.x,p1.y,p2.x,p2.y,dist);
	else dist=sqrt(dist);
	return dist;
}
int compX(const void *p1 , const void *p2)
{
	return ((Point*)p1)->x - ((Point*)p2)->x ;
}
int compY(const void *p1 , const void *p2)
{
	return ((Point*)p1)->y - ((Point*)p2)->y ;
}
Point* getStrip(Point *plane , int start , int end)
{
	//printf("Generating Strip from %d,%d.\n",start,end);
	Point *strip=(Point*)calloc(end-start,sizeof(Point));
	int i;
	for(i=start;i<end;i++) strip[i-start]=plane[i];
	//printf("Sorting points in strip.\n");
	qsort(strip,end-start,sizeof(Point),compY);
	//printf("Strip generated.\n");
	return strip;
}
#define MAXX 300
#define MAXY 300
Point *generatePlane(int n)
{
	//printf("Generating plane.\n");
	srand(time(NULL));
	int i;
	Point *plane=(Point*)calloc(n,sizeof(Point));
	for(i=0;i<n;i++){
		plane[i].x=rand()%MAXX+30;
		plane[i].y=rand()%MAXY+30;
		printf("point %d %d 7 green|",(int)plane[i].x,(int)plane[i].y);
		//printf("point %d %d 2|",(int)plane[i].x,(int)plane[i].y);
		printf("txt %d %d %d|",(int)plane[i].x,(int)plane[i].y,i);
	}
	qsort(plane,n,sizeof(Point),compX);
	//printf("X-coordinates are: ");
	//for(i=0;i<n;i++) printf("%d ",plane[i]);
	//printf("\n");
	return plane;
}















