#include"Instruction.h"
void pass2();
int main()
{	
	printf("Starting pass2.\n");
	pass2();
	printf("Pass2 complete. Object code written to object.txt\n\n\n");
	return 0;
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










