/*
Project name : string_task
Created on : Sat Dec  7 01:12:11 IST 2013
http://codeforces.com/problemset/problem/118/A

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
bool debug=false;
bool isVowel(char c)
{
    switch(c)
    {
    case 'a':return true;
    case 'A':return true;
	case 'e':return true;
    case 'E':return true;
	case 'i':return true;
    case 'I':return true;
	case 'o':return true;
    case 'O':return true;
	case 'u':return true;
    case 'U':return true;
	case 'y':return true;
    case 'Y':return true;
    default:
        return false;
    }
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string data;cin>>data;
	for(int i=0;i<data.size();++i){
		if(isVowel(data[i]))continue;
		printf(".%c",tolower(data[i]));
	}
	printf("\n");
	return 0;
}

