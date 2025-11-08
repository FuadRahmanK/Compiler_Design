%{
	#include<math.h>
	int flag=0,num=0;
%}
DIGIT [0-9]
%%
"\n" {printf("Result is %d\n",num);exit(0);}
"+" {flag=1;}
"-" {flag=2;}
"*" {flag=3;}
"/" {flag=4;}
"^" {flag=5;}
{DIGIT}+ {if(flag==0)
		num=atoi(yytext);
	else if(flag==1)
		num+=atoi(yytext);
	else if(flag==2)
		num-=atoi(yytext);
	else if(flag==3)
		num*=atoi(yytext);
	else if(flag==4)
		num/=atoi(yytext);
	else if(flag==5)
		num=pow(num,atoi(yytext));}
. {printf("Invalid\n");exit(0);}
%%
void main(){
	printf("Enter expression: ");
	yyin=stdin;
	yylex();
}
int yywrap(){
	return 1;
}
