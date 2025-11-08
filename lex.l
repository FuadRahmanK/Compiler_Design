%{
	int line=1,slno=1;
	FILE *fp;
%}
WS [ \t]
L [a-zA-Z]
D [0-9]
%%
{WS} {}
"\n" {line++;}
";" {fprintf(fp,"%d\t\t%s\t\tSemi\t\t%d\n",slno++,yytext,line);}
"+"|"-"|"*"|"/" {fprintf(fp,"%d\t\t%s\t\tA_OP\t\t%d\n",slno++,yytext,line);}
"("|"{"|"[" {fprintf(fp,"%d\t\t%s\t\tOP_BRK\t\t%d\n",slno++,yytext,line);}
")"|"}"|"]" {fprintf(fp,"%d\t\t%s\t\tCLS_BRK\t\t%d\n",slno++,yytext,line);}
"<"|">"|"<="|">="|"!="|"==" {fprintf(fp,"%d\t\t%s\t\tR_OP\t\t%d\n",slno++,yytext,line);}
"=" {fprintf(fp,"%d\t\t%s\t\tAss_OP\t\t%d\n",slno++,yytext,line);}
"void"|"main"|"int"|"include"|"stdio.h" {fprintf(fp,"%d\t\t%s\t\tKeyword\t\t%d\n",slno++,yytext,line);}
{D}+"."(D)* {fprintf(fp,"%d\t\t%s\t\tFLT_NO\t\t%d\n",slno++,yytext,line);}
{D}+ {fprintf(fp,"%d\t\t%s\t\tNO\t\t%d\n",slno++,yytext,line);}
{L}+({L}|{D})* {fprintf(fp,"%d\t\t%s\t\tIdent\t\t%d\n",slno++,yytext,line);}
. {fprintf(fp,"%d\t\t%s\t\tUNREC\t\t%d\n",slno++,yytext,line);}
%%
void main(int argc, char* argv[]){
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	fprintf(fp,"SlNO\t\tLexeme\t\tToken\t\tLine\n");
	yylex();
}
int yywrap(){
	return 1;
}
