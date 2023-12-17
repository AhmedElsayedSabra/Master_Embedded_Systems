# include <stdio.h>
#include <math.h>
int main ()
{
	int choice ;
	int number =0;																	// Program two Variable
	int number_one , number_two ;													// Program three Variable
	float one , two , sum ;															// Program four Variable
	char c = 'b';																	// Program five Variable
	float cup_one = 0 , cup_two = 0 , temp_cup = 0  ;								// Program six Variable
	int a , b ;																		// Program Seven Variable
	printf("enter the number of the program( 1 - 7) =   "); fflush(stdout) ;
	scanf("%d" ,&choice ); fflush(stdin);
	switch (choice)
	{
	case 1 :
		printf(" c programming \n ") ; fflush(stdout) ;
		break;
	case 2:
		printf("enter the number :- "); fflush(stdout) ;
		scanf("%d",&number); fflush(stdin);
		printf("the number you entered is :- %d\n",number ); fflush(stdout) ;
		break ;
	case 3 :
		printf("enter the first number :- "); fflush(stdout) ;
		scanf("%d", &number_one); fflush(stdin);
		printf("enter the second number :- "); fflush(stdout) ;
		scanf("%d", &number_two); fflush(stdin);
		printf("the sum is :- %d \n", number_one+number_two); fflush(stdout) ;
		break ;
	case 4:
		printf("enter the first number :- "); fflush(stdout) ;
		scanf("%f", &one); fflush(stdin);
		printf("enter the second number :- ");  fflush(stdout) ;
		scanf("%f", &two); fflush(stdin);
		sum = one + two ;
		printf("the sum is :- %f \n", sum);  fflush(stdout) ;
		break ;
	case 5 :
		printf("enter the character :- "); fflush(stdout) ;
		scanf("%c",&c); fflush(stdin);
		// %d displays the integer value of a character
		// %c displays the actual character
		printf("ASCII value of %c = %d \n", c , c);  fflush(stdout) ;
		break ;
	case 6:
		printf("enter the first number a =  "); fflush(stdout) ;
		scanf("%f", &cup_one); fflush(stdin);
		printf("enter the second number b =  "); fflush(stdout) ;
		scanf("%f", &cup_two);  fflush(stdin);
		temp_cup = cup_one ;
		cup_one =cup_two ;
		cup_two = temp_cup ;
		fflush(stdout) ; fflush(stdin);
		printf("After swapping, value of a = %f\n", cup_one); fflush(stdout) ;
		printf("After swapping, value of b = %f\n", cup_two); fflush(stdout) ;
		break ;
	case 7:
		// it is an interview trick
		// Write Source Code to Swap Two Numbers without temp variable.
		printf("enter the first number a =  "); fflush(stdout) ;
		scanf("%d", &a); fflush(stdin);
		printf("enter the second number b =  "); fflush(stdout) ;
		scanf("%d", &b); fflush(stdin);
		a = a + b ;
		b = a - b ;
		a = a - b ;
		printf("After swapping, value of a = %d\n", a); fflush(stdout) ;
		printf("After swapping, value of b = %d\n", b); fflush(stdout) ;
		break ;
	default :
		printf("the homework is 7 program only - Wrong Number Problem "); fflush(stdout) ;
		break ;
	}
	return 0 ;
}
