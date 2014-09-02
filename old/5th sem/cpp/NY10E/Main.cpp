#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
void print(vector<long long int> v){
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
class Solver{
	int num;
	long long int recurse(vector<long long int> &lookup , vector<long long int> &arr , int nDigits){
		arr[0]=lookup[0];
		for(int i=1;i<arr.size();++i){
			arr[i]=arr[i-1]+lookup[i];
		}
		if(debug){
			cout<<"#"<<nDigits<<" : ";
			print(arr);
		}
		if(nDigits==num){
			long long int sum=0;
			for(int i=0;i<arr.size();++i)sum+=arr[i];
			return sum;
		}
		return recurse(arr,lookup,nDigits+1);
	}
public:
	Solver(int n):
	num(n){}
	
	long long int solve(){
		if(num==1)return 10;
		vector<long long int>lookup(10,1),arr(10);
		return recurse(lookup,arr,2);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,i;scanf("%d",&t);
	while(t){
		scanf("%d %d",&i,&n);
		Solver s(n);
		printf("%d %lld\n",i,s.solve());
		--t;
	}
	return 0;
}

