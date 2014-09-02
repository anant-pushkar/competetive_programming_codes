#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<stack>
using namespace std;
class Boggle{
	vector< vector<char> > arr;
	map<char,stack<pair<int,int> > > lookup;
	int size;
	void insert(char c , int x , int y){
		map<char,stack<pair<int,int> > >::iterator it=lookup.find(c);
		if(it==lookup.end()){
			lookup[c]=stack<pair<int,int> >();
			lookup[c].push(make_pair(x,y));
		}else{
			lookup[c].push(make_pair(x,y));
		}
	}
	bool traverse(pair<int,int> pos ,const string &str , int index){
		cout<<"Traversing "<<arr[pos.first][pos.second]<<endl;
		if(index==str.size()-1){
			return true;
		}
		if(pos.first+1<size && arr[pos.first+1][pos.second]==str[index+1]){
			return traverse(make_pair(pos.first+1,pos.second) , str , index+1);
		}
		if(pos.first-1>-1 && arr[pos.first-1][pos.second]==str[index+1]){
			return traverse(make_pair(pos.first-1,pos.second) , str , index+1);
		}
		if(pos.second+1<size && arr[pos.first][pos.second+1]==str[index+1]){
			return traverse(make_pair(pos.first,pos.second+1) , str , index+1);
		}
		if(pos.second-1>-1 && arr[pos.first][pos.second-1]==str[index+1]){
			return traverse(make_pair(pos.first,pos.second-1) , str , index+1);
		}
		if(pos.first+1<size && pos.second+1<size && arr[pos.first+1][pos.second+1]==str[index+1]){
			return traverse(make_pair(pos.first+1,pos.second+1) , str , index+1);
		}
		if(pos.first+1<size && pos.second-1>-1 && arr[pos.first+1][pos.second-1]==str[index+1]){
			return traverse(make_pair(pos.first+1,pos.second-1) , str , index+1);
		}
		if(pos.first-1>-1 && pos.second+1<size && arr[pos.first-1][pos.second+1]==str[index+1]){
			return traverse(make_pair(pos.first-1,pos.second+1) , str , index+1);
		}
		if(pos.first-1>-1 && pos.second-1>-1 && arr[pos.first-1][pos.second-1]==str[index+1]){
			return traverse(make_pair(pos.first-1,pos.second-1) , str , index+1);
		}
		return false;
	}
public:
	Boggle(int n):
	size(n),
	arr(vector< vector<char> >(n,vector<char>(n,'|')))
	{
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cin>>arr[i][j];
				insert(arr[i][j],i,j);
			}
		}
	}
	bool search(string str){
		bool check=false;
		if(lookup.find(str[0])==lookup.end()){
			return false;
		}
		stack<pair<int,int> > tempSt=lookup[str[0]];
		do{
			check = traverse(tempSt.top(),str,0);
			tempSt.pop();
		}while(!tempSt.empty() && !check);
		return check;
	}
};
int main()
{
	Boggle b(4);
	int T;cin>>T;
	string str;
	for(int t=0;t<T;t++){
		cin>>str;
		if(b.search(str)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
