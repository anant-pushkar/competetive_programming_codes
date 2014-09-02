#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool debug=false;
struct closestPath{
	pair<int,int> start;
	pair<int,int> end;
	int len;
	vector<vector<pair<int,int> > > edgeTo;
	
	closestPath():
	start(make_pair(-1,-1)),
	end(make_pair(-1,-1)),
	len(0)
	{}
	
	closestPath(int n , int m , pair<int,int> s):
	start(s),
	edgeTo(vector<vector<pair<int,int> > >(n+1,vector<pair<int,int> >(m+1,make_pair(-1,-1)))),
	len(0)
	{}
	
	void print(){
		for(int i=1;i<edgeTo.size();++i){
			for(int j=1;j<edgeTo[i].size();++j){
				printf(" (%d,%d) ",edgeTo[i][j]);
			}
			printf("\n");
		}
	}
};
struct Soln{
	queue<string> cmd;
	int time;
	
	Soln():
	time(0)
	{}
	
	void swap(int x1,int y1, int x2, int y2){
		char c_str[100];
		if(debug)cout<<"Swapping "<<x1<<","<<y1<<" "<<x2<<","<<y2<<endl;
		sprintf(c_str,"1 %d %d %d %d\n",x1,y1,x2,y2);
		cmd.push(string(c_str));
		++time;
	}
	
	void flip(int x,int y,int c){
		char c_str[100];
		if(debug)cout<<"Flipping "<<x<<","<<y<<endl;
		sprintf(c_str,"3 %d %d\n",x,y);
		cmd.push(string(c_str));
		time+=c;
	}
	
