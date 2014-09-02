#include "read_module.h"
#include <stdbool.h> 
#define BUFFER_SIZE 20
static char buffer[BUFFER_SIZE];
static char *lexeme_begin , *forward;
static eof_check=0;
static void update_first();
void init(){
	//printf("Initializing.\n");
	lexeme_begin=buffer;
	forward=buffer;
	int i=0;
	//printf("Reading first buffer\n");
	update_first();
	//printf("\tbuffer : |%s|\n",buffer);
}
static void update_first(){
	int i=0,j;
	//printf("Updating first\n");
	for(;i<BUFFER_SIZE/2;i++){
		scanf("%c",&buffer[i]);
		if(feof(stdin)){
			eof_check=1;
			for(;i<BUFFER_SIZE;i++){
				buffer[i]='\0';
			}
		}
	}
	//printf("\tbuffer : |%s|\n",buffer);
}
static void update_next(){
	int i,j;
	//printf("Updating next\n");
	for(i=BUFFER_SIZE/2;i<BUFFER_SIZE;i++){
		scanf("%c",&buffer[i]);
		if(feof(stdin)){
			eof_check=1;
			for(;i<BUFFER_SIZE;i++){
				buffer[i]='\0';
			}
		}
	}
	//printf("\tbuffer : |%s|\n",buffer);
}
static void advance_forward(){
	forward++;
	//printf("Advanciong forward\n");
	if(forward >= buffer+BUFFER_SIZE){
		update_first();
		forward=buffer;
	}
	else if(forward == buffer+BUFFER_SIZE/2-1){
		update_next();
	}
}
static void advance_lexeme_begin(){
	lexeme_begin++;
	//printf("Advancing lexeme begin\n");
	if(lexeme_begin >= buffer+BUFFER_SIZE){
		lexeme_begin=buffer;
	}
}
static bool is_whitespace(char *ptr){
	if(*ptr==' ' || *ptr=='\n' || *ptr=='\t' ){
		return true;
	}
	return false;
}
static bool is_unit(char *ptr){
	if(*ptr=='(' || *ptr==')' || *ptr=='{' || *ptr=='}' || *ptr=='[' 
		|| *ptr==']' || *ptr==';' || *ptr==',' || *ptr=='%' || *ptr=='/'
		|| *ptr=='+' || *ptr=='-' || *ptr=='=' || *ptr=='!' || *ptr=='<'
		|| *ptr=='>' || *ptr=='*'){
		return true;
	}
	return false;
}
char *extract_lexeme(){
	char* reference=lexeme_begin;
	int count=0;
	while(lexeme_begin!=forward){
		advance_lexeme_begin();
		count++;
	}
	lexeme_begin=reference;
	char* lexeme=(char*)calloc(count+2,sizeof(char));
	int i=0;
	for(;i<count;i++){
		lexeme[i]=*lexeme_begin;
		advance_lexeme_begin();
	}
	return lexeme;
}
char* return_unit(){
	char *lexeme=(char*)calloc(4,sizeof(char));
	lexeme[0]=*forward;
	if(*forward=='>' || *forward=='<' || *forward=='!' || *forward=='='){
		if(*(forward+1)=='='){
			lexeme[1]=*(forward+1);
			advance_forward();
		}
	}
	if(*forward=='*'){
		if(*(forward+1)=='=' || *(forward+1)=='/'){
			lexeme[1]=*(forward+1);
			advance_forward();
		}
	}
	if(*forward=='/'){
		if(*(forward+1)=='=' || *(forward+1)=='*'){
			lexeme[1]=*(forward+1);
			advance_forward();
		}
	}
	if(*forward=='+'){
		if(*(forward+1)=='=' || *(forward+1)=='+'){
			lexeme[1]=*(forward+1);
			advance_forward();
		}
	}
	if(*forward=='-'){
		if(*(forward+1)=='=' || *(forward+1)=='+'){
			lexeme[1]=*(forward+1);
			advance_forward();
		}
	}
	advance_forward();
	return lexeme;
}
char* get_next_lexeme(){
	//printf("\n\nGetting next lexeme\n");
	if(is_unit(forward)){
		return return_unit();
	}
	//printf("no unit found\n");
	while(is_whitespace(forward)){
		advance_forward();
	}
	if(*forward=='\0') return NULL;	
	lexeme_begin=forward;
	while(!is_whitespace(forward)){
		if(is_unit(forward)) break;
		advance_forward();
	}
	return extract_lexeme();
}

