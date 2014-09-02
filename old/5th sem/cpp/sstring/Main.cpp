#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
const int MODULO = 1009;
using namespace std;

class Sstring{
	string str;
	vector<int> lookup;
	int count;
public:
	Sstring(string s):
	str(s),
	lookup(vector<int>(s.size(),0)),
	count(0)
	{
		int len=s.size();
		for(int i=0;i<len;i++){
			lookup[i]=str[i]-'a'+1;
		}
		int check=0,temp;
		vector<int> pow(len,1);
		for(int i=1;i<len;i++){
			pow[i]=pow[i-1]*25;
			pow[i]=pow[i]%MODULO;
		}
		for(int i=0;i<len;i++){
			if(i>1 && lookup[i-1]==lookup[i-2]) break;
			check = (i>0 && lookup[i-1]<lookup[i])? 1 : 0;
			temp  = lookup[i]-1-check;
			count+= (temp>0 ? temp : 0)*pow[len-i-1];
			count = count%MODULO;
		}
		check=1;
		for(int i=1;i<len;i++){
			if(lookup[i-1]==lookup[i]){
				check=0;
				break;
			}
		}
		count+= check;
		count = count%MODULO;
	}
	int getCount(){
		return count;
	}
};
int main()
{
	string str;
	cin>>str;
	Sstring counter(str);
	cout<<counter.getCount()<<endl;
	return 0;
}
