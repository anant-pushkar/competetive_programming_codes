#include"Instruction.h"
void pass1(char *filename);
int main()
{
	char filename[20];
	printf("Enter file to be assembled : ");
	scanf("%s",filename);
	
	printf("Starting pass1.\n");
	pass1(filename);
	printf("Pass1 complete. Intermediate code written to intermediate.txt .\nSymbol table written to symboltable.txt\n\n\n");
	return 0;
}
void pass1(char *filename)
{
	FILE *ptr = fopen(filename,"r");
	FILE *out = fopen("intermediate.txt","w+");
	
	printf("\n\tReading from file.\n");
	Instruction *scanner = generateScanner(ptr);//preprocess the file into appropriate data structure for pass1
	
	printf("\tImplementing Pass1 algorithm.\n");
	traverse(scanner);//implement pass1 algorithm
	
	printf("\tWriting Intermediate code to file.\n");
	printIntermediate(out,scanner);//print the intermediate code to file
	
	printf("\tFreeing dynamic memory space.\n");
	freeSet(scanner);
	
	fclose(ptr);
	fclose(out);
}
