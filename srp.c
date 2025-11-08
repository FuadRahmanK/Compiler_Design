#include<stdio.h>
char stack[100],input[100];
int ind=0,top=0,Sl=1;
int reduce(){
		for(int i=0;i<top;i++){
			if(stack[i]=='i'){
				stack[i]='E';
				printf("%d\t$%s\t%s$\treduce E-->i\n",Sl,stack,input);
				Sl++;
			}
		}
		for(int i=0;i<top;i++){
			if(stack[i]=='(' && stack[i+1]=='E' && stack[i+2]==')')
			stack[i]='E';
			stack[i+1]=='\0';
			top=top-2;
			printf("%d\t$%s\t%s$\treduce E-->(E)\n",Sl,stack,input);
			Sl++;
		}
		for(int i=0;i<top;i++){
			if(stack[i]=='E' && stack[i+1]=='+' && stack[i+2]=='E')
			stack[i]='E';
			stack[i+1]=='\0';
			top=top-2;
			printf("%d\t$%s\t%s$\treduce E-->E+E\n",Sl,stack,input);
			Sl++;
		}for(int i=0;i<top;i++){
			if(stack[i]=='E' && stack[i+1]=='*' && stack[i+2]=='E')
			stack[i]='E';
			stack[i+1]=='\0';
			top=top-2;
			printf("%d\t$%s\t%s$\treduce E-->E*E\n",Sl,stack,input);
			Sl++;
		}


}
int main(){
		printf("enter the expression");
		scanf("%s",input);
		printf("SLNum\tstack\tinput\taction\n\n");
		printf("%d\t$%s\t%s$\t-\n",Sl,stack,input);
		Sl++;
		while(input[ind]!='\0'){
			stack[top++]=input[ind];
			stack[top]='\0';
			input[ind++]=' ';
			printf("%d\t$%s\t%s$\tshift %c\n",Sl,stack,input,stack[top-1]);
			Sl++;
			reduce();
		
		}
		if(stack[0]=='E' &&stack[1]=='\0'){
				printf("accepted\n");
		
		
		}else{
			printf("rejected\n");
		}

}
