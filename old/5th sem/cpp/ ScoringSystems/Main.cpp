/*
Project name :  ScoringSystems
Created on : Sun Dec  8 01:00:02 IST 2013
http://community.topcoder.com/stat?c=problem_statement&pm=12830
Input format : 
t{number of tets cases}
n{number of questions} 
<c[i]> 
<s[i]> 
eg : 
1
3 
250 500 1000 
300 600 900

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
typedef long long int lld;
struct SubSet{
	lld value,signature;
	
	SubSet():
	value(-1),
	signature(-1){}
	
	SubSet(lld v , lld s):
	value(v),
	signature(s){}
};
bool compare(const SubSet &a , const SubSet &b){
	return a.value<b.value;
}
bool debug=false;
int n,t;
vector<int> c,s;
deque<SubSet> c_subset_list , s_subset_list;
void recurse(const vector<int> &v , lld sign , lld val, int index , deque<SubSet> &list){
	if(index==v.size()){
		list.push_back(SubSet(val,sign));
		return ;
	}
	recurse(v,sign<<1,val,index+1,list);//not including v[index]
	recurse(v,(sign<<1)+1,val+v[index],index+1,list);//including v[index]
}
void create_list(){//creates list of subsets and sorts each half of the each subset list according to value
	recurse(c,0,0,0,c_subset_list);
	recurse(s,0,0,0,s_subset_list);
	sort(c_subset_list.begin(),c_subset_list.begin()+c_subset_list.size()/2);
	sort(c_subset_list.begin()+c_subset_list.size()/2,c_subset_list.end());
	sort(s_subset_list.begin(),s_subset_list.begin()+s_subset_list.size()/2);
	sort(s_subset_list.begin()+s_subset_list.size()/2,s_subset_list.end());
}
bool operator!=(const SubSet &a , const SubSet &b){
	return a.signature!=b.signature;
}
bool operator>(const SubSet &a , const SubSet &b){
	return a.value>b.value;
}
bool operator<(const SubSet &a , const SubSet &b){
	return a.value<b.value;
}
ostream& operator<<(ostream &out ,const  SubSet &s){
	out<<"["<<s.value<<","<<s.signature<<"]";
	return out;
}
bool compare_list(){
	if(debug){
		cout<<"C : ";
		for(int i=0;i<c_subset_list.size();++i)cout<<c_subset_list[i]<<" ";
		cout<<endl;
		
		cout<<"S : ";
		for(int i=0;i<s_subset_list.size();++i)cout<<s_subset_list[i]<<" ";
		cout<<endl;
	}
	for(int i=0;i<c_subset_list.size();++i)if(c_subset_list[i]!=s_subset_list[i])return false;
	int i1=0,i2=c_subset_list.size()/2;
	while(i1<c_subset_list.size()/2 && i2<c_subset_list.size()){
		if(c_subset_list[i1].value<c_subset_list[i2].value){
			if(s_subset_list[i1].value<s_subset_list[i2].value)++i1;
			else{
				if(debug)cout<<"returning on "<<i1<<","<<i2<<endl;
				return false;
			}
		}
		if(c_subset_list[i1].value>c_subset_list[i2].value){
			if(s_subset_list[i1].value>s_subset_list[i2].value)++i2;
			else{
				if(debug)cout<<"returning on "<<i1<<","<<i2<<endl;
				return false;
			}
		}
		if(c_subset_list[i1].value==c_subset_list[i2].value){
			if(s_subset_list[i1].value==s_subset_list[i2].value)++i1;
			else{
				if(debug)cout<<"returning on "<<i1<<","<<i2<<endl;
				return false;
			}
		}
	}
	return true;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d",&t);
	while(t--){
		//input : O(n)
		scanf("%d",&n);
		c=vector<int>(n);
		s=vector<int>(n);
		for(int i=0;i<n;++i)scanf("%d",&c[i]);
		for(int i=0;i<n;++i)scanf("%d",&s[i]);
		
		/*
		population of list : O(2^n)
		sorting half lists : O(4*(n/2)*(2^(n/2))) = O(n2^(n/2))
		Total : O(2^n)
		*/
		create_list();
		
		//comparision of list : O(2^n)
		if(!compare_list()){
			printf("Not Equivalent\n");
		}else{
			printf("Equivalent\n");
		}
		
		c_subset_list.clear();
		s_subset_list.clear();
	}
	return 0;
}

