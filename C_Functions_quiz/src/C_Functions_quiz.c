/*
 ============================================================================
 Name        : C_Functions_quiz.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<conio.h>
#define Max_Size 100
int Compare_String(char arr_string[] , char user_name[]);
void Input_Array(int Arr[] , int Size_input) ;
void Swap_Array_Defferent_Size(int Arr_one[] ,int Arr_two[]) ;
void Print_Array(int Arr[] ,int Size_print);
void Reverse_Array(int Arr[] , int Size_arr);
int Check_Power_Number(int Number);
int Clear_specified_bit(int n , int bit) ;
int Last_Occurance_Of_Number(int Last_Arr[] , int Last_size , int Number) ;
unsigned int Str_to_Uint(char arr[] , int len);

int main(void)
{
	int choice ;
	char arr_string[100] ; char user_name[100] ;										// Program one Variable
	int Arr_one[Max_Size] ; int Arr_two[Max_Size] ; int Size_one , Size_two  ;			// Program two Variable
	int Array_to_reverse[100] ; int size_arr ;											// Program three Variable
	int number ,  bit ;																	// Program four Variable
	// Program five Variable
	unsigned int Number_Power ;															//Program six Variable
	int Last_Array[Max_Size] ; int Last_Size ; int Last_Number ;						//Program seven Variable
	printf("Enter the number of program you want run (1 - 7 ) :");  fflush(stdout) ;
	scanf("%d" , &choice) ;
	switch(choice)
	{
	case 1 :
		fflush(stdin) ;
		printf("Enter your name ="); fflush(stdout) ;
		gets(arr_string) ; fflush(stdin) ;
		printf("Enter your user name =");fflush(stdout) ;
		gets(user_name) ; fflush(stdin) ;
		if (stricmp(arr_string , user_name) == 0)
			printf("\n Identical , Welcome %s\n " ,arr_string ) ;
		else
			printf("\n Non Identical !!!!!\n") ;
		break ;
	case 2 :
		printf("Enter the Size of Array one = "); fflush(stdout) ;
		scanf("%d" ,&Size_one) ; fflush(stdin) ;
		printf("Enter the Size of Array two = "); fflush(stdout) ;
		scanf("%d" ,&Size_two) ; fflush(stdin) ;
		printf("Enter the %d element in source Array = " , Size_one) ; fflush(stdout) ;
		Input_Array(Arr_one , Size_one) ; fflush(stdin) ;
		printf("Enter the %d element in destination Array = " , Size_two) ; fflush(stdout) ;
		Input_Array(Arr_two , Size_two) ; fflush(stdin) ;
		Swap_Array_Defferent_Size(Arr_one ,Arr_two) ;
		printf("\n the Source Array after Swapping      = ") ; fflush(stdout) ;
		Print_Array(Arr_one , Size_two);fflush(stdout) ;fflush(stdout) ;
		printf("\n the destination Array after Swapping = ") ; fflush(stdout) ;
		Print_Array(Arr_two , Size_one);
		break ;
	case 3 :
		printf("Enter the size of array to reverse = "); fflush(stdout) ;
		scanf("%d" , &size_arr) ; fflush(stdin) ;
		printf("Enter the %d element of array to reverse = " , size_arr ); fflush(stdout) ;
		Input_Array(Array_to_reverse ,size_arr);
		Reverse_Array(Array_to_reverse ,size_arr );
		printf("\n the Array element after reversing       = "); fflush(stdout) ;
		Print_Array(Array_to_reverse ,size_arr );
		break ;
	case 4 :
		printf("Enter the number to clear the bit = ") ; fflush(stdout) ;
		scanf("%d" , &number) ;  fflush(stdin) ;
		printf("Enter the number of bit you want to clear = ") ; fflush(stdout) ;
		scanf("%d" , &bit) ; fflush(stdin) ;
		printf("the result is = %d " ,  Clear_specified_bit(number , bit) ); fflush(stdout) ;
		break ;
	case 5 :
		char str[10] ;						// should be size = 10 or less to be suitable to unsigned int
		fflush(stdout) ;
		printf("Enter the Number AS String = "); fflush(stdout) ;
		scanf("%s" , str) ;
		unsigned int nomber;
		nomber = Str_to_Uint(str , strlen(str)) ;
		printf("the unsigned integer after converting is = %u ", nomber); fflush(stdout) ;
		break ;
	case 6 :
		printf("Enter the number to check it if power of three or not = ") ; fflush(stdout) ;
		scanf("%d" , &Number_Power) ; fflush(stdin) ;
		Check_Power_Number(Number_Power) ? printf("%d is == > 0 " , Number_Power) : printf("%d is == > 1 " , Number_Power) ;
		break ;
	case 7 :
		printf("Enter the Size of Array "); fflush(stdout) ;
		scanf("%d" , &Last_Size);	 fflush(stdin) ;
		printf("Enter the  %d Element of array = " , Last_Size) ; fflush(stdout) ;
		Input_Array(Last_Array , Last_Size) ;
		printf("Enter the Number you want to get its last occurance = "); fflush(stdout) ;
		scanf("%d" , &Last_Number) ; fflush(stdin) ;
		printf("the last occurance of number %d is = %d "  ,Last_Number ,Last_Occurance_Of_Number(Last_Array,Last_Size,Last_Number)); fflush(stdout) ;
		break ;
	default :
		printf("Wrong number program !! ") ;fflush(stdout) ;
		break ;
	}
}


int Compare_String(char arr_string[] , char user_name[])
{
	int i = 0 ;
	while (arr_string[i] == user_name[i])
	{
		if (arr_string[i] == '\n'  || user_name[i] == '\n')
			break ;
		i++ ;
	}
	if (arr_string[i] == '\n'  && user_name[i] == '\n')
		return 1 ;
	else
		return 0 ;
}

void Input_Array (int Arr[] ,int Size_input)
{
	for(int i = 0 ; i < Size_input ; i++ )
	{
		scanf("%d" , &Arr[i]) ;
	}
}

void Swap_Array_Defferent_Size(int Arr_one[] ,int Arr_two[] )
{
	for (int i = 0 ; i < Max_Size ; i++)
	{
		Arr_one[i] = Arr_one[i] + Arr_two[i] ;
		Arr_two[i] = Arr_one[i] - Arr_two[i] ;
		Arr_one[i] = Arr_one[i] - Arr_two[i] ;
	}
}

void Print_Array(int Arr[] ,int Size_print)
{
	for (int i = 0 ; i < Size_print ; i++)
	{
		printf("%d\t" , Arr[i]) ;
	}
}

void Reverse_Array(int Arr[] , int Size_arr)
{
	for(int i = 0 , j = Size_arr -1 ; i < Size_arr/2 ; i++  ,j--)
	{
		Arr[i] = Arr[i] + Arr[j]   ;
		Arr[j] = Arr[i] - Arr[j]   ;
		Arr[i] = Arr[i] - Arr[j]   ;
	}
}

int Clear_specified_bit(int n , int bit)
{
	return n &= ~ ( 1 << bit ) ;
}

int Check_Power_Number(int Number)
{
	double i = log(Number) / log (3) ;
	return  i == trunc(i) ;
}

int Last_Occurance_Of_Number(int Last_Arr[] , int Last_size , int Number)
{
	int counter = 0 ;
	for (int i = 0 ; i < Last_size ; i++)
	{
		if(Number == Last_Arr[i])
			counter = i +1 ;
	}
	if (counter == 0 )
	{
		printf("the number %d is Not Exist \n " ,Number ) ;
		return counter ;
	}
	else
		return counter ;
}

unsigned int Str_to_Uint(char arr[] , int len)
{
	int i ;
	unsigned int n ;
	unsigned int total_n = 0 ;
	for (i = 0 ; i < len ; i++)
	{
		total_n *= 10 ;
		n = arr[i] - '0' ;
		total_n += n ;
	}
	return total_n ;
}
