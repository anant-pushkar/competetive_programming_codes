#include "nfa.h"
#include "read_module.h"
#include "regex.h"
#include <stdbool.h> 
#include <string.h>
hashtable_t *symboltable ;
void pre_populate_symboltable(){
	symboltable = ht_create( 10000 );
	ht_set( symboltable, "short", "0");
	ht_set( symboltable, "sizeofint", "0");
	ht_set( symboltable, "float", "0");
	ht_set( symboltable, "double", "0");
	ht_set( symboltable, "bool", "0");
	ht_set( symboltable, "char", "0");
	ht_set( symboltable, "signed", "0");
	ht_set( symboltable, "unsigned", "0");
	ht_set( symboltable, "for", "0");
	ht_set( symboltable, "while", "0");
	ht_set( symboltable, "do", "0");
	ht_set( symboltable, "return", "0");
	ht_set( symboltable, "structconst", "0");
	ht_set( symboltable, "void", "0");
	ht_set( symboltable, "switch", "0");
	ht_set( symboltable, "break", "0");
	ht_set( symboltable, "case", "0");
	ht_set( symboltable, "continue", "0");
	ht_set( symboltable, "goto", "0");
	ht_set( symboltable, "long", "0");
	ht_set( symboltable, "static", "0");
	ht_set( symboltable, "union", "0");
	ht_set( symboltable, "default", "0");
}
void print_symbol_table(){
	FILE *fptr=fopen("symbol_table_1.out","w+");
	print_table(symboltable,fptr);
}
static hashtable_t *staticLookup;
void create_lookup(){
	staticLookup = ht_create( 10000 );
	//printf("Creating lookup\n");
	FILE *fptr = fopen("regexp.in","r");
	if(fptr==NULL){
		printf("regexp.in not found.");
		return;
	}
	char name[50],regex[50];
	//printf("Scanning from file\n");
	while(fscanf(fptr,"%s",name)){
		fscanf(fptr,"%s",regex);
		printf("Adding defination : %s->%s\n",name,regex);
		ht_set( staticLookup, name , regex);
		if(strcmp(name,"DEFAULT")==0)break;
	}
	fclose(fptr);
}
static bool is_identifier(char *lexeme){
	return matchRegex(ht_get(staticLookup,"IDNTIFIER"),lexeme);
}
static bool is_int_const(char* lexeme){
	return matchRegex(ht_get(staticLookup,"INT_CONST"),lexeme);
}
static bool is_flo_const(char *lexeme){
	return matchRegex(ht_get(staticLookup,"FLO_CONST"),lexeme);
}
static bool is_plus(char * lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"PLUS"))==0;
}
static bool is_minus(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"MINUS"))==0;
}
static bool is_mult(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"MULT"))==0;
}
static bool is_div(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"DIV"))==0;
}
static bool is_percent(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"PERCENT"))==0;
}
static bool is_plus_plus(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"PLUS_PLUS"))==0;
}
static bool is_minus_minus(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"MINUS_MINUS"))==0;
}
static bool is_equal(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"EQ"))==0;
}
static bool is_minus_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"MINUS_EQ"))==0;
}
static bool is_plus_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"PLUS_EQ"))==0;
}
static bool is_mult_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"MULT_EQ"))==0;
}
static bool is_div_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"DIV_EQ"))==0;
}
static bool is_eq_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"EQ_EQ"))==0;
}
static bool is_lesser(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"LESSER"))==0;
}
static bool is_less_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"LESS_EQ"))==0;
}
static bool is_greater(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"GREATER"))==0;
}
static bool is_great_eq(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"GREAT_EQ"))==0;
}
static bool is_l_square(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"L_SQUARE"))==0;
}
static bool is_r_square(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"R_SQUARE"))==0;
}
static bool is_l_paraen(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"L_PARAEN"))==0;
}
static bool is_r_paraen(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"R_PARAEN"))==0;
}
static bool is_l_cbrace(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"L_CBRACE"))==0;
}
static bool is_r_cbrace(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"R_CBRACE"))==0;
}
static bool is_comma(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"COMMA"))==0;
}
static bool is_semicol(char *lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"SEMICOL"))==0;
}
static bool is_short(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"SHORT"))==0;
}
static bool is_int(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"INT"))==0;
}
static bool is_float(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"FLOAT"))==0;
}
static bool is_double(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"DOUBLE"))==0;
}
static bool is_bool(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"BOOL"))==0;
}
static bool is_char(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"CHAR"))==0;
}
static bool is_signed(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"SIGNED"))==0;
}
static bool is_unsigned(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"UNSIGNED"))==0;
}
static bool is_for(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"FOR"))==0;
}
static bool is_while(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"WHILE"))==0;
}
static bool is_do(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"DO"))==0;
}
static bool is_return(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"RETURN"))==0;
}
static bool is_struct(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"STRUCT"))==0;
}
static bool is_const(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"CONST"))==0;
}
static bool is_void(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"VOID"))==0;
}
static bool is_switch(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"SWITCH"))==0;
}
static bool is_break(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"BREAK"))==0;
}
static bool is_case (char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"CASE"))==0;
}
static bool is_continue(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"CONTINUE"))==0;
}
static bool is_goto(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"GOTO"))==0;
}
static bool is_long(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"LONG"))==0;
}
static bool is_static(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"STATIC"))==0;
}
static bool is_union(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"UNION"))==0;
}
static bool is_default(char* lexeme){
	return strcmp(lexeme,ht_get(staticLookup,"DEFAULT"))==0;
}
static bool is_comment_start(char *lexeme){
	if(strcmp(lexeme,"/*")==0) return true;
	else return false;
}
static bool is_comment_end(char *lexeme){
	if(strcmp(lexeme,"*/")==0) return true;
	else return false;
}
char *get_token(char *lexeme , int mode){
	char *token=(char*)calloc(strlen(lexeme)+50,sizeof(char));
	//printf("Getting token\n");
	if(is_long(lexeme)){
		sprintf(token,"%d",LONG);
	}
	else if(is_static(lexeme)){
		sprintf(token,"%d",STATIC);
	}
	else if(is_union(lexeme)){
		sprintf(token,"%d",UNION);
	}
	else if(is_default(lexeme)){
		sprintf(token,"%d",DEFAULT);
	}
	else if(is_break(lexeme)){
		sprintf(token,"%d",BREAK);
	}
	else if(is_case(lexeme)){
		sprintf(token,"%d",CASE);
	}
	else if(is_continue(lexeme)){
		sprintf(token,"%d",CONTINUE);
	}
	else if(is_goto(lexeme)){
		sprintf(token,"%d",GOTO);
	}
	else if(is_struct(lexeme)){
		sprintf(token,"%d",STRUCT);
	}
	else if(is_const(lexeme)){
		sprintf(token,"%d",CONST);
	}
	else if(is_void(lexeme)){
		sprintf(token,"%d",VOID);
	}
	else if(is_switch(lexeme)){
		sprintf(token,"%d",SWITCH);
	}
	else if(is_for(lexeme)){
		sprintf(token,"%d",FOR);
	}
	else if(is_while(lexeme)){
		sprintf(token,"%d",WHILE);
	}
	else if(is_do(lexeme)){
		sprintf(token,"%d",DO);
	}
	else if(is_return(lexeme)){
		sprintf(token,"%d",RETURN);
	}
	else if(is_bool(lexeme)){
		sprintf(token,"%d",BOOL);
	}
	else if(is_char(lexeme)){
		sprintf(token,"%d",CHAR);
	}
	else if(is_signed(lexeme)){
		sprintf(token,"%d",SIGNED);
	}
	else if(is_unsigned(lexeme)){
		sprintf(token,"%d",UNSIGNED);
	}
	else if(is_short(lexeme)){
		sprintf(token,"%d",SHORT);
	}
	else if(is_int(lexeme)){
		sprintf(token,"%d",INT);
	}
	else if(is_float(lexeme)){
		sprintf(token,"%d",FLOAT);
	}
	else if(is_double(lexeme)){
		sprintf(token,"%d",DOUBLE);
	}
	else if(is_l_square(lexeme)){
		sprintf(token,"%d",L_SQUARE);
	}
	else if(is_r_square(lexeme)){
		sprintf(token,"%d",R_SQUARE);
	}
	else if(is_l_paraen(lexeme)){
		sprintf(token,"%d",L_PARAEN);
	}
	else if(is_r_paraen(lexeme)){
		sprintf(token,"%d",R_PARAEN);
	}
	else if(is_l_cbrace(lexeme)){
		sprintf(token,"%d",L_CBRACE);
	}
	else if(is_r_cbrace(lexeme)){
		sprintf(token,"%d",R_CBRACE);
	}
	else if(is_comma(lexeme)){
		sprintf(token,"%d",COMMA);
	}
	else if(is_semicol(lexeme)){
		sprintf(token,"%d",SEMICOL);
	}
	else if(is_eq_eq(lexeme)){
		sprintf(token,"%d",EQ_EQ);
	}
	else if(is_lesser(lexeme)){
		sprintf(token,"%d",LESSER);
	}
	else if(is_less_eq(lexeme)){
		sprintf(token,"%d",LESS_EQ);
	}
	else if(is_div(lexeme)){
		sprintf(token,"%d",DIV);
	}
	else if(is_greater(lexeme)){
		sprintf(token,"%d",GREATER);
	}
	else if(is_great_eq(lexeme)){
		sprintf(token,"%d",GREAT_EQ);
	}
	else if(is_plus_eq(lexeme)){
		sprintf(token,"%d",PLUS_EQ);
	}
	else if(is_minus_eq(lexeme)){
		sprintf(token,"%d",MINUS_EQ);
	}
	else if(is_div_eq(lexeme)){
		sprintf(token,"%d",DIV_EQ);
	}
	else if(is_mult_eq(lexeme)){
		sprintf(token,"%d",MULT_EQ);
	}
	else if(is_minus_minus(lexeme)){
		sprintf(token,"%d",MINUS_MINUS);
	}
	else if(is_plus_plus(lexeme)){
		sprintf(token,"%d",PLUS_PLUS);
	}
	else if(is_percent(lexeme)){
		sprintf(token,"%d",PERCENT);
	}
	else if(is_div(lexeme)){
		sprintf(token,"%d",DIV);
	}
	else if(is_mult(lexeme)){
		sprintf(token,"%d",MULT);
	}
	else if(is_minus(lexeme)){
		sprintf(token,"%d",MINUS);
	}
	else if(is_plus(lexeme)){
		sprintf(token,"%d",PLUS);
	}
	else if(is_int_const(lexeme)){
		printf("int");
		sprintf(token,"%d\t%s",INT_CONST,lexeme);
	}
	else if(is_flo_const(lexeme)){
		printf("float");
		sprintf(token,"%d\t%s",FLO_CONST,lexeme);
	}
	else if(is_comment_start(lexeme)){
		sprintf(token,"$start");
	}
	else if(is_comment_end(lexeme)){
		sprintf(token,"$end");
	}
	else if(is_identifier(lexeme)){
		printf("Identifier");
		if(mode==1) ht_set( symboltable, lexeme, "1");
		sprintf(token,"%d\t%s",IDNTIFIER,lexeme);
	}
	else sprintf(token,"%d",NOTOK);
	return token;
}







