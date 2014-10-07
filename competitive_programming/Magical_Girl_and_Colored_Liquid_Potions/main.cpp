/*
Project name : Magical_Girl_and_Colored_Liquid_Potions
Created on : Tue Oct  7 09:16:18 2014
Author : Anant Pushkar
http://www.codechef.com/OCT14/problems/PRPOTION
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
inline int get_max(int a , int b){
	return a>b ? a : b;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int r , g , b , m , r_max , g_max , b_max , val , max;
	while(t--){
		cin>>r>>g>>b>>m;
		r_max=0;
		g_max=0;
		b_max=0;
		for(int i=0;i<r;++i){
			cin>>val;
			r_max = get_max(r_max , val);
		}
		for(int i=0;i<g;++i){
			cin>>val;
			g_max = get_max(g_max , val);
		}
		for(int i=0;i<b;++i){
			cin>>val;
			b_max = get_max(b_max , val);
		}
		while(m--){
			max = get_max(r_max , get_max(g_max , b_max));
			if(max==0){
				break;
			}
			if(max==r_max){
				r_max = r_max>>1;
			}else if(max==g_max){
				g_max = g_max>>1;
			}else{
				b_max = b_max>>1;
			}
		}
		cout<<get_max(r_max , get_max(g_max , b_max))<<endl;
	}
	return 0;
}

