#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "conio.h"

#define SIZE 100
char Stack[SIZE];
int top = -1 ;

void push(char item){
	if (top >= SIZE-1){
		printf("Stack over flow");	
	} 
	else {
		top = top + 1;
		Stack[top] = item;
	}
}

char pop(void){
	char item ; 
	if (top == -1 ){
		return('\0');
	}
	else {
		item = Stack[top];
		top = top - 1;
		return(item);
	}
}

int is_operator(char item){
	if (item == '^' || item == '*' || item == '/' || item == '+' || item == '-'){
		return(1);
	}
	else 
		return(0);
}

int precedene(char item){
	if (item == '^'){
		return(3);
	}
	else if (item == '*' || item == '/'){
		return(2);
	}
	else if (item == '+' || item == '-'){
		return(1);
	}
	else
		return(0);
}

void InfixtoPostfix(char infix[] , char postfix[]){
	int i , j ;
	char item ; 
	char x ;
	i = 0 ;
	j = 0 ;
	item = infix[i];
	while(item != '\0'){
		if(item == '('){
			push(item);
		}
		else if(isalpha(item)){
			postfix[j] = item;
			j++;
		}
		else if(is_operator(item) == 1){
			if(top == -1 ){
				push(item);
			}
			else {
				x = pop();
				if(is_operator(x) == 1 && precedene(item) <= precedene(x) ){
					postfix[j] = x;
					j++;
					x = pop();
				}
				push(x);
				push(item);
			}
		}
		else if(item == ')'){
			x = pop();
			while(x != '('){
				if(item == ')' && x != '(' && x == '\0'){
					printf("Invalid infix exprassion ! expected to be '(' ");
					exit(1);
				}
				postfix[j] = x ;
				j++;
				x = pop();
			}
		}
		else {
			printf("Invalid infix exprassion !\n"); 
			exit(1);
		}
		i++;
		item = infix[i];
	}
	if(item == '\0'){
		x = pop();
		while(x != '\0'){
			if(x == '(' ){
				printf("Invalid infix exprassion ! expected to be ')' \n");
				exit(1);
			}
			postfix[j] = x ;
			j++;
			x = pop();
		}
	}
	if(top >= 0){
		printf("Invalid infix exprassion\n");
	}
	postfix[j] = '\0';
}

void reversed(char infix[] ,char reinfix[]){
	char item ,x;
	int i = 0 , j = 0 ;
	
	item = infix[i];
	while(item != '\0'){
		if(item == '('){
			item = ')';
			push(item);
		}
		else if(item == ')'){
			item = '(';
			push(item);
		}
		else{
			push(item);
		}
		i++;
		item = infix[i];
	}
	x = pop();
	while(x != '\0'){
		reinfix[j] = x ;
		j++;
		x = pop();
	}
	reinfix[j] = '\0';
}

int main(){
	char infix[SIZE],postfix[SIZE],prefix[SIZE],reinfix[SIZE];
	char chioce ; 

	while(1){
		system("cls");
		printf("[1] inFix to postFix\n");
		printf("[2] inFix to preFix\n");
		printf("Select chioce : ");
		gets(&chioce);
		if (chioce == '1'){
			printf("Enter your infix exprassion : ");
			gets(infix);
		
			InfixtoPostfix(infix,postfix);
		
			printf("Convers infix to postfix exprassion is : ");
			puts(postfix);
			
		}
		else if (chioce == '2'){
			printf("Enter your infix exprassion : ");
			gets(infix);
			
			reversed(infix,reinfix);
			//strrev(infix);
			//puts(reinfix);
			InfixtoPostfix(reinfix,prefix);
			strrev(prefix);
			
			printf("Convers infix to prefix exprassion is : ");
			puts(prefix);
			
		}
		else 
			break;
		getch();
	}
	return(0);
}

















