//////////////////////////////////////////////////////////////////////////////////////
/*  																				*/
/*																Joe Van Deusen		*/
/*														Worked with	Nick Wheeler	*/
/*  																				*/
/* This Program uses a number of varies functions to work with a pointer array.     */
/* This array is created by the user who specifies the size and then fills the      */
/* array. The array is then displayed both forward and backwards. Then the user is  */
/* asked for a number to search the pointer array for. This is then searched using  */
/* 4 different methods. These methods are the recursive and non recursive versions  */
/* of linear search and binary search methods. The list in then sorted from least   */
/* highest using a bubblesort function. Then the user is asked a number to add to	*/
/* list and a position to put it and a function inserts the value and displays the	*/
/* new list.																		*/
/*																					*/
/*																					*/
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void build_array(int *p, int size);
void print_array(int *p, int size);
void min_max(int *p, int size, int *minp, int *maxp);
void linear_search(int *p, int size, int targ);
void reclinear_search(int *p, int size, int targ);
void print_back(int *p, int last_index);
void add_num(int *p, int size);
void binary_search(int *p, int size, int targ);
void bubble_sort(int *p, int size);
void swap(int *p, int size, int pos);
void rec_binsearch(int *p, int low, int high, int target, int found);

int main()
{
	int *p;
	int size, temp=0, targ=0, min=0, max=0;
	//p=(int*)malloc(sizeof(int)*5);
	//after this line p is a pointer pointing to the first elemment and it is an array name.

	printf("How many numbers do you want to accomodate? \n");
	scanf("%d", &size);
	p=(int*)calloc(size, sizeof(int));
	build_array(p,size);//fills the array
	print_array(p,size);//prints the array
	printf("The array backwards is as follows: \n");
	print_back(p,size-1);

	min_max(p,size,&min,&max);//finds and prints minimum and maximum
	printf("Min: %d Max: %d \n \n", min, max);

	printf("Please input a value to search for. \n");
	scanf("%d",&targ);

	printf("\n\nPerforming Linear Search \n");
	linear_search(p, size, targ);//linear search non-recursive

	printf("\n\nPerforming Recursive Linear Search. \n");
	reclinear_search(p, size, targ);//linear search recursive

	printf("\n\nPerforming Binary Search. \n");
	binary_search(p, size, targ);//binary search non recursive

	printf("\n\nPerforming Recursive Binary Search. \n");
	rec_binsearch(p, 0, size, targ,  0);//binary search recursive

	printf("\n\nSorting array with bubble sort. \n");
	bubble_sort(p,size);
	print_array(p,size);

	printf("\n\nAdding an Element to the array. \n");
	add_num(p, size);//adding an element to the array
}

void build_array(int *p, int size)
{
	int i;
	printf("Enter %d numbers separated by spaces. \n", size);

	for(i=0; i<size; i++){
		scanf("%d", &p[i]);
	}
	printf("Array Built! \n");
}

void print_array(int *p, int size)
{
	int i;
	for(i=0; i<size; i++){
		printf("%3d \n", p[i]);
	}
}

void min_max(int *p, int size, int *minp, int *maxp)
{//this function will return void, but print max and min in main()
	int *q; //assuming there is value in the array already, set to a number in the array.
	(*minp) = *p;
	for(q=p; q<=p+(size-1); q=q+1){
		if(*q > (*maxp)){
			(*maxp) = *q;
		}
		if(*q < (*minp)){
			(*minp) = *q;
		}
	}
}


void linear_search(int *p, int size, int targ)
{
	int found=0, i=0;

	for(i=0; i<size-1 && found!=1; i++){
		if(p[i] == targ){
			found=1;
			break;
		}
	}
	if(found==1){
		printf("Found it! This value is at position %d. \n", i);
	}
	else{
		printf("Sorry, that value is not in this array. \n");
	}
}

void reclinear_search(int *p, int first_index, int targ)// this is not yet working
{
	if(p[first_index]==targ){
		printf("Found it! This value is at position %d. \n", first_index);
	}
	else{
		if(first_index==0){
			printf("Sorry, that value is not in the array. \n");
		}
		else
		{
			reclinear_search(p, first_index-1, targ);
		}
	}
}

void print_back(int *p, int last_index)//recursive
{
	if(last_index==0){
		printf("%d \n \n", p[last_index]);
	}
	else
	{
		printf("%d \n", p[last_index]);//putting the function cal first prints forwards.
		print_back(p, last_index-1);
	}
}

void add_num(int *p, int size)
{
	int val=0, pos=0, i, *b;
	size++;

	printf("Please put the number your adding then the \n");
	printf("position you would like it in the array. \n");
	scanf("%d",&val);
	scanf("%d",&pos);

	b=(int*)calloc(size,sizeof(int));//allocate space for the larger array
	b[pos]=val;//sets the desired value to the desired place in the new array.

	for(i=0; i<pos; i++){//fill in the array before the desired value
		b[i]=p[i];
	}

	for(i=pos+1; i<(size); i++){//fill in the array after the desired value
		b[i]=p[i-1];
	}
	p=b;//sets the origional array to become the recently created larger array.
	printf("\n Here is the new array with the value added. \n \n");
	print_array(p,size);//prints the array
}

void binary_search(int *p, int size, int target)
{
	int low=0, high=size-1, middle, found=0;//initializing found, low and high

	while(low<=high && found!=1)
	{
		middle=(high+low)/2; 

		if(p[middle]==target){
			found=1; 
		}
		else{
			if(target<p[middle]){
				high=middle-1; //target is smaller than the number in the middle, move high to middle-1
			}
			if(p[middle]<target){
				low=middle+1; //target is greater than the number in the middle, move low to middle+1
			}
		}
	}
	if(found==1)
	printf("Yes this number is in the array \n");

	if(found==0)
	printf("Sorry, that value is not in the array. \n");
}

void bubble_sort(int *p, int size)
{
	int i, j;
	for(j=0; j<size-1; j++)//run the comparison for each value through the list for as many as are in the list.
		for(i=0; i<size-1; i++)//run a comparision once for each value, this compares the entire list and the above loops this for as many as are in the list.
		{
			if (p[i]>p[i+1])//if the second number is greater than the first, swap
			{
				swap(p,size,i);
			}
		}
}

void swap(int *p, int size, int pos)
{
	int temp;
	temp=p[pos];//store first
	p[pos]=p[pos+1];//set first to the second
	p[pos+1]=temp;//set second to the stored first value.
}

void rec_binsearch(int *p, int low, int high, int target, int found)
{      
	int middle=0;

	if(low>high)
		printf("No, the target number is not in the array \n");
	else{
		middle=(low+high)/2;

		if(p[middle]==target){
			printf("The target number is in the array It's position is %d\n", middle);
			found=1;
		}
		else{
			if(p[middle]<target)//change low, keep high
			rec_binsearch(p, middle+1,  high, target, found);

			if(p[middle]>target)//change high, keep low
			rec_binsearch(p, low,  middle-1, target, found);
		}
	}
 }