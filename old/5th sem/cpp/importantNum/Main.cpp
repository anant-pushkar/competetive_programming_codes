#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n , m;
vector< vector<int> > output;
int maxCount;
void printArr(vector< vector<int> > arr){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"\t"<<arr[i][j];
		}
		cout<<endl;
	}
}
bool propogate(vector< vector<int> > arr , int &x , int &y){
	int maxVal=-1 , maxX , maxY;
	if(x+1<n && arr[x+1][y]>maxVal){
		maxX=x+1;
		maxY=y;
		maxVal=arr[maxX][maxY];
	}
	if(y+1<m && arr[x][y+1]>maxVal){
		maxX=x;
		maxY=y+1;
		maxVal=arr[maxX][maxY];
	}
	if(x-1>-1 && arr[x-1][y]>maxVal){
		maxX=x-1;
		maxY=y;
		maxVal=arr[maxX][maxY];
	}
	if(y-1>-1 && arr[x][y-1]>maxVal){
		maxX=x;
		maxY=y-1;
		maxVal=arr[maxX][maxY];
	}
	if(maxVal==-1 || maxVal<=arr[x][y]) return false;
	x=maxX;
	y=maxY;
	//cout<<"Important found at : "<<x<<","<<y<<endl;
	return true;
}
int countImportant(vector< vector<int> > arr){
	int c=0,x=0,y=0;
	//cout<<"Processing : "<<endl;
	//printArr(arr);
	while(propogate(arr,x,y)){
		c++;
	}
	return c;
}
void process(vector< vector<int> > arr){
	int c=countImportant(arr),diff=0;
	//cout<<"C : "<<c<<"maxCount : "<<maxCount<<endl;
	if(c>maxCount){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				//cout<<"Accessing : "<<i<<","<<j<<endl;
				if(output[i][j]!=arr[i][j])diff++;
				output[i][j]=arr[i][j];
			}
		}
		maxCount=c;
		cout<<"Diff : "<<diff<<endl;
	}
}
void populate(vector< vector<int> > arr , vector<bool> numUsed){
	bool flag=false;
	//cout<<"populating : "<<endl;
	//printArr(arr);
	//cout<<endl<<endl;
	if(find(numUsed.begin() , numUsed.end() , false)==numUsed.end()) flag=true;
	if(flag){
		process(arr);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==-1){
				for(int k=0;k<numUsed.size();k++){
					if(!numUsed[k]){
						arr[i][j]=k+1;
						numUsed[k]=true;
						
						populate(arr,numUsed);
						
						arr[i][j]=-1;
						numUsed[k]=false;
					}
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	vector< vector<int> > arr(n,vector<int>(m,-1));
	output = vector< vector<int> >(n,vector<int>(m,-1)) ;
	maxCount=0;
	vector<bool> numUsed(n*m,false);
	string str;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>str;
			if(str!="?"){
				arr[i][j]=atoi(str.c_str());
				numUsed[arr[i][j]-1] = true;
			}
		}
	}
	//printArr(arr);
	populate(arr,numUsed);
	cout<<"maxCount : "<<maxCount+1<<endl;
	printArr(output);
	return 0;
}
