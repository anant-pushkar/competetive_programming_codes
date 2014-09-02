#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<climits>
using namespace std;
bool debug=false;
const int INF=1<<29;
struct OrderByRisk{
    bool operator() (pair<int,int> const &a, pair<int,int> const &b) { return a.first > b.first; }
};
typedef std::priority_queue<pair<int,int>, std::vector<pair<int,int> >, OrderByRisk> risk_queue;
class Solver{
	int nVertices,maxTime;
	vector<vector<int> > time , risk;
public:
	Solver(int n, int t):
	nVertices(n),
	maxTime(t),
	time(vector<vector<int> >(n,vector<int>(n,-1))),
	risk(vector<vector<int> >(n,vector<int>(n,-1))){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&time[i][j]);
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&risk[i][j]);
			}
		}
	}
	pair<int,int> solve(){
		vector< vector<int> > riskTo= vector< vector<int> >(maxTime+1,vector<int>(nVertices,INF) ),timeTo= vector< vector<int> >(maxTime+1,vector<int>(nVertices,INF) );
		for(int i=0;i<nVertices;++i){
			for(int j=time[0][i];j<maxTime;++j){
				riskTo[j][i]=risk[0][i];
				timeTo[j][i]=time[0][i];
			}
		}
		int riskVal,timeVal;
		for(int i=1;i<=maxTime;++i){
			for(int j=0;j<nVertices;++j){
				riskVal=INF;
				for(int k=0;k<nVertices;++k)if(i-time[k][j]>=0){
					if(riskVal>riskTo[i-time[k][j]][k]+risk[k][j]){
						riskVal=riskTo[i-time[k][j]][k]+risk[k][j];
						timeVal=timeTo[i-time[k][j]][k]+time[k][j];
					}
				}
				if(riskVal>riskTo[i-1][j] || (riskVal==riskTo[i-1][j] && timeVal<timeTo[i-1][j]) ){
					riskVal=riskTo[i-1][j];
					timeVal=timeTo[i-1][j];
				}
				riskTo[i][j]=riskVal;
				timeTo[i][j]=timeVal;
				if(debug){
					cout<<"riskTo["<<i<<"]["<<j<<"] = "<<riskVal<<endl;
					cout<<"timeTo["<<i<<"]["<<j<<"] = "<<timeVal<<endl;
					cout<<endl;
				}
			}
		}
		return make_pair(riskTo[maxTime][nVertices-1],timeTo[maxTime][nVertices-1]);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,N,T;scanf("%d",&t);
	pair<int,int> soln;
	while(t--){
		scanf("%d",&N);scanf("%d",&T);
		Solver s(N,T);
		soln=s.solve();
		if(soln.second<=T)
			printf("%d %d\n",soln.first,soln.second);
		else printf("-1\n");
	}
	return 0;
}

