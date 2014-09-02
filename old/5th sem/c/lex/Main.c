#include "read_module.h"
#include "dfa.h"
int main()
{
	init();
	pre_populate_symboltable();
	create_lookup();
	char *lexeme=get_next_lexeme(),*token;
	FILE *fptr=fopen("a4_1.out","w+");
	while(lexeme!=NULL) {
		if(strlen(lexeme)>0){
			token=get_token(lexeme,1);
			if(strcmp(token,"$start")==0){
				while(strcmp(token,"$end")!=0){
					free(token);
					free(lexeme);
					lexeme=get_next_lexeme();
					token=get_token(lexeme,0);
				}
			}
			printf("%s : %s\n",lexeme,token);
			if(strcmp(token,"-1")!=0) fprintf(fptr,"%s\n",token);
			free(token);
		}
		free(lexeme);
		lexeme=get_next_lexeme();
	}
	print_symbol_table();
	return 0;
}
