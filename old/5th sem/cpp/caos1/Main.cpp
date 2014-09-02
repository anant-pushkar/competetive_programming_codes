#include<iostream>
#include<vector>
using namespace std;
int minOf4(int a , int b , int c, int d){
	d = a>d? d : a;
	c = b>c? c : b;
	d = c>d? d : c;
	return d;
}
void printArr(const vector< vector<int> > &arr,int R , int C){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<arr[i][j]<<"\t";
		}
	cout<<endl;
	}
}
int countMonsters(const vector< vector<char> > &playarea){
	int count=0,R=playarea.size(),C=playarea[0].size();
	/////////////////////////get top Arr///////////////////////////////////////////
	vector< vector<int> > top(R,vector<int>(C,0));
	for(int i=0;i<R;i++){
		for(int j=C-2;j>-1;j--){
			if(playarea[i][j]!='#' && playarea[i][j+1]=='^')top[i][j]=top[i][j+1]+1;
		}
	}
	//////////////////////////get bottom Arr/////////////////////////////////////////
	vector< vector<int> > bottom(R,vector<int>(C,0));
	for(int i=0;i<R;i++){
		for(int j=1;j<C;j++){
			if(playarea[i][j]!='#' && playarea[i][j-1]=='^')bottom[i][j]=bottom[i][j-1]+1;
		}
	}
	///////////////////////////get left Arr//////////////////////////////////////////
	vector< vector<int> > left(R,vector<int>(C,0));
	for(int i=R-2;i>-1;i--){
		for(int j=0;j<C;j++){
			if(playarea[i][j]!='#' && playarea[i+1][j]=='^')left[i][j]=left[i+1][j]+1;
		}
	}
	////////////////////////////get right Arr///////////////////////////////////
	vector< vector<int> > right(R,vector<int>(C,0));
	for(int i=1;i<R;i++){
		for(int j=0;j<C;j++){
			if(playarea[i][j]!='#' && playarea[i-1][j]=='^')right[i][j]=right[i-1][j]+1;
		}
	}
	//////////////////////////get min of L , R , T , B//////////////////////////
	/*cout<<"\n\nRight : "<<endl;printArr(top,R,C);
	cout<<"\n\nLeft : "<<endl;printArr(bottom,R,C);
	cout<<"\n\nBottom : "<<endl;printArr(left,R,C);
	cout<<"\n\nTop : "<<endl;printArr(right,R,C);
	cout<<"\n\nMin : "<<endl;*/
	int min;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			min=minOf4(left[i][j],right[i][j],top[i][j],bottom[i][j]);
			if(min>1) count++;
			//cout<<min<<"\t";
		}
		//cout<<endl;
	}
	return count;
}
int main()
{
	int T;cin>>T;
	int R,C;
	for(int t=0;t<T;t++){
		cin>>R>>C;
		vector< vector<char> > playarea(R,vector<char>(C));
		for(int r=0;r<R;r++){
			for(int c=0;c<C;c++){
				cin>>playarea[r][c];
			}
		}
		cout<<countMonsters(playarea)<<endl;
	}	
	return 0;
}
