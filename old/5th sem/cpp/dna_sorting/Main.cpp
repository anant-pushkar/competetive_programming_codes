#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
int merge(string &s,int start,int mid, int end){
	//if(debug)cout<<"merge("<<s<<","<<start<<","<<mid<<","<<end<<")"<<endl;
	int i=start,j=mid,count=0,index=0;
	for(int i=start;i<mid;++i){
		while(j<end && s[j]<s[i])++j;
		//if(s[j]>=s[i] || (j==end && s[j-1]<s[i])){
			count+=j-mid;
			//if(debug)cout<<s[i]<<":"<<j-mid<<endl;
		//}
		//while(j<end && s[j]==s[i])++j;
	}
	i=start;j=mid;
	vector<char> str(end-start);
	while(i<mid && j<end && index<end-start){
		if(s[i]-'0'<=s[j]-'0')str[index++]=s[i++];
		else str[index++]=s[j++];
	}
	while(i<mid)str[index++]=s[i++];
	while(j<end)str[index++]=s[j++];
	for(i=start;i<end;++i)s[i]=str[i-start];
	return count;
}
int recurse(string &s,int start,int end){
	//if(debug)cout<<"recurse("<<s<<","<<start<<","<<end<<")"<<endl;
	if(start>=end-1)return 0;
	int mid=(start+end)/2,count=0;
	count+=recurse(s,start,mid);
	count+=recurse(s,mid,end);
	count+=merge(s,start,mid,end);
	return count;
}
int getInversionCount(string s){
	return recurse(s,0,s.size());
}
bool compare(const string &s1 ,const string &s2){
	return getInversionCount(s1)<=getInversionCount(s2);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m ; scanf("%d %d\n",&n,&m);
	vector<string> arr(m);
	while(m--)cin>>arr[m];
	sort(arr.begin(),arr.end(),compare);
	//if(debug)cout<<endl;
	//for(int i=0;i<arr.size();++i)cout<<arr[i]<<" "<<getInversionCount(arr[i])<<endl;
	for(int i=0;i<arr.size();++i)cout<<arr[i]<<endl;
	return 0;
}

