//////////////////////////////////////////////////////////////////////////////////////
/*  																				*/
/*																Joe Van Deusen		*/
/*														Worked with	Nick Wheeler	*/
/*  																				*/
/* This program constructs a double linked list of Anime series from a text file	*/
/* called "input.txt". It can search the list for a node specified by the user and	*/
/* deletes it. It can also add a node to the end of the list useing data specified	*/
/* by the user. The user can chose to do either of these or do no modifications.	*/
/* Then the program sorts the list based on the criteria specified. This criteria	*/
/* is determined by a value input from the user. The list is then displayed in an	*/
/* external text file named "output.txt".											*/
/*																					*/
/*																					*/
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	char name[15], lang[15];
	int epi;

	struct Node *next;
	struct Node *prev;
};

typedef struct Node* Box;
Box buildNode(FILE *inputp);

int main()
{
	FILE *inputp, *outputp;
	Box head=NULL, tail=NULL, temp, behind, front, low;
	int i=0, answer=0, counter=0, found=0;
	char *search;
	char ansstr[15];

	inputp=fopen("input.txt", "r");
	outputp=fopen("output.txt", "w");

	head=buildNode(inputp);//build and set head
	tail=buildNode(inputp);//build and set tail
	head->next=tail;//link nodes
	tail->prev=head;
	counter=2;//use a counter and start with head and tail

	while((search = fgetc(inputp)) != EOF){//build and link nodes while there is still values
		temp=buildNode(inputp);
		tail->next=temp;
		temp->prev=tail;
		tail=tail->next;//reset tail each time
		counter++;
	}
	printf("There are %d nodes in this list \n", counter);

	do{
		printf("\n");
		if(answer==0){
			printf("If you do not need to make any modifications enter 0. \n");
		}
		else{
			printf("If you do not need any further modifications enter 0. \n");
		}
		printf("If you would like to delete a node enter 1. \n");
		printf("If you would like to add a node enter 2. \n");
		scanf("%d",&answer);
		switch(answer){
			case 1:
			{
				//Search and Delete
				printf("\nPlease type the name of the anime you would like deleted.\n");
				printf("Use _ for spaces. And it is case sensitive. \n");
				scanf("%s",&ansstr);
				for(temp=head; temp!= NULL; temp=temp->next){//search forward
					if(strcmp(temp->name, ansstr) == 0) {
						printf("Found it. Deleted it.\n");
						behind=temp->prev;//remove an entry
						front=temp->next;
						if(behind!=NULL){//in case it is the first value, this prevents a crash
							behind->next=front;
						}
						else{//if it is the first value, reset the head
							head=front;
						}
						if(front!=NULL){//in case it is the last value, this prevents a crash
							front->prev=behind;
						}
						else{//if it is the last value, reset the tail
							tail=behind;
						}
						free(temp);//free the memory
						found=1;
						counter--;
						break;
					}
				}
				if(found==0){
					printf("Sorry, I could not find it \n");
				}
				break;
			}
			case 2:
			{	
				//Add A Node
				temp=(Box)malloc(sizeof(struct Node));
				printf("\nTo add a node please enter each value as prompted. \n");
				printf("Please enter the name useing _ instead of spaces. \n");
				scanf("%s",&temp->name);
				printf("Please enter the language useing _ instead of spaces. \n");
				scanf("%s",&temp->lang);
				printf("Please enter the number of episodes. \n");
				scanf("%d",&temp->epi);
				temp->next=NULL;
				temp->prev=tail;
				tail->next=temp;
				tail=temp;
				counter++;
				printf("Anime added.\n");
				break;
			}
			default:
			{
				printf("Alright, moving on to Sorting the list. \n");
				printf("\n");
				answer=0;
				break;
			}
		}
	}while(answer!=0);

	//Sorting the list
	printf("Please type the number corresponding to the value you would like sorted. \n");
	printf("1 is name, 2 is laguage, 3 is episodes. \n");
	scanf("%d",&answer);
	switch(answer){
		case 1://name
		{
			for(i=0; i<counter; i++){//run for as many as in the list.
				for(temp=head; temp->next!=NULL; temp=temp->next){//comparisons for each value.
					if(strcmp(temp->name, temp->next->name) > 0){//This is the comparison
						behind=temp->prev;
						front=temp->next->next;
						low=temp->next;
						if(temp->prev==NULL){//if it is the first values
							low->prev=NULL;
							low->next=temp;
							temp->prev=low;
							temp->next=front;
							front->prev=temp;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
						else if(front==NULL){//if it is the last values
							behind->next=low;
							low->prev=behind;
							low->next=temp;
							temp->prev=low;
							temp->next=NULL;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
						else{//all the middle values
							behind->next=low;
							low->prev=behind;
							low->next=temp;
							front->prev=temp;
							temp->next=front;
							temp->prev=low;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
					}
					tail=temp;//reset tail so at the end of the loop tail will be at the end.
				}
				for(temp=tail; temp!=NULL; temp=temp->prev){//reset head
					head=temp;
				}
			}
			break;
		}
		case 2://language
		{
			for(i=0; i<counter; i++){//run for as many as in the list.
				for(temp=head; temp->next!=NULL; temp=temp->next){//comparisons for each value.
					if(strcmp(temp->lang, temp->next->lang) > 0){//This is the comparison
						behind=temp->prev;
						front=temp->next->next;
						low=temp->next;
						if(temp->prev==NULL){//if it is the first values
							low->prev=NULL;
							low->next=temp;
							temp->prev=low;
							temp->next=front;
							front->prev=temp;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
						else if(front==NULL){//if it is the last values
							behind->next=low;
							low->prev=behind;
							low->next=temp;
							temp->prev=low;
							temp->next=NULL;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
						else{//all the middle values
							behind->next=low;
							low->prev=behind;
							low->next=temp;
							front->prev=temp;
							temp->next=front;
							temp->prev=low;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
					}
					tail=temp;//reset tail so at the end of the loop tail will be at the end.
				}
				for(temp=tail; temp!=NULL; temp=temp->prev){//reset head
					head=temp;
				}
			}
			break;
		}
		case 3://episodes
		{
			for(i=0; i<counter; i++){//run for as many as in the list.
				for(temp=head; temp->next!=NULL; temp=temp->next){//comparisons for each value.
					if(temp->next->epi < temp->epi && temp->next!=NULL){//This is the comparison
						behind=temp->prev;
						front=temp->next->next;
						low=temp->next;
						if(temp->prev==NULL){//if it is the first values
							low->prev=NULL;
							low->next=temp;
							temp->prev=low;
							temp->next=front;
							front->prev=temp;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
						else if(front==NULL){//if it is the last values
							behind->next=low;
							low->prev=behind;
							low->next=temp;
							temp->prev=low;
							temp->next=NULL;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
						else{//all the middle values
							behind->next=low;
							low->prev=behind;
							low->next=temp;
							front->prev=temp;
							temp->next=front;
							temp->prev=low;
							temp=low;//must set the current pointer back so when it increments it does not skip anything.
						}
					}
					tail=temp;//reset tail so at the end of the loop tail will be at the end.
				}
				for(temp=tail; temp!=NULL; temp=temp->prev){//reset head
					head=temp;
				}
			}
			break;
		}
	}

	//Replace Underscores with Spaces
	for(temp=head; temp!=NULL; temp=temp->next){//Replace _ with Space
		search = strchr(temp->name,'_');//points to the underscore
		while(search != NULL) {
			i = search - temp->name;//makes it an int to indetify where it is, use i for now
			temp->name[i] = ' ';
			search = strchr(search + 1, '_');
		}
	}

	for(temp=head; temp!=NULL; temp=temp->next){//print loop
		fprintf(outputp, "%15s   %15s   %10d \n", temp->name, temp->lang, temp->epi);
	}
	printf("\nCongratulations, your new list is now awaiting in the ouput file! \n");

return 0;
}
Box buildNode(FILE *inputp)
{
	Box temp=NULL;
	temp=(Box)malloc(sizeof(struct Node));
	fscanf(inputp, "%s", &temp->name);
	fscanf(inputp, "%s", &temp->lang);
	fscanf(inputp, "%d", &temp->epi);
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
