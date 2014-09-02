#include<iostream>
using namespace std;
int main()
{
	int T,N,K,pre,next,count,interval;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>N>>K;count=0;
		cin>>pre;
		for(int n=1;n<N;n++)
		{
			cin>>next;
			if(next<pre)count++;
			pre=next;
		}
		count = count>N-count ? N-count : count ;
		if(K>=N){
			cout<<"0"<<endl;
			continue;
		}
		//interval = count<=K/2 ? K-count : K-1 ;
		//interval=K-1;
		interval=1;
		cout<<(N%interval==0 ? N/interval : N/interval+1)<<endl;
		next=N;
		while(N>0)
		{
			cout<<(next-N+1)<<" ";
			N-=interval;
		}
		cout<<endl;
	}
	return 0;
}
