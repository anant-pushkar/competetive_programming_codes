#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	int T,N,K,temp;
	std::vector<int> numArr;
	std::cin>>T;
	for(int t=0;t<T;t++)
	{
		std::cin>>N>>K;K++;
		numArr.clear();numArr=std::vector<int>(K,0);
		for(int n=0;n<N;n++)
		{
			std::cin>>temp;
			numArr[temp%K]++;
		}
		temp=0;
		for(int i=0;i<K;i++)
			if(numArr[i]>=N-1)
				temp=1;
		if(temp==1)
			std::cout<<"YES"<<std::endl;
		else
			std::cout<<"NO"<<std::endl;
	}
	return 0;
}
