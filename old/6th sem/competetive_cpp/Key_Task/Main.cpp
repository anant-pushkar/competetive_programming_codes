/*
Project name : Key_Task
Created on : Fri Jan 31 22:33:42 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CERC07K/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool debug=false;
typedef long long int lld;
class Grid{
	vector<vector<char> > map;
	int nRow,nCol,x_pos,y_pos;
	queue<pair<int,int> > posQ;
	queue<int> count;
	queue<bool> BQ,YQ,RQ,GQ;
	vector<vector<int> > bLookup,yLookup,rLookup,gLookup;
	int i,j,c;
	bool b,y,r,g;
	void visit(int p,int q){
		if(debug){
			cout<<"Visiting "<<map[p][q]<<" at "<<p<<","<<q<<endl;
		}
		posQ.push(make_pair(p,q));
		BQ.push(b);bLookup[p][q]=bLookup[i][j];
		YQ.push(y);yLookup[p][q]=yLookup[i][j];
		RQ.push(r);rLookup[p][q]=rLookup[i][j];
		GQ.push(g);gLookup[p][q]=gLookup[i][j];
		count.push(c+1);
	}
	void touch(int n,int m){
		if(n<nRow && n>=0 && m<nCol && m>=0 && map[n][m]!='#'){
			if(bLookup[i][j]==bLookup[n][m] && yLookup[i][j]==yLookup[n][m] && rLookup[i][j]==rLookup[n][m] && gLookup[i][j]==gLookup[n][m]){
				if(debug)cout<<"Exiting with repetetion from "<<map[n][m]<<" at "<<n<<","<<m<<endl;
				return;
			}
			if(map[n][m]=='*' || map[n][m]=='X' || map[n][m]=='.' || (map[n][m]=='G' && g) || (map[n][m]=='R' && r) || (map[n][m]=='Y' && y) || (map[n][m]=='B' && b)){
				visit(n,m);
			}else if(map[n][m]=='g'){
				g=true;
				visit(n,m);
				if(!GQ.front())++gLookup[n][m];
			}else if(map[n][m]=='r'){
				r=true;
				visit(n,m);
				if(!RQ.front())++rLookup[n][m];
			}else if(map[n][m]=='y'){
				y=true;
				visit(n,m);
				if(!YQ.front())++yLookup[n][m];
			}else if(map[n][m]=='b'){
				b=true;
				visit(n,m);
				if(!BQ.front())++bLookup[n][m];
			}
		}
	}
public:
	Grid(int r,int c):
	nRow(r),
	nCol(c),
	map(vector<vector<char> >(r,vector<char>(c))){
		char temp;
		scanf("%c",&temp);
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='*'){
					x_pos=i;
					y_pos=j;
				}
			}
		}
	}
	int solve(){
		bLookup=vector<vector<int> >(nRow,vector<int>(nCol,-1));
		yLookup=vector<vector<int> >(nRow,vector<int>(nCol,-1));
		rLookup=vector<vector<int> >(nRow,vector<int>(nCol,-1));
		gLookup=vector<vector<int> >(nRow,vector<int>(nCol,-1));
		b=false;y=false;r=false;g=false;
		i=x_pos;j=y_pos;
		bLookup[i][j]=0;
		yLookup[i][j]=0;
		rLookup[i][j]=0;
		gLookup[i][j]=0;
		c=-1;
		visit(i,j);
		
		int a,b;
		while(!posQ.empty()){
			i=posQ.front().first;
			j=posQ.front().second;
			if(map[i][j]=='X')break;
			posQ.pop();
			c=count.front();count.pop();
			
			b=BQ.front();
			y=YQ.front();
			r=RQ.front();
			g=GQ.front();
			
			touch(i+1,j);
			touch(i,j+1);
			touch(i,j-1);
			touch(i+1,j);
			
			BQ.pop();
			YQ.pop();
			RQ.pop();
			GQ.pop();
		}
		if(map[i][j]=='X')return count.front();
		return -1;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int r,c,soln;
	char temp;
	while(1){
		cin>>r>>c;
		if(debug)cout<<"r="<<r<<"c="<<c<<endl;
		if(r==0 && c==0)break;
		Grid g(r,c);
		soln=g.solve();
		if(soln==-1)printf("The poor student is trapped!\n");
		else printf("Escape possible in %d steps.\n",soln);
		scanf("%c",&temp);scanf("%c",&temp);
	}
	return 0;
}

