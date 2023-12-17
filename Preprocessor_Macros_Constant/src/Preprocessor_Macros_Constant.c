/*
 ============================================================================
 Name        : Preprocessor_Macros_Constant.c
 Author      : Ahmed Elsayed Bassiouny Sabra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define debug
#define Ahmed_Elsayed_sabra
#define a 100					//example on #if
// ************************* macros version ******************//
#define value 3 														 // version Macros
#define PR(Value , Max_Value) (100.0 * Value / (double) Max_Value)  	 // version two macros
#define Ahmed_Printer(...) printf(__VA_ARGS__)  						 // version three macros
#define learn_in_depth(a,...) printf(__VA_ARGS__,a)				     	// version four macros
#define ahmed m##a##i##n												// version five macros
//*****************	Debugging ****************//
// #define debug
#define DPRINTF(debug_level,...)  if(debug_level >1){\
		printf("@ func :%s , file :%s , line :%d ", __func__ , __FILE__  , __LINE__) ; \
		printf(">> \t") ;\
		printf(__VA_ARGS__);}
void can_send()
{
#ifdef debug
	DPRINTF(3 , "\n") ;
#endif
}

void can_init()
{
#ifdef debug
	DPRINTF(3 , "\n") ;
#endif
}
//******************************* end debugging *******************//
int main(void)
{
	//************ Example Of #ifdef #else #endif
#ifdef Ahmed_Elsayed_sabra
	printf("Ahmed elsayed sabra id defined" ) ;
#else
	printf("Ahmed elsayed sabra is not defined ") ;
#endif
	//**************** end example ******************************//

	//****************** Start debugging code in main **************//
#ifdef debug
	DPRINTF(3 , "\n") ;
#endif
	can_send();
	can_init();
#ifdef debug
	DPRINTF(3 , "\n") ;
#endif
	//******************* end debugging code in main ********************//

	//******************* start example of version of macros ***********//
	fflush(stdout);
	Ahmed_Printer("Arabic is = %lf\n" ,PR(30,50) ) ;
	learn_in_depth(value, "Arabis is= %d\n" ) ;
	//***************** start example of version of macros ************//

	//*************************** Start example on #if  #else  #endif ****** //
#if (a== 100)
	printf("A == 100 already. this line will be added if a=100") ;
#else
	printf("A != 100 already.this line will be added if a != 100 ") ;
#endif
	return 0 ;
}

