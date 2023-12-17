# include <stdio.h>
#include <math.h>
int main ()
{
	int choice ;
	int number;																// program one
	char c ;																//program two
	float num1 , num2 , num3 ;												//program three
	float n_pos_neg ;														//program four
	char character ;														// program five
	unsigned int sum =0 , n = 0 , count = 1 ;								// program six 6
	unsigned int x , factorial = 1 , i = 1 ;								// program seven
	float operand_one , operand_two ; char operator_calc ;					// program eight
	printf("enter the number of choice (1 - 8)= "); fflush(stdout);
	scanf("%d", &choice); fflush(stdin) ;
	switch (choice )
	{
	case 1:
		// enter the number = 25 >>>  odd
		// enter the number = 20  >>> even
		printf("enter the number to test odd or even = "); fflush(stdout);
		scanf("%d", &number);  fflush(stdin) ;
		((number % 2 == 0)) ? printf("%d is even \n",number) : printf("%d is odd \n",number) ;
		break ;
	case 2 :
		// c program code to check the character vowel || consonant
		printf("enter an alphabet =  "); fflush(stdout);
		scanf("%c", &c); fflush(stdin) ;
		if (c == 'a' || c == 'i'|| c == 'o' || c == 'u' || c == 'e' )
			printf("the alphabet  %C is = vowel", c);
		else if (c == 'A' || c == 'I'|| c == 'O' || c == 'U' || c == 'E')
			printf("the alphabet  %c is = vowel\n", c);
		else
			printf("the alphabet  %c is = consonant\n", c);
		break ;
	case 3:
		printf("enter the first number = "); fflush(stdout);
		scanf("%f", &num1); fflush(stdin) ;
		printf("enter the second number = ");  fflush(stdout);
		scanf("%f", &num2); fflush(stdin) ;
		printf("enter the third number = "); fflush(stdout);
		scanf("%f", &num3); fflush(stdin) ;
		if (num1 > num2)
		{
			if(num1 > num3)
				printf("the biggest number is = %f\n",num1);
			else
				printf("the biggest number is = %f\n",num3);
		}
		else
		{
			if (num2 > num3)
				printf("the biggest number is = %f\n",num2);
			else
				printf("the biggest number is = %f\n",num3);
		}
		break ;
	case 4 :
		printf("enter the number to check it positive or negative or zero = "); fflush(stdout);
		scanf("%f", &n_pos_neg); fflush(stdin) ;
		if (n_pos_neg > 0)
			printf("the number you entered is positive ");
		else if (n_pos_neg < 0)
			printf("the number you entered is negative ");
		else
			printf("the number you entered is Zerooo ");
		break ;
	case 5 :
		// c code to check whether a character is alphabet or not
		printf("enter the character to check it alphabet or not = "); fflush(stdout);
		scanf("%c",&character); fflush(stdin) ;
		if ( (character >= 'a' && character <='z') || ( character >= 'A' && character <='Z'))
			printf("%c is the character you entered is an alphabet \n",character);
		else
			printf("%c  is not an alphabet \n",character);
		break ;
	case 6 :
		// c code to calculate the natural numbers	 program 1,2,3,4,5  .... n sum += count
		printf("enter an integer number = "); fflush(stdout);
		scanf("%d",&n); fflush(stdin) ;
		for (count = 1 ; count <= n ; count++)
			sum += count ;
		printf("sum of natural number %d  is = %d\n", n , sum); fflush(stdout);
		break ;
	case 7 :
		// c code to calculate the factorial  numbers	 program 1,2,3,4,5  .... x sum *= count ;
		printf("enter an integer number = "); fflush(stdout);
		scanf("%d",&x); fflush(stdin) ;
		if (x == 0 || x < 0)
			printf("error !!! factorial of negative number of zero  is not exisit \n");
		else
		{
			for (i =1 ; i <= x ; i++)
				factorial *= i ;
			printf("factorial of %d is =  %d\n", x , factorial); fflush(stdout);
		}
		break ;
	case 8 :
		// Description :: C Program To Execute Simple Calculator
		printf("enter the first operand  = "); fflush(stdout);
		scanf("%f", &operand_one); fflush(stdin) ;
		printf("enter the second operand  = "); fflush(stdout);
		scanf("%f", &operand_two); fflush(stdin) ;
		printf("enter the operator either + or - or * or / =  "); fflush(stdout);
		scanf("%c",&operator_calc) ;  fflush(stdin) ;
		switch(operator_calc)
		{
		case '+' :
			printf("%f + %f = %f \n", operand_one , operand_two, operand_one + operand_two); fflush(stdout);
			break ;
		case '-' :
			printf("%f - %f = %f \n", operand_one , operand_two, operand_one - operand_two); fflush(stdout);
			break ;
		case '*' :
			printf("%f * %f = %f \n", operand_one , operand_two, operand_one * operand_two); fflush(stdout);
			break ;
		case '/' :
			printf("%f / %f = %f \n", operand_one , operand_two, operand_one / operand_two);  fflush(stdout);
			break ;
		default :
			printf("wrong operator !!!!!!!!!"); fflush(stdout);
			break ;

		}
		break ;
		default:
			printf("wrong number program !!!!!!!!!\n"); fflush(stdout);
			break ;
	}
	return 0 ;
}
