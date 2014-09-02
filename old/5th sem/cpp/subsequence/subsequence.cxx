#include"subsequence.h"
using namespace std;
SubSequenceFinder::SubSequenceFinder(string s1 , string s2):
lookup(vector< vector<int> >(s2.size()+1 , vector<int>(s1.size()+1,0)))
{
	int temp;
	for(int i=1;i<=s2.size();i++){
		for(int j=1;j<=s1.size();j++){
			if(s2[i-1]==s1[j-1])
				temp=lookup[i-1][j-1]+1>lookup[i-1][j] ? lookup[i-1][j-1]+1 : lookup[i-1][j] ;
			else
				temp=lookup[i-1][j];
			lookup[i][j] = temp > lookup[i][j-1] ? temp : lookup[i][j-1] ;
		}
	}
	//printLookup();
	length=lookup[s2.size()][s1.size()];
}
int SubSequenceFinder::getLength()
{
	return length;
}
void SubSequenceFinder::printLookup()
{
	for(int i=0;i<lookup.size();i++){
		for(int j=0;j<lookup[0].size();j++)
			cout<<lookup[i][j]<<" ";
		cout<<endl;
	}
}