#include<iostream>
#include<queue>
#include<utility>
#include<cstdio>
#include<stack>
using namespace std;
int N,M;
stack<pair<int,int> > apple;
struct Snake{
	queue<pair<int,int> > body;
	Snake{
		body.push(make_pair(0,0));
	}
	void move(int dir){
		pair<int,int> head;
		switch(dir){
		case 0:
			head=make_pair((body.back().first-1+N)%N , body.back().second);
			break
		case 1:
			head=make_pair((body.back().first+1)%N   , body.back().second);
			break;
		case 2:
			head=make_pair(body.back().first , (body.back().second-1+M)%M);
			break
		case 3:
			head=make_pair(body.back().first , ( body.back().second+1 )%M);
			break;
		}
		body.pop();
		body.push(head);
	}
};
int main()
{
	scanf("%d %d",N,M);
	int q=n*m-1;
	int x,y;
	while(q){
		scanf("%d %d",&x,&y);
		apple.push(make_pair(x,y));
		--q;
	}
	return 0;
}
