#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n , m;
	char c;
	vector<vector<int> > playArea;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		playArea=vector<vector<int> >(m,vector<int>(n,0));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>c;
				
			}
		}
		
		playArea.clear();
	}
	return 0;
}
