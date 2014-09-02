/*
Project name : Hacking_the_random_number_generator
Created on : Thu Jun 12 20:02:51 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HACKRNDM/
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , k , num;
	scanf("%d %d",&n,&k);
	
	set<int> s;
	for(int i=0;i<n;++i){
		scanf("%d",&num);
		s.insert(num);
	}
	
	int count=0;
	set<int>::iterator iter;
	for(iter=s.begin();iter!=s.end();++iter){
		if(debug)cout<<"Looking on "<<(*iter)<<endl;
		if(s.find((*iter)+k)!=s.end()){
			if(debug)cout<<"Found "<<(*iter)+k<<endl;
			++count;
		}
		if(s.find((*iter)-k)!=s.end()){
			if(debug)cout<<"Found "<<(*iter)-k<<endl;
			++count;
		}
	}
	printf("%d\n",count/2);
	
	return 0;
}

