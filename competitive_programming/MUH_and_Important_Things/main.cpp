/*
Project name : MUH_and_Important_Things
Created on : Fri Sep 26 21:18:28 2014
Author : Anant Pushkar
http://codeforces.com/contest/471/problem/B
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
#include<map>
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
void print_soln(deque<queue<int> > &s){
	bool check=true;
	int size = s.size();
	vector<int> rotated(size,0);
	for(int k=0;k<3;++k){
		check = true;
		for(int i=0;i<size;++i){
			if(s[i].size()==1){
				cout<<s[i].front()+1<<" ";
			}else{
				queue<int> q;
				while(!s[i].empty()){
					cout<<s[i].front()+1<<" ";
					q.push(s[i].front());
					s[i].pop();
				}
				if(check && rotated[i]<q.size()-1){
					q.push(q.front());
					q.pop();
					++rotated[i];
					check = false;
				}
				s[i] = q;
			}
		}
		cout<<endl;
	}
}

void is_possible(map<int , set<int> > &lookup){
	map<int , set<int> >::iterator it = lookup.begin();
	int count=0;
	deque<queue<int> > s;
	set<int>::iterator v;
	for(;it!=lookup.end();++it){
		v = it->second.begin();
		queue<int> q;
		while(v!=it->second.end()){
			q.push(*v);
			++v;
		}
		count += q.size()-1;
		s.push_back(q);
	}
	if(count<2){
		printf("NO\n");
	}else{
		printf("YES\n");
		print_soln(s);
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	int a;
	map<int , set<int> > lookup;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		if(lookup.find(a)==lookup.end()){
			lookup[a] = set<int>();
		}
		lookup[a].insert(i);
	}
	
	is_possible(lookup);

	return 0;
}

