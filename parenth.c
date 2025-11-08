#include<stdio.h>
int main(int argc, char* argv[]){
	FILE *fp=fopen(argv[1],"r");
	char ch,ch1,stack[100];
	int top=-1,line=1,error=0;
	while((ch=fgetc(fp))!=EOF){
		switch(ch){
			case '(':
			case '{':
			case '[':	stack[++top]=ch;
					break;
			case '\n':	line++;
					break;
			case ')':	if(top==-1){
						printf("Opening bracket mismatch %c at line %d\n",ch,line);
						error=1;
					}else{
						ch1=stack[top--];
						if(ch1!='('){
							printf("Parenthesis mismatch %c at line %d\n",ch,line);
							error=1;
							stack[++top]=ch1;
						}
					}break;
			case '}':	if(top==-1){
						printf("Opening bracket mismatch %c at line %d\n",ch,line);
						error=1;
					}else{
						ch1=stack[top--];
						if(ch1!='{'){
							printf("Parenthesis mismatch %c at line %d\n",ch,line);
							error=1;
							stack[++top]=ch1;
						}
					}break;
			case ']':	if(top==-1){
						printf("Opening bracket mismatch %c at line %d\n",ch,line);
						error=1;
					}else{
						ch1=stack[top--];
						if(ch1!=']'){
							printf("Parenthesis mismatch %c at line %d\n",ch,line);
							error=1;
							stack[++top]=ch1;
						}
					}break;
		}
	}while(top!=-1){
		ch=stack[top--];
		printf("Closing bracket missing for %c at line %d\n",ch,line);
		error=1;
	}if(error==0){
		printf("Parenthesis is balanced\n");
	}fclose(fp);
}
