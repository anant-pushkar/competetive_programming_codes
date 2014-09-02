#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char str[80];
	vector<int> frequency(26,0);
	for(int q=0;q<4;++q){
		cin.getline(str,75);
		for(int i=0;i<strlen(str);++i)if(str[i]-'A'>=0 && str[i]-'A'<26)++frequency[str[i]-'A'];
	}
	int max=0;
	for(int i=0;i<26;++i){
		if(max<frequency[i])max=frequency[i];
	}
	vector<vector<char> > screen(max+1,vector<char>(26,' '));
	for(int i=0;i<max;++i){
		for(int j=0;j<26;++j){
			if(frequency[j]==max-i){
				screen[i][j]='*';
				--frequency[j];
			}
		}
	}
	for(int i=0;i<max;++i){
		for(int j=25;j>=0;--j){
			if(screen[i][j]==' ')screen[i][j]='#';
			else break;
		}
	}
	for(int i=0;i<26;++i)screen[max][i]=(char)('A'+i);
	for(int i=0;i<=max;++i){
		for(int j=0;j<26 && screen[i][j]!='#';++j)printf("%c ",screen[i][j]);
		printf("\n");
	}
	return 0;
}

