#include"subsequence.h"
using namespace std;
int main()
{
	int T;cin>>T;
	string s1 , s2;
	for(int t=0;t<T;t++){
		cin>>s1>>s2;
		SubSequenceFinder finder(s1,s2);
		cout<<finder.getLength()<<endl;
	}
	return 0;
}
