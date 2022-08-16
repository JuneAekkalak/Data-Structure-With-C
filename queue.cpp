#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

#define size 7 
int head = -1 , tail = -1 ;
char queue[size];

int queueinsert(char data){
	int front ;
	if (head == size-1){
		front = 0;
	}else{
		front = head + 1;
	}
	if (front == tail){
		printf("<< !! queue overflow !! >>\n");
		return(0);
	}
	head = front ;
	queue[head] = data;
	if (tail == -1){
		tail = 0;
	}
	return(1);
}

int queuedelete(void){
	char data ;
	if (tail == -1){
		printf("<< !! queue underflow !! >>\n");
		return(0);
	}
	data = queue[tail];
	if(tail == head){
		tail = -1;
		head = -1;
	}
	else if(tail == size-1){
		tail = 0 ;
	}
	else{
		tail = tail + 1 ;
	}
	return(1);
}

int main(){
	int c , result ;
	char data;
	while(1){	
		system("cls");
		printf("[1] Insert queue \n");
		printf("[2] Delete queue \n");
		printf("[3] Exit program \n");
		printf("Select choice : ");
		scanf("%d",&c);
		if(c == 1){
			printf("Enter your data to insert in the queue : ");
			scanf("%s",&data);
			result = queueinsert(data);
			if (result == 1){
				printf("<< !!! Successful !! >>\n");
			}
			else{
				printf("<< !! Unsuccessful !! >>\n");
			}
		}
		else if(c == 2){
			result = queuedelete();
			if(result == 1){
				printf("<< !!! Successful !! >>\n");
			}
			else{
				printf("<< !! Unsuccessful !! >>\n");
			}
		}
		else 
			break;
		getch();
		
	}
	return(0);
}
