/*
 ============================================================================
 Name        : C_Functions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int check_Prime_Number (int n ) ;
int Factorial_function (int num) ;
void Reverse_Sentence(void);
int Power_function (int base , int exp) ;
int Minimum_function( int arr[] , int number);


int main(void)
{
	int choice ;
	int Begin_number , End_Number ; int flag ;									// program one variable
	int n ;																		// program two variable
	int base ; int exp ;														// program four variable
	int arr_z[8] = {50, 30 , 100 , 10 , 60 , 3 , 5 , 1000 };					// program five variable
	printf("enter the number of the program (1 - 5 )= ") ; fflush(stdout);
	scanf("%d" , &choice) ; fflush(stdin) ;
	switch(choice)
	{
	case 1:
		//  Description: program that find and print the prime numbers between two intervals entered by the user.
		printf("Enter the Two NUmber (Interval) to find the Prime number Between two interval = ") ; fflush(stdout) ;
		scanf("%d %d" , &Begin_number , &End_Number) ;fflush(stdin) ;
		printf("Prime numbers between %d and %d are: ",Begin_number , End_Number); fflush(stdout) ;
		for (int i = Begin_number ; i < End_Number ; i++)
		{
			flag = check_Prime_Number (i) ;
			if (flag == 1)
				printf(" %d  " , i);
		}
		break;
	case 2 :
		printf("Enter the number you want to calculate the factorial = ") ; fflush(stdout);
		scanf("%d" , &n ) ;  fflush(stdin) ;
		printf(" the factorial of number %d is = %d   ", n , Factorial_function(n)) ; fflush(stdout);
		break ;
	case 3:
		printf("Enter the sentence := "); fflush(stdout);
		Reverse_Sentence() ;
		break ;
	case 4 :
		printf("Enter the base = ") ; fflush(stdout);
		scanf("%d" , &base) ; fflush(stdin) ;
		printf("Enter the Exp = "  ) ; fflush(stdout);
		scanf("%d" , &exp) ;  fflush(stdin) ;
		int result = Power_function(base , exp) ;
		printf("%d ^ %d = %d " , base , exp , result) ; fflush(stdout);
		break ;
	case 5 :
		printf("calculate the minimum value of arrays \n ") ; fflush(stdout);
		printf("the min Value of array is = %d" , Minimum_function(arr_z , 8) ) ; fflush(stdout);
		break ;
	default :
		printf("wrong the number of the program") ; fflush(stdout);
		break ;

	}
}

int check_Prime_Number (int n )
{
	int j , flag =1 ;
	for (j = 2 ; j < n ; j++)
	{
		if (n == 0 || n == 1)
		{
			flag = 1;
			break ;
		}
		if (n % j == 0)
		{
			flag = 0 ;
			break ;
		}
	}
	return flag ;
}

int Minimum_function( int arr[] , int number)
{
	int i =0 ;
	int min_value = arr[0] ;
	for ( i = 0 ; i < number ; i++)
	{
		if (min_value > arr[i])
			min_value = arr[i] ;
	}
	return min_value ;
}

int Factorial_function (int num)
{
	if (num != 1 )
		num = num * Factorial_function(num-1) ;
	return num ;
}

void Reverse_Sentence(void)
{
	char c ;
	scanf("%c" , &c) ; fflush(stdin) ;
	if (c != '\0')
	{
		Reverse_Sentence();
		printf("%c" , c) ; fflush(stdin) ;
	}

}

int Power_function (int base , int exp)
{
	if (exp != 0)
		return (base * Power_function(base , exp-1)) ;
	else
		return 1 ;
}

