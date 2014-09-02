/*
Project name : Glass_Beads
Created on : Tue Jun 10 10:27:21 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BEADS/
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
struct Bead{
	char *str;
	int index;
	Bead(char* s):
		str(s){}
	Bead(const Bead &b):
		str(b.str),
		index(b.index){}
};
int circular_strcmp(const char*str1 , const int index1 , const char *str2 , const int index2){
	int i1=index1 , i2=index2 , l1=strlen(str1) , l2 = strlen(str2);
	do{
		if(str1[i1] != str2[i2]){
			return str1[i1]-str2[i2];
		}
		i1 = (i1+1)%l1;
		i2 = (i2+1)%l2;
	}while(i1!=index1 && i2!=index2);
	return l1-l2;;
}
bool operator>(const Bead &b1 , const Bead &b2){
	return circular_strcmp(b1.str,b1.index,b2.str,b2.index) > 0;
}
class Solver{
	vector<Bead> beadList;
	char* str;
	int len;
public:
	Solver(char* s):
		str(s),
		len(strlen(s)),
		beadList(vector<Bead>(strlen(s),Bead(s))){
			for(int i=0;i<len;++i){
				beadList[i].index = i;
			}
		}
	int solve(){
		Bead min(str);
		min.index=0;
		for(int i=0;i<len;++i){
			min = min>beadList[i] ? beadList[i] : min;
		}
		return min.index+1;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	char str[10001];
	while(t--){
		scanf("%s",str);
		Solver s(str);
		printf("%d\n",s.solve());
	}
	return 0;
}

