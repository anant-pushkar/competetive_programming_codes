#include"knapsack.h"
int main()
{
	int n,W;
	
	printf("Enter number of items : ");
	scanf("%d",&n);
	
	printf("Enter bag capacity : ");
	scanf("%d",&W);
	
	Item *itemList=generateItems(n);
	getBinarySoln(itemList,n,W);
	getFractionalSoln(itemList,n,W);
	
	return 0;
}
