#include"inorder.h"
using namespace std;
int main()
{
	int n;
	cout<<"Enter Number of nodes in BST : ";
	cin>>n;
	
	BST tree(n);
	
	while(1){
		cout<<"Enter a node value : ";
		cin>>n;
		n=tree.getSuccesor(n);
		if(n!=-1) cout<<"The next succesor is "<<n<<endl ;
	}
	
	return 0;
}
