/* This Program is not Functioning. it was used as prototype and demonstrational */
/* class activity. The more complete verion of this code is GeussingAssignment.  */

#include<stdio.h>
#include<math.h>

int main()
{
	int low =0, high =0, count =0, middle =0;
	char answer;

	printf("Please input low bound \n");
	scanf("%d", &low);
	printf("Please input high bound \n");
	scanf("%d", &high);
	middle = (low+high)/2;

	// this works, but you'd need to reset the low and high inputs to origional
	do{
		printf("low:%d  middle:%d  high:%d \n", low, middle, high);
		low = middle;
		middle = (low+high)/2;
		count++;
	}while(middle != low);

	printf("I can guess your number within %d guesses. \n", count);

	do{
		printf("Is your number higher than or equal to %d - y or n", middle);
		scanf("%c", &answer);
		if(answer == 'y'){
			low = middle;
		}
		else{
			high = middle;
		}
		middle = (low+high)/2;
	}while(low != middle && high != middle);
	printf("your number is %d", middle);
}