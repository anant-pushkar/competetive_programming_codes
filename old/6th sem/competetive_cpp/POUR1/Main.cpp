/*
Project name : POUR1
Created on : Sat Mar  8 13:04:24 2014
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
using namespace std;
bool debug=false;
typedef long long int lld;
class Problem{
	int v1,v2,target;
	queue<int> q1,q2,d;
	vector<vector<bool> > lookup;
	int hcf(int a , int b){
		if(b==0)return a;
		return hcf(b,a%b);
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
		d.push(0);
		lookup[0][0]=true;
	}
	int solve(){
		if(target>v1)return -1;
		int n=hcf(v1,v2);
		if(target%n!=0)return -1;
		v1/=n;
		v2/=n;
		target/=n;
		int a=v1,b=v2,count=1;
		while((b-1)%a!=0){
			b+=v2;
			++count;
			if(count>a+2){
				count=-1;
				break;
			}
		}
		int c1=count;
		count=1;
		b=v2;
		a=a%b;
		while((a-1)%b!=0){
			a+=(v1%v2);
			++count;
			if(count>b+2){
				count=-1;
				break;
			}
		}
		int c2=count;
		if(c1==-1 && c2==-1)return -1;
		if(c1==-1)return target/c2;
		if(c2==-1)return target/c1;
		return target/c1>target/c2 ? target/c2 : target/c1 ;
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

