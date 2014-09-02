/*
Project name : Xor_and_Sum
Created on : Sat Jul 26 19:05:20 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101jul14/challenges/xor-and-sum
10
1010

0001000
0010110
0101010
1010010

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
const int LIM = 100001;
const int END = 314159;
const int MOD = 1000000007;
char a[LIM] , b[LIM];
int len_b , len_a , max_lim , min_lim;
int get_bit(char str[] , int index){
	int l=strlen(str);
	//if(debug)cout<<"getting bit for : "<<index<<" to "<<l-index-1<<endl;
	return str[l-index-1] - '0';
}
inline int get_max(int a , int b){
	return a>b ? a : b;
}
inline int get_min(int a , int b){
	return a<b? a : b;
}
inline int get_count(int index){
	if(index<=min_lim){
		return index;
	}
	if(index>=END){
		return len_b - (index-END);
	}
	return len_b;
}
lld cache=-1;
lld reverse_cache=-1;
lld get_bit_sum(int start , int end, bool reverse){
	if(start == len_b-1 && end==-1 && cache!=-1 && !reverse){
		return cache;
	}
	if(start == len_b-1 && end==-1 && reverse_cache!=-1 && reverse){
		return reverse_cache;
	}
	int bit;
	lld sum=0;
	for(int i=start ; i>end ; --i){
		bit = get_bit(b,i);
		if(reverse){
			bit = (bit+1)%2;
		}
		sum += bit;
	}
	if(start = len_b-1 && end==-1 && cache==-1 && !reverse){
		cache = sum;
	}
	if(start = len_b-1 && end==-1 && reverse_cache==-1 && reverse){
		reverse_cache = sum;
	}
	return sum;
}
lld get_sum(int index){
	int start = index>len_b-1 ? len_b-1 : index;
	int count = get_count(index);
	int end   = start - count;
	bool reverse = index<len_a ? get_bit(a,index)==1 : false;
	
	if(debug)cout<<"index:"<<index<<" reverse : "<<reverse<<" count:"<<count<<endl;
	
	lld sum=get_bit_sum(start,end,reverse);
	
	return sum + (reverse?1:0)*(END-count+1)%MOD;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%s",a);
	scanf("%s",b);
	
	len_b = strlen(b);
	len_a = strlen(a);
	max_lim   = get_max(len_b,END);
	min_lim   = get_min(len_b,END);
	
	lld place_val=0 , face_val=1 , val=0;
	for(int i=0;i<END+len_b;++i){
		place_val = get_sum(i)%MOD;
		if(debug)cout<<"face:"<<face_val<<" place:"<<place_val<<endl<<endl;
		val += (place_val * face_val)%MOD;
		val  = val%MOD;
		
		face_val = face_val<<1;
		face_val = face_val&(INT_MAX);
		face_val = face_val%MOD;
	}
	printf("%lld\n",val);
	
	return 0;
}

