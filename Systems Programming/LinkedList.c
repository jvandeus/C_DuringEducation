/*----------------------------------------------------------------------------------*/
/* Linked List:																		*/
/*																					*/
/* This program creates a linked list, with the nodes reffered to as goats. A goat	*/
/* is then removed from the list and printed again. Then the user enters a value to	*/
/* search the list for id. If found, the program outputs the ID and name.			*/
/*																					*/
/* Author: Joe Van Deusen															*/
/*----------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

struct Goat
{
	int id;
	char name;
	struct Goat *next;
};

int main()
{
	struct Goat *temp, *head, *above, *below;
	int counter = 0, targetId = 0, found=0, sort=0;

	//creating the first goat
	temp = (struct Goat*)malloc(sizeof(struct Goat));
	(*temp).id=1;
	(*temp).name='M';
	(*temp).next=NULL;
	head=temp; //placing head

	//creating the second goat
	temp = (struct Goat*)malloc(sizeof(struct Goat));
	temp->id=3;//(*temp).id=3;
	temp->name='W';//(*temp).name='W';
	temp->next=NULL;//(*temp).next=NULL;

	//connecting two nodes
	head->next=temp;

	//creating the third goat
	temp = (struct Goat*)malloc(sizeof(struct Goat));
	temp->id=10;//(*temp).id=10;
	temp->name='A';//(*temp).name='A';
	temp->next=NULL;//(*temp).next=NULL;

	//connecting node 2 and node 3
	head->next->next=temp;

	//creating the forth goat
	temp = (struct Goat*)malloc(sizeof(struct Goat));
	temp->id=11;//(*temp).id=11;
	temp->name='D';//(*temp).name='D';
	temp->next=NULL;//(*temp).next=NULL;

	//connecting node 3 and node 4
	head->next->next->next=temp;

	//creating the fifth goat
	temp = (struct Goat*)malloc(sizeof(struct Goat));
	temp->id=12;//(*temp).id=12;
	temp->name='R';//(*temp).name='R';
	temp->next=NULL;//(*temp).next=NULL;

	//connecting node 4 and node 5
	head->next->next->next->next=temp;

	//creating the sixth goat
	temp = (struct Goat*)malloc(sizeof(struct Goat));
	temp->id=666;//(*temp).id=666;
	temp->name='B';//(*temp).name='B';
	temp->next=NULL;//(*temp).next=NULL;

	//connecting node 5 and node 6
	head->next->next->next->next->next=temp;

	printf("the last id is %d \n",head->next->next->next->next->next->id);
	printf("the last Name is %c \n",head->next->next->next->next->next->name);

	printf("the entire list is as follows: \n");

	for(temp=head; temp != NULL; temp= temp->next){//print and count
		printf("%d, %c \n", temp->id, temp->name);
		counter++;
	}
	printf("There are a total of %d goats \n\n", counter);

	above=head->next;//remove an entry
	below=head->next->next->next;
	above->next=below;
	
	printf("Printing the list without the third goat\n");
	counter=0;
	for(temp=head; temp != NULL; temp= temp->next){//print and count
		printf("%d, %c \n", temp->id, temp->name);
		counter++;
	}
	printf("There are a total of %d goats \n\n", counter);

	printf("Please enter an id to search for. \n");
	scanf("%d", &targetId);
	for(temp=head; temp != NULL; temp= temp->next){//search for goat
		if(temp->id==targetId){
			printf("Found it, that goat is: \n");
			printf("%d, %c \n", temp->id, temp->name);
			//temp=NULL;		//messes up the loop, so excluding until solution is found. The object of this should be to end the loop.
			found=1;
		}
	}
	if(found==0){
		printf("Sorry, I could not find your goat \n");
	}
	/* //I Modified this code, to tried and make improvements, so I am leaving out the sort until it is solved. this was not a requirement for this assignment anyway..
	for(sort=counter; sort != 1; sort--){//run for as many items in the list
		for(temp=head; temp->next != NULL; temp= temp->next){//for each member in the list
			if(temp->id > temp->next->id){//check and swap
				//she only used id and name values, i am trying to sort with pointers...
				below=temp->next;//smaller id
				temp=below->next;//the larger number needs to point to the the one after the smaller num.
				temp->next=temp;//the smaller number needs to point to the larger number.
				//if there is one before it i think i must have it point to the new smaller number position.
			}
		}
		head=temp;
	}
	for(temp=head; temp != NULL; temp= temp->next){//print and count
		printf("%d, %c \n", temp->id, temp->name);
		counter++;
	}
	printf("There are a total of %d goats \n\n", counter);
	*/
return 0;
}