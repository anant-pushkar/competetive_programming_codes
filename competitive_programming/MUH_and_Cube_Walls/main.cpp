/*
Project name : MUH_and_Cube_Walls
Created on : Fri Sep 26 21:49:40 2014
Author : Anant Pushkar
http://codeforces.com/contest/471/problem/D
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
void preKMP(vector<int> &pattern, int f[])
{
    int m = pattern.size(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
//check whether target string contains pattern 
int KMP(vector<int> &pattern, vector<int> &target)
{
    int m = pattern.size();
    int n = target.size();
    int f[m];     
    preKMP(pattern, f);     
    int i = 0;
    int k = 0;
    int count=0;     
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m){
            	++count;
            	k = f[m-1];
            	--i;
            }
        }
        else
            k = f[k];
    }
    return count;
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , w;
	scanf("%d %d",&n,&w);
	
	int x , y;
	vector<int> a(n-1) , b(w-1);
	
	scanf("%d",&x);
	for(int i=0;i<n-1;++i){
		scanf("%d",&y);
		a[i] = y-x;
		x = y;
	}
	
	scanf("%d",&x);
	for(int i=0;i<w-1;++i){
		scanf("%d",&y);
		b[i] = y-x;
		x = y;
	}
	
	cout<<(w!=1 ? KMP(b,a) : n)<<endl;
	
	return 0;
}

