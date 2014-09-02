/*
Project name : Prime_Path
Created on : Wed Jun 11 20:53:40 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PPATH/
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
vector<bool> isPrime;
void init(){
	isPrime = vector<bool>(10000,true);
	isPrime[0]=false;isPrime[1]=false;
	for(int i=2;i<10000;++i)if(isPrime[i]){
		for(int j=2*i;j<10000;j+=i){
			isPrime[j]=false;
		}
	}
}
class DoorNumber{
	int digit[4];
public:
	DoorNumber(int a , int b , int c , int d){
			digit[0]=a;
			digit[1]=b;
			digit[2]=c;
			digit[3]=d;
		}
	DoorNumber(int val){
			digit[0]=val%10;
			digit[1]=(val/10)%10;
			digit[2]=(val/100)%10;
			digit[3]=(val/1000)%10;
		}
	int getVal(){
		return digit[0] + 10*digit[1] + 100*digit[2] + 1000*digit[3];
	}
	DoorNumber getNext(int place){
		int arr[4];
		for(int i=0;i<4;++i){
			arr[i] = digit[i];
			if(i==place){
				arr[i] = (arr[i]+1)%10;
			}
		}
		return DoorNumber(arr[0],arr[1],arr[2],arr[3]);
	}
	DoorNumber setDigit(int place , int val){
		int arr[4];
		for(int i=0;i<4;++i){
			arr[i] = digit[i];
			if(i==place){
				arr[i] = val;
			}
		}
		return DoorNumber(arr[0],arr[1],arr[2],arr[3]);
	}
	int getDigit(int place){
		return digit[place];
	}
};
class Solver{
	int start , target;
	int getSoln(){
		int d , digit , val;
		DoorNumber num(0) , temp(0);
		queue<DoorNumber> q;
		queue<int> dist;
		vector<bool>lookup(10000,false);
		
		q.push(DoorNumber(start));
		dist.push(0);
		lookup[start]=true;
		
		while(!q.empty()){
			num = q.front();
			q.pop();
			
			d = dist.front();
			dist.pop();
			
			for(int i=0;i<4;++i){
				digit = num.getDigit(i);
				for(int j=(digit+1)%10;j!=digit;j=(j+1)%10){
					temp = num.setDigit(i,j);
					val  = temp.getVal();
					if(val==target){
						return d+1;
					}
					if(val>1000 && isPrime[val] && !lookup[val]){
						if(debug)cout<<"Pushing "<<val<<" at dist "<<d+1<<endl;
						q.push(temp);
						dist.push(d+1);
						lookup[val] = true;
					}
				}
			}
		}
		return -1;
	}
public:
	Solver(int a , int b):
		start(a),
		target(b){
			
		}
	char* solve(){
		char* str = (char*)calloc(11,sizeof(char));
		if(start==target){
			str[0]='0';
			return str;
		}
		int soln = getSoln();
		if(soln==-1){
			sprintf(str,"Impossible");
		}else{
			sprintf(str,"%d",soln);
		}
		return str;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , a , b;
	scanf("%d",&t);
	init();
	char *soln;
	while(t--){
		scanf("%d %d",&a,&b);
		Solver s(a,b);
		soln = s.solve();
		printf("%s\n",soln);
		free(soln);
	}
	return 0;
}

