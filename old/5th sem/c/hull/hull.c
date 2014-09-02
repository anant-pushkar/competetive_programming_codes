#include<time.h>
#include<stdio.h>
#include"hull.h"
#define MAXX 1000
#define MAXY 1000
int compX(const void*p1 , const void *p2)
{
	return ((Point*)p1)->x - ((Point*)p2)->x ;
}
void printPlane(Point* plane , int n)
{
	int i;
	for(i=0;i<n;i++) printf("\t#%d (%f,%f)\n",i,plane[i].x,plane[i].y);
}
Point* generatePlane(int n)
{
	srand(time(NULL));
	int i;
	Point * plane=(Point*)calloc(n,sizeof(Point));
	for(i=0;i<n;i++){
		plane[i].x = rand()%MAXX;
		plane[i].y = rand()%MAXY;
	}
	qsort(plane,n,sizeof(Point),compX);
	printf("Points generated and sorted are:\n");printPlane(plane,n);
	return plane;
}
Hull * generateHull(Point* plane , int n1 , int n2 , int n3)
{
	Point *set = (Point*)calloc(3,sizeof(Point));
	double crossPro = (plane[n1].x-plane[n2].x)*(plane[n1].y-plane[n3].y)-(plane[n1].x-plane[n3].x)*(plane[n1].y-plane[n2].y);
	set[0] = plane[n1];
	set[1] = plane[(crossPro>0 ? n2 : n3)];
	set[2] = plane[(crossPro>0 ? n3 : n2)];
	
	printf("Generating  hull for (%f,%f) , (%f,%f) , (%f,%f).\n",set[0].x,set[0].y,set[1].x,set[1].y,set[2].x,set[2].y);
	Hull *hull   = (Hull*)malloc(sizeof(Hull));
	hull->ptSet  = set;
	hull->count  = 3;
	hull->present= 0;
	return hull;
}
Point *getPresent(Hull* hull)
{
	printf("Hull at : %d\n",hull->present);
	return hull->ptSet+hull->present;
}
Point *advanceForward(Hull *hull)
{
	printf("Advancing forward . ");
	hull->present++;
	hull->present = hull->present%hull->count;
	return getPresent(hull);
}
Point *advanceBackward(Hull *hull)
{	
	printf("Advancing backward . ");
	hull->present--;
	hull->present+= hull->count;
	hull->present = hull->present%hull->count;
	return getPresent(hull);
}
Point *getNext(Hull *hull)
{
	return hull->ptSet + (hull->present+1)%hull->count;
}
Point *getPrevious(Hull *hull)
{
	return hull->ptSet + (hull->present-1+hull->count)%hull->count;
}
Point *goToRightmost(Hull* hull)
{
	printf("Getting to right most");
	Point *pt = getPresent(hull);
	while(pt->x <= getNext(hull)->x || pt->x <=getPrevious(hull)->x){
		pt = advanceForward(hull);
		printf(".");
	}
	printf("\n");
	return pt;
}
Point *goToLeftmost(Hull *hull)
{	
	printf("Getting to left most");
	Point *pt = getPresent(hull);
	while(pt->x >= getNext(hull)->x || pt->x >= getPrevious(hull)->x){
		pt = advanceForward(hull);
		printf(".");
	}
	printf("\n");
	return pt;
}
int getSide(Point *p1 , Point *p2 , Point *p3)
{
	return (p3->x-p1->x)*(p2->y-p1->y)-(p3->y-p1->y)*(p2->x-p1->x);
}
int checkSide(Point *p1 , Point *p2 , Point *p3 , Point *p4)
{
	return getSide(p1,p2,p3)*getSide(p1,p2,p4)>0 ? 1 : -1 ;
}
Hull *mergeHull(Hull *h1 , Hull *h2)
{
	Point *p1 = goToRightmost(h1);
	Point *p2 = goToLeftmost(h2) ;
	
	printf("Merging hulls.\n");
	//till both hulls lye on different sides of line joining p1 and p2
	while(checkSide(p1,p2,getNext(h1),getPrevious(h1))+checkSide(p1,p2,getNext(h2),getPrevious(h2)) < 0){
		p1 = advanceForward(h1);
		//printf("advancing h1 forward till both hulls lye on different sides of line joining p1 and p2 for first point\n");
	}
	
	//till exactly one of the hulls completely lyes to one side
	while(checkSide(p1,p2,getNext(h2),getPrevious(h2)) == -1){
		p2 = advanceBackward(h2);
		printf("advancing h2 backward till exactly one of the hulls completely lyes to one side for first point\n");
	}
	while(h1->count>2 && checkSide(p1,p2,getNext(h1),getPrevious(h1)) == -1){
		p1 = advanceForward(h1);
		printf("advancing h1 forward till exactly one of the hulls completely lyes to one side for first point\n");
	}
	int i1 = h1->present , i2 = h2->present;
	
	p1 = goToRightmost(h1);
	p2 = goToLeftmost(h2) ;
	
	//till both hulls lye on different sides of line joining p1 and p2
	while(checkSide(p1,p2,getNext(h1),getPrevious(h1))+checkSide(p1,p2,getNext(h2),getPrevious(h2)) < 0){
		p1 = advanceBackward(h1);
		printf("advancing h1 backword till both hulls lye on different sides of line joining p1 and p2 for second point\n");
	}
	//till exactly one of the hulls completely lyes to one side
	while(checkSide(p1,p2,getNext(h2),getPrevious(h2)) == -1){
		p2 = advanceForward(h2);
		printf("Advancing h2 forward till exactly one of the hulls completely lyes to one side for second point\n");
	}
	while(h1->count>2 && checkSide(p1,p2,getNext(h1),getPrevious(h1)) == -1){
		p1 = advanceBackward(h1);
		printf("advancing h1 backward till exactly one of the hulls completely lyes to one side for second point\n");
	}
		
	int i3 = h1->present , i4 = h2->present ;
	p1 = goToRightmost(h1);
	p2 = goToLeftmost(h2) ;
	
	int i5 = h1->present , i6 = h2->present , count=0; 
	count+=(i5<=3 && i5>=i1) ? h1->count-i3+i1+1 : i1-i3+1 ;
	count+=(i6<i4 && i6>=i2) ? h2->count-i4+i2+1 : i2-i4+1 ;
	
	int index=0;
	Point *ptset = (Point*)calloc(count,sizeof(Point));
	
	while(h1->present!=i1 && h1->present!=i3) p1=advanceForward(h1);
	do{
		ptset[index].x = p1->x;
		ptset[index].y = p1->y;
		index++;
		p1=advanceForward(h1);
	}while(h1->present!=i1 && h1->present!=i3);
	
	while(h2->present!=i2 && h2->present!=i4) p2=advanceForward(h2);
	do{
		ptset[index].x = p2->x;
		ptset[index].y = p2->y;
		index++;
		p2=advanceForward(h2);
	}while(h2->present!=i2 && h2->present!=i4);
	
	free(h1->ptSet);free(h2->ptSet);
	free(h1);free(h2);
	
	Hull* h   = (Hull*)malloc(sizeof(Hull));
	h->count  = index;
	h->ptSet  = ptset;
	h->present= 0;
	printf("points in merged hull: \n");printPlane(h->ptSet,h->count);
	
	return h;
}
Hull* getHull(Point *plane , int start , int end){
	int span = end-start;
	printf("getHull() called on %d,%d.\n",start,end);
	if(span == 3)return generateHull(plane,start,start+1,start+2);
	if(span<3 && span>0 ){
		int index  = start,i;
		
		Point *set = (Point*)calloc(span,sizeof(Point));
		for(i=0;index<end;i++) set[i]=plane[index++];
		
		Hull *h   = (Hull*)malloc(sizeof(Hull));
		h->count  = span;
		h->ptSet  = set ;
		h->present=0;
		return h;
	}
	if(span<=0) return NULL;
	int mid = (start+end)>>1;
	Hull *h1 = getHull(plane,start,mid);
	printf("points in left hull: \n");printPlane(h1->ptSet,h1->count);
	printf("\n\n");
	Hull *h2 = getHull(plane, mid ,end);
	printf("points in right hull: \n");printPlane(h2->ptSet,h2->count);
	
	return mergeHull(h1,h2);
}
int testHull(Point *plane , int n , Hull *h)
{
	int index=h->present , i=0 , side=0 , temp , check;
	do{
		i=0;side=0;check=0;
		while(side==0) side=getSide(getPresent(h),getNext(h),&plane[i++]);
		side = side<0 ? -1 : 1 ;
		while(i<n){
			temp=0;
			while(temp==0) temp=getSide(getPresent(h),getNext(h),&plane[i++]);
			if(temp*side<0){
				check=1;
				break;
			}
		}
		if(check==1) break;
		advanceForward(h);
	}while(index!=h->present);
	return check==0;
}














