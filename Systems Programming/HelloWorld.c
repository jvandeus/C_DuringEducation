/*----------------------------------------------------------------------------------*/
/* Hello world:																		*/
/*																					*/
/* A simple introduction to input and output in the C language.					 	*/
/* This program was a simple way to get started and assert the basics of C.			*/
/*																					*/
/* Author: Joe Van Deusen															*/
/*----------------------------------------------------------------------------------*/

#include<stdio.h>

int main()
{
	int siblings;

	printf("How many siblings do you have? \n");
	scanf("%d",&siblings);
	printf("Those %d people are indeed your brothers and/or sisters. \n", siblings);

	return 0;
}
