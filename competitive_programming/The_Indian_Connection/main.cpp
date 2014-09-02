/*
Project name : The_Indian_Connection
Created on : Wed Jul 30 19:52:02 2014
Author : Anant Pushkar
http://www.spoj.com/problems/DCEPC504/
1                     M								1
2                   M    F							2
4                 M  F  F M							3
8               M F F M F M M F						4
16           M F F M F M M F F M M F M F F M		5
parent(n,k) = (n-1,k/2)
n,k -> n-1,k/2 -> n-2,k/4 -> n-3,k/8 ---> n-i,k/(2^i)
(2,0)=M
(2,1)=F

(n,0)=M
(n,1)=F
(n,2^(n-1)-1) = n%2==1 ? M : F
(n,2^(n-1)-2) = n%2==1 ? F : M
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
inline char get_sex(char p , int n , lld k){
	if(n==1){
		return 'M';
	}
	if(n==2){
		return k==0 ? 'M' : 'F';
	}
	if(k<2){
		return k==0 ? 'M' : 'F';
	}
	if(k==(1<<(n-1))-1){
		return n%2==1 ? 'M' : 'F';
	}
	if(k==(1<<(n-1))-2){
		return n%2==1 ? 'F' : 'M';
	}
	return p=='M' ? k%2==0 ? 'M' : 'F' : k%2==0 ? 'F' : 'M';
}
inline char get_parent(int n , lld k){
	if(n==2){
		return 'M';
	}
	char p = get_sex(get_parent(n-1,k/2) , n-1 , k/2);
	if(debug){
		char sex = get_sex(p,n,k);
		cout<<"parent of "<<n<<","<<k<<" is "<<p<<" and it has sex "<<sex<<endl;
	}
	return p;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	lld k;
	char sex;
	while(t--){
		scanf("%d %lld",&n,&k);
		--k;
		if(n!=1){
			sex = get_sex(get_parent(n,k) , n , k);
			if(debug){
				cout<<"sex returned "<<sex<<endl;
			}
			printf("%s\n" , sex == 'M' ? "Male" : "Female");
		}else{
			printf("Male\n");
		}
		
	}
	return 0;
}

