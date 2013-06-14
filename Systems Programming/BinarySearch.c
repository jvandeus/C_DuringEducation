/*----------------------------------------------------------------------------------*/
/* Binary Search:																	*/
/*																					*/
/* This program will search a predetermined array for a number specified by the 	*/
/* user. This program does so using a method called binary search.					*/
/*																					*/
/* Author: Joe Van Deusen															*/
/*----------------------------------------------------------------------------------*/

#include<stdio.h>

int main()
{
	int my_array[10]={100,102, 200, 207, 304,308,409, 506, 566, 879};
	int low=0;
	int high=9;
	int target;
	int middle;
	int found=0;

	printf("Enter a number to search for \n");
	scanf("%d", &target);

	while(low<=high)
	{

		middle=(low+high)/2;

		if(my_array[middle]==target)
		{	 
		low=high; //need a value to get out of the loop
		found=1; //need a value to indicate that the number is found
		}
		if(target<my_array[middle]){
		 high=middle; //where do we move high or low
		}
		if(my_array[middle]<target){
		 low=middle; //where do we move high or low
		}
	}

	if(found==1){
	 printf("Yes the number we searched for is in the array\n");
	}

	if(found==0){
	 printf("No, the number we searched for is in the array\n");
	}
	return 0;
}
