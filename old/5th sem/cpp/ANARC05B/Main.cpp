#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
bool debug=false;
int n1,n2,j;
vector<int> a1,a2;
stack<int> s1,s2;
stack<int> calcSum(const vector<int>&arr , stack<int> s){
	int sum,index=arr.size()-1;
	stack<int> s_stack;
	while(!s.empty()){
		sum=0;
		for(int i=index;i>s.top();--i)sum+=arr[i];
		s_stack.push(sum);
		index=s.top();s.pop();
	}
	return s_stack;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	while(1){
		scanf("%d",&n1);if(n1==0)break;
		a1=vector<int>(n1);
		for(int i=0;i<n1;++i)scanf("%d",&a1[i]);
		
		scanf("%d",&n2);
		a2=vector<int>(n2);
		for(int i=0;i<n2;++i)scanf("%d",&a2[i]);
		
		j=0;
		s1.push(-1);s2.push(-1);
		for(int i=0;i<n1;++i){
			while(j<n2 && a2[j]<a1[i])++j;
			if(a1[i]==a2[j]){
				s1.push(i);
				s2.push(j);
			}
		}
		s1=calcSum(a1,s1);
		s2=calcSum(a2,s2);
		
		j=0;
		while(!s1.empty()){
			j+= s1.top()>s2.top() ? s1.top() : s2.top() ;
			s1.pop();s2.pop();
		}
		printf("%d\n",j);
	}
	return 0;
}

