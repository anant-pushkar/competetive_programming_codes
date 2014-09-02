#include"Instruction.h"
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define DEFAULT_LABEL ""
#define DEFAULT_ERROR ""
#define DEFAULT_OBJCODE ""
static int nLines;
/*
	creates and innitializes an instance of Instruction data type to store and manipulate each line of the input code
*/
Instruction *newInstruction (char instruction[3][20] , int n , int line)
{
	Instruction *ptr = (Instruction*)malloc(sizeof(Instruction));
	if(n<2){
		strcpy(ptr->error,"Insufficient number of operands");
	}else if(n>3){
		n=3;//to snap out comments from the code {NOTE: defination of code is mentioned in readInstruction}
		strcpy(ptr->error,DEFAULT_ERROR);
	}else strcpy(ptr->error,DEFAULT_ERROR);
	
	if(n==3) strcpy(ptr->label,instruction[0]);
	else	 strcpy(ptr->label,DEFAULT_LABEL);
	
	strcpy(ptr->op,instruction[n-2>=0 ? n-2 : n-1]);
	if(n>1) strcpy(ptr->operand,instruction[n-1]);
	ptr->lineNum = line ;
	ptr->loc     = 0 ;
	ptr->next    = NULL ;
	strcpy(ptr->objCode,DEFAULT_OBJCODE);
	return ptr;
}
Instruction *readInstruction(int n , FILE * fPtr)
{
	char str[200] , *pch , *ptr , instruction[3][20];
	int i;
	if(fgets(str,sizeof(str),fPtr)!=NULL){
		i=0;//remove leading spaces
		while(str[i]==' ' || str[i]=='\t') strcpy(str,&str[++i]);
		
		pch=strtok(str," \t");
		ptr=pch;
		while(*ptr!='\n' && *ptr!='/' && *ptr!='\\') ptr++;//remove new lines at the end and comments starting from "/"
		/*
			NOTE:
				-All string starting with / are considered as comments
				-All strings appearing as second operand, ie immediately after 
				 the operand followed by space are implicitly 
				 considered comments and truncated
		*/
		while(isspace(*(ptr-1))) *(ptr--)='\0';
		*ptr='\0';//remove implicit comments and trailing spaces
		int i=0;
		//split the input based on space and tab characters
		while(pch!=NULL && i<3){
			strcpy(instruction[i++],pch);
			pch=strtok(NULL," \t");
		}
		return newInstruction(instruction,i,n);//create new instruction object using the tokens split from the input
	}else return NULL;//return NULL in case of eof
}
Instruction *generateScanner(FILE *filePtr)
{
	int i=1;
	Instruction *root=readInstruction(i,filePtr) , *node=root;
	if(root==NULL) printf("No Instructions found.\n"); //handle empty file exception 
	while(node!=NULL){//iterate through the input file
		node->next = readInstruction(++i,filePtr);
		node = node->next;
	}
	nLines=i;
	return root;
}
/*
	Main implimentation of pass1 is done here
*/
void traverse(Instruction *scanner )
{
	long int loc=0;
	char buffer[20];//buffer for cnverting location counter value to string
	
	//read optional opcodes fromtxt file and generate hash table for the same
	FILE *opPtr = fopen("optionaloptable.txt","r");
	hashtable_t *optionalTable = create_from_file(opPtr);
	fclose(opPtr);
	
	//check for START command 
	if(strcmp(scanner->op , "START")==0) loc = strtol(scanner->operand,NULL,16)-3;
	hashtable_t *symboltable = ht_create( nLines );//innitialise hashtable with container size = number of lines
	
	while(scanner!=NULL){//Iterate Through the scanner object
		scanner->loc = loc ;
		if(strcmp(scanner->label,DEFAULT_LABEL)!=0){
			if(ht_get( symboltable, scanner->label )==NULL){//if symbol table does not contain label
				sprintf(buffer,"%x",loc);
				ht_set( symboltable, scanner->label, buffer);
			}else strcpy(scanner->error,"Duplicate label");
		}
		if(strcmp(scanner->op,"BYTE")==0)loc+=strlen(scanner->operand);
		else if(strcmp(scanner->op,"RESB")==0)loc+=  strtol(scanner->operand,NULL,10);
		else if(strcmp(scanner->op,"RESW")==0)loc+=3*strtol(scanner->operand,NULL,10);
		else if(strcmp(scanner->op,"WORD")==0)loc+=3;
		else{
			if(strcmp(scanner->op,"ADD")!=0 && strcmp(scanner->op,"LDA")!=0 && strcmp(scanner->op,"MUL")!=0 && strcmp(scanner->op,"DIV")!=0 && strcmp(scanner->op,"STA")!=0 && strcmp(scanner->op,"START")!=0 && strcmp(scanner->op,"END")!=0 && ht_get(optionalTable,scanner->op)==NULL) 
				strcpy(scanner->error,"Undefined Instruction.");
			loc+=3;
		}
		scanner = scanner->next ;
	}
	//print sumbol table to temporary file
	FILE *fptr=fopen("symboltable.txt","w+");
	print_table(symboltable,fptr);
	fclose(fptr);
}
void printIntermediate(FILE *out , Instruction * scanner)
{
	while(scanner!=NULL){
		fprintf(out,"%x\t%s %s %s\t\t%s \n",scanner->loc,scanner->label,scanner->op,scanner->operand,scanner->error);
		scanner=scanner->next;
	}
}
char *substring(char *out, char const *in, size_t len) { 
    memcpy(out, in, len);
    out[len] = '\0';
    return out;
}
Instruction *getOperation(FILE *fptr)
{
	char str[100],list[5][100];
	int begin=0,forward=1;
	Instruction * op = (Instruction*)malloc(sizeof(Instruction));
	if(fgets(str,sizeof(str),fptr)!=NULL){
		begin=0; forward=1;
		
		while(str[forward]!=' ' && str[forward]!='\t') forward++;//get Address from intermediate code
		strcpy(list[3],substring((char*)calloc(forward-begin,sizeof(char)) , str , forward-begin));
		
		forward++;begin=forward;
		if(str[begin]==' ')strcpy(list[0],DEFAULT_LABEL);
		else{
			while(str[forward]!=' ' && str[forward]!='\t') forward++;//get Label from intermediate code
			strcpy(list[0],substring((char*)calloc(forward-begin,sizeof(char)) , &str[begin] , forward-begin));
		}
		forward++;begin=forward;
		while(str[forward]!=' ' && str[forward]!='\t') forward++;//get Instruction from intermediate code
		strcpy(list[1],substring((char*)calloc(forward-begin,sizeof(char)) , &str[begin] , forward-begin));
		
		forward++;begin=forward;
		while(str[forward]!=' ' && str[forward]!='\t') forward++;//get Instruction from intermediate code
		strcpy(list[2],substring((char*)calloc(forward-begin,sizeof(char)) , &str[begin] , forward-begin));
		
		forward++;forward++;begin=forward;
		while(str[forward]!='\n') forward++;//get Instruction from intermediate code
		strcpy(list[4],substring((char*)calloc(forward-begin,sizeof(char)) , &str[begin] , forward-begin));
		
	}else return NULL;
	strcpy(op->label  , list[0]);
	strcpy(op->op     , list[1]);
	strcpy(op->operand, list[2]);
	strcpy(op->address, list[3]);
	strcpy(op->error  , list[4]);
	strcpy(op->objCode, DEFAULT_OBJCODE);
	return op;
}
Instruction *getConverter(FILE *fptr)
{
	Instruction *root=getOperation(fptr),*node=root;
	while(node!=NULL){
		node->next=getOperation(fptr);
		node=node->next;
	}
	return root;
}
void convert(Instruction *converter , hashtable_t *st)
{
	//read optional opcodes fromtxt file and generate hash table for the same
	FILE *opPtr = fopen("optionaloptable.txt","r");
	hashtable_t *optionalTable = create_from_file(opPtr);
	fclose(opPtr);
	
	char objCode[10];
	while(converter!=NULL && strcmp(converter->op,"END")!=0){
		if(converter->error!=""){//no error
			//printf("No errors found\n");
			strcpy(objCode,DEFAULT_OBJCODE);
			if(strcmp(converter->op,"BYTE")==0)strcpy(objCode,converter->operand);
			else if(strcmp(converter->op,"RESB")==0)strcpy(objCode,"");
			else if(strcmp(converter->op,"RESW")==0)strcpy(objCode,"");
			else if(strcmp(converter->op,"WORD")==0)sprintf(objCode,"%06ld",strtol(converter->operand,NULL,10));
			else{
				//printf("Processing : |%s| |%s| |%s|\n",converter->label,converter->op,converter->operand);
				if(strcmp(converter->op,"LDA")==0 ){
					strcpy(objCode,"00");
				}else if(strcmp(converter->op,"MUL")==0 ){
					strcpy(objCode,"20");
				}else if(strcmp(converter->op,"DIV")==0 ){
					strcpy(objCode,"24");
				}else if(strcmp(converter->op,"STA")==0 ){
					strcpy(objCode,"0C");
				}else if(strcmp(converter->op,"ADD")==0 ){
					strcpy(objCode,"18");
				}else if(ht_get(optionalTable,converter->op)!=NULL){
					strcpy(objCode,ht_get(optionalTable,converter->op));
				}else {
					strcpy(converter->error,"Instruction not defined");
				}
				
				//printf("putting address\n");
				if(ht_get(st,converter->operand)!=NULL)strcat(objCode,ht_get(st,converter->operand));
				else{
					strcpy(converter->error,"Operand not found");
				}
				//printf("copying obj code\n");
			}
			
			strcpy(converter->objCode,objCode);
		}
		//printf("Advancing converter\n");
		converter=converter->next;
	}
}
void printObj(Instruction *converter , FILE *fptr)
{
	while(converter!=NULL && strcmp(converter->op,"END")!=0){
		fprintf(fptr,"%s\t%10s %10s %10s\t%s\t\t\t%s\n",converter->address,converter->label,converter->op,converter->operand,converter->objCode,converter->error);
		converter=converter->next;
	}
}
void freeSet(Instruction *ptr)
{
	Instruction *tempPtr;
	while(ptr!=NULL){
		tempPtr=ptr;
		ptr=ptr->next;
		free(tempPtr);
	}
}
int count_macro(Instruction *readhead ){
	int i=0;
	while(readhead!=NULL){
		if(strcmp(readhead->op,"MACRO")){
			i++;
		}
		readhead=readhead->next;
	}
	return i;
}
#define DEFAULT_STR "default"
hashtable_t *get_symbol_table(char * str){
	printf("\nCreating symbol table for %s\n",str);
	int commaIndex[20],i=0,commaI=1,j;
	commaIndex[0]=0;
	for(;i<strlen(str);i++){
		if(str[i]==',')commaIndex[commaI++]=i+1;
	}
	commaIndex[commaI++]=strlen(str)+1;
	hashtable_t* symbol_table=ht_create(commaI);
	char symbol[10];
	for(i=0;i<commaI-1;i++){
		for(j=0;j<10;j++) symbol[j]='\0';
		strncpy(symbol,str+commaIndex[i],commaIndex[i+1]-commaIndex[i]);
		for(j=0;j<10;j++) if(symbol[j]==',')symbol[j]='\0';
		printf("Inserting %s\n",symbol);
		ht_set(symbol_table,symbol,DEFAULT_STR);
	}
	printf("\n");
	return symbol_table;
}
MacroLookup *getMacroArr(int macro_count , Instruction *readhead){
	printf("Creating Macro Array\n");
	char index[20];
	hashtable_t* macro_label=ht_create(10);
	Instruction *temphead;
	int level=0,i=0;
	Macro *macro_arr=(Macro*)calloc(macro_count,sizeof(Macro));
	while(readhead!=NULL){
		if(strcmp(readhead->op,"MACRO")==0){
			printf("\tFound Macro#%d : %s\n",i,readhead->label);
			sprintf(index,"%d",i);
			ht_set(macro_label,readhead->label,index);
			macro_arr[i].start=readhead->next;
			macro_arr[i].label=readhead->label;
			macro_arr[i].symbol_table=get_symbol_table(readhead->operand);
			macro_arr[i].operand=readhead->operand;
			temphead=readhead->next;
			level=0;
			while(temphead!=NULL){
				if(strcmp(temphead->op,"MACRO")==0){
					printf("Found nested macro : %s\n",temphead->label);
					level++;
				}
				if(strcmp(temphead->op,"MEND")==0){
					if(level!=0) level--;
					else break;
				}
				temphead=temphead->next;
			}
			macro_arr[i].end=temphead;
			i++;
			readhead=temphead;
		}else readhead=readhead->next;
	}
	MacroLookup* lookup = (MacroLookup*)malloc(sizeof(MacroLookup));
	lookup->size=i;
	lookup->arr=macro_arr;
	lookup->label_table=macro_label;
	return lookup;
}
void remove_macro(Instruction *readhead){
	printf("Removing macro\n");
	Instruction *temphead;
	int level;
	while(readhead->next!=NULL){
		if(strcmp(readhead->next->op,"MACRO")==0){
			temphead=readhead->next;
			level=0;
			printf("\tRemoving macro : %s\n",readhead->next->label);
			while(temphead->next!=NULL){
				printf("\t\tEncountered : %s \n",temphead->label,level);
				if(strcmp(temphead->next->op,"MACRO")==0)level++;
				else if(strcmp(temphead->next->op,"MEND")==0 && level!=0)level--;
				else if(strcmp(temphead->next->op,"MEND")==0 && level==0)break;
				temphead=temphead->next;
			}
			readhead->next=temphead->next->next;
		}
		readhead=readhead->next;
	}
}
#define MACRO_NOT_FOUND "not found"
Macro getMacro(char *label , MacroLookup* lookup){
	int index;
	char* indexStr=ht_get(lookup->label_table,label);
	printf("Looking for %s \n",label);
	if(indexStr==NULL){
		printf("%s is not a macro\n\n",label);
		Macro macro;
		macro.label=MACRO_NOT_FOUND;
		return macro;
	}
	printf("Found macro\n\n");
	sscanf(indexStr,"%d",&index);
	return lookup->arr[index];
}
void populate_symbols(char *macro_ops , char *ops , hashtable_t* symboltable){
	int commaIndex[20],i=0,commaI=1,j;
	commaIndex[0]=0;
	for(;i<strlen(ops);i++){
		if(ops[i]==',')commaIndex[commaI++]=i+1;
	}
	commaIndex[commaI++]=strlen(ops);
	int keyCommaIndex[20];commaI=1;
	keyCommaIndex[0]=-1;
	for(i=0;i<strlen(macro_ops);i++){
		if(macro_ops[i]==',')keyCommaIndex[commaI++]=i;
	}
	keyCommaIndex[commaI++]=strlen(macro_ops);
	char symbol[10],key[10];
	for(i=0;i<commaI-1;i++){
		for(j=0;j<10;j++) symbol[j]='\0';
		strncpy(symbol,ops+commaIndex[i],commaIndex[i+1]-commaIndex[i]);
		for(j=0;j<10;j++) if(symbol[j]==',')symbol[j]='\0';
		
		for(j=0;j<10;j++) key[j]='\0';
		strncpy(key,macro_ops+keyCommaIndex[i]+1,keyCommaIndex[i+1]-keyCommaIndex[i]);
		for(j=0;j<10;j++) if(key[j]==',')key[j]='\0';
		
		printf("Inserting %s to %s\n",symbol,key);
		ht_set(symboltable,key,symbol);
	}
	printf("\n");
}
void expand_macro(Instruction *scanner , MacroLookup *lookup){
	Instruction *readhead=scanner,*temphead,*expandhead,*nexthead;
	char *symbol;
	while(readhead->next!=NULL){
		printf("reading : %s\t%s\t%s\n",readhead->label,readhead->op,readhead->operand);
		Macro macro=getMacro(readhead->next->op , lookup);
		if(strcmp(macro.label,MACRO_NOT_FOUND)!=0){
			printf("Expanding macro : %s:%s\n",macro.label,macro.operand);
			temphead=macro.start;
			populate_symbols(macro.operand,readhead->next->operand,macro.symbol_table);
			nexthead=readhead->next;
			if(nexthead->next!=NULL)nexthead=nexthead->next;
			while(temphead!=macro.end){
				printf("%s\t%s\t%s\n",temphead->label,temphead->op,temphead->operand);
				expandhead=(Instruction*)malloc(sizeof(Instruction));
				
				symbol=ht_get(macro.symbol_table,temphead->label);
				if(strcmp(temphead->label,DEFAULT_LABEL)!=0 && symbol!=NULL) strcpy(expandhead->label,ht_get(macro.symbol_table,temphead->label));
				else strcpy(expandhead->label,temphead->label);
				
				symbol=ht_get(macro.symbol_table,temphead->op);
				if(strcmp(temphead->op,DEFAULT_LABEL)!=0 && symbol!=NULL) strcpy(expandhead->op,ht_get(macro.symbol_table,temphead->op));
				else strcpy(expandhead->op,temphead->op);
				
				symbol=ht_get(macro.symbol_table,temphead->operand);
				if(strcmp(temphead->operand,DEFAULT_LABEL)!=0 && symbol!=NULL) strcpy(expandhead->operand,ht_get(macro.symbol_table,temphead->operand));
				else strcpy(expandhead->operand,temphead->operand);
				
				readhead->next=expandhead;
				readhead=readhead->next;
				temphead=temphead->next;
			}
			readhead->next=nexthead;
			printf("\n\n");
		}else readhead=readhead->next;
	}
}
bool contains_macro(Instruction *scanner){
	while(scanner!=NULL){
		if(strcmp(scanner->op,"MACRO")==0)return false;
		scanner=scanner->next;
	}
	return true;
}
void process_macro(Instruction *scanner ){
	int macro_count=count_macro(scanner);
	MacroLookup *lookup = getMacroArr(macro_count,scanner);
	remove_macro(scanner);
	expand_macro(scanner,lookup);
	while(!contains_macro(scanner)){
		macro_count=count_macro(scanner);
		lookup = getMacroArr(macro_count,scanner);
		remove_macro(scanner);
		expand_macro(scanner,lookup);
	}
	FILE *out = fopen("expanded_code.txt","w+");
	while(scanner!=NULL){
		fprintf(out,"%s %s %s\n",scanner->label,scanner->op,scanner->operand);
		scanner=scanner->next;
	}
}









