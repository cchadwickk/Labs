%option	noyywrap

%{
	#include<stdio.h>
	int lineno=0;
%}

%%

("//".*\n)|("/*"([^*]|(\*+[^*/]))*\*+\/)	{printf("Comment at line%d\n",lineno++);}
\**[a-zA-Z_][a-zA-Z_0-9]*			{printf("Identifier : %s\n",yytext); fputs(yytext, yyout);}
\n						{lineno++;putc('\n',yyout);}

%%

main(int argc,char *argv[])
{
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	yylex();
	fclose(yyin);
	fclose(yyout);
	return 0;
}