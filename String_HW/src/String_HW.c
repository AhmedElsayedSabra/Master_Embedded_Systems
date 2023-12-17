/*
 ============================================================================
 Name        : String_HW.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int choice ;
	char array_string[1000] ; char character ; int freq ; int i =0 ;	// program one variable
	char arr_string[1000] ; int length = 0  ;							// program two variable
	char str[100] ; char temp ; int j ;									// program three variable
	printf("Enter the number of program = ") ; fflush(stdout) ;
	scanf("%d" , &choice) ; fflush(stdin) ;
	switch( choice )
	{
	case 1 :
		printf("Enter your String or name =  "); fflush(stdout) ;
		gets(array_string) ; fflush(stdin) ;
		printf("Enter the character you want to calculate the freq = "); fflush(stdout) ;
		scanf("%c" ,&character)  ; fflush(stdin) ;
		freq =0 ;
		for (i =0 ; i < 1000 ; i++)
		{
			if (character == array_string[i])
				freq += 1 ;
			else if (array_string [i] == 0)
				break ;
			else
				continue ;
		}
		printf("the freq of character = %d" , freq ); fflush(stdout) ;
		break ;
	case 2 :
		printf("Enter the your string you want to count the length = "); fflush(stdout) ;
		gets(arr_string) ; fflush(stdin) ;
 		i = 0;
		while(arr_string[i] != 0)
		{
			length += 1 ;
			i++ ;
		}
		printf("the length of your string is =  %d " , length) ; fflush(stdout) ;
		break ;
	case 3 :
		printf("enter the string you want to reverse it = "); fflush(stdout) ;
		gets(str) ; fflush(stdin) ;
		i = 0 ;
		j = strlen(str) - 1 ;
		while ( i < j)
		{
			temp = str[i];
			str[i] = str[j] ;
			str[j] = temp ;
			i++ ;
			j-- ;
		}
		printf("the reversed string is =  %s" , str); fflush(stdout) ;
		break ;
	default :
		printf("Wrong program number ") ; fflush(stdout) ;
		break ;
	}
}
