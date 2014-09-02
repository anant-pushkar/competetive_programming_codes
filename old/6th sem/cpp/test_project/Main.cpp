/*
Project name : test_project
Created on : Tue Dec 17 20:29:56 2013
test project for first complete implementation
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(debug)cout<<n<<"+2=";
		printf("%d\n",n+2);
	}
	return 0;
}

