/*
Project name : JEDNAKOST
Created on : Wed Jul 23 18:44:25 2014
Author : Anant Pushkar
http://www.spoj.com/problems/JEDNAKOS/
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
vector<vector<int> > lookup;
void print(int v[]){
	for(int i=0;i<4;++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int get_last_index(char eqn[]){
	int len = strlen(eqn);
	for(int i=len-1;i>0;--i){
		if(eqn[i]=='='){
			eqn[i] = '\0';
			return i;
		}
	}
	return 0;
}
int get_val(char str[] , int start , int end){
	int val=0 , index=start;
	while(index<end){
		val = val*10 + (str[index]-'0');
		++index;
	}
	return val;
}
vector<int> get_next(char eqn[] , int start , int end){
// 	vector<int> next_val(4);
// 	next_val[0] = eqn[start]-'0';
// 	if(start+1<end){
// 		next_val[1] = next_val[0]*10 + eqn[start+1] - '0';
// 		if(start+2<end){
// 			next_val[2] = next_val[1]*10 + eqn[start+2] - '0';
// 			if(start+3<end){
// 				next_val[3] = next_val[2]*10 + eqn[start+3] - '0';
// 			}else{
// 				next_val[3] = INT_MIN;
// 			}
// 		}else{
// 			next_val[2] = INT_MIN;
// 			next_val[3] = INT_MIN;
// 		}
// 	}else{
// 		next_val[1] = INT_MIN;
// 		next_val[2] = INT_MIN;
// 		next_val[3] = INT_MIN;
// 	}
// 	if(debug){
// 		cout<<"get_next : eqn:"<<eqn+start<<" next: ";
// 		print(next_val);
// 	}
	
	//return next_val;
}
inline vector<int> get_countlist(const vector<int> &next_val , char eqn[] , int start , int end , int target);
inline int get_min(const vector<int> &v);
int get_count(char eqn[] , int start , int end , int target){
	if(target==0 && start==end){
		return 0;
	}
	
	if(start>=end || target<0){
		return INT_MAX-1;
	}
	
	if(lookup[start][target]!=-1){
		if(debug)cout<<"get_count : eqn:"<<eqn+start<<" target:"<<target<<" memoized min:"<<lookup[start][target]<<endl<<endl<<endl;
		return lookup[start][target];
	}
	
	int size = 4;
	int next_val[size];
	next_val[0] = eqn[start]-'0';
	if(start+1<end){
		next_val[1] = next_val[0]*10 + eqn[start+1] - '0';
		if(start+2<end){
			next_val[2] = next_val[1]*10 + eqn[start+2] - '0';
			if(start+3<end){
				next_val[3] = next_val[2]*10 + eqn[start+3] - '0';
			}else{
				next_val[3] = INT_MIN;
			}
		}else{
			next_val[2] = INT_MIN;
			next_val[3] = INT_MIN;
		}
	}else{
		next_val[1] = INT_MIN;
		next_val[2] = INT_MIN;
		next_val[3] = INT_MIN;
	}
	if(debug){
		cout<<"get_next : eqn:"<<eqn+start<<" next: ";
		print(next_val);
	}
	
	int countlist[size];
	for(int i=0;i<size;++i){
		if(next_val[i]==target && start+i+1==end){
			return 1;
		}
		countlist[i] = ( next_val[i]!=INT_MIN && next_val[i]<target ) ? get_count(eqn , start+i+1 , end , target-next_val[i])+1 : INT_MAX;
	}
	if(debug){
		cout<<"get_countlist : eqn:"<<eqn+start<<" target:"<<target<<" countlist:";
		print(countlist);
	}
	
	//vector<int> countlist = get_countlist(get_next(eqn , start , end) , eqn , start , end , target);
	int min = INT_MAX;
	for(int i=0;i<size;++i){
		min = min>countlist[i] ? countlist[i] : min ;
	}
	int min_count = min==INT_MAX ? INT_MAX-1 : min ;
	//int min_count = get_min(countlist);
	if(debug)cout<<"get_count : eqn:"<<eqn+start<<" target:"<<target<<" min:"<<min_count<<endl<<endl<<endl;
	
	lookup[start][target] = min_count;
	return min_count;
}
inline int get_min(const vector<int> &v){
// 	int min = INT_MAX;
// 	for(int i=0;i<v.size();++i){
// 		min = min>v[i] ? v[i] : min ;
// 	}
// 	return min==INT_MAX ? INT_MAX-1 : min ;
}
inline vector<int> get_countlist(const vector<int> &next_val , char eqn[] , int start , int end , int target){
// 	vector<int> countlist(next_val.size());
// 	for(int i=0;i<next_val.size();++i){
// 		countlist[i] = next_val[i]!=INT_MIN ? get_count(eqn , start+i+1 , end , target-next_val[i])+1 : INT_MAX;
// 	}
// 	if(debug){
// 		cout<<"get_countlist : eqn:"<<eqn+start<<" target:"<<target<<" countlist:";
// 		print(countlist);
// 	}
	//return countlist;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char eqn[10007];
	scanf("%s",eqn);
	
	int len = strlen(eqn) , index = get_last_index(eqn) , target = get_val(eqn,index+1,len);
	lookup = vector<vector<int> >(index+1 , vector<int>(target+1,-1));
	
	printf("%d\n",get_count(eqn,0,index,target)-1);
	
	return 0;
}

