#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void printAll(int n){
	queue<string> q;
	stack<string> s1,s2;
	q.push("0");q.push("1");
	for(int i=1;i<n;i++){
		while(!q.empty()){
			s1.push(q.front());
			q.pop();
		}
		while(!s1.empty()){
			s2.push(s1.top());
			q.push("1"+s1.top());
			s1.pop();
		}
		while(!s2.empty()){
			q.push("0"+s2.top());
			s2.pop();
		}
	}
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
}
int main()
{
	int n;
	while(1){
		cin>>n;
		printAll(n);
		cout<<endl<<endl;
	}
	return 0;
}
