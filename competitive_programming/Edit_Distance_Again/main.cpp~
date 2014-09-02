/*
Project name : Edit_Distance_Again
Created on : Fri Aug  1 19:11:02 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EDIT/
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
const int UPPER = 1;
const int LOWER = 0;
class Solver{
	char * str;
	int len;
	vector<vector<int> > lookup;
	int get_min_dist(int index , int orientation){
		int val = (orientation==UPPER && isupper(str[index])) || (orientation==LOWER && islower(str[index])) ? 0 : 1 ;
		if(index==0){
			return val; 
		}
		if(lookup[orientation][index]!=INT_MAX){
			return lookup[orientation][index];
		}
		lookup[orientation][index] = get_min_dist(index-1 , (1+orientation)%2) + val;
		return lookup[orientation][index];
	}
public:
	Solver(char * ptr):
	str(ptr),
	len(strlen(ptr)),
	lookup(vector<vector<int> >(2 , vector<int>(strlen(ptr) , INT_MAX)))
	{
		
	}
	
	int mem_solve(){
		int v1 = get_min_dist(len-1 , UPPER);
		int v2 = get_min_dist(len-1 , LOWER);
		int v = v1>v2 ? v2 : v1;
		return v;
	}
	int solve(){
		lookup[UPPER][0] = isupper(str[0]) ? 0 : 1;
		lookup[LOWER][0] = islower(str[0]) ? 0 : 1;
		for(int i=1;i<len;++i){
			lookup[UPPER][i] = lookup[LOWER][i-1] + (isupper(str[i]) ? 0 : 1 );
			lookup[LOWER][i] = lookup[UPPER][i-1] + (islower(str[i]) ? 0 : 1 );
		}
		return lookup[LOWER][len-1]<lookup[UPPER][len-1] ? lookup[LOWER][len-1] : lookup[UPPER][len-1];
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char str[1001];
	while(!(cin>>str).eof()){
		if(debug)cout<<str<<" strlen : "<<strlen(str)<<endl;
		if(strlen(str)==0){
			break;
		}
		Solver s(str);
		printf("%d\n",s.solve());
	}
	return 0;
}

