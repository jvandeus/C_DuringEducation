//////////////////////////////////////////////////////////////////////////////////////
/*  																				*/
/*																Joe Van Deusen		*/
/*														Worked with	Nick Wheeler	*/
/*  																				*/
/* This program constructs my family tree using linked lists. After creation	 	*/
/* of the tree and linking of the family members this program will print The node	*/
/* That represents me via 2 different link paths. Thus the same thing is printed	*/
/* Twice, but via two differnt link paths.											*/
/*  																				*/
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	char name[30], relation[30];

	struct Node *child1;
	struct Node *child2;
	struct Node *child3;
	struct Node *child4;
	struct Node *marriage;
};

typedef struct Node leaf;//leaf is a member of the family tree

int main()
{
	leaf *root, *temp;

	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Great Grandmother");//setting a value to string variables.
	strcpy(temp->name,"Sherri");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root=temp;
	//printf("%5s   %5s \n", root->relation, root->name);

	//contructing first uncle
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Great Uncle");//setting a value to string variables.
	strcpy(temp->name,"Dave");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child1=temp;//connecting great grandfather and first uncle
	//printf("%5s   %5s \n", root->child1->relation, root->child1->name);

	//contructing first great cousin (if that is what they are called)
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Great Cousin");//setting a value to string variables.
	strcpy(temp->name,"Dave Jr");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child1->child1=temp;//connecting great grandfather and first uncle
	//printf("%5s   %5s \n", root->child1->child1->relation, root->child1->child1->name);

	//contructing grandfather
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Grandfather");//setting a value to string variables.
	strcpy(temp->name,"Robert");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2=temp;//connecting great grandfather and grandfather

	//contructing Mother
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Mother");//setting a value to string variables.
	strcpy(temp->name,"Anna");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child1=temp;//connecting grandfather and mother

	//contructing Father
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Mother");//setting a value to string variables.
	strcpy(temp->name,"Anna");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child1->marriage=temp;//connecting Mother and Father

	//contructing Myself
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Myself");//setting a value to string variables.
	strcpy(temp->name,"Joe");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child1->child1=temp;//connecting Mother and Myself
	root->child2->child1->marriage->child1=temp;//connecting Father and Myself

	//contructing Brother
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Brother");//setting a value to string variables.
	strcpy(temp->name,"DJ");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child1->child2=temp;//connecting Mother and Brother
	root->child2->child1->marriage->child2=temp;//connecting Father and Brother

	//contructing Uncle
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Uncle");//setting a value to string variables.
	strcpy(temp->name,"Bob");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child2=temp;//connecting grandfather and uncle

	//contructing Cousin 1
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Cousin");//setting a value to string variables.
	strcpy(temp->name,"Mary");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child2->child1=temp;//connecting uncle and Cousin

	//contructing Cousin 2
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Cousin");//setting a value to string variables.
	strcpy(temp->name,"Nina");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child2->child2=temp;//connecting uncle and Cousin

	//contructing Cousin 3
	temp=(leaf*)malloc(sizeof(leaf));
	strcpy(temp->relation,"Cousin");//setting a value to string variables.
	strcpy(temp->name,"Bill");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;

	root->child2->child2->child3=temp;//connecting uncle and Cousin

	//print connection via mother
	printf("As a decendant of my great grandparents on my mothers side I am :\n");
	printf("Relation: %5s   Name:%5s \n", root->child2->child1->child1->relation, root->child2->child1->child1->name);
	//print connetion via father
	printf("As a child of my father I am:\n");
	printf("Relation: %5s   Name:%5s \n", root->child2->child1->marriage->child1->relation, root->child2->child1->marriage->child1->name);

	return 0;
}
