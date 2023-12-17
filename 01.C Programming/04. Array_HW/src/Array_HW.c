/*
 ============================================================================
 Name        : Array_HW.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int choice ; int i = 0 , j =0 ;
	float matrix_one [2][2] , matrix_two[2][2] , matrix_three[2][2] ;				// program one variable
	int element_number ; float numbers[100] ;   float sum=0 ; float avg ;			// program two variable
	int row , column ; int matrix[10][10] , t_matrix[10][10] ;						// program three variable
	int arr[30] , n , element , location;											// program four variable
	int searched_array[30] ; int num_element ; int n_array  ;						// program five variable
	printf("Enter the number of program ( 1 - 5 ) = "); fflush(stdout);
	scanf("%d",&choice); fflush(stdin) ;
	switch (choice)
	{
									// Description :: C Program To Sum MultiDimentional Array
	case 1 :
		printf("///////fill  matrix 1////////\n"); fflush(stdout);
		for (i=0 ; i < 2 ; i++)
		{
			for (j=0  ; j < 2 ; j++)
			{
				printf("Enter the item ( %d %d ) of matrix one = " , i, j); fflush(stdout);
				scanf("%f",&matrix_one[i][j]); fflush(stdin) ;
			}
		}
		printf("///////fill  matrix 2////////\n"); fflush(stdout);
		for (i=0 ; i <2 ; i++)
		{
			for (j = 0 ; j < 2 ; j++)
			{
				printf("Enter the item ( %d %d ) of matrix two = " , i, j); fflush(stdout);
				scanf("%f",&matrix_two[i][j]); fflush(stdin) ;
			}
		}
		printf("///////  the sum of 2 matrix ////////\n"); fflush(stdout);
		for (i=0 ; i <2 ; i++)
		{
			for (j = 0 ; j < 2 ; j++)
			{
				matrix_three[i][j]= matrix_one[i][j] + matrix_two[i][j] ;
				printf("%2.2f \t" , matrix_three[i][j]); fflush(stdout);
			}
			printf("\n\n"); fflush(stdout);
		}
		break ;
	case 2 :
										// Description :: C Program to Calculate Average Using Arrays
		printf("enter the number of element you want to calculate the avg = ") ; fflush(stdout);
		scanf("%d" , &element_number); fflush(stdin) ;
		for (i = 0 ; i < element_number ; i++)
		{
			printf("enter the %d element = ", i+1); fflush(stdout);
			scanf("%f", &numbers[i]); fflush(stdin) ;
		}
		for (i = 0 ; i < element_number ; i++)
		{
			sum+=numbers[i];

		}
		avg = sum / element_number ;
		printf(" the avg  is = %2.2f \n" , avg); fflush(stdout);
		break ;
	case 3 :
											// Description :: C Program To Transpose Of Matrix
		printf(" enter the number of row = ") ; fflush(stdout);
		scanf("%d" , &row) ; fflush(stdin) ;
		printf(" enter the number of column = ") ;  fflush(stdout);
		scanf("%d" , &column) ; fflush(stdin) ;
		for (i = 0 ; i < row ; i++)
		{
			for(j =0 ; j < column ;j++)
			{
				printf("Enter the item ( %d %d ) of matrix one = ", i+1,j+1); fflush(stdout);
				scanf("%d",&matrix[i][j]); fflush(stdin) ;
			}
		}
		printf(" the matrix you entered \n") ; fflush(stdout);
		for (i =0 ; i < row ; i++)
		{
			for (j=0 ; j < column ; j++)
			{
				printf("%d \t" , matrix[i][j]); fflush(stdout);
			}
			printf("\n\n"); fflush(stdout);
		}
		printf("the transposed matrix \n") ; fflush(stdout);
		for (i =0 ; i < row ; i++)
		{
			for (j=0 ; j < column ; j++)
			{
				t_matrix[j][i] = matrix[i][j] ;
			}
		}
		for (i =0 ; i < row ; i++)
		{
			for (j=0 ; j < column ; j++)
			{
				printf("%d \t" , t_matrix[i][j]); fflush(stdout);
			}
			printf("\n\n"); fflush(stdout);
		}
		break ;
	case 4 :
										// Description :: C Program To  insertion Element In An Array
		printf("enter the Size  of array : "); fflush(stdout);
		scanf("%d" , &n) ; fflush(stdin) ;
		for ( i =0 ; i < n ; i++)
		{
			printf("Enter the element %d = ", i+1); fflush(stdout);
			scanf("%d" ,&arr[i]); fflush(stdin) ;
		}
		printf("Enter the element you want insert = "); fflush(stdout);
		scanf("%d" , &element); fflush(stdin) ;
		printf("enter the location = "); fflush(stdout);
		scanf("%d" , &location ) ; fflush(stdin) ;
		if( location >=  0 && location < n)
		{
			for ( i =n ; i >= location ; i--)
			{
				arr[i] = arr[i- 1] ;
			}
		}
		else
			printf("wrong location") ;
		n++ ;
		arr[location -1 ] = element ;
		printf("\n") ; fflush(stdout);
		for (i = 0 ; i < n ; i++)
			printf(" %d \t" , arr[i]) ;
		break ;
	case 5 :
									// Description ::  c program code to search an element in an array
		printf("Enter the Size of array  =  ") ; fflush(stdout);
		scanf("%d" , &n_array) ; fflush(stdin) ;
		for (i = 0 ; i < n_array ; i++)
		{
			printf("Enter the item % d of Array = " , i+1) ; fflush(stdout);
			scanf("%d" ,& searched_array[i]); fflush(stdin) ;
		}
		// read the element
		printf("enter the element to be searched = "); fflush(stdout);
		scanf("%d", &num_element) ; fflush(stdin) ;
		for (i = 0 ; i < n_array ; i++)
		{
			if (num_element == searched_array[i])
			{
				printf("element %d fount at location at=  %d " , num_element, i+1 ); fflush(stdout);
				break ;
			}
			else
				continue ;
		}
		if ( num_element != searched_array[i] && i >=  n_array )
			printf("the element %d was not found " , num_element) ;
		/* i = 0 ;
		while (i < n_array && num_element != searched_array[i])
		{
			i++ ;
		}
		if ( i < n_array)
			printf("\n element %d fount at location at %d " , num_element, i+1 );
		else
			printf("the element %d was not found " , num_element) ;  */
		break ;
	default :
		printf("Wrong the number of program ");
		break ;
	}
}
