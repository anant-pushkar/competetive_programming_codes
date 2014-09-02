/*
Project name : The_Next_Palindrome
Created on : Fri May 16 11:44:20 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PALIN/
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
const int STRSIZE = 1000010;
class Solver{
	char *str,*ptr;
	int mid1,mid2;
	void evalMid(){
		int l = strlen(str);
		mid1 = (l-1)/2;
		mid2 =  l/2;
	}
	void propogate(){
		int i = mid1 ,carry=1,val;
		while(i>-1 && carry==1){
			val = str[i]-'0'+carry;
			str[i] = (char)(val%10 + '0');
			carry=val/10;
			--i;
		}
		if(carry==1 && i==-1){
			--str;
			str[0]='1';
			evalMid();
		}
	}
	void reflect(){
		int i = mid1 , j = mid2;
		while(i>-1){
			str[j] = str[i];
			--i;++j;
		}
	}
	char *all9(){
		int l = strlen(str) , i=l-2;
		while(i>-1)str[i--] = '0';
		--str;str[0]='1';
		str[l]='1';
		return str;
	}
public:
	Solver(){
		str = new char[STRSIZE];
		ptr=str;++str;
		scanf("%s",str);
		evalMid();
	}
	char *solve(){
		bool check=true;
		int i=mid1 , j=mid2;
		while(i>-1 && str[i]==str[j]){
			check = (str[i]=='9') && check;
			--i;++j;
		}
		if(i==-1 && check)return all9();
		if(i==-1 || str[i]<str[j]){
			propogate();
			reflect();
		}else reflect();
		return str;
	}
	~Solver(){
		delete[](ptr);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld t;
	scanf("%lld",&t);
	while(t--){
		Solver s;
		printf("%s\n",s.solve());
	}
	return 0;
}

