#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
using namespace std;
bool debug=false;
class Grid{
	vector<vector<char> > arr;
	queue<pair<int,int> > start;
	int height,width;
public:
	Grid(int h , int w):
	height(h),
	width(w),
	arr(vector<vector<char> >(h,vector<char>(w)))
	{
		for(int i=0;i<h;++i){
			char c;scanf("%c",&c);
			for(int j=0;j<w;++j){
				scanf("%c",&arr[i][j]);
				if(arr[i][j]=='A')start.push(make_pair(i,j));
			}
		}
		if(debug){
			for(int i=0;i<h;++i){
				for(int j=0;j<w;++j){
					cout<<arr[i][j];
				}
				cout<<endl;
			}
		}
	}
	int longestPath(){
		int maxLen=0;
		pair<int,int> root;
		while(!start.empty()){
			root=start.front();start.pop();
			vector<vector<bool> > lookup(height,vector<bool>(width,false));
			stack<pair<int,int> > s;s.push(root);lookup[root.first][root.second]=true;
			stack<int> count;count.push(1);
			pair<int,int> v,node;
			int n;
			while(!s.empty()){
				v=s.top();s.pop();
				n=count.top();count.pop();
				if(n>maxLen)maxLen=n;
				if(debug)cout<<"Traversing "<<v.first<<","<<v.second<<":"<<arr[v.first][v.second]<<endl;
				for(int i=-1;i<2;++i){
					for(int j=-1;j<2;++j)if(i!=0 || j!=0){
						if(v.first+i>-1 && v.first+i<height && v.second+j>-1 && v.second+j<width){
							if(debug)cout<<"at "<<v.first+i<<","<<v.second+j<<endl;
							if(!lookup[v.first+i][v.second+j] && arr[v.first+i][v.second+j]-arr[v.first][v.second]==1){
								s.push(make_pair(v.first+i,v.second+j));
								count.push(n+1);if(debug)cout<<"Pushing "<<v.first+i<<","<<v.second+j<<endl;
								lookup[v.first+i][v.second+j]=true;
							}
						}
					}
				}
			}
		}
		return maxLen;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int h,w,i=1;
	while(1){
		scanf("%d %d",&h,&w);
		if(h==0 && w==0)break;
		Grid g(h,w);
		printf("Case %d: %d\n",i++,g.longestPath());
	}
	return 0;
}

