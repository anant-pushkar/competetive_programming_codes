/*
Project name : Subarray_LCM
Created on : Sun Sep 21 21:58:51 2014
Author : Anant Pushkar
http://www.codechef.com/COOK50/problems/SUBLCM
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
template<class T>
inline void inputInt(T &n )
{
	n=0;
	int sign=1;
 	T ch=getchar_unlocked();
  	while(( ch < '0' || ch > '9') && ch!='-')
      ch=getchar_unlocked();
	if(ch=='-')
	{
		sign=-1;
		ch=getchar_unlocked();
	}
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	n*=sign;
}
class Solver{
	int n;
	vector<int> arr;
	int get_gcd(int a , int b){
		if(a<b){
			lld c = a;
			a = b;
			b = c;
		}
		return a%b==0 ? b : get_gcd(b , a%b);
	}
public:
	Solver(int x):
	n(x),
	arr(vector<int>(x)){
		for(int i=0;i<n;++i){
			inputInt(arr[i]);
		}
	}
	int solve(){
		int len=1 , max=0 , g;
		lld lcm=arr[0];
		for(int i=1;i<n;++i){
			g = get_gcd(lcm , arr[i]);
			if(g==1){
				++len;
				lcm = lcm * arr[i];
			}else{
				max = max<len ? len : max;
				len = 1;
				lcm = arr[i];
			}
		}
		max = max<len ? len : max;
		return max==1 ? -1 : max;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		inputInt(n);
		Solver s(n);
		printf("%d\n",s.solve());
	}
	
	return 0;
}

