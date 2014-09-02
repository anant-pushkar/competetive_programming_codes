#include"circus.h"
using namespace std;
extern void printSoln(std::vector<std::pair<int,int> >);
int main()
{
	int T,N;
	cin>>T;
	
	vector<pair<int,int> > v;
	std::vector<std::pair<int,int> > soln;
	for(int t=0;t<T;t++){
		cin>>N;
		SeqFinder finder(N);
		printSoln(finder.find());
	}
	return 0;
}
