#include "opencv2/opencv.hpp"
#include "StdAfx.h"
#include <vector>
#include <cv.h>
#include <cv.hpp>
#include <cxcore.h>
#include <highgui.h>
#include <iostream>
#include <utility>
#include <math.h>
#include <time.h>  
#include <algorithm>
#include <stack>
using namespace std; 
using namespace cv;

pair<int , int> pivot;//to store bottom  most point
stack< pair<int , int> > hull;//stack to store hull
const int frameSize=600;//size of display window
const double PI = 3.141592653589793238462;
vector< pair <int,int> > points;//vector to store points randomly generated
Mat img=Mat::zeros(frameSize,frameSize, CV_8UC1);//ouput image

/*
 * function to draw filled circles of given radius to mark a point
 */
void drawFilledCircle( Mat img, Point center ,int radius)
{
 int thickness = -1;//default thickness
 int lineType = 8;

 circle( img,
         center,
         radius,
         255,
         thickness,
         lineType );
}

/*
 * function to draw line of given  thickness and shade
 */
void drawLine( Mat img, Point start, Point end ,int shade,int thickness)
{
  int lineType = 8;
  shade=shade%256;
  line( img,
    start,
    end,
    shade,
    thickness,
    lineType );
}

/*
 * function to return angle between given points
 */
float getAngle(pair<int,int> p1 , pair<int,int>p2){
	return atan2(static_cast<double>(p1.second-p2.second) , static_cast<double>(p1.first-p2.first))*180/PI;
}

/*
 * function to compare points on the basis of polarangles, used to sort points
 */
bool compareFunction(pair<int,int> p1 , pair<int,int> p2){
	return ( getAngle(p1,pivot)>getAngle(p2,pivot) );
}

/*
 * print location of mouse click
 */
void mouseEvent(int evt, int x, int y, int flags, void* param){
    if(evt==CV_EVENT_LBUTTONDOWN){
        cout<<"Click at : ( "<<(x-frameSize/2)<<" , "<<(y-frameSize/2)<<" ) , Polar Angle: "<<getAngle(make_pair(x,y),pivot)<<endl;
    }
}

/*
 * prompt user to enter number of points and xdraw the points on the frame
 */
void setUpFrame(){
	int n;
	cout<<"Enter number of points: ";
	cin>>n;

	for(int i=0;i<n;i++)
		points.push_back(make_pair((rand()%static_cast<int>(frameSize*0.75) +frameSize*0.125) , (rand()%static_cast<int>(frameSize*0.75)  +frameSize*0.125)));

	for(int i=0;i<n;i++)
		drawFilledCircle( img, Point(points[i].first, points[i].second) ,2);
	drawLine(img , Point(frameSize/2,0) , Point(frameSize/2,frameSize),100,1);
	drawLine(img , Point(0,frameSize/2) , Point(frameSize,frameSize/2),100,1);

	cout<<"Settingup frame...\nPress enter to continue."<<endl;
}

/* 
 * select bottom most point (pivot)
 */
void setPivot(){
	int max=-2*frameSize , index=0;
	for(int i=0;i<points.size();i++){
		if(points[i].second>max){
			max=points[i].second;
			index=i;
		}
	}
	pivot=points[index];
	points.erase(points.begin()+index);

	drawFilledCircle( img, Point(pivot.first, pivot.second) ,6);
	cout<<"Pivot chosen at: ( "<<(pivot.first-frameSize/2)<<" , "<<(pivot.second-frameSize/2)<<" )\nPress enter to continue."<<endl;
}

/*
 * sort points on the basis of polar angle
 */
void sortPoints(){
	cout<<"Sorting points on the basis of polar angles."<<endl;
	std::sort(points.begin(),points.end(),compareFunction);
}

/*
 * use stack to store hull points
 */
void createHull(){
	hull.push(pivot);
	hull.push(points[0]);
	pair<int ,int> previous,temp;
	int x1,x2,y1,y2;

	//push pivot and point[1] (innitialization for the loop) 
	hull.push(pivot);
	hull.push(points[0]);

	previous=pivot;

	for(int i=1;i<points.size();i++){
		do{
			x1=previous.first-hull.top().first;
			y1=previous.second-hull.top().second;
			x2=hull.top().first-points[i].first;
			y2=hull.top().second-points[i].second;

			if(x1*y2-x2*y1 >= 0)
				hull.pop();//pop the point pushed to the stack in previous loop if a left turn is observed

			//reset loop parameters
			temp=hull.top();
			hull.pop();
			previous=hull.top();
			hull.push(temp);

		}while(x1*y2-x2*y1 >= 0);

		previous=hull.top();
		hull.push(points[i]);
	}
}
/*
 * draw hull to the frame
 */
void drawHull(){
	int size=hull.size();
	pair<int,int> pt;
	drawLine(img,Point(pivot.first,pivot.second),Point(hull.top().first,hull.top().second),200,1);
	for(int i=1;i<size;i++){
		drawFilledCircle( img, Point(hull.top().first, hull.top().second) ,4);
		pt=hull.top();
		hull.pop();
		drawLine(img,Point(pt.first,pt.second),Point(hull.top().first,hull.top().second),200,1);
	}
	drawLine(img,Point(pivot.first,pivot.second),Point(hull.top().first,hull.top().second),200,1);
}

int main(int, char**)
{
	srand (time(NULL));
	namedWindow("Output",1);
	cvSetMouseCallback("Output", mouseEvent, 0);

	setUpFrame();
	setPivot();
	sortPoints();
	createHull();
	drawHull();

    imshow("Output", img);
	waitKey(0);
    return 0;
}
