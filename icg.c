#include<stdio.h>
#include<string.h>
#include<ctype.h>
char expr[20],postfix[20],stack[20],ch;
int prec(char ch){
	if(ch=='^')return 3;
	else if(ch=='*'||ch=='/')return 2;
	else if(ch=='+'||ch=='-')return 1;
	else return -1;
}
int intopost(char* expr){
	int len=strlen(expr);
	int j=0,top=-1;
	for(int i=0;i<len;i++){
		ch=expr[i];
		if(isalnum(ch)){
			postfix[j++]=ch;
		}else if(ch=='('){
			stack[++top]=ch;
		}else if(ch==')'){
			while(top!=-1&&stack[top]!='('){
				postfix[j++]=stack[top--];
			}top--;
		}else{
			while(top!=-1&&(prec(ch)<=prec(stack[top]))){
				postfix[j++]=stack[top--];
			}stack[++top]=ch;
		}
	}while(top!=-1){
		postfix[j++]=stack[top--];
	}postfix[j]='\0';
	printf("postfix expression: %s\n",postfix);
}
int TA(){
	int top=-1,i=0,slno=1;
	char ch,ch1,ch2;
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalnum(ch)){
			stack[++top]=ch;
		}else{
			ch1=stack[top--];
			ch2=stack[top--];
			printf("t%d = %c %c %c\n",slno,ch2,ch,ch1);
			stack[++top]=slno+'0';
			slno++;
		}i++;
	}
}
int QUAD(){
	int top=-1,i=0,slno=1;
	char ch,ch1,ch2;
	printf("Op\tArg1\tArg2\tRes\n");
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalnum(ch)){
			stack[++top]=ch;
		}else{
			ch1=stack[top--];
			ch2=stack[top--];
			printf("%c\t%c\t%c\tt%d\n",ch,ch2,ch1,slno);
			stack[++top]=slno+'0';
			slno++;
		}i++;
	}
}
int triple(){
	int top=-1,i=0,slno=1;
	char ch,ch1,ch2;
	printf("No\tOp\tArg1\tArg2\n");
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalnum(ch)){
			stack[++top]=ch;
		}else{
			ch1=stack[top--];
			ch2=stack[top--];
			if(isalpha(ch1)&&isalpha(ch2))
				printf("(%d)\t%c\t%c\t%c\n",slno-1,ch,ch2,ch1);
			else if(isalpha(ch1)&&isdigit(ch2))
				printf("(%d)\t%c\t(%c)\t%c\n",slno-1,ch,ch2,ch1);
			else if(isdigit(ch1)&&isalpha(ch2))
				printf("(%d)\t%c\t%c\t(%c)\n",slno-1,ch,ch2,ch1);
			else if(isdigit(ch1)&&isdigit(ch2))
				printf("(%d)\t%c\t(%c)\t(%c)\n",slno-1,ch,ch2,ch1);
			stack[++top]=slno+'0';
			slno++;
		}i++;
	}
}
int main(){
	printf("Enter expression: ");
	scanf("%s",expr);
	intopost(expr);
	TA();
	QUAD();
	triple();
}