	void print(){
		printf("%d\n",time);
		while(!cmd.empty()){
			cout<<cmd.front();
			cmd.pop();
		}
	}
};
class Solver{
	vector<vector<char> > board;
	int c2,c3,n,m;
	pair<int,int> findBlack(){
		if(debug){
			cout<<"Finding black"<<endl;
			print();
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				//if(debug)cout<<"Looking at "<<i<<","<<j<<endl;
				if(board[i][j]=='B'){
					if(debug)cout<<"Found black at "<<i<<" "<<j<<".Checking neighbours"<<endl;
					if(i>0 && board[i-1][j]=='G')return make_pair(i,j);
					if(i<n && board[i+1][j]=='G')return make_pair(i,j);
					if(j>0 && board[i][j-1]=='G')return make_pair(i,j);
					if(j<n && board[i][j+1]=='G')return make_pair(i,j);
					if(debug)cout<<"No neighbour found"<<endl;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				//if(debug)cout<<"Looking at "<<i<<","<<j<<endl;
				if(board[i][j]=='B'){
					if(debug)cout<<"Found black at "<<i<<" "<<j<<endl;
					return make_pair(i,j);
				}
			}
		}
		if(debug)cout<<"Could not find black"<<endl;
		return make_pair(-1,-1);
	}
	closestPath findClosest(){ 
		if(debug){
			cout<<"findClosest called"<<endl;
			print();
		}
		pair<int,int> start = findBlack();
		if(start.first!=-1){
			pair<int,int> cell;
			int len;
			queue<pair<int,int> > q;
			queue<int> lenQ;
			closestPath cp(n,m,start);
			cp.edgeTo[start.first][start.second]=start;
			q.push(start);lenQ.push(0);
			board[start.first][start.second]='W';
			while(!q.empty()){
				cell=q.front();
				if(debug)cout<<"At "<<cell.first<<","<<cell.second<<endl;
				//if(debug)print();
				len=lenQ.front();
				if(cell!=start && board[cell.first][cell.second]=='B'){
					break;
				}
				q.pop();lenQ.pop();
				if(cell.first>1 && cp.edgeTo[cell.first-1][cell.second].first==-1 && board[cell.first-1][cell.second]!='G'){
					if(debug)cout<<"Pushing "<<cell.first-1<<","<<cell.second<<endl;
					q.push(make_pair(cell.first-1,cell.second));
					lenQ.push(len+1);
					cp.edgeTo[cell.first-1][cell.second]=cell;
				}
				if(cell.first<n && cp.edgeTo[cell.first+1][cell.second].first==-1 && board[cell.first+1][cell.second]!='G'){
					if(debug)cout<<"Pushing "<<cell.first+1<<","<<cell.second<<endl;
					q.push(make_pair(cell.first+1,cell.second));
					lenQ.push(len+1);
					cp.edgeTo[cell.first+1][cell.second]=cell;
				}
				if(cell.second>1 && cp.edgeTo[cell.first][cell.second-1].first==-1 && board[cell.first][cell.second-1]!='G'){
					if(debug)cout<<"Pushing "<<cell.first<<","<<cell.second-1<<endl;
					q.push(make_pair(cell.first,cell.second-1));
					lenQ.push(len+1);
					cp.edgeTo[cell.first][cell.second-1]=cell;
				}
				if(cell.second<m && cp.edgeTo[cell.first][cell.second+1].first==-1 && board[cell.first][cell.second+1]!='G'){
					if(debug)cout<<"Pushing "<<cell.first<<","<<cell.second+1<<endl;
					q.push(make_pair(cell.first,cell.second+1));
					lenQ.push(len+1);
					cp.edgeTo[cell.first][cell.second+1]=cell;
				}
			}
			if(debug)cout<<"Found end at "<<cell.first<<","<<cell.second<<endl;
			board[start.first][start.second]='B';
			//if(!q.empty()){
				cp.end=cell;
				cp.len=len;
			//}
			//else cp.end=make_pair(-1,-1);
			if(debug)cout<<"Found closest path"<<endl;
			return cp;
		}
		return closestPath();
	}
public:
	Solver(int n1 , int m1 , int cost2 , int cost3):
	n(n1),
	m(m1),
	board(vector<vector<char> >(n1+1,vector<char>(m1+1,'$'))),
	c2(cost2),
	c3(cost3)
	{
		char c;
		for(int i=1;i<=n;++i){
			scanf("%c",&c);
			for(int j=1;j<=m;++j){
				scanf("%c",&board[i][j]);
			}
		}
	}
	void print(){
		printf("\n");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				printf("%c",board[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	Soln solve(){
		closestPath cp=findClosest();
		Soln s;
		while(cp.start.first!=-1){
			if(board[cp.end.first][cp.end.second]=='W'){
				if(debug)cout<<"Flipping last"<<endl;
				s.flip(cp.start.first,cp.start.second,c3);
				board[cp.start.first][cp.start.second]='W';
				cp=findClosest();
				continue;
			}
			if(debug)cp.print();
			pair<int,int>cell=cp.end,next;
			if(cp.len<2*c3){
				do{
					if(debug)cout<<"At "<<cell.first<<","<<cell.second<<endl;
					s.swap(cell.first,cell.second,cp.edgeTo[cell.first][cell.second].first,cp.edgeTo[cell.first][cell.second].second);
					char c=board[cell.first][cell.second];
					board[cell.first][cell.second]=board[cp.edgeTo[cell.first][cell.second].first][cp.edgeTo[cell.first][cell.second].second];
					board[cp.edgeTo[cell.first][cell.second].first][cp.edgeTo[cell.first][cell.second].second]=c;
					cell=cp.edgeTo[cell.first][cell.second];
					next=cp.edgeTo[cell.first][cell.second];
					if(debug)print();
				}while(cp.edgeTo[next.first][next.second]!=next);
				if(board[cell.first][cell.second]!='W'){
					board[cell.first][cell.second]='B';
					board[next.first][next.second]='G';
				}else{
					board[next.first][next.second]='B';
				}
				if(debug)print();
			}else{
				s.flip(cp.start.first,cp.start.second,c3);
				board[cp.start.first][cp.start.second]='W';
				
				s.flip(cp.end.first,cp.end.second,c3);
				board[cp.end.first][cp.end.second]='W';
			}
			cp=findClosest();
		}
		return s;
	}
	/*bool isLast(pair<int,int> p){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)if(i!=p.first && j!=p.second){
				if(board[i][j]=='B')return false;
			}
		}
		return true;
	}*/
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t){
		int n,m,c2,c3;
		scanf("%d %d %d %d",&n,&m,&c2,&c3);
		Solver s(n,m,c2,c3);
		Soln soln=s.solve();
		if(debug)s.print();
		soln.print();
		--t;
	}
	return 0;
}

