#include"Instruction.h"
void pass1(char *filename);
void pass2();
int main()
{
	char filename[20];
	printf("Enter file to be assembled : ");
	scanf("%s",filename);
	
	printf("Starting pass1.\n");
	pass1(filename);
	printf("Pass1 complete. Intermediate code written to intermediate.txt .\nSymbol table written to symboltable.txt\n\n\n");
	
	printf("Starting pass2.\n");
	pass2();
	printf("Pass2 complete. Object code written to object.txt\n\n\n");
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
void pass2()
{
	printf("\tretreiving symbol table from temporary file.\n");
	FILE *fptr = fopen("symboltable.txt","r");
	hashtable_t *symboltable = create_from_file(fptr);
	fclose(fptr);
	
	printf("\tReading from intermediate file.\n");
	fptr = fopen("intermediate.txt","r");
	Instruction *converter = getConverter(fptr);
	fclose(fptr);
	
	//escape start statement
	if(strcmp(converter->op,"START")==0)converter=converter->next;
	
	printf("\tImplementing Pass2 algorithm.\n");
	convert(converter,symboltable);//implement pass2
	
	fptr=fopen("object.txt","w+");
	printObj(converter,fptr);
	fclose(fptr);
	
	printf("\tFreeing dynamic memory space.\n");
	freeSet(converter);
}










