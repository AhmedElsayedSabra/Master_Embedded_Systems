/*
 ============================================================================
 Name        : Structures_Enum_Union_HW.c
 Author      : Ahmed Elsayed Bassiouny Sabra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#define PI 3.1415
#define area(r) (PI*(r)*(r))

//////// Prototyping ///////////////
struct SComplex Read_Complex_Number(char name[]) ;
struct SComplex Add_Complex_Number ( struct SComplex A, struct SComplex B) ;
void print_Complex_Number (char name[] , struct SComplex C) ;

struct info_of_student
{
	char name[50] ;
	int roll ;
	float mark ;
};

struct Distance
{
	int feet ;
	float inch ;
};

struct SComplex
{
	double real ;
	double imaginary ;
};

struct Job_One
{
	char name[32];
	float Salary ;
	int Worker_no ;
}S;

union Job
{
	char name[32];
	float Salary ;
	int Worker_no ;
}U;
int main(void)
{
	int choice ;
	struct info_of_student S ;																// program One Variable
	struct Distance d1 , d2 , sum ;															// Program two Variable
	struct SComplex S1 , S2 , Sum ;															// Program three Variable
	struct info_of_student Students[10] ; int i = 0 ;										// Program Four Variable
	int raduis ; float Area ;																// Program Five Variable
	printf("Enter the Number of Program you want run ( 1 - 6 )= "); fflush(stdout) ;
	scanf("%d" , &choice) ; fflush(stdin) ;
	switch (choice )
	{
	case 1 :
		printf("Enter the Information of student = \n");fflush(stdout) ;
		printf("enter the name of student = ");fflush(stdout) ;
		gets(S.name) ;fflush(stdin) ;
		printf("Enter the roll number = ") ;fflush(stdout) ;
		scanf("%d" , &S.roll) ;fflush(stdin) ;
		printf("Enter the mark of student = ") ;fflush(stdout) ;
		scanf("%f" , &S.mark);fflush(stdin) ;
		printf("Displaying the information \n" ) ;fflush(stdout) ;
		printf("Name: %s \n roll : %d \n mark : %f \n " , S.name , S.roll , S.mark);fflush(stdout) ;
		break ;
	case 2 :
		printf("Enter the information for 1st distance \n"); fflush(stdout) ;
		printf("Enter the feet = ") ;   fflush(stdout) ;
		scanf("%d" , &d1.feet) ;  fflush(stdin) ;
		printf("Enter the inch = ") ;  fflush(stdout) ;
		scanf("%f" , &d1.inch) ;  fflush(stdin) ;
		printf("Enter the information for 2st distance \n");  fflush(stdout) ;
		printf("Enter the feet = ") ;   fflush(stdout) ;
		scanf("%d" , &d2.feet) ;   fflush(stdin) ;
		printf("Enter the inch = ") ;   fflush(stdout) ;
		scanf("%f" , &d2.inch) ;  fflush(stdin) ;
		sum.feet = d1.feet + d2.feet ;								// we can use also >>  sum = d1 +d2 ; //structure =  structure + structure
		sum.inch = d1.inch + d2.inch ;
		if (sum.inch > 12.0)
		{
			sum.inch = sum.inch - 12.0  ;
			++sum.feet ;
		}
		printf("Sum of Distance is = %d \'  -  %2.2f\" " , sum.feet , sum.inch) ;   fflush(stdout) ;
		break ;
	case 3 :
		S1 = Read_Complex_Number("S1") ;
		S2 = Read_Complex_Number("S2") ;
		Sum = Add_Complex_Number( S1 , S2) ;
		print_Complex_Number("Sum" , Sum) ;
		break ;
	case 4 :
		printf("Enter 10 Data of Student to store in structures of array\n ") ; fflush(stdout) ;
		for (i = 0 ; i < 10 ; i++)
		{
			Students[i].roll = i + 1 ;
			printf("Enter the name  of Student %d = ", i+1); fflush(stdout) ;
			scanf("%s" , Students[i].name);fflush(stdin) ;
			printf("Enter the mark  of Student %d = ", i+1);fflush(stdout) ;
			scanf("%f" , & Students[i].mark) ;	fflush(stdin) ;
		}
		printf("Displaying of 10 Data of Structures of Array \n") ;
		for (i = 0 ; i < 10 ; i++)
		{
			printf("Roll Number %d \t %s \t %2.2f \n" , Students[i].roll , Students[i].name , Students[i].mark) ;
			fflush(stdout) ;
		}
		break ;
	case 5:
		printf("Enter The Raduis = "); fflush(stdout) ;
		scanf("%d" , &raduis) ;fflush(stdin) ;
		Area =area( raduis );
		printf("the Area is = %.2f" , Area) ; fflush(stdout) ;
		break ;
	case 6:
		printf("Size of Union = %lld \n" , sizeof(U) ) ; fflush(stdout) ;
		printf("Size of Structures = %lld \n" , sizeof(S) ) ; fflush(stdout) ;
		break ;
	default :
		printf(" Wrong Number Program ") ;
		break ;

	}
	return 0 ;
}

//     definition Of Function ///
struct SComplex Read_Complex_Number(char name[])
{
	struct SComplex C ;
	printf("Enter %s Complex Value (EX : 5 , -3 ) = " , name) ; fflush(stdout) ;
	scanf("%lf %lf" , &C.real , &C.imaginary) ; fflush(stdin) ;
	return C ;
}

struct SComplex Add_Complex_Number ( struct SComplex A, struct SComplex B)
{
	struct SComplex C ;
	C.real = A.real  + B.real ;
	C.imaginary = A.imaginary  + B.imaginary ;
	return C ;
}

void print_Complex_Number (char name[] , struct SComplex C)
{
	printf("%s  = (%2.2lf) +  (%2.2lf) I \r\n" , name , C.real  , C.imaginary) ;   fflush(stdout) ;
}
