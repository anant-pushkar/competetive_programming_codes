#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool debug=false;
class Solver{
	int nDollars , cost , offer ;
public:
	Solver(int n , int c , int m):
	nDollars(n),
	cost(c),
	offer(m){}
	
	int solve(){
		int nChocolates = nDollars/cost , nWrappers=nChocolates;
		while(nWrappers>=offer){
			nChocolates+=nWrappers/offer;
			nWrappers = nWrappers%offer + nWrappers/offer;
			if(debug)cout<<nChocolates<<","<<nWrappers<<endl;
		}
		return nChocolates;
	}
};	
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,c,m;scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&c,&m);
		Solver s(n,c,m);
		printf("%d\n",s.solve());
	}
	return 0;
}

