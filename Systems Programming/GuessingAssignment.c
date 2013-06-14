/*----------------------------------------------------------------------------------*/
/* Guessing Game:																	*/
/*																					*/
/* This is a simple program that guess a number that the user thinks of. The user	*/
/* Will simply put in a number that is lower and a number that is higher, then the	*/
/* Program will output the maximum number of questions it will take to find it.		*/
/* The Program then asks questions until the answer is found.						*/
/*																					*/
/* Author: Joe Van Deusen															*/
/*----------------------------------------------------------------------------------*/

#include<stdio.h>

int main()
{
	int low;
	int high;
	int search_space;
	int counter=0;
	int middle=0;
	int input=0;

	printf("Enter the low bound \n");

	scanf("%d", &low);

	printf("Enter the high bound \n");

	scanf("%d", &high);

	search_space= high-low;

	printf("We have %d numbers to search \n", search_space);

	while(search_space!=1){
		search_space = search_space/2;
		counter++;
	}
	printf("I will guess your number at most %d questions \n", counter+2);

	counter=0;

	while(low<=high)
	{

		middle=(high+low)/2;
		counter++;
		printf("Question # %d \n", counter);
		printf("Press 1 if your number is %d \n", middle);
		printf("Press 2 if your number is greater than %d \n", middle);
		printf("Press 3 if your number is smaller than %d \n", middle);

		scanf("%d", &input);

		if(input==1)
		{
			printf("I've found your number with %d questions \n", counter);
			low=high+1;
		}
		if(input==2)
			low=middle+1;
		if(input==3)
			high=middle-1;
	}
return 0;
}
