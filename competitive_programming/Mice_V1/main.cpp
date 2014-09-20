/*
Project name : Mice_V1
Created on : Sat Sep 13 17:01:05 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/csindia/challenges/mice-v1
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
    int n;
    vector<lld> mouse , hole;
    inline lld get_max(lld a , lld b){
    	return a>b ? a : b;
    }
    inline lld get_min(lld a , lld b){
    	return a<b ? a : b;
    }
public:
    Solver(int x):
    n(x),
    mouse(vector<lld>(x)),
    hole(vector<lld>(x)){
        for(int i=0;i<n;++i){
            scanf("%lld",&mouse[i]);
        }
        sort(mouse.begin() , mouse.end());
        for(int i=0;i<n;++i){
            scanf("%lld",&hole[i]);
        }
        sort(hole.begin() , hole.end());
    }
    lld solve(){
        lld d1 , d2 , d;
        vector<int> index(n , 0);
        for(int i=1;i<n;++i){
            d1 = get_max( abs(hole[i]-mouse[i-1]) , abs(hole[index[i-1]]-mouse[i]) );
            d2 = get_max( abs(hole[i]-mouse[i]) , abs(hole[index[i-1]]-mouse[i-1]) );
            if(d1>d2){
            	index[i] = i;
            }else{
            	index[i] = index[i-1];
            	index[i-1] = i;
            }
        }
        
        lld diff = 0;
        for(int i=0;i<n;++i){
        	diff = get_max(diff , abs(mouse[i]-hole[index[i]]));
        }
        
        return diff;
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int t;
    scanf("%d",&t);
    
    int n;
    while(t--){
        scanf("%d",&n);
        Solver s(n);
        printf("%lld\n",s.solve());
    }
    
	
	return 0;
}

