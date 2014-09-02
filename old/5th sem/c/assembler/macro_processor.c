#include"Instruction.h"
void assemble(char *filename){
	FILE *ptr = fopen(filename,"r");
	FILE *out = fopen("expanded_code.txt","w+");
	
	printf("\n\tReading from file.\n");
	Instruction *scanner = generateScanner(ptr);//preprocess the file into appropriate data structure for macro processing
	
	process_macro(scanner);//implement macro processing
}
int main(){
	char filename[20];
	printf("Enter file to be assembled by macro processor : ");
	scanf("%s",filename);
	
	printf("Starting macro processor.\n");
	assemble(filename);
	
	printf("Macro processing complete\n");
	
	return 0;
}