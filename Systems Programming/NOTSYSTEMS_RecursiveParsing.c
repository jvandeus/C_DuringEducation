#include <stdio.h>

char harold[]="1+2*(32+4)-5";
char *cp = harold;

int Expr();
int Term();
int Factor();
int Number();

int main(){
	int x = Expr(); /* get value of expresssion */ 

	printf("%d\n", x);
	return 0;
} 

int Expr(){
	int final=0;
	//int i=0;
	final += Number();
	while(*cp){					//I wanted to make it loop till end of string, I don't think its working.
	//for(i=0; i<=1; i++){		//So I replaced it with a for loop for a bit. I am switching off.
		if(*cp == '+'){
			cp++;
			final += Term();
		}
		else if(*cp == '-'){
			cp++;
			final -= Term();
		}
	}
	return final;
}

int Term(){
	int answer=0;

	answer += Number();

	if(*cp == '*'){
		cp++;
		answer *= Factor();
	}
	else if(*cp == '/'){
		cp++;
		answer /= Factor();
	}
	else if (*cp == ')'){
		cp++;
	}

	return answer;
}

int Factor(){
	int answer=0;

	if (*cp == '(') {
		cp++;
		answer = Expr();
	}
	else{
		answer = Number();
	}
	
	return answer;
}

int Number(){
	int answer=0;
	if (*cp < '0' || *cp > '9'){ /* must be at least on digit in a number */
		return 0; /* error exit from program */
	}
	answer = *cp++ - '0'; /* get numeric value of ascii digit, skip char*/
	while (*cp >= '0' && *cp < '9'){
		answer = answer * 10 + *cp - '0';
		cp++; /* skip over the character we just digested */
	} 
	return answer;
}