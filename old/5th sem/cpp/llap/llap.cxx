#include"llap.h"
#include <algorithm>
#include <stack>
using namespace std;
LlapFinder::LlapFinder():
length(0)
{}
#define MAX 10000
void LlapFinder::preprocess()
{
	sort(arr.begin(),arr.end());
	lookupLen = vector<int>(len,0);
	lookupPre = vector<int>(len,-1);
}
void LlapFinder::generate(int n)
{	
	srand(time(NULL));
	len=n;
	arr=vector<int>(n);
	for(int i=0;i<n;i++){
		//cout<<"Pushing : ";
		arr[i]=rand() % MAX;
		//cout<<arr[i]<<endl;
	}
	preprocess();
}
void LlapFinder::read()
{
	cin.clear();
	length=0;
	string line;
	int num;
	stack<int> inputStack;
	getline(cin,line);
	istringstream linestream(line);
	while(linestream>>num){
		inputStack.push(num);
	}
	len=inputStack.size();
	arr=vector<int>(len);
	for(int i=0;i<len;i++){
		arr[i]=inputStack.top();
		inputStack.pop();
	}
	preprocess();
}
int LlapFinder::getLength()
{
	find();
	return length>=2 ? length+1 : 0;
}
void LlapFinder::find()
{
	//pre populate lookup
	lookupPre[0] = 0 ;
	lookupPre[1] = 0 ;
	lookupLen[1] = 1 ;
	
	int index;
	for(int i=2;i<len;i++){
		index=maxIndex(0,i);
		if(index!=-1){
			lookupPre[i] = index;
			lookupLen[i] = lookupLen[index]+1;
		}else{
			lookupPre[i] = i ;
			lookupLen[i] = 0 ;
		}
	}
	length=genMaxLen(0,len);
}
int LlapFinder::maxIndex(int start , int end)
{
	int index=-1,maxLen=-1;
	for(int i=start;i<end;i++){
		if(maxLen<lookupLen[i] && arr[lookupPre[i]]+arr[end]==2*arr[i]){
			index=i;
			maxLen=lookupLen[i];
		}
	}
	return index;
}
int LlapFinder::genMaxLen(int start , int end)
{
	int index=-1,maxLen=-1;
	for(int i=start;i<end;i++){
		if(maxLen<lookupLen[i]){
			index=i;
			maxLen=lookupLen[i];
		}
	};
	if(index==-1) return -1;
	llap.clear();
	while(index!=lookupPre[index]){
		llap.push_back(arr[index]);
		index=lookupPre[index];
	}
	llap.push_back(arr[index]);
	return maxLen;
}
void LlapFinder::print()
{
	int maxLen=getLength();
	cout<<maxLen<<" ";
	for(int i=0;i<llap.size() && maxLen!=0;i++){
		cout<<llap[i]<<" ";
	}
	cout<<endl;
}













