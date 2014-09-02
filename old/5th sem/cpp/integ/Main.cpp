#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//  long long int level;
/*int getCount(const vector<int> &val , int index , int X , int sum){
	int idx=X-index+2>0? X-index+2 : -(X-index+2) ;
	//if(level==-val[idx])cout<<"Asserion faled at "<<level<<endl;
	if(X>index+1) return sum<0?-sum:sum;
	//cout<<"level #"<<level<<" , index="<<index<<" , sum="<<sum<<endl;
	if(index==-1) return 0;
	if(index==0){
		return X!=0 ? -val[0] : 0;
	}
	int newIndex=index;
	while(newIndex>-1 && val[newIndex]>=-level-1)newIndex--;
	if(level*X-sum > (level+1)*X-sum-index-1){
		level++;
		return getCount(val,newIndex,X,sum+index+1);
	}
	else return level*X-sum ;
}*/
void test(){
	  long long int N,X;
	cin>>N;
	vector<  long long int> val(N);
	for(int i=0;i<N;i++) cin>>val[i];
	cin>>X;
	if(X==0){
		cout<<"0"<<endl;
		return;
	}
	  long long int count=0;
	sort(val.begin(),val.end());
	//for(int i=0;i<N;i++) cout<<val[i]<<" ";cout<<endl;
	  long long int index=lower_bound(val.begin(),val.end(),0)-val.begin()-1;
	if(index==0){
		cout<<-val[0]<<endl;
		return;
	}
	if(index==-1){
		cout<<"0"<<endl;
		return;
	}
	
	  long long int sum=0;
	for(  long long int i=0;i<=index;i++)sum+=val[i];
	if(X>=index+1) cout<<(-sum)<<endl;
	else{
		  long long int n = -val[X];
		  long long int s = n*X ;
		sum=0;
		for(  long long int i=0;i<X;i++) sum+=val[i]+n;
		cout<<(s-sum)<<endl;
	}
	/*level=0;
	cout<<getCount(val,index,X,sum)<<endl;*/
}
int main()
{
	//int T;cin>>T;
	//for(int i=0;i<T;i++){
		test();
	//}
	return 0;
}
