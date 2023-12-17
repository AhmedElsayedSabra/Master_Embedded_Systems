/*
 ============================================================================
 Name        : Mid_Term_Exam_Training.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<math.h>
#include<string.h>

int Sum_Individual_Digits(int number) ;
double Calc_Square_Root(double number_To_Squre_Root);
int check_Prime_Number (int n ) ;
int Reversed_Number_Function(int Number) ;
void Reversed_Number_Function_two (char arr[] , int length);
int Counter_Of_Ones_Digits (int number);
void Input_Array(int Arr[] , int Size_input) ;
void Check_Unique_Value_Of_Array(int arr[] , int size);
int Sum_Number_Between_1_To_100(int num , int Sum);
void Reverse_Array(int Arr[] , int Size_arr);
void Print_Array(int Arr[] ,int Size_print) ;
void Printing_Reversed_String(char str[]);
int Counter_Max_Ones_Between_Two_Zeros ( int number);

int main(void)
{
	int choice ;
	int number ;																			// Program One Variable
	double  number_To_Squre_Root ;															// Program Two Variable
	int Begin_number , End_Number ; int flag ;												// Program three Variable
	int Number_to_Reverse ; char Number_to_reverse[100]  ; int Length ;						// Program four Variable
	int Num ;																				// Program five Variable
	int Array_to_unique[100] , Size_Array ;													// Program Six Variable
	int Array_to_reverse[100] ; int size_arr ;												// Program eight Variable
	char str[100];																			// Program nine Variable
	int Number ;																			//  Program Ten Variable
	printf("Enter the number of program you want run (1 - 10 ) :");  fflush(stdout) ;
	scanf("%d" , &choice) ;fflush(stdin) ;
	switch(choice)
	{
	case 1 :
		// Description: This C program takes a number and sum its all individual digits.
		printf("Enter the number you want sum its all individual digits = ") ; fflush(stdout) ;
		scanf("%d" , &number);fflush(stdin) ;
		printf("The sum of all individual digits is = %d " , Sum_Individual_Digits(number));
		break ;
	case 2 :
		//Description:  This C function takes a number from the user and calculate it's square root
		printf("Enter the number you want to calculate the square root = ") ; fflush(stdout) ;
		scanf("%lf" , &number_To_Squre_Root);fflush(stdin) ;
		printf("The number is %.4lf and the Square root is = %.4lf ", number_To_Squre_Root , Calc_Square_Root(number_To_Squre_Root));
		break ;
	case 3:
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
		break ;
	case 4 :
		// Description: program that reverse the digits of a number entered by the user and print it.
		// C Program to reverse the digits of a number like that  ( 12345  >>>   54321)
		printf("Enter the Number to reverse it by using array of character = " );fflush(stdout) ;
		gets(Number_to_reverse) ;
		printf("Enter the Number to Reverse it by using Algorithms         = ");fflush(stdout) ;
		scanf("%d" , &Number_to_Reverse) ;fflush(stdin) ;
		Length = strlen(Number_to_reverse) ;
		Reversed_Number_Function_two(Number_to_reverse , Length) ;
		printf("\nThe Number %d After Reversing by using Algorithms is = %d \n" , Number_to_Reverse , Reversed_Number_Function(Number_to_Reverse)) ;fflush(stdout) ;
		break ;
	case 5 :
		// Description: program that counts the number of ones in binary number
		printf("Enter the number to Count the Number of ones digits after convert it to binary numbers = ");fflush(stdout) ;
		scanf("%d" ,&Num) ;fflush(stdin) ;
		printf("The number of of ones in %d  is = %d" , Num , Counter_Of_Ones_Digits(Num) ) ;fflush(stdout) ;
		break ;
	case 6 :
		//  Description: C program that return the unique number in an array with one loop.
		// test case 1:    input: int a[7]={4,2,5,2,5,7,4};                  output:7.
		// test case 2:    input: int a[3]={4,2,4};                     	 output:2.
		printf("Enter the Size of Array to Discover the Unique Value = ");fflush(stdout) ;
		scanf("%d" , &Size_Array );fflush(stdin) ;
		printf("Enter the %d Elemant to calculate the unique value = " , Size_Array); fflush(stdout) ;
		Input_Array(Array_to_unique , Size_Array);  fflush(stdin) ;
		Check_Unique_Value_Of_Array(Array_to_unique , Size_Array) ;fflush(stdout) ;
		break ;
	case 7 :
		// Description: C program that sum numbers from 1 to 100 (without loop).
		printf("The Sum Of Numbers Between 1 To 100 is = %d  Without Looping " , Sum_Number_Between_1_To_100(100 , 0)) ; fflush(stdout) ;
		break ;
	case 8 :
		// Description: C Program to reverse the Array With out Another array & temp Variable
		printf("Enter the size of array to reverse = "); fflush(stdout) ;
		scanf("%d" , &size_arr) ; fflush(stdin) ;
		printf("Enter the %d element of array to reverse = " , size_arr ); fflush(stdout) ;
		Input_Array(Array_to_reverse ,size_arr);                    fflush(stdin) ;
		Reverse_Array(Array_to_reverse ,size_arr );
		printf("the Array element after reversing       = ");    fflush(stdout) ;
		Print_Array(Array_to_reverse ,size_arr );
		break ;
	case 9 :
		printf("Please Enter any String: "); fflush(stdout);
		gets(str);
		Printing_Reversed_String(str);
		break ;
	case 10 :
		// Description: program that count the max number of ones between two zeros in a binary number To Decimal Number
		printf("Enter the Decimal Number to count the max number of ones between two zeros in a binary number") ;fflush(stdout) ;
		scanf("%d" , &Number); fflush(stdin);
		printf("the max number of ones between two zeros in a binary number To %d is = %d\n" ,Number,Counter_Max_Ones_Between_Two_Zeros(Number)) ;
		break ;
	default :
		printf("Wrong number program ") ;
		break ;
	}
	return 0 ;
}

int Sum_Individual_Digits(int number)
{

	int sum = 0 ;
	while ( number / 10 != 0)
	{
		sum +=  number%10 ;
		number = number / 10 ;
	}
	return (sum + number) ;
}

double Calc_Square_Root(double  number_To_Squre_Root)
{
	// return sqrt(number_To_Squre_Root );                          //  you can remove the below code and use this line
	double i = 0 , j = number_To_Squre_Root / 2 ;
	while (j != i )
	{
		i = j ;
		j = ( number_To_Squre_Root / i + i ) /2 ;
	}
	return j ;
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

int Reversed_Number_Function(int Number)
{
	int Reversed_Number = 0 ;
	int Remainder ;
	for (int temp = Number ; temp != 0 ; temp /= 10)
	{
		Remainder = temp % 10 ;									// Extract the last digit of number
		Reversed_Number = Reversed_Number * 10 + Remainder ;	// Append the extracted digit to the reversedNumber
	}
	return Reversed_Number ;
}

void Reversed_Number_Function_two (char arr[] , int length)
{
	printf("The Number %s After Reversing by using Array Of Character is = " , arr ) ;fflush(stdout) ;
	for (int i = length -1 ; i >= 0 ; i--)
		printf("%c" , arr[i]);
}

int Counter_Of_Ones_Digits (int number)
{
	int New_Number , Counter = 0 ;
	for ( int Number_Of_Integer_Bits = 31; Number_Of_Integer_Bits >= 0 ;  Number_Of_Integer_Bits--)
	{
		New_Number = number >> Number_Of_Integer_Bits ;
		if (New_Number & 1)
			Counter++ ;
	}
	return Counter ;
}

void Input_Array (int Arr[] ,int Size_input)
{
	for(int i = 0 ; i < Size_input ; i++ )
	{
		scanf("%d" , &Arr[i]) ;
	}
}

void Check_Unique_Value_Of_Array(int arr[] , int size)
{
	int result = 0 ;
	for (int i =0 ; i <size ; i++)
		result ^=arr[i] ;
	printf("The Unique Value of that Array is = %d" , result) ;
}

int Sum_Number_Between_1_To_100(int Num , int Sum)
{
	Sum += Num ;
	Num-- ;
	if (Num != 0)
		return Sum_Number_Between_1_To_100(Num , Sum) ;
	return Sum ;
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

void Print_Array(int Arr[] ,int Size_print)
{
	for (int i = 0 ; i < Size_print ; i++)
	{
		printf("%d\t" , Arr[i]) ;
	}
}

void Printing_Reversed_String(char str[])
{
	printf("The Reversed String is = ") ; fflush(stdout) ;
	int Start_Index , End_Index ;
	End_Index = strlen(str) - 1 ;
	for (int i = End_Index ; i >= 0 ; i--)
	{
		if (str[i] == ' ' || i == 0)
		{
			if (i == 0)
				Start_Index = 0 ;
			else
				Start_Index = i + 1 ;
			for (int j = Start_Index ; j <= End_Index ; j++)
				printf("%c" ,str[j]) ;
			End_Index = i - 1 ;
			printf(" ") ;
		}
	}

}

int Counter_Max_Ones_Between_Two_Zeros ( int number)
{
	int Counter = 0 ,  Max_Ones = 0 ;
	for(int i = 0 ; i < 32 ; i++)
	{
		if(number & (1 << i))
		{
			Counter++ ;
			if (Counter > Max_Ones )
				Max_Ones = Counter ;
		}
		else
			Counter = 0 ;
	}
	return Max_Ones ;
}
