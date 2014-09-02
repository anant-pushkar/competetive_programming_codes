#include<iostream>
#include<map>
#include<vector>
using namespace std;
int update(map<char,int> &lastPos , char c , int pos){
	int index=-1;
	if(lastPos.find(c)!=lastPos.end()){
		index=lastPos[c];
	}
	lastPos[c]=pos;
	return index;
}
vector<int> populate_lookup(const string &str){
	map<char,int> lastPos;
	vector<int> lookup(str.size());
	for(int i=str.size()-1;i>-1;i--){
		lookup[i]=update(lastPos , str[i] , i );
	}
	cout<<endl;
	return lookup;
}
int count_layer(const string &str , int index , int left , int right){
	int i=right , j=left , count=0;
	cout<<"at "<<i;
	while(j>-1 && i<str.size()){
		if(str[i]==str[j]){
			count++;
			i++;
			j--;
		}else break;
	}
	cout<<"("<<str[i]<<") count : "<<count<<endl;
	return count;
}
int count_palin_substr(const string &str){
	vector<int> lookup=populate_lookup(str);
	for(int i=0;i<str.size();i++){
		cout<<lookup[i]<<" ";
	}
	int i=0 , count=0;
	while(i<str.size()){
		count+=count_layer(str , i , i-1 , i+1);//count even palindromes
		count+=count_layer(str , i , i , i+1);//count odd palindromes
		if(lookup[i]==-1 || lookup[lookup[i]]==-1 )i++; //***a**a*****
		else i=(lookup[i]+lookup[lookup[i]])>>1;
		//i++;
	}
	return count;
}
int main()
{
	string str;
	while(1){
		cin>>str;
		cout<<count_palin_substr(str)<<endl;
	}
	return 0;
}
