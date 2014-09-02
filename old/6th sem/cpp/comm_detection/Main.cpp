/*
Project name : comm_detection
Created on : Mon Feb 10 15:59:23 2014
Author : Anant Pushkar
test project to implement comm detection algo
*/
/*
 * aglomarative algo using similarity
 * 
	void reduce(int m){
		double max,sim;
		int x,y;
		for(int c=0;c<n;++c){
			if(c%m==0)print();
			max=0;
			for(int i=0;i<n;++i)if(live[i]){
				for(int j=i+1;j<n;++j)if(live[j]){
					sim=getSimilarity(i,j);
					if(sim>max){
						max=sim;
						x=i;
						y=j;
					}
				}
			}
			for(int i=0;i<n;++i)adjMat[x][i]+=adjMat[y][i];
			live[y]=false;
		}
	}
	*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<deque>
#include<ctime>
#include<queue>
using namespace std;
bool debug=false;
class RandomGraph{
	int n;
	double p;
	vector<vector<double> > adjMat;
	vector<bool> live;
	double getSimilarity(int x,int y){
		double d1=0,d2=0,sum=0;
		for(int i=0;i<n;++i){
			sum+=adjMat[x][i]*adjMat[y][i];
			d1+=adjMat[x][i];
			d2+=adjMat[y][i];
		}
		return sum/(d1*d2);
	}
	void bfs(int s){
		vector<bool> lookup(n,false);
		
	}
public:
	RandomGraph(int num, double prob,int a):
	n(num),
	p(prob),
	live(vector<bool>(num,true)),
	adjMat(vector<vector<double> >(num,vector<double>(num,0))){
		int v,d,i1;
		for(int i=0;i<num;++i){
			for(int j=0;j<num;++j)if(i!=j){
				d=0;
				for(int k=0;k<n;++k)d+=adjMat[j][k];
				v=0.5*(rand()%1000)+d*100;
				if(v<p*1000){
					adjMat[i][j]=1;
					if(debug)cout<<v<<" "<<p*1000<<endl;
				}
			}
			for(int j=0;j<a;++j){
				
				i1=0;
				while(i1<n && adjMat[i][i1]==0)++i1;
				do{
					d=rand()%n+1;
				}while(d==i && d>=0 && d<n && adjMat[i1][d]==0);
				adjMat[i][d]=1;
			}
		}
		//print();
	}
	void refresh(){
		for(int i=0;i<n;++i)live[i]=true;
	}
	void reduce(int m){
		double max,sim;
		int x,y;
		for(int c=0;c<n;++c){
			if(c%m==0)print();
			max=0;
			for(int i=0;i<n;++i)if(live[i]){
				for(int j=i+1;j<n;++j)if(live[j]){
					sim=getSimilarity(i,j);
					if(sim>max){
						max=sim;
						x=i;
						y=j;
					}
				}
			}
			for(int i=0;i<n;++i)adjMat[x][i]+=adjMat[y][i];
			live[y]=false;
		}
	}
	/*
	 * ^{
			"type":"graph",
			"name" : "test Graph",
			"obj":[
				[1,2,"aev1"],
				[2,3,"sfref"]
			]
		}
	*/
	void print(){
		cout<<"^{\"type\":\"graph\",\"name\":\"G("<<n<<","<<p<<")\",\"obj\":[";
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j)if(adjMat[i][j]!=0 && live[i] && live[j]){
				cout<<"["<<i+1<<","<<j+1<<",\"\"],";
			}
		}
		cout<<"[1,1,\"\"]]}"<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	srand(time(NULL));
	int t;cin>>t;
	int n,m,a;
	double p;
	while(t--){
		cin>>n>>p>>a;
		RandomGraph g(n,p,a);
		cin>>m;
		g.reduce(m);
		g.refresh();
		g.print();
	}
	return 0;
}

