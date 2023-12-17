/*
 ============================================================================
 Name        : C_Pointer_HW.c
 Author      : Ahmed Elsayed Bassiouny Sabra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
	char *empname;  // Employee name (string pointer)
	int empid;      // Employee ID (integer)
};
int main(void)
{
	int choice ;
	int m_var ; int* ptr = &m_var ; int** ptr_to_ptr = &ptr ;									// program one variable
	char* ptr_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int i ;									// program two variable
	char arr_alphabet[26]; char* ptr_arr_alphabet = arr_alphabet ;								// program three variable_Second way
	char Arr_string[100]; 																		// program four variable
	int Arr_Number[15] ; int size ; int* ptr_Arr_Number  ;										// program five variable
	printf("Enter the Number of Program ( 1 - 5 ) :: "); fflush(stdout);
	scanf("%d" , &choice) ;
	switch(choice)
	{
	case 1 :
		*ptr = 29 ;
		printf("the Address of M_Var is       = ox%x  and it's value = %d\n" , ptr , *ptr) ; fflush(stdout) ;
		printf("the Address of ptr to ptr  is = ox%x  and it's value = %d \n" ,*ptr_to_ptr , **ptr_to_ptr) ; fflush(stdout) ;
		m_var = 34 ;
		printf("the Address of ptr to ptr  is = ox%x  and it's value = %d \n" , *ptr_to_ptr , **ptr_to_ptr) ; fflush(stdout);
		**ptr_to_ptr = 7 ;
		printf("the Address of ptr to ptr  is = ox%x  and it's value = %d \n" ,*ptr_to_ptr , **ptr_to_ptr) ; fflush(stdout);
		break ;
	case 2:
		printf("print all the alphabet By Using The Pointer - First Way\n"); fflush(stdout) ;
		for (i = 0 ; i <26 ; i++)
		{
			if( i == 13)
				printf("\n");
			printf("%C\t" , *ptr_alphabet) ;fflush(stdout) ;
			ptr_alphabet++ ;
		}
		printf("\nprint all the alphabet By Using The Pointer - Second Way\n"); fflush(stdout) ;
		//******************** Another Way to print all the alphabet By Using The Pointer ************
		for( i = 0 ; i < 26 ; i++ , ptr_arr_alphabet ++ )
			*ptr_arr_alphabet = 'A' + i ;
		for( i = 0 , ptr_arr_alphabet = arr_alphabet ; i < 26 ; i++ , ptr_arr_alphabet ++ )
		{
			if(i == 13)
				printf("\n");
			printf("%C\t" , *ptr_arr_alphabet);
		}
		printf("\n") ; fflush(stdout);
		//******************** Another Way to print all the alphabet By Using The Pointer ***********
		break ;
	case 3 :
		printf("program in C to print a string in reverse using a pointer\n") ; fflush(stdout) ;
		printf("Enter the String you want to reverse it by pointer = "); fflush(stdout);
		fflush(stdin);
		gets(Arr_string);
		printf("the output After  the reversing is = "); fflush(stdout);
		int length = strlen(Arr_string) ;
		char *ptr_Arr_string = &Arr_string[length];
		for(int i = strlen(Arr_string) ; i >= 0 ; i-- , ptr_Arr_string-- )
			printf("%c", *(char *)ptr_Arr_string);
		printf("\n");fflush(stdout) ;
		break ;
	case 4 :
		printf ("Enter the Number of element you want to store = "); fflush(stdout) ;
		scanf("%d" , &size) ;
		printf("Enter the %d element you want to reverse       = ", size);fflush(stdout) ;
		for (i = 0 ; i <size ;i++)
			scanf("%d" ,&Arr_Number[i]);
		ptr_Arr_Number = &Arr_Number[size - 1] ;
		printf("The Reversed Number                            = ");
		for (i = 0 ; i <size ; i++ ,ptr_Arr_Number-- )
			printf("%d ", *ptr_Arr_Number);
		printf("\n");
		break ;
	case 5 :
		struct employee emp_one = {"Ahmed" , 1001}, emp_two = {"Midoo" , 1002} , emp_three = {"Gazza", 1003} ;
		struct employee(*Arr_struct[3])= {&emp_one , &emp_two, &emp_three};
		struct employee(* (*ptr_arr_struct)[3]) = & Arr_struct ;
		printf("the Name of first Employee is = %s and it's Id is = %d \n", (*(*(*ptr_arr_struct))).empname , (*(*ptr_arr_struct))->empid);
		fflush(stdout) ;
		printf("the Name of first Employee is = %s and it's Id is = %d \n", (*(*(*ptr_arr_struct+1))).empname , (*(*ptr_arr_struct+1))->empid);
		fflush(stdout) ;
		printf("the Name of first Employee is = %s and it's Id is = %d \n", (*(*(*ptr_arr_struct+2))).empname , (*(*ptr_arr_struct+2))->empid);
		fflush(stdout) ;
		break ;
	default :
		printf("Wrong Number Program \n");
		break ;
	}
}
