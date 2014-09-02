#include<iostream>
#include<sstream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int ADD=-1;
const int SUB=-2;
const int MUL=-3;
const int DIV=-4;
queue<double> getNumQueue(const string &str){
	//cout<<"Processing num"<<endl;
	string temp=str;
	queue<double> q;
	double n;
	replace(temp.begin(),temp.end(),'+',' ');
	replace(temp.begin(),temp.end(),'-',' ');
	replace(temp.begin(),temp.end(),'*',' ');
	replace(temp.begin(),temp.end(),'/',' ');
	//cout<<"temp : "<<temp<<endl;
	for(int i=0;i<str.size()-1;i++){
		if( (str[i]=='*' || str[i]=='/') && str[i+1]=='-'){
			temp[i+1]='-';
		}
	}
	stringstream ss(temp);
	while(ss){
		ss>>n;
		q.push(n);
	}
	return q;
}
queue<double> getOpsQueue(const string &str){
	//cout<<"Processing ops"<<endl;
	string temp=str;
	temp=str;
	for(int i=0;i<temp.size();i++){
		if(temp[i]-'0'>-1 && temp[i]-'0'<10){
			temp[i]=' ';
		}
		if(temp[i]=='.'){
			temp[i]=' ';
		}
	}
	for(int i=0;i<str.size()-1;i++){
		if( (str[i]=='*' || str[i]=='/') && str[i+1]=='-'){
			temp[i+1]=' ';
		}
	}
	//cout<<temp<<endl;
	stringstream ss(temp);
	queue<double> ops;
	char c;
	while(ss){
		ss>>c;
		switch(c){
		case '+':
			ops.push(ADD);
			break;
		case '-':
			ops.push(SUB);
			break;
		case '*':
			ops.push(MUL);
			break;
		case '/':
			ops.push(DIV);
			break;
		default:
			cout<<"Invalid character at : "<<c<<endl;
			break;
		}
	}
	return ops;
}
vector<double> preProccess(const string &str){
	queue<double> q=getNumQueue(str) , ops=getOpsQueue(str);
	int len=q.size()+ops.size();
	vector<double> v(len-2);
	int i=1;
	v[0]=q.front();q.pop();
	while(i<len-2){
		v[i++]=ops.front();ops.pop();
		v[i++]=q.front();q.pop();
	}
	return v;
}
double calculate(string str){
	replace(str.begin(),str.end(),'(',' ');
	replace(str.begin(),str.end(),')',' ');
	cout<<"Calculate called on : |"<<str<<"|"<<endl;
	vector<double> v=preProccess(str);
	cout<<"Original vector : ";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v.size()-2;i+=2){
		if(v[i+1]==DIV){
			if(v[i+2]==SUB){
				v.erase(v.begin()+i+2);
				v[i+2]=-v[i+2];
			}
			v[i]=v[i]/v[i+2];
			v.erase(v.begin()+i+2);
			v.erase(v.begin()+i+1);
		}
	}
	cout<<"After Division : ";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v.size()-2;i+=2){
		if(v[i+1]==MUL){
			if(v[i+2]==SUB){
				v.erase(v.begin()+i+2);
				v[i+2]=-v[i+2];
			}
			v[i]=v[i]*v[i+2];
			v.erase(v.begin()+i+2);
			v.erase(v.begin()+i+1);
		}
	}
	cout<<"After Multiplication : ";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v.size()-2;i+=2){
		if(v[i+1]==SUB){
			v[i]=v[i]-v[i+2];
			v.erase(v.begin()+i+1);
			if(v.size()>2)v.erase(v.begin()+i+1);
		}
	}
	cout<<"After Subtraction : ";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	double sum=0;
	for(int i=0;i<v.size();i+=2){
		sum+=v[i];
	}
	return sum;
}
double eval(string str , int start , int end){
	cout<<"eval called on : ";
	for(int i=start;i<end;i++)cout<<str[i];
	cout<<endl;
	int i=start , j=end-1 ;
	double ret;
	while(i<str.size() && str[i]!='(')i++;
	while(j>-1 && str[j]!=')')j--;
	if(i==str.size()){
		ret=calculate(str.substr(start,end-start));
		cout<<"returning : "<<ret<<endl;
		return ret;
	}
	else{
		double val=eval(str , i+1 , j);
		if(i>0 && str[i-1]-'0'>-1 && str[i-1]-'0'<10){
			str[i]='*';
			i++;
		}
		stringstream ss;ss<<val;
		str.replace(i,j-i+1,ss.str());
		ret=calculate(str.substr(start,end-start));
		cout<<"returning : "<<ret<<endl;
		return ret;
	}
}
double evalFunction(string str , double x){
	stringstream ss;ss<<x;
	string strVal=ss.str();
	int index=str.find('x',0);
	while(str.find('x',index)!=string::npos){
		if(index>0 && str[index-1]-'0'>-1 && str[index-1]-'0'<10) str.replace(index,1,"*"+strVal);
		else str.replace(index,1,strVal);
		index=str.find('x',index+1);
	}
	return eval(str,0,str.size());
}
int main()
{
	string str;
	int index;
	double soln,c,m,rhs;
	while(1){
		getline(cin,str);
		index=str.find('=');
		c=evalFunction(str.substr(0,index),0);
		m=evalFunction(str.substr(0,index),1)-c;
		stringstream ss(str.substr(index+1));
		ss>>rhs;
		cout<<"Simplified eqn : "<<m<<"x+"<<c<<"="<<rhs<<endl;
		soln=(rhs-c)/m;
		cout<<"x = "<<soln<<endl;
	}
	return 0;
}
