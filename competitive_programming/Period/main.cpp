/*
Project name : Period
Created on : Sat Sep 27 04:30:09 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PERIOD/
void FailureFunction()
{
    int i=1,j=0;
    failur[0]=0;
    while(i<length_b)
    {
        if(pattern[i]==pattern[j])
        {
            j++;
            failur[i]=j;
            i++;
        }
        else if(j>0)
            j=failur[j-1];
        else
        {
            failur[i]=0;
            i++;
        }
    }
}

void KMPmatch()
{
    FailureFunction();
    int i=0,j=0;

    while(i<length_a)
    {
        if(text[i]==pattern[j])
        {
            if(j==length_b-1)
                cnt++;
            i++;
            j++;
        }
        else if(j>0)
            j=failur[j-1];
        else
            i++;

    }
}
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
vector<int> preKMP(const string &pattern)
{
    int m = pattern.size(), k , j=0;
    vector<int> f(m);
    f[0] = 0;
    for (int i = 1; i < m; )
    {
        if(pattern[i]==pattern[j])
        {
            j++;
            f[i]=j;
            i++;
        }
        else if(j>0)
            j=f[j-1];
        else
        {
            f[i]=0;
            i++;
        }
    }
    return f;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	int n , diff ;
	string str;
	vector<int> f ;
	for(int t=1;t<=T;++t){
		scanf("%d",&n);
		cin>>str;
		cout<<"Test case #"<<t<<endl;
		f = preKMP(str);
		if(debug){
			cout<<str<<endl;
			for(int i=0;i<n;++i){
				cout<<f[i]<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<n;++i){
			diff = i+1-f[i];
			if((i+1)%diff==0 && (i+1)/diff>1){
				cout<<i+1<<" "<<(i+1)/diff<<endl;
			}
		}
		cout<<endl;
	}
	
	return 0;
}

