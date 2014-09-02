#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
class Solver{
	string str;
	vector<int> lookup;
	void populate(){
		int j = -1;
		lookup[0] = j;
		for (int i = 1; i < str.size(); ++i ) {
			while (j > -1 && str[j+1] != str[i])
				j = lookup[j];
			if (str[i] == str[j+1])
				++j;
			lookup[i] = j;
		}
	}
	void printLookup(){
		if(debug){
			for(int i=0;i<lookup.size();++i){
				printf("%d ",lookup[i]);
			}
			printf("\n");
		}
	}
public:
	Solver(){
		cin>>str;
		lookup=vector<int>(str.size(),0);
	}
	/*int solve(){
		int count=str.size();
		for(int i=1;i<str.size();++i){
			int j=0,index=i;
			while(index<str.size()){
				if(str[index++]==str[j++])count++;
				else break;
			}
		}
		return count;
	}*/
	int solve(){
		populate();
		printLookup();
		vector<int> arr(str.size(),-1);
		arr[0]=str.size();
		int index,count;
		for(int i=1;i<str.size();++i){
			if(arr[i]==-1){
				int j=0,index=i;count=0;
				while(index<str.size()){
					if(str[index++]==str[j++])count++;
					else break;
				}
				arr[i]=count;
				while(lookup[j]!=-1){
					j=lookup[j];
					int delta=j-i;
					if(delta>0){
						lookup[index-j+i]=delta;
					}
				}
			}
		}
		count=0;
		for(int i=0;i<str.size();++i){
			count+=arr[i];
		}
		return count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t){
		Solver s;
		printf("%d\n",s.solve());
		--t;
	}
	return 0;
}

