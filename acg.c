#include<stdio.h>
#include<string.h>
#include<ctype.h>
char expr[100],ch,postfix[100],stack[100];
int prec(char ch){
	if(ch=='^')
		return 3;
	else if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='+'||ch=='-')
		return 1;
	else
		return -1;
}
int intopost(char* expr){
	int j=0,top=-1;
	int len=strlen(expr);
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
	}
	while(top!=-1){
		postfix[j++]=stack[top--];
	}
	postfix[j]='\0';
	printf("Postfix is %s\n",postfix);
}
int main(){
	printf("Enter expression: ");
	scanf("%s",expr);
	intopost(expr);
	int add;
	printf("Enter starting address: ");
	scanf("%d",&add);
	int i=0;
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalnum(ch)){
			printf("%d:\tMOV A,%c\n",add++,ch);
			printf("%d:\tPUSH A\n",add++);
		}else{
			printf("%d:\tPOP B\n",add++);
			printf("%d:\tPOP A\n",add++);
			switch(postfix[i]){
				case '+':	printf("%d:\tADD B\n",add++);
						break;
				case '-':	printf("%d:\tSUB B\n",add++);
						break;
				case '*':	printf("%d:\tMUL B\n",add++);
						break;
				case '/':	printf("%d:\tDIV B\n",add++);
						break;
			}
			printf("%d:\tPUSH A\n",add++);
		}
		i++;
	}
	printf("%d:\tPOP A\n",add++);
	printf("%d:\tHLT\n",add++);
}
