%{
#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h>
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UMINUS
%%
L:E'\n' {printf("Result is %d\n",$1);exit(0);}
;
E:E'+'E {$$ = $1 + $3;}
|E'-'E {$$ = $1 - $3;}
|E'*'E {$$ = $1 * $3;}
|E'/'E {$$ = $1 / $3;}
|'('E')' {$$ = $2;}
|'-'E %prec UMINUS {$$=-$2;}
|NUMBER {$$=$1;}
;
%%
void main()
{
	printf("Enter expression: "); 
	yyparse();
}
int yylex()
{
	char ch;
	ch = getchar(); 
	if(isdigit(ch)){
		ungetc(ch, stdin);
		scanf("%d", &yylval); 
		return NUMBER;
	}else
		return ch;
}
int yyerror()
{
	printf("Error: Invalid expression\n"); 
	exit(0);
}
