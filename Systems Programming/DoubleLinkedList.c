/*----------------------------------------------------------------------------------*/
/* Double Linked List:																*/
/*																					*/
/* This program demonstrates the usage of double linked lists. It first constructes	*/
/* A double linked list and then prints it forward and backward. Afterwards the user*/
/* Inputs a value to delete from the list, and it is printed both ways again. After */
/* this the program reveives another value from the user, that is then used to		*/
/* search the list and then display to the user what node it is located at.			*/
/*																					*/
/* Author: Joe Van Deusen															*/
/*----------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;

	struct Node *next;
	struct Node *prev;
};

int main()
{
	struct Node *temp, *temp1, *head, *tail, *above, *below;
	int target=0, found=0, counter=0;

	//contructing first Node
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=25;//put values for the node
	temp->next=NULL;
	temp->prev=NULL;
	head=temp;//placeing head
	tail=temp;

	//contructing second Node
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=38;//put values for the node
	temp->next=NULL;
	//connecting 1st and 2nd
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;//placing tail
	
	//contructing third Node
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=3;//put values for the node
	temp->next=NULL;
	//connecting 2nd and 3rd
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;//placing tail

	//contructing fourth Node
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=1;//put values for the node
	temp->next=NULL;
	//connecting 3rd and 4th
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;//placing tail

	//contructing fifth Node
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=10;//put values for the node
	temp->next=NULL;
	//connecting 4th and 5th
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;//placing tail

	//contructing sixth Node
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=11;//put values for the node
	temp->next=NULL;
	//connecting 5th and 6th
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;//placing tail

	for(temp1=head; temp1!= NULL; temp1= temp1->next){//print and count
		printf("%d \n", temp1->value);
		counter++;
	}
	printf("\n");

	printf("NOW BACKWARDS! \n");
	for(temp1=tail; temp1!= NULL; temp1= temp1->prev){//print backwards
		printf("%d \n", temp1->value);
	}
	printf("There are %d Nodes.\n",counter);
	printf("\n");

	//contructing hat, another entry on top of head
	temp = (struct Node*)malloc(sizeof(struct Node));//allocate space
	temp->value=100;//put values for the node
	temp->next=NULL;
	temp->prev=NULL;
	//connecting head to hat
	head->prev=temp;
	temp->next=head;
	head=head->prev;//placing new head

	printf("New List with a value added \n");
	counter=0;//reset counter
	for(temp1=head; temp1!= NULL; temp1= temp1->next){//print and count
		printf("%d \n", temp1->value);
		counter++;
	}
	printf("There are %d Nodes.\n",counter);
	printf("\n");

	//HOMEWORK!!!! search for a node input by user, delete it, pint it backwards and forwards.
	printf("Please enter a value to search for. \n");
	scanf("%d", &target);
	counter=0;//reset counter
	for(temp1=head; temp1!= NULL; temp1=temp1->next){//search forward
		counter++;
		if(temp1->value==target) {
			printf("Found it. Deleted it.\n");
			printf("This value was found in node %d. \n", counter);
			above=temp1->prev;//remove an entry
			below=temp1->next;
			if(above!=NULL){//in case it is the first value, this prevents a crash
				above->next=below;
			}
			else{//if it is the first value, reset the head
				head=below;
			}
			if(below!=NULL){//in case it is the last value, this prevents a crash
				below->prev=above;
			}
			else{//if it is the last value, reset the tail
				tail=above;
			}
			found=1;
			break;
		}
	}
	if(found==0){
		printf("Sorry, I could not find it \n");
	}

	printf("\n");//print new list
	printf("New List \n");
	counter=0;//reset counter
	for(temp1=head; temp1!= NULL; temp1= temp1->next){//print and count
		printf("%d \n", temp1->value);
		counter++;
	}
	printf("\n");
	printf("NOW BACKWARDS! \n");
	for(temp1=tail; temp1!= NULL; temp1= temp1->prev){//print backwards
		printf("%d \n", temp1->value);
	}
	printf("There are %d Nodes.\n",counter);

	//HOMEWORK! part 2. Search backwards for number input by user, display node number.
	printf("\n");//Now search backwards
	printf("NOW SEARCH BACKWARDS! Please enter a value to search for. \n");
	scanf("%d", &target);
	found=0;//reset found
	for(temp1=tail; temp1!= NULL; temp1=temp1->prev){//search backwards
		if(temp1->value==target) {
			printf("Found it.\n");
			printf("This value was found in node %d. \n", counter);
			found=1;
			break;
		}
		counter--;//work back from the previous count of Nodes.
	}
	if(found==0){
		printf("Sorry, I could not find it \n");
	}
return 0;
}