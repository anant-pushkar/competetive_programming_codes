#include"tree.h"
int main()
{
	srand(time(NULL));
	int n,m,p,type,r1,r2;
	node *root;
	
	printf("Enter Type of tree:");
	printf("\n\t1 : Random Binary tree");
	printf("\n\t2 : Binary search tree");
	printf("\n\t>>");
	scanf("%d",&type);
	
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	
	switch(type){
	case 1:
		printf("Enter balance Left ratio : ");
		scanf("%d",&r1);
		
		printf("Enter balance Right ratio : ");
		scanf("%d",&r2);
		
		root = generateRandom(n,r1,r2);
		break;
	case 2:
		root = generateBST(n);
	}
	while(1){
		printf("\n\t1 to print parent list");
		printf("\n\t2 to find Least common parent");
		printf("\n\t3 to check balance");
		if(type==2){
			printf("\n\t4 to swap extreme points");
			printf("\n\t5 to restore");
			printf("\n\t7 to get next in BST");
			printf("\n\t8 to convert to doubly linked list");
		}
		printf("\n\t6 for level order traversal of tree");
		printf("\n\t\tEnter query : ");
		scanf("%d",&n);
		switch(n){
		case 1:
			printf("\t\tEnter node value : ");
			scanf("%d",&m);
			m=getParents(m,root);
			if(m==0)printf("Node not found");
			printf("\n");
			break;
		case 2:
			printf("\t\tEnter node 1 : ");
			scanf("%d",&m);
			
			printf("\t\tEnter node 2 : ");
			scanf("%d",&p);
			
			m=getLeastCommonParent(m,p,root);
			if(m==0) printf("None of the nodes were found");
			printf("\n");
			break;
		case 3:
			m=checkBalance(root);
			break;
		case 4:
			swap(root);
			break;
		case 5:
			restore(root);
			break;
		case 6:
			levelOrderTraversal(root);
			break;
		case 7:
			printf("Enter node : ");
			scanf("%d",&m);
			printf("Next : %d\n",getNext(root,m));
		case 8:
			printf("Converting to DList...\n");
			root=getDList(root);
			printf("Printing DList : ");
			printDList(root);
			printf("\n");
			break;
		}
	}
	return 0;
}

