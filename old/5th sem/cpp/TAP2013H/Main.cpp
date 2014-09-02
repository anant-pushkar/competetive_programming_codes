#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
bool debug=false;
vector<int> lookup;
map<int,int> mem;
const int seive_size=1010;
void preprocess(){
	if(debug)cout<<"Preprocessing"<<endl;
	vector<bool> seive(seive_size,true);
	int count=0;
	for(int i=2;i<seive_size;++i)if(seive[i]){
		++count;
		for(int j=i+2;j<seive_size;++j){
			if(j%i==0)seive[j]=false;
		}
	}
	lookup=vector<int>(count);
	int index=0;
	for(int i=2;i<seive_size;++i)if(seive[i]){
		lookup[index++]=i;
		mem[i]==1;
	}
}
int getOrder(int n){
	if(debug)cout<<"getting order of "<<n<<endl;
	if(mem.find(n)!=mem.end()){
		return mem[n];
	}
	int sum=0,num=n;
	for(int i=0;i<lookup.size();++i){
		if(n==1 || lookup[i]>n)break;
		if(n%lookup[i]==0){
			sum+=lookup[i];
			while(n%lookup[i]==0)n/=lookup[i];
		}
	}
	int order;
	if(n!=1){
		mem[n]=1;
		sum+=n;
	}
	order=getOrder(sum)+1;
	mem[num]=order;
	return order;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,a,b,k,order,count;scanf("%d",&t);
	preprocess();
	while(t--){
		scanf("%d %d %d",&a,&b,&k);
		if(k>7){
			printf("0\n");
			continue;
		}
		count=0;
		for(int i=a;i<=b;++i){
			order=getOrder(i)+1;
			if(debug)cout<<"order="<<order<<endl;
			if(order==k)++count;
			if(debug)cout<<endl<<endl;
		}
		printf("%d\n",count);
	}
	return 0;
}

