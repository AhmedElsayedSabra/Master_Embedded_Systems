#include<stdio.h>
int main()
{
	int choice  ;
	float Avg  , sum = 0 , num ;  int n ;										// Program One Variable
	int num2 , i =1 , product = 1 ;												// // Program Two Variable
	printf("enter the number of program  ( 1 : 2) = ") ; fflush(stdout);
	scanf("%d" , &choice) ;
	switch(choice)
	{
	case 1 :
		printf("enter the max of number you want to calculate the avg= "); fflush(stdout);
		scanf("%d", &n); fflush(stdin);
		for (int i =1 ; i <= n ; i++)
		{
			printf("Enter the number %d = ", i); fflush(stdout);
			scanf("%f", &num); fflush(stdin);
			if (num < 0.0)
				break ;							// Break statement
			sum = sum +num ;
		}
		Avg = sum / n ;
		printf("The avg of number is = %2.2f" , Avg); fflush(stdout);
		break ;
	case 2 :
		for (; i <= 4 ; i++)
		{
			printf("enter the number  %d =  " , i) ; fflush(stdout);
			scanf("%d"  , &num2) ; fflush(stdin);
			if ( num2 == 0 )
				continue ;						// continue Statement
			product *= num2 ;
		}
		printf("product is :- %d " , product ) ; fflush(stdout);
		break ;
	default :
		printf("\n wrong number program") ; fflush(stdout);
		break ;
		return 0 ;
	}
}
