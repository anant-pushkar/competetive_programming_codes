#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int N;
vector<int> operator+(const vector<int> &a , const vector<int> &b){
	vector<int> v(a.size());
	for(int i=0;i<v.size();i++){
		v[i]=a[i]+b[i];
	}
	return v;
}
ostream& operator<<(ostream &out , const vector<int> &v){
	for(int i=0;i<v.size();i++){
		out<<v[i]<<" ";
	}
	return out;
}
inline void swap(int &a,int &b){
	if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}
vector<int>qLookup;
struct Node{
	const int start,end;
	vector<int> qCount;
	Node *left;
	Node *right;
	bool flagX;
	bool flagY;
	Node(int s , int e):
	start(s),end(e),qCount(vector<int>(4,0)),left(NULL),right(NULL),flagX(false),flagY(false)
	{}
};
Node* createTree(int start , int end)
{
	if(debug)cout<<"Creating tree of "<<start<<","<<end<<endl;
	Node* node = new Node(start,end);
	if(start==end){
		node->qCount[qLookup[start]]++;
	}else{
		int mid=start+(end-start)/2;
		node->left = createTree(start , mid);
		node->right= createTree(mid+1 , end);
		node->qCount=node->left->qCount+node->right->qCount;
	}
	return node;
}
vector<int> traverse(int start , int end , Node *root , bool flagX , bool flagY , bool reflectX ,bool reflectY)
{
	if(debug){
		cout<<"Function parameters : \n";
		cout<<"\tstart\t"<<start<<endl;
		cout<<"\tend\t"<<end<<endl;
		cout<<"\tRoot details : "<<endl;
		cout<<"\t\tstart:\t"<<root->start<<endl;
		cout<<"\t\tend:\t"<<root->end<<endl;
		cout<<"\t\tflagX:\t"<<root->flagX<<endl;
		cout<<"\t\tflagY:\t"<<root->flagY<<endl;
		cout<<"\tflagX:\t"<<flagX<<endl;
		cout<<"\tflagY:\t"<<flagY<<endl;
		cout<<"\treflectX:\t"<<reflectX<<endl;
		cout<<"\treflectY:\t"<<reflectY<<endl;
		cout<<endl;
	}
	bool nextFlagX=flagX^(root->flagX);
	bool nextFlagY=flagY^(root->flagY);
	if(root->end<start || root->start>end){
		if(debug)cout<<"Processing out of range node"<<endl;
		if(root->left!=NULL)root->flagX=nextFlagX;if(debug)cout<<"\tat out of range root->flagX set to "<<root->flagX<<endl;
		if(root->left!=NULL)root->flagY=nextFlagY;if(debug)cout<<"\tat out of range root->flagY set to "<<root->flagY<<endl;
		if(flagY){
			if(debug)cout<<"Reflecting along Y Axis"<<endl;
			swap(root->qCount[0],root->qCount[1]);
			swap(root->qCount[2],root->qCount[3]);
		}
		if(flagX){
			if(debug)cout<<"Reflecting along X Axis"<<endl;
			swap(root->qCount[0],root->qCount[3]);
			swap(root->qCount[1],root->qCount[2]);
		}
		if(debug)cout<<"Returning out of range node with "<<vector<int>(4,0)<<"true value being "<<root->qCount<<endl;
		return vector<int>(4,0);
	}else if(root->end<=end && root->start>=start){
		if(debug)cout<<"Processing proper range node"<<endl;
		if(root->left!=NULL)root->flagX=reflectX?!nextFlagX:nextFlagX;if(debug)cout<<"\tat proper root->flagX set to "<<root->flagX<<endl;
		if(root->left!=NULL)root->flagY=reflectY?!nextFlagY:nextFlagY;if(debug)cout<<"\tat proper root->flagY set to "<<root->flagY<<endl;
		if(reflectY^flagY){
			if(debug)cout<<"Reflecting along Y Axis"<<endl;
			swap(root->qCount[0],root->qCount[1]);
			swap(root->qCount[2],root->qCount[3]);
		}
		if(reflectX^flagX){
			if(debug)cout<<"Reflecting along X Axis"<<endl;
			swap(root->qCount[0],root->qCount[3]);
			swap(root->qCount[1],root->qCount[2]);
		}
		if(debug)cout<<"returning proper node with "<<root->qCount<<endl;
		return root->qCount;
	}else if(root->left!=NULL){
		if(debug)cout<<"Processing mixed range node"<<endl;
		vector<int> v1,v2;
		if(debug)cout<<"Traversing left node"<<endl;
		v1=traverse(start,end,root->left ,root->flagX^flagX,root->flagY^flagY,reflectX,reflectY);
		if(debug)cout<<"Traversing right node"<<endl;
		v2=traverse(start,end,root->right,root->flagX^flagX,root->flagY^flagY,reflectX,reflectY);
		root->flagX=false;if(debug)cout<<"\tat mixed root->flagX set to "<<root->flagX<<endl;
		root->flagY=false;if(debug)cout<<"\tat mixed root->flagY set to "<<root->flagY<<endl;
		root->qCount=root->left->qCount+root->right->qCount;
		if(debug)cout<<"returning mixed node "<<root->start<<","<<root->end<<"with : "<<(v1+v2)<<endl;
		return v1+v2;
	}else{
		if(debug)cout<<"Processing out of range leaf node"<<endl;
		if(flagY){
			if(debug)cout<<"Reflecting along Y Axis"<<endl;
			swap(root->qCount[0],root->qCount[1]);
			swap(root->qCount[2],root->qCount[3]);
		}
		if(flagX){
			if(debug)cout<<"Reflecting along X Axis"<<endl;
			swap(root->qCount[0],root->qCount[3]);
			swap(root->qCount[1],root->qCount[2]);
		}
		if(debug)cout<<"Returning form out of range leaf node with "<<root->qCount<<endl;
		return root->qCount;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d",&N);
	qLookup=vector<int>(N+1,-1);
	int x,y;
	for(int i=1;i<=N;++i){
		scanf("%d %d",&x,&y);
		if(x>0){
			if(y>0) qLookup[i]=0;
			else qLookup[i]=3;
		}else{
			if(y>0) qLookup[i]=1;
			else qLookup[i]=2;
		}
		if(debug)cout<<"\tQ:"<<qLookup[i]<<endl;
	}
	Node* root=createTree(1,N);
	int m;scanf("%d",&m);
	char c;
	vector<int> v;
	while(m){
		cin>>c>>x>>y;
		if(debug)cout<<c<<" "<<x<<" "<<y<<" "<<endl;
		v=traverse(x,y,root,false,false,c=='X',c=='Y');
		if(c=='C')printf("%d %d %d %d\n",v[0],v[1],v[2],v[3]);
		--m;
	}
	return 0;
}


