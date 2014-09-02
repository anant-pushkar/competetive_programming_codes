#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class  Lookup{
	vector<int> arr;
public:
	Lookup(int n):
		arr(vector<int>((n + pow(2 , (static_cast<int>(log(n)/log(2))+1))) , 0 ))
		{
			//cout<<"Lookup Created"<<endl;
		}
	
	int flip(int l , int u , int index , int a , int b)
	{
		//cout<<"Flipping request at "<<l<<" "<<u<<"a="<<a<<" b="<<b<<endl;
		if(index >= this->arr.size() ){
			return 0;
		}
		if(l==u){
			//cout<<"Flipping "<<l<<endl;
			this->arr[index] = this->arr[index]^1;
			return pow(-1,this->arr[index]+1);
		}
		if(b<=(l+u)/2){
			//cout<<"Did not flip because b<=u/2"<<endl;
			int delta=this->flip(l,(l+u)/2,2*index+1,a,b);
			this->arr[index]+=delta;
			return delta;
		}
		if(a>(l+u)/2){
			//cout<<"Did not flip because a>u/2"<<endl;
			int delta=this->flip((l+u)/2+1,u,2*index+2,a,b);
			this->arr[index]+=delta;
			return delta;
		}
		int delta1=this->flip(l,(l+u)/2,2*index+1,a,(l+u)/2);
		int delta2=this->flip((l+u)/2+1,u,2*index+2,(l+u)/2+1,b);
		this->arr[index]+=delta1+delta2;
		return delta1+delta2;
	}
	int query(int l , int u , int index , int a , int b)
	{
		//cout<<"Querying "<<l<<" "<<u<<endl;
		if(index >= this->arr.size() ){
			return this->arr[this->arr.size()-1];
		}
		if(a==l && u==b){
			return this->arr[index];
		}
		if(l==u){
			return this->arr[index];
		}
		if(b<=(l+u)/2){
			return this->query(l,(l+u)/2,2*index+1,a,b);
		}
		if(a>(l+u)/2){
			return this->query((l+u)/2+1,u,2*index+2,a,b);
		}
		int count1=this->query(l,(l+u)/2,2*index+1,a,(l+u)/2);
		int count2=this->query((l+u)/2+1,u,2*index+2,(l+u)/2+1,b);
		return count1+count2;
	}
};
int main()
{
	int n,q,op,a,b;
	cin>>n>>q;
	Lookup play(n);
	for(int i=0;i<q;i++)
	{
		cin>>op>>a>>b;
		if(op == 0){
			play.flip(0,n-1,0,a,b);
		}
		if(op == 1){
			cout<<( play.query(0,n-1,0,a,b) )<<endl;
		}
	}
	return 0;
}
