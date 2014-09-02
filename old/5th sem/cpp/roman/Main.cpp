#include<iostream>
#include<map>
using namespace std;
/*
	I:1
	V:5
	X:10
	L:50
	C:100
	D:500
	M:1000
*/
map<char,int> lookup;
void populateLookup(){
	lookup['I']=1;
	lookup['V']=5;
	lookup['X']=10;
	lookup['L']=50;
	lookup['C']=100;
	lookup['D']=500;
	lookup['M']=1000;
}
int getVal(char c){
	//cout<<"looking for "<<c<<endl;
	if(lookup.find(c) == lookup.end()) return -1;
	return lookup[c];
}
int convert(string roman){
	
	int acc=getVal(roman[0]) , val , preVal=acc , bufferVal=acc;
	if(acc==-1){
		//cout<<"Returned at 0"<<endl;
		return -1;
	}
	for(int i=1;i<roman.size();i++){
		//cout<<acc<<endl;
		val=getVal(roman[i]);
		if(val<=preVal){
			if(val==preVal) bufferVal+=val;
			acc+=val;
			bufferVal=val;
		}else{
			acc=acc+val-2*bufferVal;
			bufferVal=val;
		}
		preVal=val;
	}
	return acc;
}
int main()
{
	populateLookup();
	string roman;
	while(1){
		cin>>roman;
		cout<<convert(roman)<<endl;
	}
	return 0;
}













