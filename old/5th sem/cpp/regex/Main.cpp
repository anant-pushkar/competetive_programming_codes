#include<iostream>
using namespace std;
void read(string regex,string str){
	int i1=0,i2=1,j=0;
	char reg=regex[i1],lookahead=regex[i2],c=str[j];
	while(i2<regex.size()+1 && i1<regex.size()){
		if(j>=str.size()){
			cout<<"Input too short"<<endl;
			return;
		}
		if(lookahead=='+' || lookahead=='*'){
			if(lookahead=='+' && c!=reg){
				cout<<"Mismatch : "<<reg<<lookahead<<" not same as "<<c<<endl;
				return;
			}
			while(c==reg){
				c=str[++j];
			}
		}
		else if(c!=reg){
			cout<<"Mismatch : "<<reg<<lookahead<<" not same as "<<c<<endl;
			return;
		}else{
			c=str[++j];
		}
		i1=++i2;i2++;
		reg=regex[i1];
	}
	cout<<"Matched"<<endl;
}
int main()
{
	string regex , str;
	int T;cin>>T;
	for(int t=0;t<T;t++){
		cin>>regex>>str;
		read(regex,str);
	}
	return 0;
}
