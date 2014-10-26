/*
Project name : Closest_Point_Pair
Created on : Wed Oct 22 14:14:27 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CLOPPAIR/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<set>
#include<iomanip>
#include<cmath>
#define px first
#define py second.first
#define id second.second
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
typedef pair<lld , pair<lld,int> > Point;
const lld INF = 2000000000001ll;
lld dist(Point p1 , Point p2){
	return (p1.px-p2.px)*(p1.px-p2.px) + (p1.py-p2.py)*(p1.py-p2.py);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	cin>>n;
	
	vector<Point> pt(n);
	for(int i=0;i<n;++i){
		cin>>pt[i].px>>pt[i].py;
		pt[i].id = i;
	}
	sort(pt.begin() , pt.end());
	
	lld best=INF;
	Point p;
	set<Point> box;
	box.insert(pt[0]);
	int left=0 , index;
	for(int i=1;i<n;++i){
		while(left<i && pt[left].px>=pt[i].px+best){
			box.erase(pt[left++]);
		}
		for(set<Point>::iterator it=box.lower_bound(make_pair(pt[i].px-best , make_pair(pt[i].py-best,-1)));it!=box.end() && it->px<=pt[i].px+best ; ++it){
			if(best>dist(pt[i] , *it)){
				best = dist(pt[i] , *it);
				index = i;
			}
		}
		box.insert(pt[i]);
	}
	
	for(int i=0;i<n;++i)if(i!=index && dist(pt[i] , pt[index])==best){
		if(debug)cout<<pt[i].px<<","<<pt[i].py<<" "<<pt[index].px<<","<<pt[index].py<<endl;
		cout<<min(pt[i].id,pt[index].id)<<" "<<max(pt[i].id,pt[index].id)<<" "<<setprecision(12)<<sqrtl(best)<<endl;
		break;
	}
	
	return 0;
}

