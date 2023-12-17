/*
 ============================================================================
 Name        : C_Pointer_Training.c
 Author      : Ahmed Elsayed Bassiouny Sabra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct SData_set
{
	unsigned char data1 ;
	unsigned int data2 ;
	unsigned char data3 ;
	unsigned short data4 ;
}data_one;
struct SPerson
{
	char name[18] ;
	int m_id ;
	char m_age ;
	short m_salary ;
	double m_weight ;
};

struct Data
{
	int day ;
	int month ;
	int year ;
};

struct SStudent
{
	char neme[256] ;
	struct Data birth_day ;
	double degrees[10] ;
	double total_degree ;
};

void print_memory_range(char *base , int size)
{
	for (int i = 0 ; i <size ; i++ , base++)
		printf("%x \t %x \n" , base , (unsigned char)*base );
	fflush(stdout);
}

struct SStudent Slow_update_and_slow_data_transfer (struct SStudent s)
{
	s.total_degree = 0 ;
	for (int i = 0 ; i <10 ; i++ )
		s.total_degree += s.degrees[i] ;
	return s ;
}

void fast_update_and_fast_data_transfer(struct SStudent* ptr_s )
{
	ptr_s->total_degree = 0 ;
	for (int i = 0 ; i <10 ; i++)
		ptr_s->total_degree += ptr_s->degrees[i];
}

// void Bubble_Sort_Array(int arr_value[] , int size) == void Bubble_Sort_Array(int* arr_value , int size)

// Global Pointer To Function
void (* GP_func) () ;
void Pointer_to_Function()
{
	printf("Learn In Depth\n") ;  fflush(stdout);
}
// ProtoType to Function take pointer to function
void Check(char *s1 , char *s2 ,int  (* P_Func)(const char * , const char *));

int main(void)
{
	int k =512 ;
	char *ptr_k =(char*)&k;
	ptr_k[0] = 1 ;
	ptr_k[1] = 2 ;
	// ************ Simple Example to understand the pointer******************//
	int x = 10 ;
	int* PX = NULL ;
	PX = &x ;
	printf("0x%X \t 0x%X\n " , &x , PX) ;fflush(stdout);
	*PX = 5 ;
	printf("%d \t\t  %d\n" , x , *PX) ;fflush(stdout);
	// ************************* End of Simple Example ***********************//

	// ************************ Second Example of pointer *******************//
	int z = 5 , y = 10 ;  int*p = NULL ;
	p = &z ;
	printf("z = %d , Value pointed by P = %d \n" , z , *p) ; fflush(stdout);
	*p = 15 ;
	printf("z = %d , Value pointed by P = %d \n" , z , *p) ;fflush(stdout);
	p = &y ;
	printf("y = %d , Value pointed by P = %d \n" , y , *p) ;fflush(stdout);
	*p = 20 ;
	printf("y = %d , Value pointed by P = %d \n" , y , *p) ;fflush(stdout);
	// if you writer p = 0 ;  and *p = 15 , // Wrong and the program will crash here ;
	// ************************ End Second Example of pointer *******************//

	// ******************* unary increment operation for the pointer ******************//
	int *px = 0x0 ; char *py = 0x0 ; long long  *pz = 0x0 ;
	printf("px= ox%X \t py = 0x%x \t pz= ox%X \n" ,px , py ,pz ) ;fflush(stdout);
	px++ ;   py++ ;  pz++ ;			// each pointer increment to R/W  by size from its type
	printf("px= ox%X \t py = 0x%x \t pz= ox%X \n " ,px , py ,pz ) ;fflush(stdout);
	// ******************* End unary increment operation for the pointer **************//

	// ******************** Example of " pointer to array " **************************//
	int arr[5] = {1,2,3,4,5} ;
	int *ptr_arr = arr ;
	printf("%d \t " , *ptr_arr) ;fflush(stdout);
	ptr_arr++ ;
	printf("%d \t " , *ptr_arr) ;fflush(stdout);
	ptr_arr = arr + 3 ;
	printf("%d \t " , *ptr_arr) ;fflush(stdout);
	ptr_arr-- ;
	printf("%d \t " , *ptr_arr) ;fflush(stdout);
	ptr_arr = arr + 4  ;
	printf("%d \t \n" , *ptr_arr) ;fflush(stdout);
	// arr++ ;  Wrong !!! array is fixed address
	// ******************** end  Example of " pointer to array " **************************//

	// ********************* LAB Average of Weights by pointer and array ******************//
	int arr_box_weight[5] ;
	int *ptr_arr_box_weight = arr_box_weight ;
	int i = 0 ;  int sum = 0;
	printf(" Enter Five element to Calculate the tha averge = ") ; fflush(stdout);
	for ( i =0 ; i < 5 ; i++)
		scanf("%d" , ptr_arr_box_weight  + i );
	fflush(stdin);
	ptr_arr_box_weight = arr_box_weight ;
	for (i = 0 ; i < 5 ; i++)
		printf("%d \t" , *ptr_arr_box_weight + i) ;
	ptr_arr_box_weight = arr_box_weight ;
	for (i = 0 ; i < 5 ; i++ ,ptr_arr_box_weight++ )
		sum += *ptr_arr_box_weight ;
	printf("\nthe average of sum boxs weight is = %d\n" , sum/5) ; fflush(stdout);
	// char arr_str[80] , *ptr_str ;   ptr_str = arr_str ;
	// *(ptr_str +4) = arr_str[4] ;   this is the same if you want to access the fifth element.
	// ********************* End LAB Average of Weights by pointer and array ******************//

	//********************** Start  pointer to structures " Dumping the memory " ************************//
	data_one.data1 = 0x11 ;
	data_one.data2 =0xFFFFEEEE ;
	data_one.data3 = 0x22 ;
	data_one.data4 = 0xABCD ;
	print_memory_range(&data_one , sizeof(data_one)) ;
	char *ptr_struct_char = &data_one ;
	printf(" ptr_struct + 8 = %x \n" , (unsigned char)*(ptr_struct_char+8) ) ; fflush(stdout);
	struct SData_set *ptr_to_struct = &data_one ;
	printf(" ptr_struct + 8 = %x \n" , (unsigned char)ptr_to_struct->data3) ;fflush(stdout);
	//********************** end pointer to structures " Dumping the memory " *****************************//

	// ********* start example of pointer to Structures" Accessing member of structures by pointer" ******//
	struct SPerson manger ={"Ahmed elsayed" , 1 , 26 , 5000 , 70.50} ;
	struct SPerson employee[]={
			{"mido" , 10 , 26 , 5000 , 70.50} ,
			{"ahmed", 12 , 50 , 4000 , 80.20 } ,
			{"ibra" , 13 , 40 , 5000 , 90.2 } ,
			{"aida" , 52 , 60 , 1600 , 102.20}};
	struct SPerson* ptr_sperson_struct  =&manger;
	printf("manger : %s \t %d \t %d \t %d \t %lf \n" , ptr_sperson_struct->name ,ptr_sperson_struct->m_id,
			(int) ptr_sperson_struct->m_age,(int) ptr_sperson_struct->m_salary,ptr_sperson_struct-> m_weight) ; fflush(stdout);
	ptr_sperson_struct->m_salary = 10000 ;
	printf("manger : %s \t %d \t %d \t %d \t %lf \n" , manger.name ,manger.m_id ,
			(int) manger.m_age ,(int)manger.m_salary , manger.m_weight ) ; fflush(stdout);
	ptr_sperson_struct = employee ;
	for(int i = 0 ; i < sizeof(employee)/sizeof(struct SPerson) ; i++ , ptr_sperson_struct++)
	{
		printf("Employee %d : %s \t %d \t %d \t %d \t %lf \n" , i+1 , ptr_sperson_struct->name ,
				ptr_sperson_struct->m_id, (int)ptr_sperson_struct->m_age ,
				(int) ptr_sperson_struct->m_salary , ptr_sperson_struct-> m_weight );
		fflush(stdout);
	}
	// *********End  example of pointer to Structures" Accessing member of structures by pointer" ******//

	//********* fast data transfer using pointer and pass structures to function************************//
	struct SStudent student = { "ahmed elsayed" ,{12 , 06 , 1997} , {10,20,30,40,50,60,70,80,90,100} };
	student = Slow_update_and_slow_data_transfer(student) ;
	printf("the total degree od Student %s is = %2.2lf which mean = (%2.2lf %) \n",
			student.neme , student.total_degree, (double) (100.0 * student.total_degree/1000.0)) ;
	fflush(stdout);
	fast_update_and_fast_data_transfer(&student) ;
	printf("the total degree od Student %s is = %2.2lf which mean = (%2.2lf %) \n",
			student.neme , student.total_degree, (double) (100.0 * student.total_degree/1000.0)) ;
	fflush(stdout);
	//********* fast data transfer using pointer and pass structures to function************************//

	//******************** pointer with unknown type = generic pointer = void pointer *****************//
	int var_one = 5 ; double var_two = 10 ;
	void* ptr_var = &var_one ;
	printf("%lu\n ",sizeof(ptr_var));
	*(int*)ptr_var = 80 ; printf("var one = %d\n" , var_one ) ;
	fflush(stdout);
	ptr_var = &var_two ;
	*(double*)ptr_var= 100  ; printf("var two = %d\n" , var_two ) ;
	fflush(stdout);
	//******************** pointer with unknown type = generic pointer = void pointer *****************//

	// ****************** multiple indirection = using  pointer to pointer **************************//
	int N_one = 5 , N_two = 10 ;
	int* ptr_N = &N_one ;
	int** ptr_ptr_n = &ptr_N ;
	**ptr_ptr_n= 50 ; printf("N_one is = %d \n" , N_one) ; fflush(stdout);
	ptr_N = &N_two ;
	**ptr_ptr_n = 100 ; printf("N_two is = %d\n " , N_two) ; fflush(stdout);
	// *ptr_ptr_n = &N_two ; *ptr_N = 100 ; printf("N_two is = %d" , N_two) ;

	// ****************** multiple indirection = using  pointer to pointer **************************//

	//****************** NULL and Unassigned Pointers **********************//
	int* ptr_unassigned ; printf("ptr_unassigned point to = %d" , *ptr_unassigned) ;
	// because the (ptr_unassigned) pointer is not pointed to a valid address, it contain a memory gurbage
	/* To avoid using unassigned pointers, all pointers must hold a valid address,
	 * if not it must hold a zero value. Sometimes zero value called (NULL).*/
	int* ptr_null = NULL ;
	if (ptr_null != NULL)
		printf("ptr_null is point to = %d\n" , *ptr_null);
	else
		printf("ptr_null is not initialized \n");
	//****************** NULL and Unassigned Pointers **********************//

	//****************** Pointer to Function *****************************//
	Pointer_to_Function() ;
	GP_func = Pointer_to_Function ;
	GP_func();
	// Another Example on Pointer to function
	char s1[50] , s2[50] ;
	int (*P_Func)(const char * , const char *);
	P_Func = strcmp ;
	printf("Enter the first string ") ; fflush(stdout);
	fflush(stdin);
	gets(s1) ;
	printf("Enter the second  string ") ; fflush(stdout);
	fflush(stdin);
	gets(s2) ;
	Check(s1,s2,P_Func) ;
	//****************** Pointer to Function *****************************//

	// ****************** Example on Complex Pointer *********************//
	//void  (* (*f[])() ) () ->
	// f as array of pointer to function returning pointer to function returning void
	// int (* p)(char)
	// P is A Pointer to function  take one char argument and return integer
	//  char ** (*p)(float , float)
	// P is a pointer to function take two float agrument and return char Pointer to pointer
	// void *(*a[5])(char * const, char * const );
	// a is array of five element of pointer to function take two char pointer agr and
	// return unknown pointer
	// int *(* (* Fb1)(int))[10]
	// Fb1 is a pointer to function take int and return a pointer that point to array
	// of ten element , each element is integer pointer
	//  int *(*(*arr[5])())();
	// ****************** Example on Complex Pointer *********************//

	// ***************** Pointer with Constant *******************//
	// char  *ptr			->	 not value and not pointer
	//const char *ptr		->   value is constant
	// char const *ptr		->   value is constant
	//char* const ptr		->   pointer is constant
	//const char*const ptr	->   value and pointer is constant
	// ***************** Pointer with Constant *******************//

	//****************** Pointer Type ***************************//
	// 1) NULL Pointer = pointer which is pointing to nothing || intilizing to NULL
	// float *ptr = NULL ;    ||    float *ptr = (float*)0 ;
	//  2) Dangling Pointer = arise when an object is deleted || de allocate memory without modifying
	// 						  non existing memeory allocatoin
	// int Ptr_dang = malloc(4) ;
	// free (ptr_dang) ; ptr_dang is now become a dangling pointer
	//another example char ptr = NULL ;{int y = 0 ; ptr = &y ;} ptr is Now Dangling Pointer
	// 3) generic pointer  = which is defined by void* ptr
	// 4) Wild Pointer = that point to random memory location.
	// to avoid it initilize it with the declaration.
	// char* ptr   		-> ptr is A wild pointer.
	//  Near , Far and huge pointer
	//****************** Pointer Type ***************************//
	return 0 ;
}

void Check (char *s1, char *s2, int (*P_Func)(const char * , const char *))
{
	printf("Testing for Quality\n");
	if (!(*P_Func)(s1,s2))
		printf("Equal\n");
	else
		printf("Not Equal\n");
}
