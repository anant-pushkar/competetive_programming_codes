/*
Project name : broken_monitor
Created on : Thu Dec 12 11:40:21 IST 2013
http://codeforces.com/problemset/problem/370/D

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
struct point{
	int x,y;
	point(int a,int b):
	x(a),y(b){}
};
bool compareX(const point &p1,const point &p2){
	return p1.x<p2.x;
}
bool compareY(const point &p1,const point &p2){
	return p1.y<p2.y;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m,count=0;scanf("%d %d",&n,&m);
	vector<vector<char> > screen(n,vector<char>(m));
	int minX=n+1,maxX=-1,minY=m+1,maxY=-1;
	char c;
	for(int i=0;i<n;++i){
		scanf("%c",&c);
		for(int j=0;j<m;++j){
			scanf("%c",&screen[i][j]);
			if(screen[i][j]=='w'){
				minX=minX<i?minX:i;
				minY=minY<j?minY:j;
				maxX=maxX>i?maxX:i;
				maxY=maxY>j?maxY:j;
				++count;
			}
		}
	}
	if(debug)cout<<"minX="<<minX<<" maxX="<<maxX<<" minY="<<minY<<" maxY="<<maxY<<endl;
	int check;
	if(maxX-minX>maxY-minY && maxX-minX<(n<m?n:m)){
		int y1=minY,y2=minY+(maxX-minX);
		while(y1>=0 && y2>=maxY){
			check=0;
			for(int i=minX+1;i<maxX && check==0;++i){
				for(int j=y1+1;j<m && j<y2 && check==0;++j){
					if(screen[i][j]=='w'){
						check=1;
						break;
					}
				}
			}
			if(check==0 && y2<m)break;
			--y1;--y2;
		}
		if(check==1)goto exit_label;
		minY=y1;maxY=y2;
	}else if(maxY-minY>maxX-minX && maxY-minY<(n<m?n:m)){
		int x1=minX,x2=minX+(maxY-minY);
		while(x1>=0 && x2>=maxX){
			check=0;
			for(int i=x1+1;i<n && i<x2 && check==0;++i){
				for(int j=minY+1;j<maxY && check==0;++j){
					if(screen[i][j]=='w'){
						check=1;
						break;
					}
				}
			}
			if(check==0 && x2<n)break;
			--x1;--x2;
		}
		if(check==1)goto exit_label;
		minX=x1;maxX=x2;
	}else if(maxX-minX==maxY-minY && maxX-minX<(n<m?n:m)){
		check=0;
		for(int i=minX+1;i<n && i<maxX && check==0;++i){
			for(int j=minY+1;j<maxY && check==0;++j){
				if(screen[i][j]=='w'){
					check=1;
					break;
				}
			}
		}
		if(check==1)goto exit_label;
	}
	else{
	exit_label:
		if(debug)cout<<"returning with minX="<<minX<<" maxX="<<maxX<<" minY="<<minY<<" maxY="<<maxY<<endl;
		printf("-1\n");
		return 0;
	}
	if(debug)cout<<"minX="<<minX<<" maxX="<<maxX<<" minY="<<minY<<" maxY="<<maxY<<endl;
	for(int i=minX;i<=maxX;++i)if(screen[i][minY]=='.')screen[i][minY]='+';
	for(int i=minX;i<=maxX;++i)if(screen[i][maxY]=='.')screen[i][maxY]='+';
	for(int i=minY;i<=maxY;++i)if(screen[minX][i]=='.')screen[minX][i]='+';
	for(int i=minY;i<=maxY;++i)if(screen[maxX][i]=='.')screen[maxX][i]='+';
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			printf("%c",screen[i][j]);
		}
		printf("\n");
	}
	return 0;
}

