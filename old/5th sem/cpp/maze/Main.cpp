#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
#include <map>
using namespace std;
class Maze{
	int size;
	vector<vector<char> > arr;
	void generate(int x , int y){
		if(x==0 && y==0){
			arr[0][0]='.';
			return ;
		}
		if(x>0 && y>0){
			int check=rand()%2;
			if(check==1){
				generate(x-1,y);
			}else{
				generate(x,y-1);
			}
			arr[x][y]='.';
			return;
		}
		if(x>0){
			generate(x-1,y);
			arr[x][y]='.';
			return;
		}
		if(y>0){
			generate(x,y-1);
			arr[x][y]='.';
			return;
		}
	}
public:
	int getSize(){
		return size;
	}
	Maze(int n):
	size(n),
	arr(vector<vector<char> >(n,vector<char>(n,'X'))){
		/*int num=n*n*pow(static_cast<double>(n),0.15);
		arr[0][0]='.';
		arr[1][0]='.';
		arr[0][1]='.';
		arr[size-1][size-1]='.';
		arr[size-1][size-2]='.';
		arr[size-2][size-1]='.';
		for(int i=0;i<num;i++){
			arr[rand()%size][rand()%size]='.';
		}*/
		cout<<"Genearting path"<<endl;
		generate(size-1,size-1);
		cout<<"Generating subsidiary points"<<endl;
		int count=n*pow(static_cast<double>(n),0.5);
		for(int i=0;i<count;i++){
			arr[rand()%size][rand()%size]='.';
		}
	}
	void clearPath(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(arr[i][j]=='#')arr[i][j]='.';
			}
		}
	}	
	void paintShortestPath(){
		queue<pair<int,int> > q;
		q.push(make_pair(0,0));
		
		map< pair<int,int> , pair<int,int> > edgeTo;
		edgeTo[make_pair(0,0)]=make_pair(0,0);
		
		int x,y;
		while(q.size()>0){
			if(q.front()==make_pair(size-1,size-1)){
				//edgeTo[make_pair(size-1,size-1)]=q.front();
				cout<<"Reached the end"<<endl;
				break;
			}
			x=q.front().first;
			y=q.front().second;
			if(x+1<size && arr[x+1][y]=='.'){
				q.push(make_pair(x+1,y));
				edgeTo[make_pair(x+1,y)]=q.front();
			}
			if(y+1<size && arr[x][y+1]=='.'){
				q.push(make_pair(x,y+1));
				edgeTo[make_pair(x,y+1)]=q.front();
			}
			q.pop();
		}
		if(edgeTo.find(make_pair(size-1,size-1))==edgeTo.end()) return;
		x=edgeTo[make_pair(size-1,size-1)].first;
		y=edgeTo[make_pair(size-1,size-1)].second;
		while(x!=0 || y!=0){
			//cout<<"Painting "<<x<<","<<y<<endl;
			arr[x][y]='#';
			x=edgeTo[make_pair(x,y)].first;
			y=edgeTo[make_pair(x,y)].second;
		}
		arr[0][0]='#';
		arr[size-1][size-1]='#';
	}
	int paintPath(int x,int y){
		if(x==size-1 && y==size-1){
			arr[x][y]='#';
			return 1;
		}
		int check=-1;
		if(x+1<size && arr[x+1][y]=='.'){
			check=paintPath(x+1,y);
			if(check==1){
				arr[x][y]='#';
				return 1;
			}
		}
		if(y+1<size && arr[x][y+1]=='.'){
			check=paintPath(x,y+1);
			if(check==1){
				arr[x][y]='#';
				return 1;
			}
		}
		/*if(y-1>-1 && arr[x][y-1]=='.'){
			check=paintPath(x,y-1);
			if(check==1){
				arr[x][y]='#';
				return 1;
			}
		}*/
		/*if(x-1>-1 && arr[x-1][y]=='.'){
			check=paintPath(x-1,y);
			if(check==1){
				arr[x][y]='#';
				return 1;
			}
		}*/
		return -1;
	}
	void print(){
		for(int i=0;i<size;i++){
			cout<<"\n\t";
			for(int j=0;j<size;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
int main()
{
	srand(time(NULL));
	
	int n;
	cout<<"Enter size of maze : ";
	cin>>n;
	
	Maze maze(n);
	cout<<"Painting Depth First Path"<<endl;
	maze.paintPath(0,0);
	cout<<"Printing maze"<<endl;
	maze.print();
	
	maze.clearPath();
	
	cout<<"PAinting Breadth Frist path"<<endl;
	maze.paintShortestPath();
	cout<<"Printing maze"<<endl;
	maze.print();
	
	return 0;
}



















