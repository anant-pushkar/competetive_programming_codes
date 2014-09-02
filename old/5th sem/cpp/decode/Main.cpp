#include<iostream>
#include<string>
#include<sstream>
using namespace std;
char convert(string str){
	stringstream ss(str);
	int ascii;
	ss>>ascii;
	return static_cast<char>(ascii+96);
}
void process(const string &str , string buffer , int index){
	//cout<<"called on : "<<buffer<<endl;
	if(index==str.size()){
		cout<<buffer<<" ";
		return;
	}
	string tempBuffer=buffer;
	if(str[index]=='0') return;
	tempBuffer+=convert(str.substr(index,1));
	process(str,tempBuffer,index+1);
	
	if(str[index]-'0'==1){
		tempBuffer=buffer+convert(str.substr(index,2));
		process(str,tempBuffer,index+2);
	}else if(str[index]-'0'==2  && str[index+1]-'0'<7){
		tempBuffer=buffer+convert(str.substr(index,2));
		process(str,tempBuffer,index+2);
	}

}
int main()
{
	int T;cin>>T;
	string str;
	for(int t=0;t<T;t++){
		cin>>str;
		process(str,"",0);
		cout<<endl;
	}
	return 0;
}
