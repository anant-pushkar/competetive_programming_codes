#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
string retrieve(const vector< vector<int> > lookup , const int &n1 , const int &n2 , const string &s1){
	int maxVal=-1 , maxX , maxY;
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			//cout<<"\t"<<lookup[i][j];
			if(maxVal<lookup[i][j]){
				maxVal=lookup[i][j];
				maxX=i;
				maxY=j;
			}
		}
		//cout<<endl;
	}
	//cout<<"MaxX : "<<maxX<<" MaxY : "<<maxY<<"Max Val : "<<maxVal<<endl;
	string str="";
	stack<char> tempSt;
	for(int i=maxX;i>maxX-maxVal;i--){
		tempSt.push(s1[i]);
	}
	while(!tempSt.empty()){
		str+=tempSt.top();
		tempSt.pop();
	}
	return str;
}
string findLCS(string s1 , string s2){
	int n1=s1.size() , n2=s2.size();
	vector< vector<int> > lookup(n1,vector<int>(n2,-1));
	for(int i=0;i<n1;i++){
		lookup[i][0] = s1[i]==s2[0] ? 1 : 0;
	}
	for(int i=0;i<n2;i++){
		lookup[0][i] = s1[0]==s2[i] ? 1 : 0;
	}
	for(int i=1;i<n1;i++){
		for(int j=1;j<n2;j++){
			lookup[i][j] = s1[i]==s2[j] ? lookup[i-1][j-1]+1 : 0;
		}
	}
	printf("%d\n",lookup[s1.size()-1][s2.size()-1]);
	return retrieve(lookup,n1,n2,s1);
}
int main()
{
	string s1 ,s2;
	while(1){
		cin>>s1>>s2;
		cout<<findLCS(s1,s2)<<endl;
	}
	return 0;
}
