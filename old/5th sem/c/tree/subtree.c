#include"tree.h"
int main()
{
	int n1,n2,check;
	
	printf("Enter size of bigger BST : ");
	scanf("%d",&n1);
	
	printf("Enter size of smaller BST : (-ve for subtree matching)");
	scanf("%d",&n2);
	
	printf("Generating bigger BST :\n");
	node *T1 = generateBST(n1);
	printf("\n\n");
	
	printf("Generating smaller BST :\n");
	node *T2;
	if(n2>0) T2== generateBST(n2);
	else{
		n2=-n2;
		T2=getSubTree(T1,n2);
	}
	printf("\n\n");
	
	check=checkSubTree(T1,T2);
	printf("%d\n",check);
	
	return 0;
}