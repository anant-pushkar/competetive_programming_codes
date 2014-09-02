#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long int llu;
int main()
{
	int t;scanf("%d",&t);
	llu n,v,i,m=1;
	vector<llu> l(1000001,-1);
	l[1]=1;
	while(t--){
		cin>>n;
		i=m+1;
		v=l[m];
		for(;i<=n;++i){
			v+=i*(i+1)/2+2*(((i-1)/2)*((i+1)/2)/2)+(i%2==0?i/2:0);
			l[i]=v;
		}
		cout<<l[n]<<endl;
		m=m>n?m:n;
	}
	return 0;
}

