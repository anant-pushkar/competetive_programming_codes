#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int commonLen(const string &a ,const string &b){
	int i=0;
	while(i<max(a.size(),b.size())){
		if(a[i]==b[i])i++;
		else break;
	}
	return i;
}
int main()
{
	char* str=new char[20],*ptr=str;
	cin>>str;
	int len=strlen(str);
	vector<string> suffixArr(len);
	for(int i=0;i<len;i++){
		suffixArr[i]=string(str++,len-i);
	}
	sort(suffixArr.begin(),suffixArr.end());
	int temp,maxLen=-1;
	for(int i=0;i<len-1;i++){
		temp=commonLen(suffixArr[i],suffixArr[i+1]);
		if(temp>maxLen) maxLen=temp;
	}
	cout<<maxLen<<endl;
	return 0;
}
