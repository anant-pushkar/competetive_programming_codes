#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
bool debug=false;
class Solver{
	vector<vector<int> > grid;
	pair<int,int> target;
	int m,n,deadline;
public:
	Solver(int r , int c):
	m(r),
	n(c),
	grid(vector<vector<int> >(r,vector<int>(c,-1))){
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				scanf("%d",&grid[i][j]);
			}
		}
		scanf("%d %d %d",&target.first,&target.second,&deadline);
		--target.first;
		--target.second;
		if(debug){
			cout<<endl;
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					cout<<grid[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<"m:"<<m<<" n:"<<n<<endl;
			cout<<"Target : "<<target.first<<","<<target.second<<endl;
			cout<<"Deadline : "<<deadline<<endl;
		}
	}
	int solve(){
		queue<pair<int,int> > q;
		queue<int> time;
		vector< vector<bool> > lookup(m,vector<bool>(n,false));
		
		q.push(make_pair(0,0));time.push(0);lookup[0][0]=true;
		pair<int,int> cell;
		int delay;
		while(!q.empty()){
			cell=q.front();q.pop();
			delay=time.front();time.pop();
			if(debug)cout<<"At "<<cell.first<<" "<<cell.second<<":"<<delay<<endl;
			if(cell==target)break;
			for(int i=-1;i<2;++i){
				for(int j=-1;j<2;++j)if(i+j==1 || i+j==-1){
					if(cell.first+i>-1 && cell.first+i<m && cell.second+j>-1 && cell.second+j<n && !lookup[cell.first+i][cell.second+j]){
						if(debug)cout<<"Pushing "<<cell.first+i<<","<<cell.second+j<<endl;
						q.push(make_pair(cell.first+i,cell.second+j));
						time.push(delay+grid[cell.first][cell.second]);
						lookup[cell.first+i][cell.second+j]=true;
					}else{
						if(debug){
							cout<<"Cannot push "<<cell.first+i<<","<<cell.second+j<<endl;
						}
					}
				}
			}
			if(debug){
				cout<<"Lookup : "<<endl;
				for(int i=0;i<m;++i){
					for(int j=0;j<n;++j){
						cout<<lookup[i][j]<<" ";
					}
					cout<<endl;
				}
				cout<<endl;
			}
		}
		if(cell==target)return deadline-delay;
		else return -1;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,m,n,time;scanf("%d",&t);
	while(t){
		scanf("%d %d",&m,&n);
		Solver s(m,n);
		time=s.solve();if(debug)cout<<"time : "<<time<<endl;
		if(time<0)printf("NO\n");
		else printf("YES\n%d\n",time);
		--t;
	}
	return 0;
}

