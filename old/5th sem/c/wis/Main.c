#include"wis.h"
#include<time.h>
int main()
{
	int n;
	printf("Enter number of intervals: ");
	scanf("%d",&n);
	
	clock_t  tic , toc;
	tic = clock();
	Interval* intervalSet = generateIntervalSet(n);
	printf("Intervals generated: \n");
	printIntervalSet(intervalSet,n);
	int* previous = populatePrevious(intervalSet , n);
	traverse(intervalSet , previous , n);
	toc = clock();
	printf("Time Elapsed : %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
}
