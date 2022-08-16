#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef struct node *stacktype;
struct node {
	char data ;
	stacktype next;
};

stacktype newnode , stack , first;

void Push(int data){
	newnode = (stacktype)malloc(sizeof(node));
	newnode -> data = data ;
	newnode -> next = stack ;
	stack = newnode;
}

void Pop(){
	if (stack == NULL){
		printf("Empty Stack");
	}
	else {
		first = stack ;
		stack = first -> next ;
		first -> next = NULL;
	}
}

void printdata(){
	first = stack ;
	if (first == NULL){
		printf("\nNot data\n");
	}
	else{
		while(first != NULL){
			printf("%c \n",first -> data);
			first = first -> next;
		}
	}
}

int main (){
	stack = NULL;
	int n ;
	char data;
	bool end = true ;
	while (end == true){
		printf("[1] : Push \n");
		printf("[2] : Pop \n");
		printf("[3] : Stop program \n");
		printf("Select number : ");
		scanf("%d",&n);
		if (n == 1){
			printf("Input data :");
			scanf("%s",&data);
			while (true){
				Push(data);
				printf("Input data :");
				scanf("%s",&data);
				if (data == '0'){
					break;
				}
			}
			printdata();
		}
		if (n == 2){
			Pop();
			printdata();
		}
		if(n == 3){
			end = false ;
		} 
		
	}	
}
