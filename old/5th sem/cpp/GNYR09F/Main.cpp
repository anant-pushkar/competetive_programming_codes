#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<utility>
using namespace std;
bool debug=false;
typedef long long int lld;
map< pair< pair<int,int> , pair<int,int> > , lld> lookup;
lld look(int start , int end , int n , int k){
	if(lookup.find(make_pair( make_pair(start,end) , make_pair(n,k) )) != lookup.end()){
		if(debug){
			cout<<"looking at "<<start<<" "<<end<<" "<<n<<" "<<k<<endl;
			cout<<"Match found"<<endl;
			cout<<"Returning "<<lookup[make_pair( make_pair(start,end) , make_pair(n,k) )]<<endl<<endl;
		}
		return lookup[make_pair( make_pair(start,end) , make_pair(n,k) )];
	}
	if(n<=1 || k<0){
		//if(debug)cout<<"Returning 0"<<endl<<endl;
		return 0;
	}
	if(n==2){
		int val;
		if(start==0 || end==0) val= k==0 ? 1 : 0;
		else val= k<2 ? k : 0;
		//if(debug)cout<<"Returning "<<val<<endl<<endl;
		return val;
	}
	if(n==3){
		if(start==0 && end==0){
			if(k==0)return 2;
			else return 0;
		}
		if( start+end==1 ){
			if(k==1 || k==0)return 1;
			else return 0;
		}
		if(start==1 && end==1){
			if(k==0 || k==2) return 1;
			else return 0;
		}
	}
	if(k==n-1){
		return 1;
	}
	lld count=0 , sum;
	int mid=n/2;
	for(int i=0;i<=k;++i){
		sum = look(start,0,mid,k-i) * look(1,end,n-mid,i);
		sum = ( mid==1 && start!=0) || (n-mid==1 &&end!=1) ? 0 : sum;
		count+=sum;
		if(debug)cout<<n<<" "<<start<<".."<<0<<1<<".."<<end<<" = "<<sum<<" "<<k-i<<","<<i<<endl;
		
		sum = look(start,1,mid,k-i) * look(0,end,n-mid,i);
		sum =(mid==1 && start!=1) || (n-mid==1 && end!=0) ? 0 : sum;
		count+=sum;
		if(debug)cout<<n<<" "<<start<<".."<<1<<0<<".."<<end<<" = "<<sum<<" "<<k-i<<","<<i<<endl;
		
		sum = look(start,0,mid,k-i) * look(0,end,n-mid,i);
		sum =(mid==1 && start!=0) || (n-mid==1 && end!=0) ? 0 : sum;
		count+=sum;
		if(debug)cout<<n<<" "<<start<<".."<<0<<0<<".."<<end<<" = "<<sum<<" "<<k-i<<","<<i<<endl;
		if(k-i-1>=0){
			sum=look(start,1,mid,k-i-1) * look(1,end,n-mid,i);;
			sum=(mid==1 && start==1) || (n-mid==1 && end!=1) ? 0 : sum;
			count+=sum;
			if(debug)cout<<n<<" "<<start<<".."<<1<<1<<".."<<end<<" = "<<sum<<" "<<k-i-1<<","<<i<<endl;
		}
	}
	lookup[make_pair( make_pair(start,end) , make_pair(n,k) )] = count;
	if(debug)cout<<"looking at "<<start<<" "<<end<<" "<<n<<" "<<k<<endl;
	if(debug)cout<<"Returning "<<count<<endl<<endl;
	return count;
}
lld getCount(int n , int k){
	if(debug)cout<<"Counting for "<<n<<" "<<k<<endl;
	return look(1,1,n,k) + look(1,0,n,k) + look(0,1,n,k) + look(0,0,n,k);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,k,i;scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&i,&n,&k);
		printf("%d %lld\n",i,getCount(n,k));
	}
	return 0;
}


