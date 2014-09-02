%{
FILE * outStream;
%}
%%
[-+]?[0-9]+("."?)[0-9]* { fprintf(outStream,"id"); }
[ \n\t\r]+ {}
(.) { fprintf(outStream,"%s",yytext); }
%%
int main(int argc , char ** argv){
	if (argc > 1){
		FILE *file;
		file = fopen(argv[1], "r");
		if (!file)
		{
		    fprintf(stderr, "Could not open %s\n", argv[1]);
		    exit(1);
		}
		yyin = file;
	}
	outStream = stdout;
	yylex();
	return 0;
}
