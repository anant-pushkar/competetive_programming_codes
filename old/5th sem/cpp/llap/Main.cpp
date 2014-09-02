#include"llap.h"
using namespace std;
void verify();
void testTime();
int main()
{
	testTime();
	//verify();
	return 0;
}
void testTime()
{
	LlapFinder finder;
	
	int n;
	cout<<"Enter number of elements : ";
	cin>>n; 
	
	clock_t  tic , toc;
	tic = clock();
	
	finder.generate(n);
	cout<<"Array generated."<<endl;
	toc = clock();
	cout<<"Time Elapsed : "<<static_cast<double>( (toc - tic) / CLOCKS_PER_SEC )<<" seconds\n";
	
	finder.getLength();
	toc = clock();
	cout<<"Longest AP found."<<endl;
	cout<<"Time Elapsed : "<<static_cast<double>( (toc - tic) / CLOCKS_PER_SEC )<<" seconds\n";
}

void verify()
{
	int T;
	cin>>T;
	string temp;getline(cin,temp);
	LlapFinder finder;
	for(int t=0;t<T;t++){
		finder.read();
		finder.print();
	}
}