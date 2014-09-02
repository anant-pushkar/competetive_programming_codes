#include<iostream>
#include<vector>
using namespace std;
class Mat{
	vector< vector<int> > arr;
	int size;
public:
	Mat(int n):
	size(n),
	arr(vector< vector<int> >(n,vector<int>(n))){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
	}
	void rotate(int a,int b){
		int temp=arr[a][b],n=size;
		arr[a][b] = arr[b][n-a-1];
		arr[b][n-a-1] = arr[n-1-a][n-1-b];
		arr[n-1-a][n-1-b] = arr[n-1-b][a];
		arr[n-1-b][a] = temp;
	}
	void rotateAll(){
		for(int i=0;i<(size>>1);i++){
			for(int j=i;j<size-i-1;j++){
				rotate(j,i);
			}
		}
	}
	void printAll(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cout<<arr[i][j]<<" ";
			}
			//cout<<endl;
		}
		cout<<endl;
	}
};
int main()
{
	int T,n;cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;
		Mat mat(n);
		mat.rotateAll();
		mat.printAll();
	}
	return 0;
}
