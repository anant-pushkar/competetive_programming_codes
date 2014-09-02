/*
Project name : Pouring_water
Created on : Wed Jun 11 16:46:16 2014
Author : Anant Pushkar
http://www.spoj.com/problems/POUR1/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
bool debug=false;
typedef long long int lld;
struct _coeff{
	int x,y,c;
};
typedef struct _coeff Coeff;
Coeff getCoeff(int a , int b){
	Coeff coeff;
	if(a%b==0){
		coeff.x = -1;
		coeff.y = a/b+1;
		coeff.c = b;
		return coeff;
	}
	coeff = getCoeff(b,a%b);
	int x = coeff.x , y = coeff.y;
	coeff.x = y;
	coeff.y = x-y*(a/b) ;
	return coeff;
}
class Problem{
	int v1,v2,target,lim,n;
	queue<int> q1,q2,d;
	vector<vector<bool> > lookup;
	int hcf(int a , int b){
		if(b==0)return a;
		return hcf(b,a%b);
	}
	void propogate(int a,int b){
		if(debug)cout<<"Attempting to push"<<a<<" "<<b<<" lookup="<<lookup[a][b]<<" d="<<d.front()<<" lim = "<<lim<<endl;
		if(d.front()<lim && !lookup[a][b]){
			if(debug)cout<<"Pushing "<<a<<" "<<b<<endl;
			q1.push(a);
			q2.push(b);
			lookup[a][b]=true;
			d.push(d.front()+1);
		}
	}
	void setLim(int a , int b , int c){
		/*if(a<b){
			a = a^b;
			b = a^b;
			a = a^b;
		}*/
		int x,y;
		Coeff coeff = getCoeff(a,b);
		n = coeff.c;
		if(debug)printf("%d*%d + %d*%d = %d\n",coeff.x,a,coeff.y,b,coeff.c);
		x = coeff.x * (c/coeff.c);
		y = coeff.y * (c/coeff.c);
		if(debug)printf("%d*%d + %d*%d = %d\n",x,a,y,b,c);
		x = x>0 ? x : -x;
		y = y>0 ? y : -y;
		x = x%(b/coeff.c);
		y = y%(a/coeff.c);
		if(debug)printf("%d %d\n",x,y);
		lim = lim>x+2*y-1 ? x+2*y-1 : lim;
	}
public:
	Problem(int a , int b , int c):
	v1(a),
	v2(b),
	target(c){
		if(v1<v2){
			v1=v1^v2;
			v2=v1^v2;
			v1=v1^v2;
		}
		lookup=vector<vector<bool> >(v1+1,vector<bool>(v2+1,false));
		q1.push(0);
		q2.push(0);
		if(debug)cout<<"Going to push to d"<<endl;
		d.push(0);
		if(debug)cout<<"Pushed to d"<<endl;
		lookup[0][0]=true;
		lim = INT_MAX;
		setLim(v1,v2,target);
		setLim(v2,v1,target);
	}
	int solve(){
		if(target>v1)return -1;
		if(debug)cout<<"Target not greater than v1"<<endl;
		if(v1==target || v2==target)
			return 1;
		if(target%n!=0)return -1;
		if(target%(v1-v2)==0 && lim>3*target/(v1-v2))
			return 3*(target/(v1-v2));
		return lim;
		/*if(debug)cout<<"Target is divisible by gcd"<<endl;
		v1/=n;
		v2/=n;
		target/=n;
		int a,b;
		while(!d.empty()){
			a=q1.front();q1.pop();
			b=q2.front();q2.pop();
			if(debug)cout<<"Currently at "<<a<<" "<<b<<endl;
			if(a==target || b==target)return d.front();
			propogate(0,b);
			propogate(a,0);
			propogate(v1,b);
			propogate(a,v2);
			if(a+b>=v1)propogate(v1,a+b-v1);
			else propogate(a+b,0);
			if(a+b>=v2)propogate(a+b-v2,v2);
			else propogate(0,a+b);
			d.pop();
		}
		if(debug)cout<<"Queue is empty"<<endl;
		return -1;*/
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,a,b,c;scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&c);
		Problem p(a,b,c);
		printf("%d\n",p.solve());
	}
	return 0;
}
 
