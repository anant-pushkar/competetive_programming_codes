#include "fsm.h"
#include "read_module.h"
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
static bool is_identifier(char *lexeme){
	if(isalpha(lexeme[0]) || lexeme[0]=='_'){
		int i=0,len=strlen(lexeme);
		if(lexeme[i]=='+' || lexeme[i]=='-')i++;
		for(;i<len;i++){
			if(isalnum(lexeme[i]) || (lexeme[i]=='_' && lexeme[i-1]!='_')) continue;
			else return false;
		}
	}else return false;
	return true;
}
static bool is_int_const(char* lexeme){
	int i=0,len=strlen(lexeme);
	if(lexeme[i]=='+' || lexeme[i]=='-')i++;
	for(;i<len;i++){
		if(!isdigit(lexeme[i])) return false;
	}	
	return true;
}
static bool is_flo_const(char *lexeme){
	int i=0,len=strlen(lexeme);
	if(lexeme[i]=='+' || lexeme[i]=='-')i++;
	for(;i<len;i++){
		if(!isdigit(lexeme[i]) && lexeme[i]!='.') return false;
	}	
	return true;
}
static bool is_plus(char * lexeme){
	if(lexeme[0]=='+' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_minus(char *lexeme){
	if(lexeme[0]=='-' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_mult(char *lexeme){
	if(lexeme[0]=='*' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_div(char *lexeme){
	if(lexeme[0]=='/' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_percent(char *lexeme){
	if(lexeme[0]=='%' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_plus_plus(char *lexeme){
	if(lexeme[0]=='+' && lexeme[1]=='+'&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_minus_minus(char *lexeme){
	if(lexeme[0]=='-' && lexeme[1]=='-'&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_equal(char *lexeme){
	if(lexeme[0]=='=' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_minus_eq(char *lexeme){
	if(lexeme[0]=='-' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_plus_eq(char *lexeme){
	if(lexeme[0]=='+' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_mult_eq(char *lexeme){
	if(lexeme[0]=='*' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_div_eq(char *lexeme){
	if(lexeme[0]=='/' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_eq_eq(char *lexeme){
	if(lexeme[0]=='=' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_lesser(char *lexeme){
	if(lexeme[0]=='<' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_less_eq(char *lexeme){
	if(lexeme[0]=='<' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_greater(char *lexeme){
	if(lexeme[0]=='<' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_great_eq(char *lexeme){
	if(lexeme[0]=='<' && lexeme[1]=='='&& lexeme[2]=='\0') return true;
	else return false;
}
static bool is_l_square(char *lexeme){
	if(lexeme[0]=='[' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_r_square(char *lexeme){
	if(lexeme[0]==']' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_l_paraen(char *lexeme){
	if(lexeme[0]=='(' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_r_paraen(char *lexeme){
	if(lexeme[0]==')' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_l_cbrace(char *lexeme){
	if(lexeme[0]=='{' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_r_cbrace(char *lexeme){
	if(lexeme[0]=='}' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_comma(char *lexeme){
	if(lexeme[0]==',' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_semicol(char *lexeme){
	if(lexeme[0]==';' && lexeme[1]=='\0') return true;
	else return false;
}
static bool is_short(char* lexeme){
	if(strcmp(lexeme,"short")==0) return true;
	else return false;
}
static bool is_int(char* lexeme){
	if(strcmp(lexeme,"int")==0) return true;
	else return false;
}
static bool is_float(char* lexeme){
	if(strcmp(lexeme,"float")==0) return true;
	else return false;
}
static bool is_double(char* lexeme){
	if(strcmp(lexeme,"double")==0) return true;
	else return false;
}
static bool is_bool(char* lexeme){
	if(strcmp(lexeme,"bool")==0) return true;
	else return false;
}
static bool is_char(char* lexeme){
	if(strcmp(lexeme,"char")==0) return true;
	else return false;
}
static bool is_signed(char* lexeme){
	if(strcmp(lexeme,"signed")==0) return true;
	else return false;
}
static bool is_unsigned(char* lexeme){
	if(strcmp(lexeme,"unsigned")==0) return true;
	else return false;
}
static bool is_for(char* lexeme){
	if(strcmp(lexeme,"for")==0) return true;
	else return false;
}
static bool is_while(char* lexeme){
	if(strcmp(lexeme,"while")==0) return true;
	else return false;
}
static bool is_do(char* lexeme){
	if(strcmp(lexeme,"do")==0) return true;
	else return false;
}
static bool is_return(char* lexeme){
	if(strcmp(lexeme,"return")==0) return true;
	else return false;
}
static bool is_struct(char* lexeme){
	if(strcmp(lexeme,"struct")==0) return true;
	else return false;
}
static bool is_const(char* lexeme){
	if(strcmp(lexeme,"const")==0) return true;
	else return false;
}
static bool is_void(char* lexeme){
	if(strcmp(lexeme,"void")==0) return true;
	else return false;
}
static bool is_switch(char* lexeme){
	if(strcmp(lexeme,"switch")==0) return true;
	else return false;
}
static bool is_break(char* lexeme){
	if(strcmp(lexeme,"break")==0) return true;
	else return false;
}
static bool is_case (char* lexeme){
	if(strcmp(lexeme,"case")==0) return true;
	else return false;
}
static bool is_continue(char* lexeme){
	if(strcmp(lexeme,"continue")==0) return true;
	else return false;
}
static bool is_goto(char* lexeme){
	if(strcmp(lexeme,"goto")==0) return true;
	else return false;
}
static bool is_long(char* lexeme){
	if(strcmp(lexeme,"long")==0) return true;
	else return false;
}
static bool is_static(char* lexeme){
	if(strcmp(lexeme,"static")==0) return true;
	else return false;
}
static bool is_union(char* lexeme){
	if(strcmp(lexeme,"union")==0) return true;
	else return false;
}
static bool is_default(char* lexeme){
	if(strcmp(lexeme,"default")==0) return true;
	else return false;
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
		sprintf(token,"%d\t%s",INT_CONST,lexeme);
	}
	else if(is_flo_const(lexeme)){
		sprintf(token,"%d\t%s",FLO_CONST,lexeme);
	}
	else if(is_comment_start(lexeme)){
		sprintf(token,"$start");
	}
	else if(is_comment_end(lexeme)){
		sprintf(token,"$end");
	}
	else if(is_identifier(lexeme)){
		if(mode==1) ht_set( symboltable, lexeme, "1");
		sprintf(token,"%d\t%s",IDNTIFIER,lexeme);
	}
	else sprintf(token,"%d",NOTOK);
	return token;
}























