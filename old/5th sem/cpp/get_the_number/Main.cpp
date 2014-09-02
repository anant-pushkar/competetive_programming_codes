/*
Project name : get_the_number
Created on : Thu Dec 12 15:30:51 IST 2013
http://www.careercup.com/question?id=5361917182869504

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false,done=false;
void recurse(vector<int> v,int index,int signature){
	if(done)return;
	if(debug){
		cout<<"running on "<<index<<" : "<<signature<<endl;
		for(int i=0;i<32;++i)cout<<v[i];
		cout<<endl<<endl;
	}
	if(index==32){
		int v1=v[0]*16+v[31]*8+v[30]*4+v[29]*2+v[28];
		int v2=v[1]*16+v[0]*8+v[31]*4+v[30]*2+v[29];
		int v3=v[2]*16+v[1]*8+v[0]*4+v[31]*2+v[30];
		int v4=v[3]*16+v[2]*8+v[1]*4+v[0]*2+v[31];
		signature=signature|(1<<v1)|(1<<v2)|(1<<v3)|(1<<v4);
		if( signature==-1){
			int n=0;
			for(int i=0;i<32;++i){
				n=n*2+v[i];
				cout<<v[i];
			}
			cout<<endl<<"num = "<<n<<endl<<endl;
			done=true;
		}
		return;
	}
	int val1,val0,val=v[index-1]*8+v[index-2]*4+v[index-3]*2+v[index-4];
	val1=val+16;
	val0=val;
	if((signature&(1<<val1))==0){
		v[index]=1;
		recurse(v,index+1,signature|(1<<val1));
	}
	if((signature&(1<<val0))==0){
		v[index]=0;
		recurse(v,index+1,signature|(1<<val0));
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	vector<int> num(32,0);
	recurse(num,5,1);
	return 0;
}

