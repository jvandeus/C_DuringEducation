/*----------------------------------------------------------------------------------*/
/* Test 1:																			*/
/*																					*/
/* A program demostrating the usage and of linked lists. It creates a linked list 	*/
/* And prints it. It then takes a value from the user and if that is one of the 	*/
/* ID values, it deletes the node. The list is then printed again.					*/
/*																					*/
/* Author: Joe Van Deusen															*/
/*----------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int id;

	struct Node *next;
};

typedef struct Node box;

int main()
{
	box *head, *temp;
	int targetID, found=0;

	//constructing first node
	temp=(box*)malloc(sizeof(box));
	temp->id=1;//setting a value to id
	temp->next=NULL;

	head=temp;//place head

	//constructing second node
	temp=(box*)malloc(sizeof(box));
	temp->id=2;//setting a value to id
	temp->next=NULL;

	temp->next=head;//set next to current head
	head=temp;//reset head so new value is on top

	//constucting third node
	temp=(box*)malloc(sizeof(box));
	temp->id=3;//setting a value to id
	temp->next=NULL;

	temp->next=head;//set next to current head
	head=temp;//reset head so new value is on top

	//constructing forth node
	temp=(box*)malloc(sizeof(box));
	temp->id=4;//setting a value to id
	temp->next=NULL;

	temp->next=head;//set next to current head
	head=temp;//reset head so new value is on top

	//constructing fifth node
	temp=(box*)malloc(sizeof(box));
	temp->id=5;//setting a value to id
	temp->next=NULL;

	temp->next=head;//set next to current head
	head=temp;//reset head so new value is on top

	printf("the entire list is as follows: \n");
	for(temp=head; temp != NULL; temp= temp->next){//print
		printf("%d \n", temp->id);
	}

	printf("Please enter an id to search for and delete. \n");
	scanf("%d", &targetID);
	for(temp=head; temp != NULL; temp= temp->next){//search for id
		if(temp->id==targetID){
			printf("Found it. Deleting. \n");
			//printf("%d \n", temp->id);
			found=1;
			break;
		}
	}
	if(found==0){
		printf("Sorry, I could not find your id \n");
	}
	else{
		if(targetID==5){//if it is the head, the new head must be set
			head=head->next;
		}
		else{
			targetID++;//find the one before it so you can next what it points to
			for(temp=head; temp != NULL; temp= temp->next){//search for id
				if(temp->id==targetID){
					temp->next=temp->next->next;
					break;
				}
			}
		}
	}

	printf("the new list is as follows: \n");
	for(temp=head; temp != NULL; temp= temp->next){//print
		printf("%d \n", temp->id);
	}
}