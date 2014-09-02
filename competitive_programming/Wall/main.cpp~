/*
Project name : Wall
Created on : Sun Aug 31 11:57:42 2014
Author : Anant Pushkar
http://www.codechef.com/LTIME15/problems/WALL
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	lld h , n , m , a , b , ind;
	vector<lld> d ;
	lld next_x(lld x , lld i){
		return x + d[i];
	} 
	lld next_ind(lld i){
		return (a*i+b)%m;
	}
	double get_area(){
		lld a=0 , b , c , i , count=2;
		
		b = next_x(a,ind);
		i = next_ind(ind);
		
		double area=0;
		if(debug)cout<<a<<" "<<b<<" ";
		while(count<n){
			c = next_x(b,i);
			i = next_ind(i);
			if(debug)cout<<c<<" ";
			
			area += static_cast<double>(c-a)/2*h;
			
			a = c;
			b = next_x(a,i);
			i = next_ind(i);
			count += 2;
		}
		if(n%2==0){
			area += static_cast<double>(b-a)/2*h;
		}
		if(debug)cout<<endl;
		return area;
	}
public:
	Solver(){
		scanf("%lld",&h);
		scanf("%lld %lld",&n,&m);
		scanf("%lld %lld %lld",&a,&b,&ind);
		
		d = vector<lld>(m);
		for(int i=0;i<m;++i){
			scanf("%lld",&d[i]);
		}
	}
	void print_soln(){
		printf("%0.1f\n",get_area());
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	while(t--){
		Solver s;
		s.print_soln();
	}
	
	return 0;
}

