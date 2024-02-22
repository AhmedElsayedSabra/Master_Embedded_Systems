
/* File Guards to protect from recursive inclusion.*/
#ifndef PLATFORM_DATA_TYPES_H_
#define PLATFORM_DATA_TYPES_H_

typedef unsigned char         			Boolean;
typedef unsigned char         			uint8_t;        /*          0 ---> 255              */
typedef signed char           			sint8_t;        /*        -128 --->  +127           */
//typedef unsigned short	         		uint16_t;       /*         0 ---> 65535             */
typedef signed short          			sint16_t;       /*      -32768 ---> +32767          */
typedef unsigned long         			uint32_t;       /*           0 ---> 4294967295      */
typedef signed long           			sint32_t;       /* -2147483648 ---> +2147483647     */
typedef unsigned long long    			uint64_t;       /*       0--->18446744073709551615  */
typedef signed long long      			sint64_t;
typedef float                 			float32_t;
typedef double                			float64_t;
typedef volatile signed char 			vsint8_t ;
typedef volatile unsigned char 			vuint8_t ;
typedef volatile signed short 			vsint16_t ;
typedef volatile unsigned short 		vuint16_t ;
typedef volatile signed int 			vsint32_t ;
typedef volatile unsigned int 			vuint32_t ;
typedef volatile signed long long 		vsint64_t ;
typedef volatile unsigned long long  	vuint64_t ;
typedef volatile float 					vfloat32 ;
typedef volatile double 				vfloat64 ;

#endif /* PLATFORM_DATA_TYPES_H_ */
