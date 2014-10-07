/*
Project name : Permutation_Sequence
Created on : Thu Oct  2 16:42:06 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/permutation-sequence/
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
class Solution{
	string get_perm(vector<char> &alpha , int k , int n){
		if(debug){
			cout<<"called on k:"<<k<<" n:"<<n<<endl;
			cout<<"alhpa : ";
			for(int i=0;i<alpha.size();++i){
				cout<<alpha[i]<<" ";
			}
			cout<<endl;
		}
        if(alpha.size()==0){
            return "";
        }
        int index = k/n;
        string first_char = string(alpha.begin()+index , alpha.begin()+index+1);
        alpha.erase(alpha.begin() + index);
        
        if(debug)cout<<"first char : "<<first_char<<endl;
        
        return first_char + get_perm(alpha , k%n , alpha.size()!=0 ? n/alpha.size() : 0);
    }
public:
	bool debug;
	string getPermutation(int n, int k) {
        vector<char> alpha(n);
        int num = 1;
        for(int i=0;i<n;++i){
            alpha[i] = '1' + i;
            num *= i!=n-1 ? n-i-1 : 1 ;
        }
        return get_perm(alpha , k-1 , num);
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug=false;
	}
	
	int t;
	scanf("%d",&t);
	
	int n , k;
	while(t--){
		cin>>n>>k;
		cout<<s.getPermutation(n,k)<<endl;
	}
	
	return 0;
}

