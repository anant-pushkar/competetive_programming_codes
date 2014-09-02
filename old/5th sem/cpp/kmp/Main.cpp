#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string text,pat;
	cin>>text>>pat;
	vector<vector<int> > dfa(pat.size(),vector<int>(1<<8,0));
	dfa[0][pat[0]-0]=1;
	int i=0,j=1;
	while(j<pat.size()){
		for(int q=0;q<dfa[j].size();++q){
			if(pat[j]-0==q)dfa[j][q]=j+1;
			else dfa[j][q]=dfa[i][q];
		}
		i=dfa[i][pat[j]-0];
		++j;
	}
	for(i=0,j=0;i<text.size();++i){
		j=dfa[j][text[i]-0];
		if(j==pat.size()){
			cout<<"found"<<endl;
			break;
		}
	}
	return 0;
}
