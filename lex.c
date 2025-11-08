#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char* argv[]){
	char ch,ch1,lexeme[25];
	char keyword[6][20]={"int","float","include","stdio.h","void","main"};
	int slno=1,line=1;
	FILE *fp1=fopen(argv[1],"r");
	FILE *fp2=fopen(argv[2],"w");
	fprintf(fp2,"SlNo\t\tLexeme\t\tToken\t\tLine\n\n");
	while((ch=fgetc(fp1))!=EOF){
		if(ch==' '||ch=='\t');
		else if(ch=='\n')
			line++;
		else if(ch==';'){
			fprintf(fp2,"%d\t\t%c\t\tSemi_colon\t\t%d\n",slno,ch,line);
			slno++;
		}else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			fprintf(fp2,"%d\t\t%c\t\tArith_op\t\t%d\n",slno,ch,line);
			slno++;
		}else if(ch=='(' || ch=='{' || ch=='['){
			fprintf(fp2,"%d\t\t%c\t\tOpen_brack\t\t%d\n",slno,ch,line);
			slno++;
		}else if(ch==')' || ch=='}' || ch==']'){
			fprintf(fp2,"%d\t\t%c\t\tClose_brack\t\t%d\n",slno,ch,line);
			slno++;
		}else if(ch=='&' || ch==',' || ch=='#' || ch==':'){
			fprintf(fp2,"%d\t\t%c\t\tSpecial_char\t\t%d\n",slno,ch,line);
			slno++;
		}else if(ch=='='){
			if((ch1=fgetc(fp1))=='='){
				fprintf(fp2,"%d\t\t%c%c\t\tRelat_op\t\t%d\n",slno,ch,ch1,line);
			}else{
				fprintf(fp2,"%d\t\t%c\t\tAssign_op\t\t%d\n",slno,ch,line);
				ungetc(ch1,fp1);
			}slno++;
		}else if(ch=='<' || ch=='>' || ch=='!'){
			if((ch1=fgetc(fp1))=='='){
				fprintf(fp2,"%d\t\t%c%c\t\tRelat_op\t\t%d\n",slno,ch,ch1,line);
			}else{
				fprintf(fp2,"%d\t\t%c\t\tRelat_op\t\t%d\n",slno,ch,line);
				ungetc(ch1,fp1);
			}slno++;
		}else if(isdigit(ch)){
			int flag=0,i=0;
			lexeme[i++]=ch;
			ch1=fgetc(fp1);
			while(isdigit(ch1)||ch1=='.'){
				lexeme[i++]=ch1;
				if(ch1=='.')
					flag=1;
				ch1=fgetc(fp1);
			}lexeme[i]='\0';
			ungetc(ch1,fp1);
			if(flag)
				fprintf(fp2,"%d\t\t%s\t\tFloat_no\t\t%d\n",slno,lexeme,line);
			else
				fprintf(fp2,"%d\t\t%s\t\tNumber\t\t%d\n",slno,lexeme,line);
			slno++;
			memset(lexeme,'\0',sizeof(lexeme));
		}else if(isalpha(ch)){
			int flag=0,i=0;
			lexeme[i++]=ch;
			ch1=fgetc(fp1);
			while(isalpha(ch1)||ch1=='.'||isdigit(ch1)||ch1=='_'){
				lexeme[i++]=ch1;
				ch1=fgetc(fp1);
			}lexeme[i]='\0';
			ungetc(ch1,fp1);
			for(int j=0;j<6;j++){
				if(strcmp(lexeme,keyword[j])==0){
					flag=1;
					break;
				}
			}if(flag)
				fprintf(fp2,"%d\t\t%s\t\tKeyword\t\t\t%d\n",slno,lexeme,line);
			else
				fprintf(fp2,"%d\t\t%s\t\tIdentifier\t\t%d\n",slno,lexeme,line);
			slno++;
			memset(lexeme,'\0',sizeof(lexeme));
		}else{
			fprintf(fp2,"%d\t\t%c\t\tUnrecognized\t\t%d\n",slno,ch,line);
			slno++;
		}
	}fclose(fp1);
	fclose(fp2);
}
