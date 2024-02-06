
#ifndef PLATFORM_TYPE_H_
#define PLATFORM_TYPE_H_

 /*
  * Type definitions - SHx
  * The platform types for Renesas SHx could have the following mapping to the ANSIC types
  * Author: Ahmed Elsayed Sabra
  */
#define CPU_TYPE 				CPU_TYPE_32
#define CPU_BIT_ORDER 			LSB_FIRST
#define CPU_BYTE_ORDER 			HIGH_BYTE_FIRST

typedef unsigned char 					boolean ;
typedef signed char 					sint8_t ;
typedef unsigned char 					uint8_t ;
typedef signed short 					sint16_t ;
typedef unsigned short 					uint16_t ;
typedef signed int 						sint32_t ;
typedef unsigned int 					uint32_t ;
typedef signed long long 				sint64_t ;
typedef unsigned long long  			uint64_t ;
typedef float 							float32_t ;
typedef double 							float64_t ;

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

#endif
