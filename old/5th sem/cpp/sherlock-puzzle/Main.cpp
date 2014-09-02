#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<unordered_map>
#include <cmath> 
using namespace std;
int solveShort1(string str , int n){
	unordered_map<int,pair<int,int> > lookup;//first : lo , second : hi
	pair<int,int> p;
	int val;
	if(str[0]=='0')val=-2;
	else val=3;
	lookup[val].first=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<str.size();j++){
			if(i!=0 || j!=0){
				if(str[j]=='0'){
					val-=2;
				}else val+=3;
				//printf("val=%d : ",val);
				if(lookup.find(val)!=lookup.end()){
					//printf("Found %d\n",val);
					lookup[val].second=i+j;
				}else{
					//printf("Creating %d\n",val);
					lookup[val].first=j+i;
				}
			}
		}
	}
	unordered_map<int,pair<int,int> >::iterator it;
	int max=-1;
	for(it=lookup.begin();it!=lookup.end();it++){
		//printf("%d:%d,%d\n",it->first,it->second.first,it->second.second);
		if(max<it->second.second-it->second.first){
			max=it->second.second-it->second.first;
		}
	}
	return max;
}
int solveShort(string str , int n){
	vector<int> lookup(str.size()*n,0);
	if(str[0]=='0')lookup[0]=-2;
	else lookup[0]=3;
	for(int i=0;i<n;i++){
		for(int j=0;j<str.size();j++){
			if(i+j!=0){
				if(str[j]=='0'){
					//printf("Found 0\n");
					lookup[i*str.size()+j]=lookup[i*str.size()+j-1]-2;
				}
				if(str[j]=='1'){
					//printf("Found 1\n");
					lookup[i*str.size()+j]=lookup[i*str.size()+j-1]+3;
				}
			}
		}
	}
	int maxDiff=1000000;
	int indexdiff=0;
	/*for(int i=0;i<lookup.size();i++){
		printf("%d ",lookup[i]);
	}
	printf("\n");*/
	for(int i=0;i<lookup.size();i++){
		for(int j=i+1;j<lookup.size();j++){
			if(lookup[j]-lookup[i]>0 && lookup[j]-lookup[i]<maxDiff){
				maxDiff=lookup[j]-lookup[i];
				indexdiff=j-i;
				//printf("Found at %d,%d\n",i,j);
			}
		}
	}
	return indexdiff;
}
void test(){
	string str;
	int n;
	cin>>n>>str;
	cout<<solveShort1(str,n)<<endl;
}
int main()
{
	//int T;scanf("%d",&T);
	//for(int t=0;t<T;t++){
		test();
	//}
	return 0;
}
