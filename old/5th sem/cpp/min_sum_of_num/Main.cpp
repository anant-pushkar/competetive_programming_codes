/*
Project name : min_sum_of_num
Created on : Thu Dec 12 20:05:09 IST 2013
http://www.careercup.com/question?id=5678435150069760
Given the array of digits (0 is also allowed), what is the minimal sum
of two integers that are made of the digits contained in the array. 
For example, array: 1 2 7 8 9. The min sum (129 + 78) should be 207
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
class Set{
	vector<int> freq;
	int maxDigit,swapDigit,swap;
	bool zero_allowed;
	void manage_zero(){
		if(debug)cout<<"max digit : "<<maxDigit<<endl;
		if(zero_allowed){
			int sum_freq=0;
			for(int i=1;i<10;++i)sum_freq+=freq[i];
			if(swap==0 && sum_freq==2 && freq[0]!=0){
				if(debug)cout<<"Swapping in 0 from "<<maxDigit<<endl;
				swap=1;
				swapDigit=maxDigit;
				maxDigit=0;
			}
			if(swap==1 && freq[0]==0){
				if(debug)cout<<"Swapping back "<<swapDigit<<endl;
				maxDigit=swapDigit;
				swap=2;
			}
		}
	}
public:
	Set(int n,bool za):
	freq(vector<int>(10,0)),
	maxDigit(9),
	zero_allowed(za),
	swap(0){
		int num;
		while(n--){
			scanf("%d",&num);
			++freq[num];
		}
		while(maxDigit>=0 && freq[maxDigit]==0)--maxDigit;
	}
	int getMax(){
		while(maxDigit>=0 && freq[maxDigit]==0)--maxDigit;
		manage_zero();
		if(maxDigit==-1){
			if(debug)cout<<"Returning due to empty set"<<endl;
			return -1;
		}
		--freq[maxDigit];if(debug)cout<<"freq["<<maxDigit<<"] being reduced to "<<freq[maxDigit]<<endl;
		return maxDigit;
	}
	bool isEmpty(){
		while(maxDigit>=0 && freq[maxDigit]==0)--maxDigit;
		manage_zero();
		if(maxDigit==-1){
			if(debug)cout<<"Returning due to empty set"<<endl;
			return true;
		}
		return false;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,za;scanf("%d",&t);
	long long int sum,place_value;
	while(t--){
		scanf("%d %d",&n,&za);
		Set s(n,za==1);
		place_value=1;
		sum=0;
		while(!s.isEmpty()){
			sum+=s.getMax()*place_value;if(debug)cout<<sum<<endl;
			if(s.isEmpty())break;
			sum+=s.getMax()*place_value;if(debug)cout<<sum<<endl;
			place_value*=10;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

