#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node * Linkedlist;
struct node {
	int data ;
	Linkedlist next ;
} ;

Linkedlist i , j , first ,head , newnode;
int compare;


int search(Linkedlist first , int number){
	i = first;
	j = i -> next;
	int found = 0 , searching = 1 ;
	compare = 1;
	while (j != NULL && searching == 1 ){
		if ( j -> data == number ){
			found = 1;
			searching = 0;
		} 
		else if (j -> data < number){
			i = j ;
			j = j -> next;
			compare = compare + 1 ;
		}
		else {
			searching = 0;
		}
	}
	return(found);
}

void printdata(Linkedlist first){
	i = first ;
	j = i -> next;
	while(j != NULL){
		printf("%d \n",j -> data);
		j = j -> next;
	}
}
void deletion(int number){
	int d ;
	d = search(first,number);
	if (d == 1){
		i -> next = j -> next;
		printf("Delete complete");
	}
	else 
		printf("NOT Found");
}

int main(){
	first = NULL;
	head = (Linkedlist)malloc(sizeof(node));
	head -> data = NULL;
	head -> next = first;
	first = head;
	int number , found,n = 1,a=1;
	while (n <= 4 && n != 0){
		printf("[1] Insert data \n");
		printf("[2] print data \n");
		printf("[3] Search data \n");
		printf("[4] Delete data \n");
		printf("[5] Exit program \n");
		printf("Please select your command number : ");
		scanf("%d",&n);
		if (n == 1){
			printf("Enter value (0 = Exit): ");
			scanf("%d",&number);
			while ( number != 0){
				found = search(first , number);
				if (found == 0){
					newnode = (Linkedlist)malloc(sizeof(node));
					newnode -> data = number;
					newnode -> next = j;
					i -> next = newnode;
				}	 
				else{
					printf("You already have this number \n");
				}
				printf("Enter value (0 = Exit): ");
				scanf("%d",&number);
			}
		}
		if (n == 2){
			printdata(first);
		}
		if (n == 3){
			printf("Input number you want to seraching : ");
			scanf("%d",&number);
			found = search(first,number);
			if (found == 1){
				printf("Found , compare is %d",compare);
			}
			else{
				printf("Not found , compare is %d",compare);
			}
			printf("\n");
		}
		if (n == 4){
			printf("Input number you want to delete : ");
			scanf("%d",&number);
			deletion(number);
			printf("\n");
			printdata(first);
		}
	}
}










