#include"circus.h"
#include<algorithm>
using namespace std;
void printSoln(std::vector<std::pair<int,int> > soln)
{
	cout<<"Solution is : ";
	for(int i=0;i<soln.size();i++){
		cout<<" ("<<soln[i].first<<","<<soln[i].second<<") ";
	}
	cout<<endl;
}
bool compareFirst(pair<int,int> a , pair<int,int> b)
{
	return a.first<b.first ;
}
bool compareSecond(pair<int,int> a , pair<int,int> b)
{
	return a.second<b.second ;
}
SeqFinder::SeqFinder(int n):
seqFirst(vector<pair<int,int> >(n)),
seqSecond(vector<pair<int,int> >(n)),
lenLookup(vector<int>(n,0)),
preLookup(vector<int>(n,-1))
{
	//cout<<"Reading points."<<endl;
	for(int i=0;i<n;i++){
		cin>>seqFirst[i].first ;
		cin>>seqFirst[i].second;
		seqSecond[i]=seqFirst[i];
	}
	//cout<<"Completed reading points"<<endl;
	sort( seqFirst.begin(), seqFirst.end(), compareFirst);
	sort(seqSecond.begin(),seqSecond.end(),compareSecond);
	//cout<<"Completed sorting"<<endl;
	//cout<<"seqFirst : ";printSoln(seqFirst);
	//cout<<"seqSecond : ";printSoln(seqSecond);
}
int SeqFinder::findAncester(vector<pair<int,int> > seq , int index)
{
	int i=index-1;
	while( i>=0 && ( seq[i].first>seq[index].first || seq[i].second>seq[index].second ) ){
		i--;
	}
	return i;
}

void SeqFinder::populate(int index)
{
	//cout<<"Populating : "<<index<<endl;
	if(lenLookup[index]!=0 ){
		//cout<<"Already populated"<<endl;
		return;
	}
	if(index>seqFirst.size()-1){
		//cout<<"Index out of range"<<endl;
		return;
	}
	//get location of given point in seqSecond
	int secIndex  = lower_bound(seqSecond.begin(),seqSecond.end(),seqFirst[index])-seqSecond.begin();
	
	int firstAncIndex = findAncester(seqFirst , index);//find proper ancestor in seqFirst
	int secondAncIndex= findAncester(seqSecond, secIndex);//find proper ancestor in seqSecond
	
	if(firstAncIndex==-1 || secondAncIndex==-1){//check for base case
		lenLookup[index] = 1;
		preLookup[index] = index;
		return;
	}
	
	//getlocation of second ancestor in seqFirst as all addressing is done wrt seqFirst
	secondAncIndex = lower_bound(seqFirst.begin(),seqFirst.end(),seqSecond[secondAncIndex])-seqFirst.begin();
	if(lenLookup[secondAncIndex]==0){//populate this ancester if not done yet
		populate(secondAncIndex);
	}
	
	int ancIndex = lenLookup[firstAncIndex] > lenLookup[secondAncIndex] ? firstAncIndex : secondAncIndex;
	lenLookup[index] = lenLookup[ancIndex]+1;
	preLookup[index] = ancIndex;
}
std::vector<std::pair<int,int> > SeqFinder::find()
{
	for(int i=0;i<seqFirst.size();i++){
		populate(i);
	}
	int maxLen=-1,maxIndex=-1;
	for(int i=0;i<seqFirst.size();i++){
		if(maxLen<lenLookup[i]){
			maxLen=lenLookup[i];
			maxIndex=i;
		}
		
	}
	/*
	cout<<"seqFirst : ";
	printSoln(seqFirst);
	cout<<endl;
	
	cout<<"lenLookup : ";
	for(int i=0;i<seqFirst.size();i++){
		cout<<"\t"<<lenLookup[i];
	}	
	cout<<endl;
	
	cout<<"preLookup : ";
	for(int i=0;i<seqFirst.size();i++){
		cout<<"\t"<<preLookup[i];
	}	
	cout<<endl;
	*/
	std::vector<std::pair<int,int> > soln(maxLen);
	int index=maxIndex,i=0;
	while(preLookup[index]!=index){
		soln[i++]=seqFirst[index];
		index=preLookup[index];
	}
	
	soln[maxLen-1]=seqFirst[index];
	return soln;
}














