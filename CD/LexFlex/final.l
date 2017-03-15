%option noyywrap
%{
	#include<stdio.h>
	#include<string.h>
	int lines = 0;
	char id[20];
	char identifiers[30][15];
	char keywords[20][15];
	int iden = 0, keys = 0;
%}

keylist ("int"|"main"|"if"|"else"|"printf"|"scanf"|"char"|"return"|"void"|"for"|"while"|"do"|"long"|"float")  
%%

\n			{ lines++; fprintf(yyout  , yytext); }

#include<.*.h>		{ fprintf(yyout , yytext); }

"%"			{ fprintf(yyout , "%%"); }

{keylist} 		{ strcpy(keywords[keys++] , yytext); fprintf(yyout , yytext); }

[A-Za-z_][A-Za-z_0-9]*	{ fprintf(yyout , yytext); strcpy(identifiers[iden++] , yytext); }

"/*"[^*/]*\*+\/		{ printf("Comment removed at %d\n",lines); }

\".*\"			{ fprintf(yyout , yytext); } 

\/\/.*\n		{ fprintf(yyout , "\n"); printf("Comment removed at %d\n",lines); }

%%

main(int argc,char *argv[])
{
	int n, l;
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	yylex();

	printf("Number of lines = %d\n",lines);
	
	printf("Identifiers :\n");
	for(l = 0 ; l<iden ; l++){
		printf("%s\t" , identifiers[l]);
	}

	printf("\n\nKeywords :\n");
	for(n = 0 ; n<keys ; n++){
		printf("%s\t" , keywords[n]);
	}

	fclose(yyin);
	fclose(yyout);
	return 0;
}
