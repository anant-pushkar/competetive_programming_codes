#include<iostream>
#include<vector>
const int limit = 316240;
std::vector<int> lookup;
int len;
void init()
{
	int index=2 , temp;
	std::vector<int> arr(limit,0);
	arr[0]=1;arr[1]=1;
	while(index<limit)
	{
		while(arr[index]==1) index++;
		temp=2*index;
		while(temp<limit)
		{
			arr[temp]=1;
			temp+=index;
		}
		index++;
	}
	for(int i=0;i<limit;i++)
		if(arr[i]==0)
			lookup.push_back(i);
	len=lookup.size();
	/*for(int i=0;i<10;i++)
		std::cout<<lookup[i]<<std::endl;*/
}
void printFromCache(int n, int m)
{
	if(n==1)n++;
	for(int i=0;i<len;i++)
	{
		if(lookup[i]>m)
			break;
		if(lookup[i]>=n)
			std::cout<<lookup[i]<<std::endl;
	}
	std::cout<<std::endl;
}
void generateAndPrint(long int n , long int m)
{
	long int index=0;
	std::vector<int> resArr(m-n+1 , 0);
	for(int i=0;i<len && lookup[i]*lookup[i]<=m;i++)
	{
		index=0;
		while(index<m-n+1){
			if( (n+index)%lookup[i] != 0)
				index++;
			else
				break;
		}
		while(index<m-n+1)
		{
			if(resArr[index]!=1){
				//std::cout<<n+index<<" eleminated by "<<lookup[i]<<std::endl;
				resArr[index]=1;
			}
			index+=lookup[i];
		}
	}
	for(int i=0;i<resArr.size();i++)
		if(resArr[i]==0)
			std::cout<<(n+i)<<std::endl;
	std::cout<<std::endl;
}
void printPrime(long int n , long int m)
{
	if(m<=limit)
		printFromCache(n,m);
	else
		generateAndPrint(n,m);
}
int main()
{
	init();
	int T;
	std::cin>>T;
	long int n,m;
	for(int t=0;t<T;t++)
	{
		std::cin>>n>>m;
		printPrime(n,m);
	}
	return 0;
}