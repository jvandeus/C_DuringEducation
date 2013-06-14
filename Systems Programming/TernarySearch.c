/////////////////////////////////////////////////////////////////////////////////////
/*	Joe VanDeusen, working with Nick Wheeler										*/
/*																					*/
/*	This Program is designed to guess the number the user is thinking of within		*/
/*	the boundaries input by the user. This program can also tell if the user		*/
/*	cheats. It will tell the user how many Questions it will take to guess the		*/
/*	number. This program uses ternary search to do the guessing.					*/
/*																					*/
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

int main()
{
	int low=0,high=0,space=0,counter=0,lowmid=0,highmid=0,input=0,final=0;

	//take input from the user
	printf("Enter the low bound \n");
	scanf("%d", &low);
	printf("Enter the high bound \n");
	scanf("%d", &high);
	
	space=high-low;//space between the two numbers

	printf("We have %d numbers to search \n", space);

	while(space>=3){
		space = space/3;
		if(space==2){//in case the space in between the mids has more 2 options, another question must be asked
			counter++;
		}
		counter++;
	}
	//tells the user how many guesses will take to find out the number.
	printf("I will guess your number at most %d questions \n", counter);
	counter=0;

	while(low<=high)
	{
		space=high-low;
		lowmid=low+(space/3);
		highmid=high-(space/3);
		counter++;
		//This prints the questions to the screen
		printf("Question # %d \n", counter);
		printf("Press 1 if your number is %d \n", lowmid);
		printf("Press 2 if your number is %d \n", highmid);
		printf("Press 3 if your number is smaller than %d \n", lowmid);
		printf("Press 4 if your number is betweeen %d and %d \n", lowmid, highmid);
		printf("Press 5 if your number is greater than %d \n", highmid);

		scanf("%d", &input);//takes the users answer

		switch(input){//processs the users answer
		case 1:
			final=lowmid;
			printf("I've found your number to be %d with %d questions \n", final, counter);
			low=high+1;
			break;
		case 2:
			final=highmid;
			printf("I've found your number to be %d with %d questions \n", final, counter);
			low=high+1;
			break;
		case 3:
			high=lowmid-1;
			if(space<=2){
				printf("This game is over because YOU decided to CHEAT! \n");
			}
			break;
		case 4:
			if(highmid-lowmid==2){//if there is only one number between the lowmid and highmid
				final=lowmid+1;//then the number has to be the one in between
				printf("I've found your number to be %d with %d questions \n", final, counter);
				low=high+1;//exit the loop
			}
			else{//otherwise make the new search space
				high=highmid-1;
				low=lowmid+1;
			}
			if(space<2){ //if the choices are eliminated to an option in the loop and they lie, print statement.
				printf("This game is over because YOU decided to CHEAT! \n");
			}
			break;
		case 5:
			low=highmid+1;
			if(space<=2){ //if the choices are eliminated to an option in the loop and they lie, print statement.
				printf("This game is over because YOU decided to CHEAT! \n");
			}
			break;
		default: //if user inputs wrong number, display a warning and ask the same question again
			printf("PLAY BY THE RULES!!! \n");
			counter--;
			break;
		}
	}
	return 0;
}

/*	
	Comparison of Ternary and Binary search:
	It depens on what your looking for to tell how effiecint each methos is. If your
	looking for less questions asked to the user, ternary search is much more efficient.
	If your looking for least lines binary search is more efficient and is better in that
	sense meaning it's easier on the proccessing. If your looking for more processing with
	less lines it seems that ternary search is better. Also Ternary search technically
	requires more variables, meaning taking up more RAM. In this manner binary search
	is better. Overall programs are supposed to be designed to make things eaier and
	faster for the user. In that sense I beleive Ternary search is more efficient because
	it reqires less answers from the user.
*/