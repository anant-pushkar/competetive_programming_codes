/*
Project name : Amz_Rock
Created on : Sat Sep 20 17:50:52 2014
Author : Anant Pushkar
http://www.spoj.com/problems/AMZRCK/

f(n) = f(n-1) + f(n-2)
f(n+1) = f(n) + f(n-1)
	   = 2f(n-1) + f(n-2)
/        \      /     \   /        \
| f(n)   |      | 1 1 |   | f(n-1) |
| f(n-1) |  =   | 2 1 | * | f(n-2) |
\        /      \     /   \        /

/        \      /     \(n-1)/2 /      \
| f(n)   |      | 1 1 |        | f(2) |
| f(n-1) |  =   | 2 1 | *      | f(1) |
\        /      \     /        \      /

f(2) = 3
f(1) = 2

yeah..probably thats not even needed.
Just stick with simple dp solution
2 3 5 8 13 21
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n , a=2 , b=3  , c;
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("%d\n",2);
		}else if(n==2){
			printf("%d\n",3	);
		}else{
			for(int i=2;i<n;++i){
				c = b;
				b = a+b;
				a = c;
				if(debug)cout<<"a:"<<a<<" b:"<<b<<endl;
			}
			printf("%d\n",b);
			a=2;
			b=3;
		}
	}
	
	return 0;
}

