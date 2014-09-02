#include<iostream>
#include<vector>
using namespace std;
const int MAXLIMIT = 10000000;
vector<int> lookup(MAXLIMIT+1 , -1);
int hold;
void init(){
	lookup[1]=1;
	lookup[2]=2;
	hold=2;
}
void normalize(int& a , int& b)
{
	int c=a;
	a = a>b ? b : a;
	b = c>b ? c : b;
}
inline int next(unsigned long long int n){
	return n%2==0 ? n>>1 : 3*n+1 ;
}
int populate(unsigned long long int n , int count)
{
	//cout<<"Populating at "<<n<<" with count "<<count<<endl;
	if(n<=MAXLIMIT && lookup[n]!=-1) return count+lookup[n];
	int steps=populate(next(n),count+1);
	if(n<=MAXLIMIT)lookup[n]=steps-count;
	return steps;
}
int getAns(int a , int b)
{
	//cout<<"Starting to populate"<<endl;
	for(int i=hold+1;i<=b;i++) populate(i,0);
	hold=b;
	//cout<<"Populated lookup"<<endl;
	int max=-1;
	for(int i=a;i<=b;i++) max = max>lookup[i] ? max : lookup[i] ;
	return max;
}
int main()
{
	int i,j;
	init();
	while(cin>>i>>j){
		normalize(i,j);
		cout<<i<<" "<<j<<" "<<getAns(i,j)<<endl;
	}
	return 0;
}
