#include<stdio.h>
int m,n,f,fstate[10],transition[100][100],choice=1;
char symbols[10];
int dfa(){
	char string[100];
	printf("Enter string: ");
	scanf("%s",string);
	int currstate=0,k=0;
	while(string[k]!='\0'){
		int index=-1;
		for(int i=0;i<n;i++){
			if(string[k]==symbols[i]){
				index=i;
				break;
			}
		}currstate=transition[currstate][index];
		k++;
	}int flag=0;
	for(int i=0;i<f;i++){
		if(currstate==fstate[i]){
			flag=1;
			printf("String is accepted\n");
			break;
		}
	}
	if(flag==0){
		printf("String is rejected\n");
	}
}
int main(){
	printf("Enter no of states: ");
	scanf("%d",&m);
	printf("Enter no input symbols: ");
	scanf("%d",&n);
	printf("Enter input symbols: ");
	scanf("%s",symbols);
	printf("Enter no of final states: ");
	scanf("%d",&f);
	printf("Enter final states: ");
	for(int i=0;i<f;i++)
		scanf("%d",&fstate[i]);
	printf("Enter transition:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("from q%d for %c: ",i,symbols[j]);
			scanf("%d",&transition[i][j]);
		}
	}while(choice!=0){	
		printf("Enter 1 for input string\nEnter 0 to exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:	break;
			case 1:	dfa();
				break;
			default: printf("Invalid choice!");
		}
	}
}
